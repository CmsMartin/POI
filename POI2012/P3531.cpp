#include <bits/stdc++.h>
using namespace std;
string a , b;
int n;
long long ans;
int aa[10000050];

vector<int>vec[27];

int tp[27];
int c[10000050];

int lowbit(int x){
	return x & -x;
}
void Add(int i){
	while(i <= n){
		c[i]++;
		i+=lowbit(i);
	}
}
int GetSum(int i){
	int ret = 0;
	while(i){
		ret += c[i];
		i -= lowbit(i);
	}
	return ret;
}


int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> a >> b;
	memset(tp , -1 , sizeof(tp));
	for(int i = 0 ; i < n ; i++)
		vec[b[i] - 'A' + 1].push_back(i + 1);
	for(int i = 0 ; i < n ; i++)
	{
		aa[i + 1] = vec[a[i] - 'A' + 1][++tp[a[i] - 'A' + 1]];
	}
	for(int i = 1 ; i <= n ; i++)
	{
		Add(aa[i]);
		ans += GetSum(n) - GetSum(aa[i]);
	}
	cout << ans;
	return 0;
}