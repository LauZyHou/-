#include<bits/stdc++.h>
using namespace std;

//���庯��ָ������,��������Ϊfun,������������ı������Ǻ���ָ��
//��������ָ��ĺ�����,����ֵΪunsigned int,�βα�Ϊ(unsigned int)
typedef unsigned int (*fun)(unsigned int);

unsigned int Solution3_Teminator(unsigned int n) {//�ݹ���ڵĺ��� 
	return 0;
}

unsigned int Sum_Solution3(unsigned int n) {//�ݹ麯��
	//����fun���͵ĺ���ָ������f,������������������ĺ���ָ�� 
	static fun f[2] = {Solution3_Teminator, Sum_Solution3};
	return n + f[!!n](n - 1);//�͵ڶ��ֽⷨһ�������� 
}

int main() {
	cout<<Sum_Solution3(5)<<endl;//15
	return 0;
}
