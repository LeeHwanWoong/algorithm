#include <iostream>
using namespace std;

void pass(int b[2][2]){
	b[0][0] = 3;

	cout<<b[0][0]<<endl;
}

int main(){
	int a[2][2];
	a[0][0] = 1;
	a[0][1] = 1;
	a[1][1] = 1;
	a[1][0] = 1;

	pass(a);
	cout<<a[0][0]<<endl;

	return 0;
}
