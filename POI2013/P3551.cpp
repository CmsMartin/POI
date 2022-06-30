#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;

int N;
int K;
string S;

int Ans[MAXN] , CYB;

//超帅的手写栈 
int Stack[MAXN] , Top;

int Sum[MAXN]; //C 的数量 

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> K >> S;
	S = " " + S;
	
	for(int i = 1; i <= N; i++) {
		Stack[++Top] = i;
		Sum[Top] = Sum[Top - 1];
		
		if(S[i] == 'c') Sum[Top]++;
		
		if(Top >= K + 1 && Sum[Top] - Sum[Top - (K + 1)] == 1) { //中间往两边 
			for(int j = Top; j >= Top - K; j--) {
				Ans[++CYB] = Stack[j];
			}
			Top -= K + 1;
		} 
	}
	
	for(int i = N; i >= 1; i -= K + 1) {
		for(int j = 0; j <= K; j++) {
			cout << Ans[i - j] << " "; 
		}
		cout << "\n";
	}
	return 0;
}