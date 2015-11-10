#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char **argv)
{
        char IPdotdec[20];
        unsigned ip = strtoul(argv[1], NULL, 0);
        printf("input ip is %d\n", ip);
        inet_ntop(AF_INET, (void *)&ip, IPdotdec, 16);
        printf("inet_ntop: %s\n", IPdotdec);
        return 0;
}
