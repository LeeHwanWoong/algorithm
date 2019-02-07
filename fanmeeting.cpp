//7.6
#include <iostream>
#include <string>
using namespace std;

int nfan,nstar;
int fan[200000],star[200000];

void change(string tstar,string tfan){
	for(int i = 0;i<nstar;++i){
		if(tstar[i] == 'M'){
			star[i] = 1;
		}
		else{
			star[i] = 0;
		}
	}
	for(int i = 0;i<nfan;++i){
		if(tfan[i] == 'M'){
			fan[i] = 1;
		}
		else{
			fan[i] = 0;
		}
	}
}

int isHug(int s, int e){
	int ret = 0;
	int j = 0;
	for(int i = s;i<e;++i,++j){
		ret += star[j]*fan[i];
	}
	return ret;
}

int main(){
	int C;
	cin>>C;

	for(int cc = 0;cc<C;++cc){
		string temp1,temp2;
		cin>>temp1>>temp2;
		nfan = temp2.length();
		nstar = temp1.length();

		change(temp1,temp2);
		int ret = 0;
		for(int i = 0;(i+nstar-1)<nfan;++i){
			if(isHug(i,i+nstar) == 0){
				ret++;
			}
		}	
		cout<<ret<<endl;
	}

	return 0;
}
