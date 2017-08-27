#include <iostream>
#include <stdio.h>
using namespace std;

int F3n_1(int n)
{
    if(n==1)
        return 1;
    if(n%2==0)
        return 1+F3n_1(n/2);
    else
        return 1+F3n_1(3*n + 1);
}

int main()
{
    int i,j;
    while(scanf("%d %d",&i,&j)==2)
    {
        cout << i << " " << j << " ";
        if(j<i)
        {
            i = i ^ j;
            j = j ^ i;
            i = i ^ j;
        }
        int n,cycle_length,max_cycle_length=0;
        while(i<=j)
        {
            n=i;
            cycle_length=F3n_1(i);
            if (cycle_length>max_cycle_length)
            {
                max_cycle_length=cycle_length;
            }
            i++;
        }
        cout << max_cycle_length << endl;
    }
    return 0;
}
