import time
import random

def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

def display(arr):
    print(" ".join(map(str, arr)))

def main():
    arr = []
    n = int(input("Enter n: "))
    arr = [random.randint(0, 100000) for _ in range(n)]

    display(arr)
    start = time.time()
    bubble_sort(arr)
    end = time.time()
    display(arr)

    print(f"The time taken is {end - start:.6f} seconds")

if __name__ == "__main__":
    main()



# 10 = The time taken is 0.000035  seconds
# 100 = The time taken is 0.000358 seconds
# 1000 = The time taken is 0.033631 seconds
# 10000 = The time taken is 2.770377 seconds
# 100000 = no result for 3 mins 