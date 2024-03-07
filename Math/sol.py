# https://codeforces.com/problemset/problem/486/A

def sumOdds(n):
    if not (n & 1):
        return ((n // 2) * (n // 2)) * 2
    return (((n + 1) // 2) * ((n + 1) // 2)) * 2

def sol():
    n = int(input())
    print((n * (n + 1) // 2) - sumOdds(n))

t = 1
while t:
    sol()
    t -= 1

