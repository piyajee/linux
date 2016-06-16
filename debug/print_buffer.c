#include <stdio.h>

static void dump_buffer(unsigned char *buf,int size)
{
    {
    	int i;
    	printf("=================Data Size:%d =================\n",size);
    	for(i=0;i<size;i++)
    	{      
    		if((0==i%16)&&(i>0)) 
    			printf("\n");
    		printf("%02x ",buf[i]); 
    	}
    	printf("\n");
    }
}
