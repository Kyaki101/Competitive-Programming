#
#https://codeforces.com/problemset/problem/1955/B
#
def sol():
    n, c, d = map(int, input().split())
    numbers = list(map(int, input().split()))
    dictio = {}
    for i in numbers:
        dictio[i] = dictio.get(i, 0) + 1
    row = [0] * n
    row[0] = min(numbers)
    for i in range(1, n):
        if row[0] + d * i not in dictio:
            print("NO")
            return
        dictio[row[0] + d * i] -= 1
        row[i] = row[0] + d * i
    for i in range(n):
        for j in range(1, n):
            if row[i] + c * j not in dictio:
                print("NO")
                return
            if dictio[row[i] + c * j] == 0:
                print("NO")
                return
            dictio[row[i] + c * j] -= 1
    print("YES")

t = int(input())
while(t > 0):
    sol()
    t -= 1

