#include <stdio.h>

void Fibonacci(int n){
	int *arr = new int[n];
	printf("Day so Fibonacci la:\n");
	for(int i = 0; i <= n; i++){
		if(i == 0) arr[i] = 0;
		else if(i == 1) arr[i] = 1;
		else arr[i] = arr[i-1] + arr[i-2];
		printf("%d ", arr[i]);
	}
}
int main(){
	int n;
	printf("Enter n: "); scanf("%d", &n);
	Fibonacci(n);
	return 0;
}
