#include"pch.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> line;
vector<int> arr;
int maxNum = -987654321;
int N;
int main() {
	int a, b;
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<int> v;
		cin >> a >> b;
		v.push_back(a);
		v.push_back(b);
		line.push_back(v);
	}
	sort(line.begin(), line.end());
	for (int i = 0; i < N; i++)
		arr.push_back(line[i][1]);
	vector<int> dp(N, 1);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	for (int i = 0; i < N; ++i) {
		maxNum = max(maxNum, dp[i]);
	}
	cout << dp.size() - maxNum;
}