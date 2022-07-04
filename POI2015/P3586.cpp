#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;

int N , M;
char Op;
int K , A , C , S;

int Left[MAXN] , Right[MAXN] , Size[MAXN];
long long Sum[MAXN];
int Num[MAXN];
int ToT , root;

void Change(int &u , int l , int r , int x , int y) {
    if(!u) u = ++ToT;
    if(l == r) {
        Size[u] += y;
        Sum[u] += y * l;
        return;
    }
    int mid = l + r >> 1;
    if(x <= mid) Change(Left[u] , l , mid , x , y);
    else Change(Right[u] , mid + 1 , r , x , y);
    Size[u] = Size[Left[u]] + Size[Right[u]];
    Sum[u] = Sum[Left[u]] + Sum[Right[u]];
}

long long Query_Sum(int u , int l , int r , int ql , int qr) {
    if(!u || l > qr || r < ql) return 0ll;
    if(ql <= l && r <= qr) return Sum[u];
    int mid = l + r >> 1;
    return Query_Sum(Left[u] , l , mid , ql , qr) + Query_Sum(Right[u] , mid + 1 , r , ql , qr);
}

int Query_Size(int u , int l , int r , int ql , int qr) {
    if(!u || l > qr || r < ql) return 0;
    if(ql <= l && r <= qr) return Size[u];
    int mid = l + r >> 1;
    return Query_Size(Left[u] , l , mid , ql , qr) + Query_Size(Right[u] , mid + 1 , r , ql , qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    Change(root , 0 , 1e9 , 0 , N);

    while(M--) {
        cin >> Op;
        if(Op == 'U') {
            cin >> K >> A;
            Change(root , 0 , 1e9 , Num[K] , -1);
            Change(root , 0 , 1e9 , Num[K] = A , 1);
        }
        else if(Op == 'Z') {
            cin >> C >> S;
            int CYB = Query_Size(root , 0 , 1e9 , S , 1e9);
            long long sum = S ? Query_Sum(root , 0 , 1e9 , 0 , S - 1) : 0;
            cout << (sum >= 1ll * (C - CYB) * S ? "TAK" : "NIE") << endl;
        }
    }

    return 0;
}