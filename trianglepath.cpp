//8.4
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,tri[100][100];
int cache[100][100];

int findPath(int x, int y){
	if(x < 0 || y < 0){
		return 0;
	}
	int& ret = cache[x][y];
	if(cache[x][y] != -1){
		return ret;
	}
	
	return ret = tri[x][y] + max(findPath(x-1,y),findPath(x-1,y-1));
}


int main(){
	int C;
	cin>>C;

	for(int cc = 0;cc<C;++cc){
		cin>>n;
		vector<int> ret;
		for(int i = 0;i<n;++i){
			for(int j = 0;j<=i;++j){
				cin>>tri[i][j];
				cache[i][j] = -1;
			}
		}

		cache[0][0] = tri[0][0];
		for(int i = 0;i<n;++i){
			ret.push_back(findPath(n-1,i));
		}
		sort(ret.begin(),ret.end());
		cout<<ret[n-1]<<endl;
	}

	return 0;
}
