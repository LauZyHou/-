#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define N 100000
int q,k;
int maxr = 0;

int main() {
	scanf("%d%d",&q,&k);
	if(!q)
		return 0;
	int val[N][2];//��q��l��r
	//��ȡq��l��r
	for(int i=0;i<q;i++) {
		scanf("%d%d",&val[i][0],&val[i][1]);
		maxr = max(maxr,val[i][1]);//��¼r�����ֵ,����dpֻҪ���㵽r�Ϳ�����
	}
	
	//[*]maxr��������һ������,��k��maxr�����ʱ��,��l��rÿ����ֻ��һ�����,������dpҲ����ǰ׺��
	if(k>maxr) {
		for(int i=0;i<q;i++) {
			printf("%d\n",val[i][1]-val[i][0]+1);//r-l+1
		}
		return 0;
	}
	
	//dp[i][0]��ʾ��λ��i�ķ�����,�����һ������;dp[i][1]��ʾ��λ��i�ķ�����,�����һ������
	int dp[N][2];
	dp[0][0] = dp[0][1] = 0;
	//�ӳ�ʼλ����һ��(k)Ҳ�͵���kλ��,����֮ǰ��ֻ���߲��������ܵ���
	for(int i=0;i<k;i++) {
		dp[i][0] = 1;
		dp[i][1] = 0;
	}
	//��kλ�ÿ�����һ���ܵ���,Ҳ������һ�����߹�����
	dp[k][0] = 1;
	dp[k][1] = 1;
	//dp[i][0] = ��һ������+��һ������ �ķ�����
	//dp[i][1] = ��һ������ �ķ�����
	for(int i=k+1;i<=maxr;i++) {
		dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % MOD;
		dp[i][1] = dp[i-k][0];
	}
	
	//����Ҫ�����(dp[i][0]+dp[i][1])ʹi��l��r���,��Ϊ��ѯ�ܶ��,��ǰ׺��
	//����Ϊ��ʡ�ռ�,�������ӵ�dp[i][0]��ȥ
	for(int i=1;i<=maxr;i++) {
		dp[i][0] = (dp[i-1][0] + dp[i][0] + dp[i][1]) % MOD;
	}
	
	//��ÿ����ѯ������
	for(int i=0;i<q;i++) {
		//����ǰ׺��sum�����item(l)�ӵ�item(r)��ֵ,Ϊsum(r) - sum(l-1)
		int v = dp[val[i][1]][0]-dp[val[i][0]-1][0];
		if(v>=0)
			printf("%d\n",v);
		else
			printf("%d\n",(v+MOD)%MOD);
	}
	return 0;
}
