#include <stdio.h>
#include <math.h>
#include <assert.h>

int main()
{
    int H,D;
    double U,F;
    double state;
    scanf("%d %lf %d %lf",&H,&U,&D,&F);
    F=(F/100)*U;
    int day;
    while(H!=0)
    {
        day=1;
        state=0;
        while(1)
        {
            if(U>=0)
                state+=U;
            if (state >H)
            {
                printf("success on day %d\n",day);
                break;
            }
            else if(state<0)
            {
                printf("failure on day %d\n",day);
                break;
            }
            else
            {
                state-=D;
                if (state >H)
                {
                    printf("success on day %d\n",day);
                    break;
                }
                else if(state<0)
                {
                    printf("failure on day %d\n",day);
                    break;
                }
            }
            day++;
            U-=F;
        }
        scanf("%d %lf %d %lf",&H,&U,&D,&F);
        F=(F/100)*U;
    }
    return 0;
}
