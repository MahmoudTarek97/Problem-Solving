#include <stdio.h>

void MaximizeArray(int Valid[],int Hotels)
{
    int i;
    for(i=0;i<Hotels;i++)
        Valid[i]=500001;
}

int main()
{
    int participants,Budget,Hotels,Weeks;
    while(scanf("%d %d %d %d",&participants,&Budget,&Hotels,&Weeks) == 4)
    {
    int counter=0,check,i,j;
    int HotelPrice[Hotels];
    int WeekBeds[Weeks];
    int Valid[Hotels];
    MaximizeArray(Valid,Hotels);
    for (i=0;i<Hotels;i++)
    {
        check=0;
        scanf("%d",&HotelPrice[i]);
        for(j=0;j<Weeks;j++)
        {
            scanf("%d",&WeekBeds[j]);
            if(WeekBeds[j]>=participants)
                check=1;
        }
        if ( (check==1) &&( Budget>=(HotelPrice[i]*participants)  ) )
                Valid[counter]=HotelPrice[i];
        counter++;
    }
    int min=Valid[0];
    for(i=0;i<counter;i++)
    {
        if (min>Valid[i])
            min=Valid[i];
    }
    if (min==500001)
        printf("stay home\n");
    else
        printf("%d\n",min*participants);
    }
    return 0;
}
