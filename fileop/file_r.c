#include<stdio.h>

int main ()
{
   FILE *fp;
   char str[256] = {0};

   fp = fopen( "file.txt" , "r" ); //if append , change w to a;
   fgets(str, 256, fp);
   printf("%s\n", str);

   fclose(fp);
  
   return(0);
}
