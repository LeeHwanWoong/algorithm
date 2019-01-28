//6.8
#include <iostream>
using namespace std;

bool success;
int minimum = 9999;

const int switchB[10][5] = {
	{0,1,2,-1,-1},
	{3,7,9,11,-1},
	{4,10,14,15,-1},
	{0,4,5,6,7},
	{6,7,8,10,12},
	{0,2,14,15,-1},
	{3,14,15,-1,-1},
	{4,5,7,14,15},
	{1,2,3,4,5},
	{3,4,5,9,13}
};	

bool checkTime(int clock[16]){
	for(int i = 0;i<16;++i){
		if(clock[i] != 12){
			return false;
		}
	}
	success = true;
	return true;
}

void switchClock(int clock[16], int c_num, int s_num){
	if(c_num >= 10){
		if(checkTime(clock)){
			minimum = min(minimum,s_num);
		}
		return;
	}

	for(int i = 0;i<4;++i){
		for(int j = 0;j<5;++j){
			if(switchB[c_num][j] == -1){
				break;
			}
			clock[switchB[c_num][j]] += 3*i;
			clock[switchB[c_num][j]] = clock[switchB[c_num][j]]%12;
			if(clock[switchB[c_num][j]] == 0){
				clock[switchB[c_num][j]] = 12;
			}
		}

		switchClock(clock,c_num+1,s_num+i);

		for(int j = 0;j<5;++j){
			if(switchB[c_num][j] == -1){
				break;
			}
			clock[switchB[c_num][j]] -= 3*i;
			if(clock[switchB[c_num][j]] == 0){
				clock[switchB[c_num][j]] = 12;
			}
		}
	}
}

int main(){
	int C;
	cin>>C;

	for(int cc = 0;cc<C;++cc){
		int clock[16];
		for(int i = 0;i<16;++i){
			cin>>clock[i];
		}
		minimum = 9999;
		success = false;
		switchClock(clock,0,0);

		if(!success){
			cout<<"-1"<<endl;
		}
		else{
			cout<<minimum<<endl;
		}
	}

	return 0;
}
