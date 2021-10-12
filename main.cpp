#include "load.h"
#include <stdio.h>

int main(void)
{
    int a=0,b=1;
    printf("Choose library:\n1-matrix.\n2-array.\n3-quit.\n");
    while(b)
    {
        scanf("%d",&a);
        if(a==1)
            LoadRun("matrix.dll");
        if(a==2)
            LoadRun("array.dll");
        if(a==3)
            b=0;
    }
    return 0;
}
