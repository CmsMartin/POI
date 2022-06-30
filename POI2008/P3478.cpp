#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;

vector<int> G[MAXN << 1];

int N , Id;
long long Dp[MAXN] , Dep[MAXN] , Size[MAXN] , Ans;

void Dfs1(int x , int fa) {
	Size[x] = 1;
	Dep[x] = Dep[fa] + 1;
	for(int i : G[x]) {
		if(i == fa) continue;
		Dfs1(i , x);
		Size[x] += Size[i];
	}
}

void Dfs2(int x , int fa) {
	for(int i : G[x]) {
		if(i == fa) continue;
		Dp[i] = Dp[x] + N - 2 * Size[i];
		Dfs2(i , x);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	
	for(int i = 1 , u , v; i < N; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	Dfs1(1 , 0);
	for(int i = 1; i <= N; i++) Dp[1] += Dep[i];
	Dfs2(1 , 0);
	for(int i = 1; i <= N; i++) {
		if(Ans < Dp[i]) {
			Ans = Dp[i];
			Id = i;
		}
	}
	
	cout << Id << endl;
	
	return 0;
}