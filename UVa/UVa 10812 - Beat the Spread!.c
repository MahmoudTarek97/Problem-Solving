#include <stdio.h>
#include <math.h>

int main()
{
    long long int sum,diff;
    int t,i;
    scanf("%d",&t);
    double l,s;
    for(i=0;i<t;i++)
    {
        scanf("%lld %lld",&sum,&diff);
        l=(sum+diff)/2.0;
        s=l-diff;
        long long int cl,cs;
        cl=l;
        cs=s;

        if(l<0 || s<0 || cl!=l || cs!=s)
            printf("impossible\n");
        else
            printf("%lld %lld\n",cl,cs);
    }
    return 0;
}
