# Counting sort in Python programming
def counting_Sort(array):
    size = len(array)
    op = [0] * size

    # Initialize count array
    count = [0] * 10

    for i in range(0, size):
      count[array[i]] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    # Find the index of each element of the original array in count array
    # place the elements in output array
    i = size - 1
    while i >= 0:
        op[count[array[i]] - 1] = array[i]
        count[array[i]] -= 1
        i -= 1

    # Copy the sorted elements into original array
    for i in range(0, size):
        array[i] = op[i]


data = [4, 2, 2, 8, 3, 3, 1]
counting_Sort(data)
print("Sorted Array in Ascending Order: ")
print(data)