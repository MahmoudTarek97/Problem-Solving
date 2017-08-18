#include <stdio.h>

int main()
{
    char Rev[91];
    int i;
    for(i=0;i<91;i++)
    {
        Rev[i]=' ';
    }
    Rev['A']='A';   Rev['E']='3';   Rev['H']='H';   Rev['I']='I';   Rev['J']='L';
    Rev['L']='J';   Rev['M']='M';   Rev['O']='O';   Rev['S']='2';   Rev['T']='T';
    Rev['U']='U';   Rev['V']='V';   Rev['W']='W';   Rev['X']='X';   Rev['Y']='Y';
    Rev['Z']='5';   Rev['1']='1';   Rev['2']='S';   Rev['3']='E';   Rev['5']='Z';
    Rev['8']='8';

    char str[21];

    while(scanf("%s",str)==1)
    {
        int l=strlen(str);

        int checkP=0;
        for(i=0;i<=l/2;i++)
        {
            if(str[i]==str[l-1-i])
                checkP=1;
            else
            {
                checkP=0;
                break;
            }
        }

        int checkM=0;
        for(i=0;i<=l/2;i++)
        {
            if(str[i]==Rev[str[l-1-i]])
                checkM=1;
            else
            {
                checkM=0;
                break;
            }
        }

        if(checkP ==0)
        {
            if(checkM==0)
            {
                printf("%s -- is not a palindrome.\n\n",str);
            }

            else if(checkM==1)
            {
                printf("%s -- is a mirrored string.\n\n",str);
            }

        }
        else if(checkP==1)
        {
            if(checkM==0)
            {
                printf("%s -- is a regular palindrome.\n\n",str);
            }
            else if(checkM==1)
            {
                printf("%s -- is a mirrored palindrome.\n\n",str);
            }
        }
    }
    return 0;
}
