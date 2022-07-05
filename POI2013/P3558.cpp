#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;

int Dp[MAXN][4] , Num[MAXN] , N;

void Transfer(int i) {
    if(Num[i] == -1) {
        Dp[i][0] = Dp[i - 1][0];
        Dp[i][2] = Dp[i - 1][2] + 2;
    }
    if(Num[i] == 0) {
        Dp[i][0] = Dp[i - 1][0] + 1;
        Dp[i][1] = min(Dp[i - 1][0] , Dp[i - 1][1]);
        Dp[i][2] = Dp[i - 1][2] + 1;
    }
    if(Num[i] == 1) {
        Dp[i][0] = Dp[i - 1][0] + 2;
        Dp[i][1] = Dp[i - 1][0] + 1;
        Dp[i][2] = min(Dp[i - 1][0] , min(Dp[i - 1][1] , Dp[i - 1][2]));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> Num[i];
    }

    memset(Dp , 0x3f , sizeof Dp);

    Dp[1][Num[1] + 1] = 0;

    for(int i = 2; i <= N; i++) 
        Transfer(i);

    int Ans = min(min(Dp[N][0] , Dp[N][1]) , Dp[N][2]);

    if(Ans == Dp[0][0]) cout << "BRAK" << endl;
    else cout << Ans << endl;

    return 0;
}