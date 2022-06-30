#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 10;

char Map[MAXN][MAXN];
char Stamp[MAXN][MAXN];

int T , N , M , A , B;

bool SHW = true;

struct qwq {
	int dx , dy;
} Delta[1000010];

int CYB , WHY , ZZL;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	while(T--) {
		SHW = true;
		
		cin >> N >> M >> A >> B;
		
		CYB = WHY = ZZL = 0;
		
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				cin >> Map[i][j];
			}
		}
		
		for(int i = 1; i <= A; i++) {
			for(int j = 1; j <= B; j++) {
				cin >> Stamp[i][j];
				if(Stamp[i][j] == 'x') {
					if(WHY == 0 && ZZL == 0) {
						WHY = i;
						ZZL = j;
					}		
					else Delta[++CYB] = qwq{i - WHY , j - ZZL};
				}
			}
		}
		
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				if(Map[i][j] == '.') continue;
				for(int k = 1; k <= CYB; k++) {
					int tx = i + Delta[k].dx;
					int ty = j + Delta[k].dy;
					if(tx < 1 || ty < 1 || tx > N || ty > M || Map[tx][ty] != 'x') {
						SHW = false;
						break;
					}
					Map[tx][ty] = '.';
				}
				if(SHW == false) {
					break;
				}
			}
			if(SHW == false) {
				break;
			}
		}
		
		if(SHW) {
			cout << "TAK" << endl;
		}
		else {
			cout << "NIE" << endl;
		}
	}
	return 0;
}