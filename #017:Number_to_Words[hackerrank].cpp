#include <cmath>
#include <iostream>
using namespace std;


int main() {
    char const  *digits[] = {"", "One", "Two", "Three", "Four", 
                                "Five", "Six", "Seven", "Eight", "Nine"};
    const char  *numbers[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                            "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const char  *tens[] = {"", "", "Twenty", "Thirty", "Forty", 
                            "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    const char  *type[] = {"Trillion", "Billion", "Million" ,"Thousand", ""};
    
    int n, k;
    long tmp, x;
    
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        cin >> x;
        if (!x)
        {
            cout << "Zero" << endl;
            continue;
        }
        for (short i = 0; i < 5; i++) {
            tmp = (x / (long)pow(10, 12 - i * 3));
            if (!tmp)
                continue ;
            k = (tmp / 100) % 10;
            if (k)
                cout << digits[k] << " Hundred ";
            k = (tmp / 10) % 10;
            if (k == 1)
                cout << numbers[tmp % 10] << " ";
            else if (k)
                cout << tens[k] << " ";
            if ((k != 1) && (tmp % 10))
                cout << digits[tmp % 10] << " "; 
            cout << type[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
