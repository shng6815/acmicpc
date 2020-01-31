#include"pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001] = { 0 };
int dp[100001] = { 0 };
int N, maxx;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	dp[1] = arr[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}
	maxx = dp[1];
	for (int i = 1; i <= N; i++) {
		maxx = max(dp[i], maxx);
	}
	cout << maxx;
}