#include <iostream>
using namespace std;

typedef unsigned long long ull;

bool    isLeapYear(ull year)
{
    return (!(year % 4) && ((year % 100) || !(year % 400)));
}

short   getDayOfWeek(ull year, short month, short day)
{
    short   x;
    
    x = (14 - month)/12;
    year -= x;
    x = month + 12 * x - 2;
    return ((day + year + year / 4 - year / 100 + year / 400 + (31 * x) / 12) % 7);
}

int main() {
    ull     days, count, y[2];
    short   q, M0, M1;
    short   m[2], d[2];
    short   daysPerMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    cin >> q;
    for (short i = 0; i < q; i++) {
        // input
        for (int j = 0; j < 2; j++) {
            cin >> y[j];
            cin >> m[j];
            cin >> d[j];
        }
        
        // get starting day
        if (d[0] != 1)
        {
            m[0] = (m[0] + 1) % 13;
            y[0] += (!m[0]);
            m[0] += (!m[0]);
        }
        days = getDayOfWeek(y[0], m[0], 1);
        
        //  start counting        
        count = 0;
        M0 = m[0];
        for (ull year = y[0]; year <= y[1]; year++) 
        {
            daysPerMonth[2] = 28 + isLeapYear(year);
            M1 = 12 * (year != y[1]) + m[1] * (year == y[1]);
            for (short month = M0; month <= M1; month++)
            {   
                if (!(days % 7))
                {
                    count++;
                    days = 0;                    
                }
                days += daysPerMonth[month];
            }
            M0 = 1;
        }
        cout << count << endl;
    }
    return 0;
}
