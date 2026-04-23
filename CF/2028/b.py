t = int(input())
while t:
    t -= 1
    a, b, c = list(map(int, input().split()))
    if b == 0 and c < a - 2:
        print(-1)
        continue
    if b == 0:
        if(c >= a):
            print(a)
            continue
        print(a - 1)
        continue
    if c >= a:
        print(a)
        continue

    l = 0
    r = (1 << 61)
    while(l + 1 < r):
        mid = (l + r) // 2
        if mid * b + c < a:
            l = mid
        else: r = mid
    if l == 0:
        if c < a:
            print(a - 1)
            continue
        print(a)
        continue
    print(a - l  - 1)


