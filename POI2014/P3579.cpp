#include <bits/stdc++.h>
using namespace std;

int T , A , B , C , D;

int main() {
	scanf("%d" ,&T);
	
	while(T--) {
		scanf("%d%d%d%d" ,&A ,&B ,&C ,&D);
		int Ans = -1;
		for(int i = 1; i <= B && i <= D; i = min(B / (B / i) , D / (D / i)) + 1) {
			if(B / min(B / (B / i) , D / (D / i)) > (A - 1) / min(B / (B / i) , D / (D / i)) && D / min(B / (B / i) , D / (D / i)) > (C - 1) / min(B / (B / i) , D / (D / i)))
				Ans = min(B / (B / i) , D / (D / i));
		}
		cout << Ans << endl;
	}
	
	return 0;
}