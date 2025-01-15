import time
import random

def insertion_sort(arr):
    # Loop for passes
    for i in range(1, len(arr)):
        temp = arr[i]
        j = i - 1
        # Loop for each pass
        while j >= 0 and arr[j] > temp:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = temp

def display(arr):
    print(" ".join(map(str, arr)))

def main():
    n = int(input("Enter n: "))
    arr = [random.randint(0, 100000) for _ in range(n)]

    display(arr)
    start = time.time()
    insertion_sort(arr)
    end = time.time()
    display(arr)

    print(f"The time taken is {end - start:.6f} seconds")

if __name__ == "__main__":
    main()



# 10 = The time taken is 0.000015  seconds
# 100 = The time taken is 0.000126 seconds
# 1000 = The time taken is 0.021856 seconds
# 10000 = The time taken is 1.213831 seconds
# 100000 = The time taken is 151.065459 seconds