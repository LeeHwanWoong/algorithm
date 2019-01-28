//7.2
#include <iostream>
#include <string>
using namespace std;

string quadtree;

string tranpose(int xpos){
	string tree[4],ret = "x";
	int counter = 0;

	for(int i = xpos+1;i<quadtree.length() && counter<4;++i,++counter){
		if(quadtree[i] == 'x'){
			tree[counter] = tranpose(i);
			i += (tree[counter].length()-1);
		}else{
			tree[counter] = quadtree[i];
		}
	}

	ret+=(tree[2]+tree[3]+tree[0]+tree[1]);

	return ret;
}

int main(){
	int C;
	cin>>C;

	for(int cc = 0;cc<C;++cc){
		cin>>quadtree;
		if(quadtree.length() == 1){
			cout<<quadtree<<endl;
		}
		else{
			cout<<tranpose(0)<<endl;
		}
	}

	return 0;
}
