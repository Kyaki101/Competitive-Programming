t = int(input())


while t > 0:

    input_numbers = input()

    numbers = input_numbers.split()

    n, f, a, b = map(int, numbers)

    inp = input()

    numbers = inp.split()

    nums = list(map(int, numbers))

    for i in range(len(nums)):
        if(i == 0):
            f -= min(b, nums[0] * a)
        else: f -= min(b, (nums[i] - nums[i - 1]) * a)
    if f > 0:
        print("YES")
    else: print("NO")
    
    t-=1;
