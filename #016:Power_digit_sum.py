
n = int(input());
for i in range (n):
    res = 0;
    x = int(input());
    x = 2**x;
    while (x):
        res += x % 10;
        x //= 10;
    print(res);