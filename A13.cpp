//Program for Binary and Linear search
#include <iostream>
#include <algorithm>
using namespace std;


int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i; 
    return -1;
}


int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter value to search: ";
    cin >> key;

    
    int linPos = linearSearch(arr, n, key);
    if (linPos != -1)
        cout << "Linear Search: Element found at index " << linPos << endl;
    else
        cout << "Linear Search: Element not found\n";

    
    sort(arr, arr + n);

    
    int binPos = binarySearch(arr, n, key);
    if (binPos != -1)
        cout << "Binary Search: Element found at index " << binPos << " (after sorting)\n";
    else
        cout << "Binary Search: Element not found\n";

    return 0;
}
