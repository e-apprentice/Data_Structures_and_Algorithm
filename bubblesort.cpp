#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; ++j) {
            // Swap adjacent elements if they are in the wrong order
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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
 bubbleSort(arr, n);
cout << "Sorted array: ";
printArray(arr,n);
    return 0;
}







