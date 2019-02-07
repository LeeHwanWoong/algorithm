//8.1
#include <iostream>
#include <string.h>
using namespace std;

int board[100][100],n;
bool bBoard[100][100];

void findRoute(int x, int y){
	if(x<0 || x>n || y<0 || y>n){
		return;
	}
	
	bBoard[x][y] = true;
	if(x+board[x][y] < n && !bBoard[x+board[x][y]][y]){
		findRoute(x+board[x][y],y);
	}
	if(y+board[x][y] < n && !bBoard[x][y+board[x][y]]){
		findRoute(x,y+board[x][y]);
	}
}

int main(){
	int C;
	cin>>C;

	for(int cc = 0;cc<C;++cc){
		cin>>n;
		memset(bBoard,0,sizeof(bBoard));
		for(int i = 0;i<n;++i){
			for(int j = 0;j<n;++j){
				cin>>board[i][j];
			}
		}

		findRoute(0,0);
		if(bBoard[n-1][n-1]){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}

	return 0;
}
