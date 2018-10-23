#include<bits/stdc++.h>
using namespace std;

//����������������ֻ����һ�ε�һ������ 
int FindNumberAppearingOnce(int numbers[], int length) {
	if(numbers == nullptr || length <= 0)//����Ϸ��� 
		throw new exception();

	int bitSum[32] = {0};//4�ֽ�32λint,��32�������鰴λ��֮��ÿһλ����� 
	
	//ע��,���ﰴ���ߵ�д���Ƿ��������,�е���
	//��bit[31]��ʵ�����bitλ�ĵ�ֵ��ӵĽ��
	//����ڴ�ĽǶȿ�Ҳ�������...
	//��֮�����±�ߵĴ���������ĵ�λ�Ӻ� 
	
	for(int i = 0; i < length; ++i) {//������������ 
		int bitMask = 1;//��������,����ȡint���ض�λ�õ�bitֵ 
		for(int j = 31; j >= 0; --j) {
			int bit = numbers[i] & bitMask;//ȡ��һλ��ֵ 
			if(bit != 0)//�����1 
				bitSum[j] += 1;//�������ж�Ӧλ��+1 
			bitMask = bitMask << 1;//��������һλ,�´�ѭ��Ҫȡ��һλ��ֵ 
		}
	}

	int result = 0;//���ս��,�Ƚ�����λ����0 
	for(int i = 0; i < 32; ++i) {//�Ӹ�λ���λ�� 
		result = result << 1;//����,֮�����λ��Ҫ��������õ�λ 
		result += bitSum[i] % 3;//�����3�ı�����+0,����+1 
	}

	return result;
}

int main() {
	int numbers[] = { 1024, -1025, 1024, -1025, 1024, -1025, 1023 };
	cout<<FindNumberAppearingOnce(numbers,sizeof(numbers)/sizeof(int))<<endl;//1023
	return 0;
}
