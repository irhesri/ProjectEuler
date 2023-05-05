#include <iostream>

using namespace std;

unsigned long   gcd(unsigned long n, unsigned long m)
{
    unsigned long x = min (n, m); 
    
    for (; x > 1; x--)
    {
        if (!(n % x) && !(m % x))
            return (x);
    }
    return (1);
}

unsigned long   lcm(unsigned long n, unsigned long m)
{
    return (n * m / gcd(n, m));
}

unsigned long   lcm(unsigned long n)
{
    unsigned long x = 1;
    for (unsigned long i = 2; i <= n; i++)
        x = lcm(x, i);
    return (x);
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << lcm(n) << endl;
    }
    return 0;
}
