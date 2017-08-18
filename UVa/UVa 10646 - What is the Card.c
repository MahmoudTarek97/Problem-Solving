#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    char Arr[52][2];
    int i,j,k;
    for(i=0;i<t;i++)
    {
        for(j=0;j<52;j++)
        {
            scanf("%s",Arr[j]);
        }
        int x1,x2,x3;
        x1=Arr[26][0];
        if(x1>9)    x1=10;
        x2=Arr[15+x1][0];
        if(x2>9)    x2=10;
        x3=Arr[x1+x2+4][0];
        if(x3>9)    x3=10;
        int y=x1+x2+x3;
        //print Arr[y-1+33-y]
        printf("Case %d: %c%c\n",i+1,Arr[32][0],Arr[32][1]);

    }
    return 0;
}
