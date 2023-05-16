#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int main() {
    string const  digits[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    const string  numbers[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const string  tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    const string  type[] = {"Trillion", "Billion", "Million" ,"Thousand", ""};
    
    int n, k, j;
    long tmp, x, nbr;
    string str;
    vector <int> v, v_sort, res;

    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    v_sort  = v;
    sort (v_sort.begin(), v_sort.end());
    x = 1;

    j = 0;
    while ((j < n) && !v_sort[j])
    {
        res.push_back(4); 
        j++;
    }

    for (; j < n; j++)
    {
        for (; x <= v_sort[j]; x++)
        {
            for (short i = 0; i < 5; i++) {
                tmp = (x / (long)pow(10, 12 - i * 3));
                if (!tmp)
                    continue ;
                k = (tmp / 100) % 10;
                if (k)
                    str.append(digits[k] + "Hundred");
                if (k && (tmp % 100))
                    str.append("and");
                k = (tmp / 10) % 10;
                if (k == 1)
                    str.append(numbers[tmp % 10]);
                else if (k)
                    str.append(tens[k]);
                if ((k != 1) && (tmp % 10))
                    str.append(digits[tmp % 10]);
                str.append(type[i]);
            }
        }
        res.push_back(str.length());
    }
    
    // output
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        auto it = find(v_sort.begin(), v_sort.end(), v[i]);
        cout << res[distance(v_sort.begin(), it)] << endl;
    }
    return 0;
}
