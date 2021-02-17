#include<iostream>
using namespace std;
int dp[21][21][21];
int a,b,c;

int solv(int a,int b,int c){
	if((a<=0||b<=0)||c<=0)
		return 1;
	if(dp[a][b][c]!=0){
		return dp[a][b][c];
	}
	if ((a>20||b>20)||c>20)
    	return w(20, 20, 20);

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
	for(;;){
		cin>>a>>b>>c;
		if((a==-1&&b==-1)&&c==-1)
			break;
		printf("w(%d, %d, %d) = %d\n",a,b,c,solv(a,b,c));
	}
	
} 