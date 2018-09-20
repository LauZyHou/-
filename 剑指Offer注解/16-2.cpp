#include<bits/stdc++.h>
using namespace std;

bool g_InvalidInput = false;//��ʶ�����ȫ�ֱ���,����ʱ��Ϊtrue
bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);

// ����:
//        base:      ����
//        exponent:  ָ��
// ����ֵ:
//        base��exponent����
double Power(double base, int exponent) {
	g_InvalidInput = false;
	//�����0�ĸ�������,��Ϊ0��������ĸ,���Գ���
	if (equal(base, 0.0) && exponent < 0) {
		g_InvalidInput = true;//��ǳ���
		return 0.0;
	}

	//ȡָ���ľ���ֵ
	unsigned int absExponent = (unsigned int) (exponent);
	if (exponent < 0)
		absExponent = (unsigned int) (-exponent);
	//���ü�����ָ�����ݵķ���
	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)//ָ�������Ǹ���
		result = 1.0 / result;//��ôҪȡ������
	return result;
}

// ����:
//        base:      ����
//        exponent:  ��ָ��
// ����ֵ:
//        base��exponent����
double PowerWithUnsignedExponent(double base, unsigned int exponent) {
	if (exponent == 0)
		return 1;//�κ�����0����Ϊ1
	if (exponent == 1)
		return base;//�κ�����1����Ϊ�䱾��

	//������:�ݹ�����������ָ����һ��Ĵ���
	double result = PowerWithUnsignedExponent(base, exponent >> 1);
	result *= result;//������һ����ݳ������͵õ���������
	if ((exponent & 0x1) == 1)//������λ��1,��Ϊ����
		result *= base;//��7/2=3,3*3=6����һ��base,��������
	return result;
}

//��������������,ֻҪ���ǵĲ�ֵ�㹻С�����ж�Ϊ���,�����Ƿ���� 
bool equal(double num1, double num2) {
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

int main(){
	cout<<Power(2,3)<<endl;
	cout<<Power(-2,-3)<<endl;
	return 0;
}
