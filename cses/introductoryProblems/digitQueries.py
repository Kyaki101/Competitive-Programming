import math

t = int(input())
while(t):
    n = int(input())

    top = 9
    pre = 0
    power = 0
    group = 9
    digits = 1
    while(n > top):
        power += 1
        digits += 1
        group = int(digits * math.pow(10, power) * 9)
        pre = top
        top += group

    n -= pre
    s = str(int(pow(10, power)) + (n - 1) // digits)
    print(s[(n - 1) % digits])

    t -= 1
