#include <stdio.h>

int main()
{
    int Pages,Counter,n,i,SheetNo;
    int Arr[101];
    scanf("%d",&Pages);
    while(Pages!=0)
    {
        n=Pages;
        while(n%4!=0)
            n++;
        Counter=1;
        for(i=0;i<n;i++)
        {
            if(i+1>Pages)
                Arr[i]=0;
            else
                Arr[i]=Counter;
            Counter++;
        }
        Counter=1;
        SheetNo=1;
        printf("Printing order for %d pages:\n",Pages);
        for(i=0;i<n/2;i++)
        {
            if(Arr[i]==0 && Arr[n-1-i]==0)
                break;
            if(Counter%2==0)
            {
                    if(Arr[i] ==0)
                        printf("Sheet %d, back : Blank, %d\n",SheetNo,Arr[n-1-i]);
                    else if(Arr[n-1-i]==0)
                        printf("Sheet %d, back : %d, Blank\n",SheetNo,Arr[i]);
                    else
                        printf("Sheet %d, back : %d, %d\n",SheetNo,Arr[i],Arr[n-1-i]);
            }
            else
            {
                if(Arr[i]==0)
                    printf("Sheet %d, front: %d, Blank\n",SheetNo,Arr[n-1-i]);
                else if(Arr[n-1-i]==0)
                    printf("Sheet %d, front: Blank, %d\n",SheetNo,Arr[i]);
                else
                    printf("Sheet %d, front: %d, %d\n",SheetNo,Arr[n-1-i],Arr[i]);
            }
            if(Counter%2==0)
                SheetNo++;
            Counter++;
        }
        scanf("%d",&Pages);
    }
    return 0;
}
