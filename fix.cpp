//Algospot
//ID : FIX
#include <iostream>
using namespace std;


int main(){
	int C;
	cin>>C;

	for(int cc = 0;cc<C;++cc){
		int N,temp,counter = 0;
		cin>>N;
		for(int i = 1;i<=N;++i){
			cin>>temp;
			if(temp == i){
				counter++;
			}
		}
		cout<<counter<<endl;
	}
	return 0;
}
