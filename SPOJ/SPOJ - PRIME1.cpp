/****************************************************/
/**                                                **/
/**   SPOJ - PRIME1.cpp                            **/
/**   Credits to Mahmoud Tarek Samir               **/
/**   Ma7moud.tarek97@gmail.com                    **/
/**                                                **/
/****************************************************/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <bitset>
using namespace std;
typedef long long int ll;
bitset<10000010> is_prime;
vector<ll> primes;

// O(n * log (log (n)))
void sieve(ll n)
{
    is_prime.set();                                      // set all bits to 1
    is_prime[0] = 0;
    is_prime[1] = 0;                                     // except index 0 and 1
    for (ll i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            // cross out multiples of i starting from i * i!
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = 0;
            primes.push_back(i);
        }
    }

}
//O(#primes<=sqrt(n)) --> O(sqrt(n)/ln(sqrt(n)))
bool is_prime_func(ll n)
{
    if (n <= 10000000) return is_prime[n];                   // O(1) for small primes
    for (int i = 0; primes[i]*primes[i] <= n; i++)
        if (n % primes[i] == 0) return false;
    return true;                    // it takes longer time if N is a large prime!
}


int main()
{
    sieve(10000000);       //O(nlog(log(n)))
    int t;
    ll L,R;
    cin >> t;
    while(t--)
    {
        cin >> L >> R;
        for(ll i=L;i<=R;i++){
            if(is_prime_func(i))
                cout << i << endl;
        }
        cout << endl;
    }
    return 0;
}
