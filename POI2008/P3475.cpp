#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 10;

int N , Mid , M;
int Num[MAXN] , Ans[MAXN] , Pos[MAXN] , L[MAXN] , R[MAXN];

void SA() {
    double st = 11000.00;

    while(st > 1e-14) {
        int l = rand() % Mid + 1;
        int r = rand() % Mid + Mid + 1;

        swap(Pos[Num[l]] , Pos[Num[r]]);
        swap(Num[l] , Num[r]);

        int Now = 0;
        for(int i = 1; i <= M; i++) {
            if((Pos[L[i]] > Mid) != (Pos[R[i]] > Mid)) {
                Now++;
            }
        }

        int Delta = Now - Ans[0];

        if(Delta < 0) {
            Ans[0] = Now;
            for(int i = 1; i <= Mid; i++) {
                Ans[i] = Num[i];
            }
        }
        else if(exp(-Delta / st) * RAND_MAX <= rand()) {
            swap(Pos[Num[l]] , Pos[Num[r]]);
            swap(Num[l] , Num[r]);
        }

        st *= 0.998;
    }
}

int main() {
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    Mid = N / 2;

    for(int i = 1; i <= N; i++) {
        Num[i] = i;
        Pos[i] = i;
    }
    for(int i = 1; i <= Mid; i++) {
        Ans[i] = i;
    }
    for(int i = 1; i <= M; i++) {
        cin >> L[i] >> R[i];
        if((Pos[L[i]] > Mid) != (Pos[R[i]] > Mid)) {
            Ans[0]++;
        }
    }

    for(int i = 1; i <= 30; i++) {
        SA();
    }

    for(int i = 1; i <= Mid; i++) {
        cout << Ans[i] << " ";
    }
    return 0;
}