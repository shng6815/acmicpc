#include"pch.h"
#include<iostream>
using namespace std;
int arr[21][21];
int N;
int used[20] = { 0 };
int startSum, linkSum;
int gap = 2147438647;
int absAndSub(int a, int b) {
	if (a > b)
		return a - b;
	else
		return b - a;
}
void getResult(int idx,int cnt) {
	startSum = linkSum = 0;
	if (cnt == N / 2) {
		for (int i = 0; i < N;i++) {
			if (used[i] == 1) {
				for (int j = 0; j < N; j++) {
					if (used[j] == 1 && i != j)
						startSum += arr[i][j];
				}
			}
			else {
				for (int j = 0; j < N; j++) {
					if (used[j] == 0 && i != j)
						linkSum += arr[i][j];
				}
			}
		}
		if (gap > absAndSub(startSum, linkSum))
			gap = absAndSub(startSum, linkSum);
		return;
	}
	for (int i = idx+1; i < N; i++) {
		if (used[i] == 0) {
			used[i] = 1;
			getResult(i,cnt + 1);
			used[i] = 0;
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}
	getResult(0,0);
	cout << gap;
}