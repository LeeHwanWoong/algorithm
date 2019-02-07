//7.4
#include <iostream>
using namespace std;

int fence[20000];

int maxWidth(int s,int e){
	if((e-s) == 1){
		return fence[s];
	}
	int ret,m = (e+s)/2, minimum = min(fence[m-1],fence[m]), num = 2,l = m-2,r = m+1;

	ret = minimum * num;

	while(l >= s || r < e){
		num++;
		if(r == e){
			minimum = min(minimum,fence[l]);
			l--;
		}
		else if(l < s){
			minimum = min(minimum,fence[r]);
			r++;
		}
		else{
			if(fence[l] > fence[r]){
				minimum = min(minimum,fence[l]);
				l--;
			}
			else{
				minimum = min(minimum,fence[r]);
				r++;
			}
		}
		ret = max(ret,num*minimum);
	}
	
	return max(ret,max(maxWidth(s,m), maxWidth(m,e)));
}

int main(){
	int C;
	cin>>C;

	for(int cc = 0;cc<C;++cc){
		int N;
		cin>>N;
		for(int i = 0;i<N;++i){
			cin>>fence[i];
		}

		cout<<maxWidth(0,N)<<endl;
	}

	return 0;
}
