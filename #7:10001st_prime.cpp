#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool    isPrime(int n)
{
    for (int i = 3; i < n; i++)
    {
        if (!(n % i))
            return (0);
    }
    return (1);
}

vector<int> primes(int pos)
{
    int n = 1;
    vector<int> v;
    
    v.push_back(2);
    for (int i = 3; n < pos; i += 2)
    {
        if (isPrime(i))
        {
            v.push_back(i);
            n++;
        }
    }
    return (v);
}

int main(){
    int t, x;
    vector<int> p, N;

    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        N.push_back(n);
    }
    x = N[distance(N.begin(), max_element(N.begin(), N.end()))];
    p = primes(x);
    for (int i = 0; i < t; i++)
        cout << p[N[i] - 1] << endl;
    return 0;
}