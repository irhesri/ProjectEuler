import math as m

def sumOfDivisors(n):
    i = 2;
    total = 1;
    
    for i in range (2, int(m.sqrt(n))):
        if (not(n % i)):
            total += i + n / i;
    i += 1
    if (not(n % i)):
        total += i + (n / i) * (i != (n / i));
    return (int(total));

q = int(input());
for i in range (q):
    n = int(input())
    b = 0;
    if (n > 28123):
        print ("YES")
        continue
    for k in range (12, n - 11):
        if ((sumOfDivisors(k) > k) and (sumOfDivisors(n - k) > (n - k))):
            print("YES")
            b = 1
            break
    if not(b):
        print ("NO");
    
