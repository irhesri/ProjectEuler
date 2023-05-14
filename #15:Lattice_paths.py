def factorial (N):
    if (N <= 1):
        return (1);
    return (N * factorial(N - 1));

x = int(input());

for i in range (x):
    grid = input().split();
    m = int(grid[0]);
    n = int(grid[1]);

    res = factorial(n + m) // (factorial(m) * factorial(n));
    print (res % (10**9 + 7));
