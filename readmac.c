#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdarg.h>
#include <getopt.h>
#include <sys/ioctl.h>
#include <time.h>
#include <termios.h>

#define LOG_TAG "ReadMac"
#include "cutils/log.h"


extern void huawei_oem_rapi_streaming_function(int n, int p1, int p2, int p3, int *v1, int *v2, int *v3);

unsigned char *read_mac() {
{
    char mac_param[128];
    char x[6];
    int y;

    memset(x,0,6);
    y=0;    
    huawei_oem_rapi_streaming_function(3,0,0,0,0,&y,x);
    ALOGI("huawei_oem_rapi_streaming_function %p %x %x",x,x[1],y);
    sprintf(mac_param,"mac_param=%02X:%02X:%02X:%02X:%02X:%02X",x[5],x[4],x[3],x[2],x[1],x[0]);
    ALOGI("Got MAC Address: %s ",mac_param);
    return x;
}
