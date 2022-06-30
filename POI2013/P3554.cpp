#include <bits/stdc++.h>
using namespace std;

int Dp[300010];
int N , L , R , Mid , Ans;
vector<int> G[300010];

void Dfs(int u , int fa) {
	int Sum = 0;
	for(int v : G[u]) {
		if(v == fa) continue;
		Dfs(v , u);
		Sum += Dp[v] + 1;
	}
	Dp[u] = max(Sum - Mid , 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for(int i = 1 , u , v; i < N; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	L = 0;
	R = N;
	while(L <= R) {
		Mid = L + R >> 1;
		Dfs(1 , 0);
		if(!Dp[1]) {
			Ans = Mid;
			R = Mid - 1;
		}
		else {
			L = Mid + 1;
		}
	}
	
	cout << Ans << endl;
	return 0;
}