#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <bitset>

using namespace std;
int n;
bitset<10000010> bs;
vector<int> primes;

//generate list of primes [1 .. n]
// O(n * log (log (n)))
void sieve(int n)
{
    bs.set();                                              // set all bits to 1
    bs[0] = 0;
    primes.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        if (bs[i])
        {
            // cross out multiples of i starting from i * i!
            for (int j = i * i; j <= n; j += i)
                bs[j] = 0;
            primes.push_back(i);  // also add this vector containing list of primes
        }
    }

}

//NOTE : in this problem , 1 is a prime number
int main()
{
    int c;
    while(scanf("%d %d",&n,&c)==2)
    {
        sieve(n);
        cout << n << " " << c << ":";
        int size=primes.size();
        if(size%2==0)
            c = c*2;
        else
            c = c*2 - 1;
        if(c>size)
            c=size;
        int i,j;
        for(i=size/2-c/2,j=0;j<c;i++,j++)
            cout << " " << primes[i];
        cout << endl << endl;
        primes.clear();
    }
    return 0;
}
