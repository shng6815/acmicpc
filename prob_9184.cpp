#include<iostream>
#include<algorithm>
using namespace std;
int dp[21][21][21];

int solv(int a,int b,int c){
	if((a<=0||b<=0)||c<=0)
		return 1;
	if(dp[a][b][c]!=0){
		return dp[a][b][c];
	}
	if(a<b&&b<c){
		dp[a][b][c] = solv(a,b,c-1)+solv(a,b-1,c-1)-solv(a,b-1,c);
		return dp[a][b][c];
	}
	else{
		dp[a][b][c] = solv(a-1, b, c) + solv(a-1, b-1, c) + solv(a-1, b, c-1) - solv(a-1, b-1, c-1);
		return dp[a][b][c];
	}
}

int main() {
	int a,b,c;
	for(;;){
		cin>>a>>b>>c;
		if((a==-1&&b==-1)&&c==-1)
			break;
		if((a>20||b>20)||c>20){
			printf("w(20, 20, 20) = %d",solv(20,20,20));
			continue;
		}
		printf("w(%d, %d, %d) = %d",a,b,c,solv(a,b,c));
	}
	
} 