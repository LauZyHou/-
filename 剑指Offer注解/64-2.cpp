#include<bits/stdc++.h>
using namespace std;

class A;//��A������,��Ϊ�ڶ���֮ǰ��д�����������A*��������� 
A* Array[2];//������A���Ͷ���ָ������� 

class A {//�������A 
	public:
		//A�е�Sum����Ϊ�ݹ���ڵ��õĺ���
		virtual unsigned int Sum (unsigned int n) {
			return 0;
		}
};

class B: public A {//B����A�������,��override���Sum���� 
	public:
		//B�е�Sum����Ϊ�ݹ���õ�Sum 
		virtual unsigned int Sum (unsigned int n) {
			//��n��0ʱ,!!n==trueҲ��1;��nΪ0ʱ,!!n==falseҲ��0
			//���Եݹ���õ����n=0ʱ������Array[0]��Sum���� 
			return Array[!!n]->Sum(n-1) + n;
			//�麯������Ҫ�������������������֮�������̬��
			//��Ҫ�����ַ�����������������,��ʵҲû���õ���̬ 
		}
};

int Sum_Solution2(int n) {
	A a;
	B b;
	//��ʵ����ַ�󶨵������� 
	Array[0] = &a; 
	Array[1] = &b;

	//����B��Sum������ʼ 
	int value = Array[1]->Sum(n);

	return value;
}

int main() {
	cout<<Sum_Solution2(5)<<endl;//15
	return 0;
}
