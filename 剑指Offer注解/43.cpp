#include<bits/stdc++.h>
using namespace std;

int NumberOf1(const char* strN);
int PowerBase10(unsigned int n);

//1~n��1���ֵĴ��� 
int NumberOf1Between1AndN(int n) {
	if(n <= 0)//����Ϸ��Լ�� 
		return 0;

	char strN[50];
	sprintf(strN, "%d", n);//���뵽�ַ����� 

	return NumberOf1(strN);//���õݹ麯����� 
}

//�ݹ麯��:�����ַ�(��)��strN��ʾ��n,��1~n�и�������λ1���ִ��� 
int NumberOf1(const char* strN) {
	//���벻�Ϸ����߿մ�ʱ,��û��1�� 
	if(!strN || *strN < '0' || *strN > '9' || *strN == '\0')
		return 0;//��0��1,��Ҳ��һ�ֵݹ���� 

	int first = *strN - '0';//��ͷ��һ������ 
	//static_cast<T>(���ʽ)�����ʽת��ΪT����, 
	unsigned int length = static_cast<unsigned int>(strlen(strN));

	if(length == 1 && first == 0)//����0 
		return 0;//��û��1 

	if(length == 1 && first > 0)//������0һλ���� 
		return 1;//��1������һ����0һλ���־���һ��1 

	/*����strN��"21345"*/
	/*[A]numFirstDigit������10000-19999�ĵ�һ��λ��1����Ŀ*/
	int numFirstDigit = 0;//��¼1���������λ�Ĵ��� 
	if(first > 1)//������λ����1
		//��ô�϶���������[1�������-1��0,1�������-1��9]����1�������-1��0������
		//��Щ���ֵ����λ���и�1,�����λ��10�ĳ���-1�η���1 
		numFirstDigit = PowerBase10(length - 1);
	else if(first == 1)//������λ��1 
		//��ô���λ��1������ֻ��ĩβ��һЩ,��10..0~���һ���� 
		numFirstDigit = atoi(strN + 1) + 1; //�������Ƕ��ټ���10..0��һ��1 

	/*[B]numOtherDigits��01346-21345���˵�һλ֮�����λ��1����Ŀ*/
	//����ʣ�µ�4λ��ʵ���ϻ������ܱ����е�4λ��
	//�������λfirst�Ǽ�,�����ܼ���.�����߸���������Ӿ���������������
	//���Ҷ��ں������λ��,���迼�ǵ�һλ��0������
	//��Ϊǰ���и����λfirst�ڹ���
	//��ÿ��һ��1���ֵĴ���,����ÿһλ��1,������������
	//ÿһλ��1һ��length-1λ,�����������ϼ�Ҫ����10^(length-2)
	//�������ǻ������ظ�������,��ÿ�����������λ�ϵ�1ֻ����һ��
	//������������ĿҪ�������λ����1���ܴ��� 
	int numOtherDigits = first * (length - 1) * PowerBase10(length - 2);
	/*[C]numRecursive��1-1345��1����Ŀ*/
	//������̼��ݹ��������,�����ȥ���λʣ�µĲ��ּ��� 
	int numRecursive = NumberOf1(strN + 1);
	//[A][B][C]�����ּ������������� 
	return numFirstDigit + numOtherDigits + numRecursive;
}

//��10��������n�η�
int PowerBase10(unsigned int n) {
	int result = 1;
	for(unsigned int i = 0; i < n; ++ i)//ֱ������n��10 
		result *= 10;
	return result;
}

int main() {
	cout<<NumberOf1Between1AndN(21345)<<endl;//18821
	return 0;
}
