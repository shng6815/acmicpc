#include <iostream>

using namespace std;
int getNum(int a,int b){
	if(b==1)
		return 1;
	if(a==0)
		return b;
	cout<<a<<b<<" ";
	return getNum(a-1,b) + getNum(a,b-1);
}
int main(int argc, char* argv[]) {
	int testCase, layer, room;
	cin>>testCase;
	for(int i=0;i<testCase;i++){
		cin>>layer>>room;
		cout<<getNum(layer,room)<<endl;
	}
}