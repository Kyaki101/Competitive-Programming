#
#https://codeforces.com/problemset/problem/1791/A
#

def sol():
    c = input()
    if c in "codeforces":
        print("YES")
        return
    print("NO")

t = int(input())
while t:
    sol()
    t -= 1


#numbers = input_numbers.split() splits input by spaces
#n, f, a, b = map(int, numbers) Turns input into indivudual vars
#numbers = inp.split() Splits input by spaces
#nums = list(map(int, numbers))  Turns input into list of numbers