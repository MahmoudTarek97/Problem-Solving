#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int t,i;
    int a,b;
    scanf("%d",&t);
    char Ans[t];
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&a,&b);
        if(a>b)         Ans[i]='>';
        else if(a<b)    Ans[i]='<';
        else           Ans[i]='=';
    }
    for(i=0;i<t;i++)
    {
        printf("%c\n",Ans[i]);
    }
    return 0;
}
