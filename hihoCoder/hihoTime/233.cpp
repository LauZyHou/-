#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
typedef long long ll;
const int maxn = 1e9 + 7;
const int maxcount = 1e5 + 3;
const int maxvalue = 103;
int n;
int a[maxcount];
//DP,pre[i]��ʾ��a[1]~a[i]��ֳ����ɶ�ʹ��ÿ�κͶ���Ϊ0�ķ�����
int pre[maxcount];
map<int, int>ma;
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)scanf("%d", a + i+1);
	pre[0]=a[0] = 0;
	ma[0] = 1;
	for (int i = 1; i <= n; i++)pre[i] = pre[i - 1] + a[i];
	ll s = 1;
	ll now = 0;
	for (int i=1; i <= n; i++) {
		now = (s- ma[pre[i]]+maxn)%maxn;
		s = (s + now) % maxn;
		if (ma.count(pre[i]) == 0)ma[pre[i]] = 0;
		ma[pre[i]] = (ma[pre[i]]+now)%maxn;
	}
	cout << now<< endl;
	return 0;
}
