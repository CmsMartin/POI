#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;

struct SegmentTree {
    int LeftTree , RightTree;
    long long Min;
} Tree1[MAXN * 8] , Tree2[MAXN * 8];

long long Sum1[MAXN * 4] , Sum2[MAXN * 4];

void PushUp1(int p) {
    Tree1[p].Min = min(Tree1[p * 2].Min , Tree1[p * 2 + 1].Min);
}

void Build1(int p , int l , int r) {
    Tree1[p].LeftTree = l;
    Tree1[p].RightTree = r;
    if(l == r) {
        Tree1[p].Min = Sum1[l];
        return;
    }
    int mid = l + r >> 1;
    Build1(p * 2 , l , mid);
    Build1(p * 2 + 1 , mid + 1 , r);
    PushUp1(p);
}

long long Query1(int p , int l , int r) {
    if(l <= Tree1[p].LeftTree && r >= Tree1[p].RightTree) 
        return Tree1[p].Min;
    long long Val = LONG_LONG_MAX;
    int mid = Tree1[p].LeftTree + Tree1[p].RightTree >> 1;
    if(l <= mid) {
        Val = min(Val , Query1(p * 2 , l , r));
    }
    if(r > mid) {
        Val = min(Val , Query1(p * 2 + 1 , l , r));
    }
    return Val;
}

void PushUp2(int p) {
    Tree2[p].Min = min(Tree2[p * 2].Min , Tree2[p * 2 + 1].Min);
}

void Build2(int p , int l , int r) {
    Tree2[p].LeftTree = l;
    Tree2[p].RightTree = r;
    if(l == r) {
        Tree2[p].Min = Sum2[l];
        return;
    }
    int mid = l + r >> 1;
    Build2(p * 2 , l , mid);
    Build2(p * 2 + 1 , mid + 1 , r);
    PushUp2(p);
}

long long Query2(int p , int l , int r) {
    if(l <= Tree2[p].LeftTree && r >= Tree2[p].RightTree) 
        return Tree2[p].Min;
    long long Val = LONG_LONG_MAX;
    int mid = Tree2[p].LeftTree + Tree2[p].RightTree >> 1;
    if(l <= mid) {
        Val = min(Val , Query2(p * 2 , l , r));
    }
    if(r > mid) {
        Val = min(Val , Query2(p * 2 + 1 , l , r));
    }
    return Val;
}

int N;
int D[MAXN] , P[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> P[i] >> D[i];
        Sum1[i] = Sum1[i - 1] - D[i] + P[i];
    }
    for(int i = N + 1; i < 2 * N; i++) {
        Sum1[i] = Sum1[i - 1] - D[i - N] + P[i - N];
    }
    for(int i = 1; i < N; i++) {
        Sum2[i] = Sum2[i - 1] - D[N - i] + P[N - i + 1];
    }
    Sum2[N] = Sum2[N - 1] - D[N] + P[1];
    for(int i = N + 1; i < 2 * N; i++) {
        Sum2[i] = Sum2[i - 1] - D[2 * N - i] + P[2 * N - i + 1];
    }
    Build1(1 , 1 , N * 2 - 1);
    Build2(1 , 1 , N * 2 - 1);
    for(int i = 1; i <= N; i++) {
        if(Query1(1 , i , i + N - 1) >= Sum1[i - 1]) cout << "TAK\n";
        else if(Query2(1 , N - i + 1 , 2 * N - i) >= Sum2[N - i]) cout << "TAK\n";
        else cout << "NIE\n";
    }
    return 0;
}