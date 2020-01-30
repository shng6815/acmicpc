#include"pch.h"
#include<iostream>
using namespace std;
int dp[1000001] = { 0 ,1};
int cnt = 0;
int Min(int a, int b, int c) {
	int d = (a < b) ? a : b;
	return c < d ? c : d;
}
int Min(int a, int b) {
	return (a < b) ? a : b;
}
int func(int num) {
	if (dp[num])
		return dp[num];
	if (num % 3 == 0 && num % 2 == 0)
		return dp[num] = Min(func(num / 3) + 1, func(num / 2) + 1, func(num - 1) + 1);
	else if (num % 3 == 0)
		return dp[num] = Min(func(num / 3) + 1, func(num - 1) + 1);
	else if (num % 2 == 0)
		return dp[num] = Min(func(num / 2) + 1, func(num - 1) + 1);
	else
		return dp[num] = func(num - 1) + 1;
}
int main() {
	int N;
	cin >> N;
	cout << func(N)-1;
}