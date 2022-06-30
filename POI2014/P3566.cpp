#include <bits/stdc++.h>
using namespace std;

int M , P , Q , N;

struct lxl {
	int X , Y;
};

bool operator < (const lxl &a , const lxl &b) {
	if(a.X != b.X) {
		return a.X < b.X;
	}
	if(a.Y == Q) {
		return false;
	}
	return true;
}

priority_queue<lxl> q;

int Ans[1000010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> M >> P >> Q;
	for(int i = 1; i <= M; i++) {
		lxl CYB;
		cin >> CYB.X;
		N += CYB.X;
		if(i == P) CYB.X--;
		if(i == Q) CYB.X--;
		
		if(CYB.X < 0) {
			cout << 0;
			return 0;
		}
		
		CYB.Y = i;
		
		q.push(CYB);
	}
	
	Ans[1] = P;
	Ans[N] = Q;
	
	for(int i = 2; i < N; i++) {
		lxl CYB = q.top();
		lxl TMZ;
		bool SHW = false;
		q.pop();
		if(CYB.Y == P) {
			TMZ = CYB;
			if(!q.empty()) {
				CYB = q.top();
			}
			else {
				cout << 0;
				return 0;
			}
			q.pop();
			SHW = true;
		}
		Ans[i] = CYB.Y;
		P = CYB.Y;
		if(CYB.X - 1 > 0) {
			q.push({CYB.X - 1 , CYB.Y});
		}
		if(SHW == true) {
			q.push(TMZ);
		}
	}
	
	for(int i = 2; i <= N; i++) {
		if(Ans[i] == Ans[i - 1]) {
			cout << 0;
			return 0;
		}
	}
	
	for(int i = 1; i < N; i++) {
		cout << Ans[i] << " ";
	}
	cout << Ans[N];
	return 0;
}