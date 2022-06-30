#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;

int N;
int Dp[MAXN][5] , Num[MAXN] , Ans[MAXN];

bool Dynamic_Programming(int s) {
	memset(Dp , 0 , sizeof Dp);
	Dp[1][s] = 1;
	for(int i = 2; i <= N + 1; i++) {
		if(Dp[i - 1][1] && Num[i - 1] <= Num[i] * 2) Dp[i][1] = 1;
		if(Dp[i - 1][1] && Num[i - 1] <= Num[i]) Dp[i][3] = 1;
		if(Dp[i - 1][2] && Num[i] <= Num[i - 1] * 2) Dp[i][2] = 2;
		if(Dp[i - 1][2] && Num[i] <= Num[i - 1]) Dp[i][4] = 2;
		if(Dp[i - 1][3] && Num[i] <= Num[i - 1]) Dp[i][2] = 3;
		if(Dp[i - 1][3] && Num[i] * 2 <= Num[i - 1]) Dp[i][4] = 3;
		if(Dp[i - 1][4] && Num[i - 1] <= Num[i]) Dp[i][1] = 4;
		if(Dp[i - 1][4] && Num[i - 1] * 2 <= Num[i]) Dp[i][3] = 4;
	}
	return Dp[N + 1][s];
}

int main() {
	scanf("%d" ,&N);
	for(int i = 1; i <= N; i++) {
		scanf("%d" ,Num + i);
	}
	Num[N + 1] = Num[1];
	for(int i = 1; i <= 4; i++) {
		if(Dynamic_Programming(i)) {
			int x = i;
			for(int j = N + 1; j >= 1; j--) {
				if(x == 1) {
					Ans[j - 1] = (j - 1) % N + 1;
				}
				if(x == 2) {
					Ans[j] = (j - 1) % N + 1;
				}
				if(x == 3) {
					Ans[j - 1] = Ans[j] = (j - 1) % N + 1;
				}
				x = Dp[j][x];
			}
			for(int i = 1; i <= N; i++) {
				printf("%d " ,Ans[i]);
			}
			return 0;
		}
	}
	return 0;
}