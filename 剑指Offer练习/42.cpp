#include<bits/stdc++.h>
using namespace std;

bool g_InvalidInput = false;//ָʾ�Ƿ�����ȫ�ֱ��� 

//������������鳤��,������������������� 
int FindGreatestSumOfSubArray(int *pData, int nLength) {
	//����Ϸ��Լ�� 
	if((pData == nullptr) || (nLength <= 0)) {
		g_InvalidInput = true;
		return 0;
	}
	
	//���û����,���ﻹ�Ǳ������ߵ�д�� 
	g_InvalidInput = false;

	int nCurSum = 0;//�ۼӵ�������� 
	//��Сint��,��-(2^31),�ñ�����¼�������˲�������� 
	int nGreatestSum = 0x80000000;
	//���������е�ÿ��Ԫ�� 
	for(int i = 0; i < nLength; ++i) {
		if(nCurSum <= 0)//���֮ǰ�ۼӵĺ��Ƿ����� 
			nCurSum = pData[i];//������֮ǰ��,���������������ʼ�ۼ� 
		else//���֮ǰ�ۼӵĺ�������,�ǻ����ܶԺ����л������� 
			nCurSum += pData[i];//�ǰ���εĺͼ����� 

		if(nCurSum > nGreatestSum)//����ҵ��˸���ĺ� 
			nGreatestSum = nCurSum;//�滻�� 
	}

	return nGreatestSum;
}


int main() {
	int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
	cout<<FindGreatestSumOfSubArray(data,sizeof(data)/sizeof(int));
	return 0;
}
