#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

long    itsPrime(long n)
{
    for (long i = 2; i <= (long)sqrt(n); i++)
        if (!(n % i))
            return (0);
    return (1);
}

long    largestPrime(long n)
{
    vector<long>    v;
    int size = 0;
    
    if ((n == 2) || ((n % 2) && itsPrime(n)))
            return (n);
			
    v.push_back(1);
    for (long i = 2; i <= (long)sqrt(n); i++)
        if (!(n % i))
        {
            if (itsPrime(n / i))
                return (n / i);
            if (itsPrime(i))
            {
                v.push_back(i);
                size++;
            }
        }
    return (v[size]);
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        cout << largestPrime(n) << endl;
    }
    return 0;
}
