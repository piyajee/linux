#include <stdio.h>

static int IsBigEndian()
{
    int a =1 ; 
    if(((char*)&a)[3] ==1)
        return 1 ;
    else
        return 2 ;
}

int main()
{
	if (1 == IsBigEndian)
		printf("big end\n");
	else 
		printf("small end\n");

	unsigned char mac[6] = {0};

	mac[0] = 0x12;
	mac[1] = 0x34;
	printf("mac is 0x%x\n", *(unsigned short *)(&mac[0]));


	return 0;
}


