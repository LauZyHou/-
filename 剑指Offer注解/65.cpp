#include<bits/stdc++.h>
using namespace std;

//���������������ӷ� 
int Add(int num1, int num2) {
	int sum, carry;//�ֱ��ʾ:�����ǽ�λ�ļӺ�,��λ 
	do {
		sum = num1 ^ num2;//��ǰ�����ֱ���ö�������� 
		carry = (num1 & num2) << 1;//�������������һλ 
		
		//�ֱ�浽num1��num2��,��Ϊ�´�ѭ�����ľ���sum��carry����� 
		num1 = sum;
		num2 = carry;
	} while(num2 != 0);//ֱ��num2Ҳ����carry��λ��0Ϊֹ 

	return num1;//��ʱ����Ѿ������,��num1��sum���� 
}

int main() {
	cout<<Add(130,1888)<<endl;//2018
	return 0;
}
