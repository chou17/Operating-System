#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/syscall.h> 
#include <assert.h>
#include <string.h>
#include <math.h>

double divide=40000;
int numCPU=-1;
char* exename;

volatile double low_area[100];

void thread(void *givenName) {
    int id = (intptr_t)givenName;
    double u_sum = 1/divide;
    double l_sum = 0;
    int i=1;
    if(id==0){
        for(int i=1; i<divide/2;i++){
            double num = sqrt(divide*divide - i*i)/divide/divide;
            low_area[id] += num;
        }
    }
    if(id!=0){
        for(int i=divide/2; i<=divide-1;i++){
            double num = sqrt(divide*divide - i*i)/divide/divide;
            low_area[id] += num;
        }
    }
    
}

int main(int argc,char **argv){
    exename = argv[0];
    numCPU = sysconf( _SC_NPROCESSORS_ONLN );
    pthread_t* tid = (pthread_t*)malloc(sizeof(pthread_t) * numCPU);
    for (long i=0; i< numCPU; i++)
        pthread_create(&tid[i], NULL, (void *) thread, (void*)i);

    for (int i=0; i< numCPU; i++)
        pthread_join(tid[i], NULL);

    double total_up_area = 0;
    double total_low_area = 0;
    for (int i=0; i< numCPU; i++){
        total_low_area += low_area[i];
    }
    double a = 1/divide;
    total_up_area = total_low_area+a;
    double up_pi,low_pi,p;
    up_pi = total_up_area*4;
    low_pi = total_low_area*4;
    char up_str[1024];
    sprintf(up_str, "%f", up_pi);
    char low_str[1024];
    sprintf(low_str, "%f", low_pi);
    p = strspn(up_str,low_str);
    printf("pi = ");
    for(int i=0;i<p;i++){
        printf("%c",up_str[i]);
    }
    printf("\n");
}
