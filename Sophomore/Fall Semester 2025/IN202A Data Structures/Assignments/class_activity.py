from typing import List, Tuple

# 1. Insertion Sort — show array after each pass
def insertion_sort(arr: List[int]) -> List[int]:
    a = arr[:]  # make a copy
    print("Insertion Sort passes:")
    for i in range(1, len(a)):
        key = a[i]
        j = i - 1
        while j >= 0 and a[j] > key:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = key
        print(f" after pass {i}: {a}")
    return a


# 2. Selection Sort — print smallest element each iteration
def selection_sort(arr: List[int]) -> List[int]:
    a = arr[:]
    print("\nSelection Sort iterations (smallest each pass):")
    for i in range(len(a) - 1):
        min_idx = i
        for j in range(i + 1, len(a)):
            if a[j] < a[min_idx]:
                min_idx = j
        print(f" pass {i+1}: smallest = {a[min_idx]} (at index {min_idx})")
        a[i], a[min_idx] = a[min_idx], a[i]
    return a


# 3. Bubble Sort — count comparisons and swaps
def bubble_sort_with_counts(arr: List[int]) -> Tuple[List[int], int, int]:
    a = arr[:]
    comparisons = swaps = 0
    print("\nBubble Sort (standard):")
    for i in range(len(a) - 1):
        for j in range(len(a) - 1 - i):
            comparisons += 1
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
                swaps += 1
        print(f" after pass {i+1}: {a}")
    print(f"Total comparisons = {comparisons}, swaps = {swaps}")
    return a, comparisons, swaps


# 4. Optimized Bubble Sort — stop early if sorted
def bubble_sort_optimized(arr: List[int]) -> List[int]:
    a = arr[:]
    print("\nBubble Sort (optimized):")
    for i in range(len(a) - 1):
        swapped = False
        for j in range(len(a) - 1 - i):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
                swapped = True
        print(f" after pass {i+1}: {a}, swapped={swapped}")
        if not swapped:
            print(" Array is sorted early — stopping.")
            break
    return a


# 5. Dispatcher — sort based on method name
def sort_with_method(arr: List[int], method: str) -> List[int]:
    method = method.lower()
    if method == 'insertion':
        return insertion_sort(arr)
    elif method == 'selection':
        return selection_sort(arr)
    elif method == 'bubble':
        return bubble_sort_optimized(arr)
    else:
        raise ValueError("Unknown method. Use 'insertion', 'selection', or 'bubble'.")


# --- Test all parts ---

print("\n=== 1. Insertion Sort ===")
insertion_sort([9, 5, 1, 4, 3])

print("\n=== 2. Selection Sort ===")
selection_sort([29, 10, 14, 37, 13])

print("\n=== 3. Bubble Sort with counts ===")
bubble_sort_with_counts([5, 1, 4, 2, 8])

print("\n=== 4. Optimized Bubble Sort ===")
bubble_sort_optimized([5, 1, 4, 2, 8])
bubble_sort_optimized([1, 2, 3, 4, 5])

print("\n=== 5. Dispatcher Function ===")
print(" insertion:", sort_with_method([9, 5, 1, 4, 3], 'insertion'))
print(" selection:", sort_with_method([29, 10, 14, 37, 13], 'selection'))
print(" bubble   :", sort_with_method([5, 1, 4, 2, 8], 'bubble'))
