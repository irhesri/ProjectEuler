#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull ;
// # define fract13 6227020800
# define X 479001600 // 13! / 13

int main() {
    ull         n, x, k;
    short       q, size;
    vector<char> v = {'a', 'b', 'c', 'd', 'e', 'f', 'j', 'h', 'j', 'k', 'l', 'm'}, tmp;

    cin >> q;
    for (short i = 0; i < q; i++)
    {
        cin >> n;
        n--;
        tmp = v;
        x = X;
        size = 13;
        while (size) 
        {
            k = (n / x);
            cout << tmp[k];
            tmp.erase(tmp.begin() + k);
            n -= (n / x) * x;
            --size;
            x /= size;
        }
        cout << endl;
        tmp.clear();
    }
    return 0;
}
