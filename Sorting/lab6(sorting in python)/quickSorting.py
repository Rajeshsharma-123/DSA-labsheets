import time
import random

def partition(arr, low, high):
    pivot = arr[low]
    i = low + 1
    j = high

    while True:
        while i <= high and arr[i] <= pivot:
            i += 1

        while arr[j] > pivot:
            j -= 1

        if i < j:
            arr[i], arr[j] = arr[j], arr[i]
        else:
            break

    # Swap pivot with arr[j]
    arr[low], arr[j] = arr[j], arr[low]
    return j

def quick_sort(arr, low, high):
    if low < high:
        partition_index = partition(arr, low, high)
        quick_sort(arr, low, partition_index - 1)
        quick_sort(arr, partition_index + 1, high)

def main():
    n = int(input("Enter n: "))
    arr = [random.randint(0, 100000) for _ in range(n)]

    # print(arr)

    start = time.time()
    quick_sort(arr, 0, n - 1)
    end = time.time()

    # print(arr)

    print(f"The time taken is {end - start:.6f} seconds")

if __name__ == "__main__":
    main()


# Enter n: 10
# The time taken is 0.000014 seconds

# Enter n: 100
# The time taken is 0.000132 seconds

# Enter n: 1000
# The time taken is 0.001200 seconds

# Enter n: 10000
# The time taken is 0.010920 seconds

# Enter n: 100000
# The time taken is 0.101433 seconds

# Enter n: 10000000
# The time taken is 34.995985 seconds