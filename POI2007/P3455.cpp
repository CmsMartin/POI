#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50010;

int Prime[MAXN] , Mu[MAXN] , Cnt;
bool Vis[MAXN];
int a , b , d , N;

void Get_Mu(int N) {
	Mu[1] = 1;
	for(int i = 2; i <= N; i++) {
		if(!Vis[i]) {
			Mu[i] = -1;
			Prime[++Cnt] = i;
		}
		for(int j = 1; j <= Cnt && i * Prime[j] <= N; j++) {
			Vis[i * Prime[j]] = true;
			if(i % Prime[j] == 0) break;
			else Mu[i * Prime[j]] = -Mu[i];
		}
	}
    for(int i = 1; i <= N; i++) {
        Mu[i] += Mu[i - 1];
    }
}

long long Ans;

int main() {
	ios::sync_with_stdio(false);
    Get_Mu(50000);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a >> b >> d;
        Ans = 0;
        for(int l = 1 , r; l <= b && l <= a; l = r + 1) {
            r = min(a / (a / l) , b / (b / l));
            Ans += (long long)(Mu[r] - Mu[l - 1]) * (1ll * a / (l * d) * (1ll * b / (l * d)));
        }
        cout << Ans << endl;
    }
	return 0;
} 