#include <stdio.h>


int main()
{
    int n,p,i,j;
    char str[81];
    scanf("%d %d",&n,&p);
    int testCase=0;
    while(n!=0)
    {
        struct proposal{
            char name[81];
            double price;
            double metReq;
            double compliance;
            int index;
        }P[p+1];
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            gets(str);
        }
        for(i=0;i<p;i++)
        {
            gets(P[i].name);
            scanf("%lf %lf",&P[i].price,&P[i].metReq);
            P[i].compliance=P[i].metReq/n;
            P[i].index=i;
            for(j=0;j<P[i].metReq;j++)
            {
               scanf("%s",str);
               gets(str);
            }
        }

        double maxCompliance=P[0].compliance;
        for(i=0;i<p;i++)
        {
            if (maxCompliance<P[i].compliance)
                maxCompliance=P[i].compliance;
        }
        int counterComp=0;
        int compArr[p];
        for(i=0;i<p;i++)
        {
            if(P[i].compliance==maxCompliance)
            {
                compArr[counterComp]=P[i].index;
                counterComp++;
            }
        }

        if(counterComp==1)
        {
            if(testCase!=0)
                printf("\n");
            printf("RFP #%d\n%s\n",testCase+1,P[compArr[0]].name);

        }
        else
        {
            int minPrice=P[compArr[0]].price;
            for(i=0;i<counterComp;i++)
            {
                if(P[compArr[i]].price<minPrice)
                    minPrice=P[compArr[i]].price;
            }


        int counterPrice=0,priceArr[counterComp];
        for(i=0;i<counterComp;i++)
        {
            if(P[compArr[i]].price==minPrice)
            {
                priceArr[counterPrice]=P[compArr[i]].index;
                counterPrice++;
            }

        }
        if(counterPrice==1)
        {
            if(testCase!=0)
                printf("\n");
            printf("RFP #%d\n%s\n",testCase+1,P[priceArr[0]].name);
        }
        else
        {
            int minin=1000;
            for(i=0;i<counterPrice;i++)
            {
                if(priceArr[i]<minin)
                {
                    minin=priceArr[i];
                }
            }
            if(testCase!=0)
                printf("\n");
            printf("RFP #%d\n%s\n",testCase+1,P[minin].name);
        }

        }

        testCase++;
        scanf("%d %d",&n,&p);
    }



    return 0;
}
