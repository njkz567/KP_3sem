#include "load.h"
#include <stdio.h>

int main(void)
{
    int a=0,b=1;
    printf("Choose library:\n1-first.\n2-,\n3-quit\n");
    while(b)
    {
        scanf("%d",&a);
        if(a==1)
            LoadRun("lib1.dll");
        if(a==2)
            LoadRun("lib2.dll");
        if(a==3)
            b=0;
    }
    return 0;
}
