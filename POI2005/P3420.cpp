#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;

int Fa[MAXN] , N , Num[MAXN] , Ans;

int Find(int i) {
    return Fa[i] == i ? i : Fa[i] = Find(Fa[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        Fa[i] = i;
    }

    for(int i = 1; i <= N; i++) {
        cin >> Num[i];
        Fa[Find(Num[i])] = Fa[Find(i)];
    }

    for(int i = 1; i <= N; i++) {
        if(Fa[i] == i) {
            Ans++;
        }
    }
    
    cout << Ans << endl;
    return 0;
}