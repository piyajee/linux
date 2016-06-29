#include <stdlib.h>   
#include <sys/shm.h>
#include <sys/ipc.h>  
#include <unistd.h>  
#include <string.h>

#define PATH ""
#define SIZE 512
#define ID 0
int main()
{
    char * shmAddr;
    char * dataAddr = "Hello";
    int key = ftok(PATH,ID);
    int shmID = shmget(key,SIZE,IPC_CREAT);
    shmAddr = shmat(shmID,NULL,0);
    strcpy(shmAddr,dataAddr);
    shmdt(shmAddr);
    exit(0);
}
