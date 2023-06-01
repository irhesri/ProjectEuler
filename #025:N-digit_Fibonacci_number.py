import math as m

# Fn = ( (phi) ** n ) / sqrt(5) 

sqr5 = m.sqrt(5);
phi = (1 + sqr5) / 2;
q = int(input())
for i in range (q):
    n = int(input());
    if (n != 1):
        print (m.ceil((n - 1 + m.log10(sqr5)) / m.log10(phi)));
    else:
        print (1); 
