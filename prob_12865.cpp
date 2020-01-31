#include"pch.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> obj;
int dp[101][100001];
int N, W;
int main() {
	int a, b;
	cin >> N >> W;
	for (int i = 0; i < N; i++) {
		vector<int> v;
		cin >> a >> b;
		v.push_back(a);
		v.push_back(b);
		obj.push_back(v);
	}
	sort(obj.begin(), obj.end());
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= W; j++) {
			if (obj[i-1][0] > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - obj[i-1][0]] + obj[i-1][1]);
		}
	}
	cout << dp[N][W];
}