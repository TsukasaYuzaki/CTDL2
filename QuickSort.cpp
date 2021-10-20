#include <iostream>

using namespace std;

void swap(int *a, int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int findPivot(int arr[], int low, int high){
	int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = findPivot(arr, low, high);
 
        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main(){
	int array[] = {10, 80, 30, 90, 40, 50, 70, 50, 6, 12, 54, -4, 51, 87};
	
	//Tinh Size cua arrray
	int sSize = sizeof(array)/sizeof(array[0]);
	//cout << sSize << "\n";

	int a = 1, b = 2, i, j;
	for (i = 0; i< sSize; i++){
		cout << "array[" << i << "] = " << array[i];
		cout << "\n";
	}
	quickSort(array, 0, sSize - 1);
	
	cout << "\n";
	for (i = 0; i< sSize; i++){
		cout << array[i] << " ";
	}
	return 0;
}