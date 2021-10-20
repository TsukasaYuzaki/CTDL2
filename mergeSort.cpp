// C++ program for Merge Sort
#include <iostream>
using namespace std;
  
void merge(int array[], int const left, int const mid, int const right)
{
    int const s1 = mid - left + 1;
    int const s2 = right - mid;
  
  
    int *leftArray = new int[s1],
         *rightArray = new int[s2];
  

    for (int i = 0; i < s1; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < s2; j++)
        rightArray[j] = array[mid + 1 + j];
  
    int indexOfs1 = 0, 
        indexOfs2 = 0; 
    int indexOfsArr = left; 
  

    while (indexOfs1 < s1 && indexOfs2 < s2) {
        if (leftArray[indexOfs1] <= rightArray[indexOfs2]) {
            array[indexOfsArr] = leftArray[indexOfs1];
            indexOfs1++;
        }
        else {
            array[indexOfsArr] = rightArray[indexOfs2];
            indexOfs2++;
        }
        indexOfsArr++;
    }

    while (indexOfs1 < s1) {
        array[indexOfsArr] = leftArray[indexOfs1];
        indexOfs1++;
        indexOfsArr++;
    }

    while (indexOfs2 < s2) {
        array[indexOfsArr] = rightArray[indexOfs2];
        indexOfs2++;
        indexOfsArr++;
    }
}
  

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; 
  
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
  

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}
  

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
  
    cout << "Given array is \n";
    printArray(arr, arr_size);
  
    mergeSort(arr, 0, arr_size - 1);
  
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}