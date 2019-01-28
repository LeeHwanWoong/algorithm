//6.10
#include <iostream>
#include <algorithm>
using namespace std;

//nCk
int n,k;

int main(){
	n = 6,k = 4;
	int a[n];

	for(int i = 0;i<n;++i){
		a[i] = i+1;
	}

	int ind[n];

	for(int i = 0;i<n-k;++i){
		ind[i] = 0;
	}
	for(int i = n-k;i<n;++i){
		ind[i] = 1;
	}

	do{
		for(int i = 0;i<n;++i){
			if(ind[i] == 1){
				cout<<a[i]<<" ";
			}
		}
		cout<<endl;
	}while(next_permutation(ind,ind+6));

	return 0;
}
