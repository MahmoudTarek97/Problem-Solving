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

//O(sqrt(n)/ln(sqrt(n)))
vector<int> prime_factors(long long n)
{
    vector<int> factors;
    long long i=0;
    long long pf=primes[i];
    while(pf * pf <=n)
    {
        while(n%pf==0)
        {
            n=n/pf;
            factors.push_back(pf);
        }
        i++;
        pf=primes[i];
    }
    if(n!=1)    factors.push_back(n);
    return factors;
}

int main()
{
    sieve(1000000);       //O(nlog(log(n)))
    int n;
    cin >> n;
    while(n!=0)
    {
        vector<int> factors = prime_factors((long long) fabs(n));
        if(n>0)
        {
            printf("%d = %d",n,factors[0]);
            for(int i=1; i<factors.size(); i++)
                printf(" x %d",factors[i]);
            printf("\n");
        }
        else
        {
            printf("%d = -1 x %d",n,factors[0]);
            for(int i=1; i<factors.size(); i++)
                printf(" x %d",factors[i]);
            printf("\n");
        }
        cin >> n;
    }
    return 0;
}
