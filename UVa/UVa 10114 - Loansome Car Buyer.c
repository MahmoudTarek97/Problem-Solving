#include <stdio.h>

int main()
{
    int i,j;
    int duration,depreciations,month;
    double payment,loan,rate;
    scanf("%d %lf %lf %d",&duration,&payment,&loan,&depreciations);
    while(duration>0)
    {
        double carValue=loan+payment;
        double installment=loan/duration;
        int flag=0;

        double monthRate[duration+1];
        for(i=0;i<depreciations;i++)
        {
            scanf("%d %lf",&month,&rate);
            for(j=month;j<=duration;j++)
            {
                monthRate[j]=rate;
            }
        }

        carValue-=(monthRate[0]*carValue);
        if(carValue>loan)
        {
            printf("%d months\n",0);
            flag=1;
        }

        for(i=1;i<=duration;i++)
        {
            carValue-=(monthRate[i]*carValue);
            loan-=installment;
            if(carValue>loan && (flag==0) )
            {
                if(i==1)
                    printf("%d month\n",i);
                else
                    printf("%d months\n",i);
                break;
            }
        }
        scanf("%d %lf %lf %d",&duration,&payment,&loan,&depreciations);
    }
    return 0;
}
