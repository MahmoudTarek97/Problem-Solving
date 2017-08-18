#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int t,n,i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        int max=-1,s;
        for(j=0;j<n;j++)
        {
            scanf("%d",&s);
            if (max<s)
                max=s;
        }
        printf("Case %d: %d\n",i+1,max);
    }
    return 0;
}
