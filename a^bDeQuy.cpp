#include <iostream>

using namespace std;

int mod(int a, int b){
	if(a == 0) return 0;
	if(b == 0) return 1;
	else return a*mod(a, b-1);
}

int main(){
	cout << mod(1, 3);
	return 0;
}
