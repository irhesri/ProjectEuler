#include <iostream>

using namespace std;

long    multiples(int nbr)
{
    unsigned long n, sum[3] = {0};

    // sum of multiple of 5
    n = ((nbr - 1) / 5);
    sum[0] = (((n + 1) * n) / 2) * 5;

    // + sum of multiple of 3
    n = ((nbr - 1) / 3);
    sum[1] = (((n + 1) * n) / 2) * 3;
    
    
    // - sum of multiple of 3 && 5
    n = ((nbr - 1) / 15);
    sum[2] = (((n + 1) * n) / 2) * 15;
    
    return (sum[0] + sum[1] - sum[2]);
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        
        cin >> n;
        cout << multiples(n) << endl;
    }
    return 0;
}
