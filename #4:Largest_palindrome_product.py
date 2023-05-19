import sys

def isPalindrome(n):
    return (n == n[::-1]);

t = int(input().strip())
for a in range(t):
    n = int(input().strip())
    max = 0;
    for i in range (999, 99, -1):
        for j in range (999, 99, -1):
            m = i * j;    
            if ((m > max) and (m < n) and isPalindrome(str(m))):
                max = m;
    print (max);                
