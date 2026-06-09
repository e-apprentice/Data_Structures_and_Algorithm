#include <iostream>
using namespace std;
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        // Find the minimum element in the unsorted part of the array
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Swap the found minimum element with the first element
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
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
    selectionSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr,n);
    return 0;
}

