//1003_baekjoon
#include <iostream>
#include <vector>
using namespace std;

vector<int> zero,one;

void makeVector(int n){
	for(int i = zero.size();i<n+1;++i){
		zero.push_back(zero[i-1]+zero[i-2]);
	 	one.push_back(one[i-1]+one[i-2]);
	}
}

int main(){
	zero.push_back(1);
    zero.push_back(0);
    one.push_back(0);
    one.push_back(1);

    int T;
    scanf("%d",&T);

    for(int tt = 0;tt<T;++tt){
		int n;
		scanf("%d",&n);
		
		if(zero.size() < n+1){
			makeVector(n);
		}
		
		printf("%d %d\n",zero[n],one[n]);
	}

	return 0;
}


