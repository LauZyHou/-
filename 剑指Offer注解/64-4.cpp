#include<bits/stdc++.h>
using namespace std;

//����������nʱ,Sum_Solution4<n>::N���û�ж���
//�������Ҫ�����ö����N = Sum_Solution4<n - 1>::N + n��Ȼ��ݹ���� 
template<unsigned int n> struct Sum_Solution4 {
	enum Value { N = Sum_Solution4<n - 1>::N + n};//ֱ��n-1Ϊ1ʱ��ֱ���ҵ������Sum_Solution4<1> 
};

template<> struct Sum_Solution4<1> {//�������ݹ�ĳ���
	//enum ö�������� {ö�ٱ�};
	enum Value { N = 1};
};

//����û�����,�����Sum_Solution4<0>�͵ò���
//���Ե��������������ֵ
template<> struct Sum_Solution4<0> { 
	enum Value { N = 0};
};


int main() {
	//ȡ���е�ö����N 
	cout<<Sum_Solution4<5>::N<<endl;//15
	return 0;
}
