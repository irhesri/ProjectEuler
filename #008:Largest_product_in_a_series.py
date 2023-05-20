import sys


t = int(input().strip())
for a0 in range(t):
    n,k = input().strip().split(' ')
    n,k = [int(n),int(k)]
    num = input().strip()
    
    max = 0;
    for i in range (n - k + 1):
        m = 1;
        for j in range (i, i + k):
            m *= int (num[j]);
        if (m > max):
            max = m;
    print (max);
