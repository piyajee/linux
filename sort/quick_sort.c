#include <stdio.h>

void sort(int *a, int left, int right)
{
    if(left >= right)
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[left];
     
    while(i < j)
    {
        while(i < j && key <= a[j])
        {
            j--;
        }
         
        a[i] = a[j];
        
        while(i < j && key >= a[i])
        {
            i++;
        }
         
        a[j] = a[i];
    }
     
    a[i] = key;
    sort(a, left, i - 1);
    sort(a, i + 1, right);
}

int main()
{
    int i = 0;
    int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};

    printf("before sort\n");
    for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
 
    sort(a, 0, sizeof(a) / sizeof(a[0]) - 1);/*这里原文第三个参数要减1否则内存越界*/

    printf("after sort\n");
    for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
     
    return 0;
}