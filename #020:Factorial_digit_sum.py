def factorial(n):
    res = 1;
    for i in range (2, n + 1):
        res *= i;
    return (res);

q = int(input());
for i in range (q):
    n = int(input());
    n = str(factorial(n));
    
    total = 0;
    for j in (n):
        total += int(j);

    print (int(total));
