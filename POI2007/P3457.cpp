#include <bits/stdc++.h>
using namespace std;

int N , M;

int Id(int x , int y) {
    return (x - 1) * N + y;
}

int Fa[1000010];
bool Have[1000010];
int Num[1010][1010];
bool In_City[1000010];
int Ans;

int dx[] = {0 , 0 , -1 , 1};
int dy[] = {-1 , 1 , 0 , 0};

struct Point {
    int x , y , h;
} Position[1000010];
int ToT;

int Find(int x) {
    return Fa[x] == x ? Fa[x] : Fa[x] = Find(Fa[x]);
}

void Merge(int x , int y) {
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    Fa[x] = y;
    Have[y] |= Have[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(Num , 0x3f , sizeof Num);

    cin >> M >> N;
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> Num[i][j];
            if(Num[i][j] >= 0) In_City[Id(i , j)] = true;
            else Num[i][j] = -Num[i][j];
            Fa[Id(i , j)] = Id(i , j);
            Position[Id(i , j)] = {i , j , Num[i][j]};
        }
    }

    sort(Position + 1 , Position + 1 + Id(M , N) , [](Point x , Point y) { return x.h < y.h; });

    for(int i = 1; i <= Id(M , N); i++) {
        for(int j = 0; j < 4; j++) {
            int tx = Position[i].x + dx[j];
            int ty = Position[i].y + dy[j];
            if(tx <= 0 || tx > M || ty <= 0 || ty > N) continue;
            if(Num[tx][ty] <= Position[i].h) {
                Merge(Id(tx , ty) , Id(Position[i].x , Position[i].y));
            }
        }

        if(Position[i].h != Position[i + 1].h) {
            for(int j = i; ; j--) {
                if(Position[j].h != Position[i].h) break;

                if(In_City[Id(Position[j].x , Position[j].y)]) {
                    int fa = Find(Id(Position[j].x , Position[j].y));
                    if(!Have[fa]) {
                        Have[fa] = true;
                        Ans++;
                    }
                }
            }
        }
    }
    cout << Ans << endl;
    return 0;
}