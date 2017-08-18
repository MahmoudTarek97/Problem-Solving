#include <stdio.h>

int readLine(char str[], int size)
{
    int ch, i=0,j;
    while( (ch=getchar()) != '\n')
    {
        if(ch ==' ' || ch=='.' || ch==',' || ch=='!' || ch=='?')
            continue;
        else
        {
            str[i]=ch;
            i++;
        }
    }
    int End=0;
    if(str[0]=='D' && str[1]=='O' && str[2]=='N' && str[3]=='E' && i==4)
        End=1;
    if(End==0)
    {
        for(j=0;j<i;j++)
        {
            if (str[j]>=65 && str[j]<=90)
                str[j]+=32;
        }
    }

    return i;
}
int main()
{
    int flag,k,End=0;
    char str[100000];
    int size=readLine(str,100000);
    while(End==0)
    {
        flag=0;
        for(k=0;k<size/2;k++)
        {
            if (str[k]==str[size-k-1])
                flag=1;
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==1 || size==0 || size==1)
            printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");
        size=readLine(str,100000);
        if(str[0]=='D' && str[1]=='O' && str[2]=='N' && str[3]=='E' && size==4)
            End=1;
    }
    return 0;
}
