//8.2
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool match(string w, string t){
	if(w == "*" || (w.length() == 0 && t.length() == 0)){
		return true;
	}
	if(w.length() == 0 || t.length() == 0){
		return false;
	}
	int tcounter = 0;
	for(int i = 0;i<w.length();++i){
		if(w[i] == '*'){
			string temp = w.substr(i+1,w.length()-i-1);
			for(;tcounter<=t.length();++tcounter){
				if(match(temp,t.substr(tcounter,t.length()-tcounter))){
					return true;
				}
			}
			return false;
		}
		else{
			if(w[i] == '?'){
				tcounter++;
				continue;
			}
			if(w[i] != t[tcounter]){
				return false;
			}
			tcounter++;
		}
	}
	if(tcounter == t.length()){
		return true;
	}else{
		return false;
	}
}

int main(){
	int C;
	cin>>C;
	
	for(int cc = 0;cc<C;++cc){
		int n;
		string w;
		vector<string> ret;

		cin>>w;
		cin>>n;
		
		for(int i = 0;i<n;++i){
			string temp;
			cin>>temp;
			
			if(match(w, temp)){
				ret.push_back(temp);
			}
		}
		sort(ret.begin(),ret.end());
		for(int i = 0;i<ret.size();++i){
			cout<<ret[i]<<endl;
		}
	}

	return 0;
}
