#include<bits/stdc++.h>
using namespace std;

int l,r,k;
#define ll long long

ll sum(ll n) {
	//k^0 ~ k^1-1 ��1������
	//k^1 ~ k^2-1 ��1+k������
	//k^2 ~ k^3-1 ��1+k+k^2������
	ll kf = 1;//��ʼ,k��0�η�Ϊ1
	ll ret = 0;//����������
	ll p = 1;//��ǰ��Щ����������������
	while(kf*k-1<n) {
		ret += p*(kf*k-1 - kf + 1)%2;//���������������ż,����ģ2��Ӱ��
		p += k;
		kf = kf*k;
	}
	//���ʣ�µ���Щ
	ret += p*(n - kf + 1);
	return ret;
}

int main() {
	while(scanf("%d%d%d",&l,&r,&k)!=EOF) {
		//����k=1ʱ������ѭ������ƽ��
		if(k==1)
			puts("Draw");
		else if(((sum(r)-sum(l-1))&1)==1)//����
			puts("XHRlyb");
		else
			puts("Cwbc");
	}
	return 0;
}
