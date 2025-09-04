import math

t = int(input())
while(t > 0):
    a, b, k = map(int, input().split())
    if math.lcm(a, b) // b <= k and math.lcm(a, b) // a <= k:
        print(1)

    else:
        print(2)

    t -= 1
