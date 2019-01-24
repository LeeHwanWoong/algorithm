//6.5
#include <iostream>
#include <string.h>
using namespace std;

int H,W;
char board[20][20];
const int coverType[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}},
	{{0,0},{0,1},{1,1}}
};

int countBoard(char gboard[20][20]){
	int ret = 0;
	int x = -1,y = -1;
	
	for(int i = 0;i<H;++i){
		for(int j = 0;j<W;++j){
			if(gboard[i][j] == '.'){
				x = i;
				y = j;
				goto EXIT;
			}
		}
	}
EXIT:

	if(x == -1 && y == -1){
		return 1;
	}

	for(int i = 0;i<4;++i){
		//4종류
		int loc[3][2];
		bool possible = true;
		for(int j = 0;j<3;++j){
			//3개 점 확인
			loc[j][0] = coverType[i][j][0] + x;
			loc[j][1] = coverType[i][j][1] + y;
		}
		
		for(int j = 0;j<3;++j){
			if(loc[j][0] < 0 || loc[j][0] >= H){
				possible = false;
				break;
			}
			if(loc[j][1] < 0 || loc[j][1] >= W){
				possible = false;
				break;
			}
			if(gboard[loc[j][0]][loc[j][1]] != '.'){
				possible = false;
				break;
			}
		}
		if(!possible){
			continue;
		}
		for(int j = 0;j<3;++j){
			gboard[loc[j][0]][loc[j][1]] = '#';
		}
		ret += countBoard(gboard);
		for(int j = 0;j<3;++j){
			gboard[loc[j][0]][loc[j][1]] = '.';
		}
	}

	return ret;
}

int main(){
	int C;
	cin>>C;

	for(int cc = 0;cc<C;++cc){
		cin>>H>>W;
		memset(board,'b',sizeof(board));
		for(int i = 0;i<H;++i){
			for(int j = 0;j<W;++j){
				cin>>board[i][j];
			}
		}

		cout<<countBoard(board)<<endl;
	}

	return 0;
}
