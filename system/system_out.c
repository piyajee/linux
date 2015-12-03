#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *stream;
    char buf[256];

    memset(buf, 0, sizeof(buf));
    stream = popen("cat test_mac", "r");

    fread(buf, sizeof(char), sizeof(buf), stream);
    printf("valid buf size is %d", strlen(buf));
    printf("%s", buf);
    pclose(stream);
    
    return 0;
}
