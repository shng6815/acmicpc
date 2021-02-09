#include"pch.h"
#include<iostream>
#include<algorithm>
using namespace std;
int N;
int arr[1001];
int dp_inc[1000];
int dp_dec[1000];
int Max = 0;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp_inc[i] = dp_dec[i] = 1;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				dp_inc[i] = max(dp_inc[i], dp_inc[j] + 1);
		}
	}
	for (int i = N - 2; i >= 0; i--) {
		for (int j = N - 1; j > i; j--) {
			if (arr[j] < arr[i])
				dp_dec[i] = max(dp_dec[i], dp_dec[j] + 1);
		}
	}
	for (int i = 0; i < N; i++)
		Max = max(Max, dp_dec[i] + dp_inc[i]);
	cout << Max-1;
}