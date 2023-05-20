import sys


t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    
    sum = 0;
    res = 0;
    for i in range (n, 0, -1):
        sum += i;
        res += sum * (i - 1);
    print (2 * res);
