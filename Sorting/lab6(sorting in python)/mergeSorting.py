import time
import random

def merge_sort(arr, l, r):
    if l < r:
        m = (l + r) // 2
        merge_sort(arr, l, m)
        merge_sort(arr, m + 1, r)
        merge(arr, l, m, r)

def merge(arr, l, m, r):
    left = arr[l:m+1]
    right = arr[m+1:r+1]

    i = j = 0
    k = l

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1

    while i < len(left):
        arr[k] = left[i]
        i += 1
        k += 1

    while j < len(right):
        arr[k] = right[j]
        j += 1
        k += 1

def main():
    n = int(input("Enter n: "))
    arr = [random.randint(0, 100000) for _ in range(n)]

   
    # print(arr)

    start = time.time()
    merge_sort(arr, 0, n - 1)
    end = time.time()

    
    # print(arr)

    print(f"The time taken is {end - start:.6f} seconds")

if __name__ == "__main__":
    main()



# 10 = The time taken is 0.000016 seconds
# 100 = The time taken is 0.000148 seconds
# 1000 = The time taken is 0.001925 seconds
# 10000 = The time taken is 0.020456 seconds
# 100000 = The time taken is 0.165129 seconds
# 1000000 = The time taken is 2.337020 seconds