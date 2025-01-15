import time
import random

def selection_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        least = arr[i]
        pos = i

        for j in range(i + 1, n):
            if arr[j] < least:
                least = arr[j]
                pos = j

        if i != pos:
            # Swap arr[i] and arr[pos]
            arr[i], arr[pos] = arr[pos], arr[i]

def display(arr):
    print(" ".join(map(str, arr)))

def main():
    n = int(input("Enter n: "))
    arr = [random.randint(0, 100000) for _ in range(n)]

    # display(arr)
    start = time.time()
    selection_sort(arr)
    end = time.time()
    # display(arr)

    print(f"The time taken is {end - start:.6f} seconds")

if __name__ == "__main__":
    main()


# Enter n: 10
# The time taken is 0.000014 seconds

# Enter n: 100
# The time taken is 0.000095 seconds

# Enter n: 1000
# The time taken is 0.013498 seconds

# Enter n: 10000
# The time taken is 0.953546 seconds

# Enter n: 100000
# The time taken is 106.091875 seconds