#include<bits/stdc++.h>
using namespace std;

//������������һά������ʽ,����,����,��Ӿ������ܻ�ȡ����������ֵ
int getMaxValue_solution(const int* values, int rows, int cols) {
	if(values == nullptr || rows <= 0 || cols <= 0)//����Ϸ��Լ��
		return 0;

	//��·����:0~j-1=>f(i,0)~f(i,j-1);j~cols=>f(i-1,j)~f(i-1,cols-1)
	int* maxValues = new int[cols];
	for(int i = 0; i < rows; ++i) {//ÿһ��
		for(int j = 0; j < cols; ++j) {//���ڴ�����
			int left = 0;//��ߵ������ֵ
			int up = 0;//�ϱߵ������ֵ

			if(i > 0)//i>0ʱ�ϱ��������
				up = maxValues[j];//f(i-1,j)����mV[j]λ��

			if(j > 0)//j>0ʱ����������
				left = maxValues[j - 1];//f(i,j-1)����mV[j-1]λ��

			//��ǰλ�õ���������ֵ=��ߺ��ϱ��д��ֵ��һ��+��ǰλ�ü�ֵ
			maxValues[j] = max(left, up) + values[i * cols + j];
		}
	}

	//�����������������,���½�λ�õ�����ֵ�Ǹ���������Ԫ��
	int maxValue = maxValues[cols - 1];

	delete[] maxValues;

	return maxValue;
}

int main() {
	int values[][4] = {
		{ 1, 10, 3, 8 },
		{ 12, 2, 9, 6 },
		{ 5, 7, 4, 11 },
		{ 3, 7, 16, 5 }
	};
	
	cout<<getMaxValue_solution((int *)(values),4,4)<<endl;

	return 0;
}
