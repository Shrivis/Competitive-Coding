void heapify(int arr[], int n, int i) {
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n and arr[large] < arr[left]) large = left;
    if (right < n and arr[large] < arr[right]) large = right;
    if (large != i) {
        swap(arr[i], arr[large]);
        heapify(arr, n, large);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i) heapify(arr, n, i);
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void heapSort(int arr[], int n) { buildHeap(arr, n); }