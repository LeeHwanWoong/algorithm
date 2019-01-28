//6.10
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int v[4];

	for(int i = 0;i<4;++i){
		v[i] = i+1;
	}

	do{
		for(int i = 0;i<4;++i){
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}while(next_permutation(v,v+4));
//next_permutation(v.begin(),v.end());
	return 0;
}
