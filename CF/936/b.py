

def sol():
    n, k = map(int, input().split())
    lista = list(map(int, input().split()))
    maxi = 0
    count = 0
    streak = False
    MOD = 1000000007
    for i in lista:
        if i >= 0:
            count += i
            streak = True
        else:
            maxi = max(count, maxi)
            streak = False
            count = 0

    if(streak):
        if count >= maxi:
            maxi = count

    if maxi == 0:
        print(sum(lista) % MOD)
        return

    suma = sum(lista) + maxi
    count = maxi + count
    suma += count
    for i in range(2, k):
        suma += count * 2
        count *= 2
         
    print(suma % MOD)

    return



t = int(input())
while(t):
    sol()
    t -= 1
