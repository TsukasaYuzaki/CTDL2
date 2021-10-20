#include <iostream>

using namespace std;

int gt(int n){
	if(n == 1) return 1;
	else return n*gt(n-1);
}

int main(){
	cout << gt(5);
	return 0;
}