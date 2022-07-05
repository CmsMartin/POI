#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;

int Next[MAXN];

priority_queue<pair<int , int> > Heap;

int N , K , P , Ans;
int Num[MAXN];
map<int , int> Get_Next;

bitset<100010> Appear;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K >> P;
    for(int i = 1; i <= P; i++) {
        cin >> Num[i];
    }

    for(int i = P; i >= 1; i--) {
        if(Appear[Num[i]] == 0) {
            Next[i] = INT_MAX;
            Appear[Num[i]] = 1;
            Get_Next[Num[i]] = i;
        }
        else {
            Next[i] = Get_Next[Num[i]];
            Get_Next[Num[i]] = i;
        }
    }

    Appear.reset();

    for(int i = 1; i <= P; i++) {
        if(Appear[Num[i]]) {
            K++;
            Heap.push({Next[i] , Num[i]});
        }
        else {
            if(Heap.size() == K) {
                Appear[Heap.top().second] = 0;
                Heap.pop();
            }
            Heap.push({Next[i] , Num[i]});
            Appear[Num[i]] = 1;
            Ans++;
        }
    }

    cout << Ans << endl;
    return 0;
}