#include<bits/stdc++.h>
using namespace std;

int LastRemaining_Solution2(unsigned int n, unsigned int m) {
	if(n < 1 || m < 1)//����Ϸ��� 
		return -1;
	
	//�൱�����ϵ�f(n,m)
	//��n=1ʱ��Ϊֻ��һ������0,û�ж�����ɾ���Ծ���0 
	int last = 0;
	for (int i = 2; i <= n; i ++)//n��2��ʼһֱ�������n 
		last = (last + m) % i;//�µ�f(n,m)=(�ɵ�f(n,m)+m)%n

	return last;
}

int main() {
	cout<<LastRemaining_Solution2(4000,997)<<endl;//1027
	return 0;
}
