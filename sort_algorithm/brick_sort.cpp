//#include<bits/stdc++.h>
#include <iostream>
using namespace std;
 
// A utility function ot print an array of size n
void printArray(int arr[], int n) {
   for (int i=0; i < n; i++)
       cout << arr[i] << " ";
   cout << "\n";
}

// A function to sort the algorithm using Odd Even sort
void oddEvenSort(int arr[], int n)
{
    bool isSorted = false; // Initially array is unsorted
    while (!isSorted) {
        isSorted = true;
        // Perform Bubble sort on odd indexed element
        for (int i=1; i<=n-2; i=i+2) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                isSorted = false;
            }
        }
        // Perform Bubble sort on even indexed element
        for (int i=0; i<=n-2; i=i+2) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                isSorted = false;
            }
        }
    }
 
    return;
}


 
// Driver program to test above functions.
int main() {
    int arr[] = {3,2,3,8,5,6,4,1};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    oddEvenSort(arr, n);
    printArray(arr, n);
 
    return (0);
}
