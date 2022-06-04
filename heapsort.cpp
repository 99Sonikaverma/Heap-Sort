// Heap Sort in C++
  #include <iostream>
  using namespace std;

  void heap(int arr[], int n, int i) {
    // Find largest element among root, left child and right child
    int largest_ele = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child < n && arr[left_child] > arr[largest_ele])
      largest_ele = left_child;

    if (right_child < n && arr[right_child] > arr[largest_ele])
      largest_ele = right_child;

    // Swap and continue heapifying if root is not largest
    if (largest_ele != i) {
      swap(arr[i], arr[largest_ele]);
      heap(arr, n, largest_ele);
    }
  }

  // main function to do heap sort
  void heapSorting(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heap(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);

      // Heapify root element to get highest element at root again
      heap(arr, i, 0);
    }
  }

  // Print an array
  void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
    cout << "\n";
  }

  // Driver code
  int main() {
    int arr[] = {1, 12, 9, 5, 6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSorting(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
  }
