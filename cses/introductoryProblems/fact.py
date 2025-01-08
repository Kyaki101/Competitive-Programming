n = int(input())
res = 1;
for i in range(1, n + 1):
    res *= i
    s = str(res)
    ze = 0
    for char in s[::-1]:
        if char != '0' : break
        else: ze += 1


    print(f'{i}: {ze}')


