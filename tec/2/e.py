
t = int(input())

while(t):
    t -= 1

    n, m = list(map(int, input().split()))

    a = list(map(int, input().split()))

    s = input()

    l = 0
    r = n - 1
    mult = 1
    for i in a:
        mult *= i

    print(mult % m, end=" ")

    for i in range(n - 1):
        if(s[i] == "R"):
            mult //= a[r]
            r -= 1 
        else: 
            mult //= a[l]
            l += 1 

        print(mult % m, end=" ")

    print()





