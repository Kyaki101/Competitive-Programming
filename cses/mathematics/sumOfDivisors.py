import sys

MOD = 1000000007

def expo(n, x):
    res = 1
    while x > 0:
        if x & 1:  
            res = (res * n) % MOD
        n = (n * n) % MOD  
        x //= 2  
    return res

inv = expo(2, MOD - 2)

def modGauss(n):
    return (n * (n + 1) // 2) % MOD

n = int(input())

ans = 0
half = n // 2
k = 1

while k * k <= n:
    ans = (ans + k * (n // k)) % MOD
    k += 1

first = k

while first <= half:
    left = first
    right = half + 1
    while left + 1 < right:
        mid = (left + right) // 2
        if n // mid == n // first:
            left = mid
        else:
            right = mid

    segmentSum = (modGauss(left) - modGauss(first - 1) + MOD) % MOD
    ans = (ans + segmentSum * (n // first)) % MOD
    first = left + 1

ans = (ans + (modGauss(n) - modGauss(first - 1) + MOD) % MOD) % MOD

print(ans)

