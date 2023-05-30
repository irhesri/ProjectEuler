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

res = 0;
# all integers greater than can be written as the sum of two abundant numbers
for n in range (1, 28123):
    b = 0;
    for k in range (12, n - 11):
        if ((sumOfDivisors(k) > k) and (sumOfDivisors(n - k) > (n - k))):
            b = 1
            break
    if not(b):
        res += n;
print (res);
