n, p = map(int, input().split())

def fun(n, p):
    if(n < p): return n
    if(n == p): return 0
    if(n&1): n-=p
    return n%(2*p)

print(fun(n, p))
