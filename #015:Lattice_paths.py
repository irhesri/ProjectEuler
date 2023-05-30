def factorial (N):
    res = 1;
    for i in range (2, N + 1):
        res *= i;
    return (res);

x = int(input());

for i in range (x):
    grid = input().split();
    m = int(grid[0]);
    n = int(grid[1]);
    res = factorial(n + m) // (factorial(m) * factorial(n));
    print (res % (10**9 + 7));
