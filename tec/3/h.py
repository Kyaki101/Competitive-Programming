
import math

def lcm(a, b):
    return (a * b) // math.gcd(a, b)

def form(a, b):
    return lcm(a, b) / math.gcd(a, b) <= 3

def bruh(lim):

    lim += 1
    ans = 0
    for i in range(1, lim):
        for j in range(1, i + 1):
            if(form(i, j)): 
                if(i != j): ans += 2
                else: ans += 1
        
        print(i, ":", ans)




bruh(20)

