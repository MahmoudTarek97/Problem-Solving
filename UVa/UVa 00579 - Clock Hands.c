#include <stdio.h>
#include <math.h>

int main()
{
    int h,m;
    char useless;
    float ans;
    scanf("%d%c%d",&h,&useless,&m);
    while(h!=0)
    {
        ans=fabs( (30*(h+(m/60.0))) - 6*m );
        if(ans<=180)
            printf("%.3f\n",ans);
        else
            printf("%0.3f\n",360-ans);
        scanf("%d%c%d",&h,&useless,&m);
    }
    return 0;
}
