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
	
	int f_i=0;//�����ϴ�ѭ����f[i-1],Ҳ�����ѭ����f[i]
	//f[i]����˼���Ե�i�����ֽ�β������������� 
	
	int max_f_i=0x80000000;//����f[i]��������,��һ�����Ľ��� 
	
	for(int i=0;i<nLength;i++){
		if(f_i<=0)//���f[i-1]�Ǹ���,����Ϊf[i]��������
			f_i=pData[i];//��ǰf[i]�ʹӵ�ǰλ�ÿ�ʼ��ǰλ�ý����������� 
		else//���������,��ôf[i]�϶�Ҫ��������
			f_i=f_i+pData[i];//�����͵�ǰ������������������f[i] 
		if(f_i>max_f_i)//����ҵ��˸����f[i]
			max_f_i=f_i;
	}

	return max_f_i;//����f[i]�������� 
}

int main() {
	int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
	cout<<FindGreatestSumOfSubArray(data,sizeof(data)/sizeof(int));
	return 0;
}
