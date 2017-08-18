#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <bitset>
using namespace std;
typedef long long ll;
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

int numPrimeFactors (int n)
{
    int i=0,ans=0;
    int pf=primes[0];
    while(pf * pf <= n)
    {
        if(n%pf==0) ans++;
        while(n%pf==0)
            n=n/pf;
        i++;
        pf=primes[i];
    }
    if(n!=1)    ans++;
    return ans;
}

int main()
{
    sieve(100000);       //O(nlog(log(n)))
    int n;
    cin >> n;
    while(n != 0)
    {
        printf("%d : %d\n",n,numPrimeFactors(n));
        cin >> n;
    }
    return 0;
}
