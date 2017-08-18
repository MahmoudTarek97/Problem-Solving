#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <bitset>
using namespace std;

bitset<1000010> is_prime;
vector<int> primes;
// O(n * log (log (n)))
void sieve(long long n)
{
    is_prime.set();                                      // set all bits to 1
    is_prime[0] = 0;
    is_prime[1] = 0;                                     // except index 0 and 1
    for (long long i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            // cross out multiples of i starting from i * i!
            for (long long j = i * i; j <= n; j += i)
                is_prime[j] = 0;
            primes.push_back(i);
        }
    }

}


int main()
{
    sieve(1000010);       //O(nlog(log(n)))
    //cout << count << endl;
    int n;
    cin >> n;
    while(n!=0)        //4 <= n <= 1000000
    {
        int a=0,b=0,diff=-1,max_diff=-1;
        for(int i=0; primes[i]<=n; i++)  //O(#primes<=n) ~ O(n/ln(n))
        {
            if(is_prime[n-primes[i]])
            {
                diff=(n-primes[i])-primes[i];
                if(diff>max_diff)
                {
                    max_diff=diff;
                    a=primes[i];
                    b=n-primes[i];
                }
            }
        }
        if(a==0 && b==0)
            printf("%d:\nNO WAY!\n",n);
        else
            printf("%d:\n%d+%d\n",n,a,b);
        cin >> n;
    }
    return 0;
}
