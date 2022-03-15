#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>
#include <stdio.h>
#include <string.h>
#include <sys/syscall.h> 
#include <assert.h>
#include <string.h>
#include <stdbool.h>

FILE* temp[8];

void printusb() {
    int eatReturn;
    char tempArray1[4][1024];
    char tempArray2[4][1024];
    char tempArray3[4][1024];
    char tempArray4[4][1024];
    char tempArray5[4][1024];
    
    
    temp[0] = fopen("/sys/bus/usb/devices/usb1/busnum", "r");
    assert(temp[0] != NULL);
    temp[1] = fopen("/sys/bus/usb/devices/2-1/busnum", "r");
    assert(temp[1] != NULL);
    temp[2] = fopen("/sys/bus/usb/devices/2-2/busnum", "r");
    assert(temp[2] != NULL);
    temp[3] = fopen("/sys/bus/usb/devices/2-2.1/busnum", "r");
    assert(temp[3] != NULL);
    temp[4] = fopen("/sys/bus/usb/devices/usb2/busnum", "r");
    assert(temp[4] != NULL);
    temp[5] = fopen("/sys/bus/usb/devices/usb1/devnum", "r");
    assert(temp[5] != NULL);
    temp[6] = fopen("/sys/bus/usb/devices/2-1/devnum", "r");
    assert(temp[6] != NULL);
    temp[7] = fopen("/sys/bus/usb/devices/2-2/devnum", "r");
    assert(temp[7] != NULL);
    
    temp[8] = fopen("/sys/bus/usb/devices/2-2.1/devnum", "r");
    assert(temp[8] != NULL);
    temp[9] = fopen("/sys/bus/usb/devices/usb2/devnum", "r");
    assert(temp[9] != NULL);
    temp[10] = fopen("/sys/bus/usb/devices/usb1/idVendor", "r");
    assert(temp[10] != NULL);
    temp[11] = fopen("/sys/bus/usb/devices/2-1/idVendor", "r");
    assert(temp[11] != NULL);
    temp[12] = fopen("/sys/bus/usb/devices/2-2/idVendor", "r");
    assert(temp[12] != NULL);
    temp[13] = fopen("/sys/bus/usb/devices/2-2.1/idVendor", "r");
    assert(temp[13] != NULL);
    temp[14] = fopen("/sys/bus/usb/devices/usb2/idVendor", "r");
    assert(temp[14] != NULL);
    temp[15] = fopen("/sys/bus/usb/devices/usb1/idProduct", "r");
    assert(temp[15] != NULL);
    temp[16] = fopen("/sys/bus/usb/devices/2-1/idProduct", "r");
    assert(temp[16] != NULL);
    temp[17] = fopen("/sys/bus/usb/devices/2-2/idProduct", "r");
    assert(temp[17] != NULL);
    temp[18] = fopen("/sys/bus/usb/devices/2-2.1/idProduct", "r");
    assert(temp[18] != NULL);
    temp[19] = fopen("/sys/bus/usb/devices/usb2/idProduct", "r");
    assert(temp[19] != NULL);

 //eatReturn是明確的把「回傳值」吃掉，讓編譯器不要出現警告訊息 
    fseek(temp[0], 0, SEEK_SET);
    eatReturn=fscanf(temp[0], "%s", tempArray1[0]);
    fseek(temp[1], 0, SEEK_SET);
    eatReturn=fscanf(temp[1], "%s", tempArray2[0]);
    fseek(temp[2], 0, SEEK_SET);
    eatReturn=fscanf(temp[2], "%s", tempArray3[0]);
    fseek(temp[3], 0, SEEK_SET);
    eatReturn=fscanf(temp[3], "%s", tempArray4[0]);
    fseek(temp[4], 0, SEEK_SET);
    eatReturn=fscanf(temp[4], "%s", tempArray5[0]);
    fseek(temp[5], 0, SEEK_SET);
    eatReturn=fscanf(temp[5], "%s", tempArray1[1]);
    fseek(temp[6], 0, SEEK_SET);
    eatReturn=fscanf(temp[6], "%s", tempArray2[1]);
    fseek(temp[7], 0, SEEK_SET);
    eatReturn=fscanf(temp[7], "%s", tempArray3[1]);
    fseek(temp[8], 0, SEEK_SET);
    eatReturn=fscanf(temp[8], "%s", tempArray4[1]);
    fseek(temp[9], 0, SEEK_SET);
    eatReturn=fscanf(temp[9], "%s", tempArray5[1]);
    fseek(temp[10], 0, SEEK_SET);
    eatReturn=fscanf(temp[10], "%s", tempArray1[2]);
    fseek(temp[11], 0, SEEK_SET);
    eatReturn=fscanf(temp[11], "%s", tempArray2[2]);
    fseek(temp[12], 0, SEEK_SET);
    eatReturn=fscanf(temp[12], "%s", tempArray3[2]);
    fseek(temp[13], 0, SEEK_SET);
    eatReturn=fscanf(temp[13], "%s", tempArray4[2]);
    fseek(temp[14], 0, SEEK_SET);
    eatReturn=fscanf(temp[14], "%s", tempArray5[2]);
    fseek(temp[15], 0, SEEK_SET);
    eatReturn=fscanf(temp[15], "%s", tempArray1[3]);
    fseek(temp[16], 0, SEEK_SET);
    eatReturn=fscanf(temp[16], "%s", tempArray2[3]);
    fseek(temp[17], 0, SEEK_SET);
    eatReturn=fscanf(temp[17], "%s", tempArray3[3]);
    fseek(temp[18], 0, SEEK_SET);
    eatReturn=fscanf(temp[18], "%s", tempArray4[3]);
    fseek(temp[19], 0, SEEK_SET);
    eatReturn=fscanf(temp[19], "%s", tempArray5[3]);
   
    for(int i=0;i<20;i++)
        fclose(temp[i]);
    printf("BUS %s Device %s: ID %s:%s\n",tempArray1[0],tempArray1[1],tempArray1[2],tempArray1[3]);
    printf("BUS %s Device %s: ID %s:%s\n",tempArray2[0],tempArray2[1],tempArray2[2],tempArray2[3]);
    printf("BUS %s Device %s: ID %s:%s\n",tempArray3[0],tempArray3[1],tempArray3[2],tempArray3[3]);
    printf("BUS %s Device %s: ID %s:%s\n",tempArray4[0],tempArray4[1],tempArray4[2],tempArray4[3]);
    printf("BUS %s Device %s: ID %s:%s\n",tempArray5[0],tempArray5[1],tempArray5[2],tempArray5[3]);
}

int main(int argc, char **argv) {
    printusb();
}

