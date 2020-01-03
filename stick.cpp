//1094 baekjoon
#include <iostream>
using namespace std;

int main(){
    int len, stick = 64, sum = 0, counter = 0;
    
    cin>>len;

    while(sum != len){
        if(sum+stick > len){
            stick /= 2;
        }
        else{
            sum += stick;
            counter++;
        }
    }

    cout<<counter<<endl;
}