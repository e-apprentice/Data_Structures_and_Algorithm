#include <iostream>
using namespace std;
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);
        return binarySearch(arr, mid + 1, right, x);
    }
    return -1;
}
void printArray(int A[],int n)
{
    for(int i=0;i<n;i++)
    cout<<A[i]<<" ";
cout<<endl;
}
int main() {
    int n;
 cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the elements to be entered: ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
 cout<<endl;
 cout<<"Given array is: ";
 printArray(arr,n);
 cout<<endl;
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    printArray(arr,n);
    int x;
     cout<<"\nEnter the value you want to search: ";
     cin>>x;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        cout << "\nElement is not present in the array";
    else
        cout << "\nElement is present at index " << result;

  return 0;
}

