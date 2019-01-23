//6.3
#include <iostream>
#include <string.h>
using namespace std;

int n, m, counter;
bool isFriend[10][10];

bool allPicked(bool picked[]){
	for(int i = 0;i<n;++i){
		if(picked[i] == false){
			return false;
		}
	}

	return true;
}

void pickFriend(int p, bool picked[]){
	if(allPicked(picked)){
		counter++;
		return;
	}

	if(picked[p]){
		pickFriend(p+1, picked);
		return;
	}

	for(int i = p+1;i<n;++i){
		if(!isFriend[p][i] || picked[i]){
			continue;
		}

		picked[p] = true;
		picked[i] = true;
		pickFriend(p+1,picked);
		picked[p] = false;
		picked[i] = false;
	}
	return;
}

int main(){
	int C;
	cin>>C;

	for(int tt = 0;tt<C;++tt){
		cin>>n>>m;
		counter = 0;
		bool picked[n];

		memset(isFriend,-1,sizeof(isFriend));
		memset(picked,0,sizeof(picked));

		for(int i = 0;i<m;++i){
			int a,b;
			cin>>a>>b;
			isFriend[a][b] = true;
			isFriend[b][a] = true;
		}

		pickFriend(0,picked);
		cout<<counter<<endl;
	}

	return 0;
}
