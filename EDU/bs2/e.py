import math 

n = float(input())

l = 0
r = n
for _ in range(100):
    mid = (l + r) / 2
    if(math.sqrt(mid) + mid * mid <= n):
        l = mid
    else: r = mid
print(l)
