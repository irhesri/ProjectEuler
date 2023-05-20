#include <iostream>

using namespace std;

long    fibonacci(long n)
{
    long last = 0, nbr = 2, res = 2, tmp;
    
    while (1)
    {
        tmp = nbr * 4 + last;
        last = nbr;
        nbr = tmp;
        if (nbr > n)
            return (res);
        res += nbr;
    }
    return (res);
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        cout << fibonacci(n) << endl;
    }
    return 0;
}
