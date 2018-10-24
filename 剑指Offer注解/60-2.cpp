#include<bits/stdc++.h>
using namespace std;

int g_maxValue = 6;//�������� 

void PrintProbability_Solution2(int number) {
	if(number < 1)//����������1�� 
		return;

	int* pProbabilities[2];//��������
	//����ռ� 
	pProbabilities[0] = new int[g_maxValue * number + 1];
	pProbabilities[1] = new int[g_maxValue * number + 1];
	//ȫ����ʼ��Ϊ0 
	for(int i = 0; i < g_maxValue * number + 1; ++i) {
		pProbabilities[0][i] = 0;
		pProbabilities[1][i] = 0;
	}
	
	//��ʶҪ����������͸�����׼����,��һ������������ĵ�λ�ͽ�����
	int flag = 0; 
	//һ��ʼֻ��һ������,��0�������м�¼�鵽1~6��Ƶ������1 
	for (int i = 1; i <= g_maxValue; ++i)
		pProbabilities[flag][i] = 1;

	//��������2�����ӵ�number������ 
	for (int k = 2; k <= number; ++k) {
		//k��������С��k,����С��k�Ķ�����Ϊ0 
		for(int i = 0; i < k; ++i)
			pProbabilities[1 - flag][i] = 0;
		//��������k��6k���ǿ��ܳ��ֵ� 
		for (int i = k; i <= g_maxValue * k; ++i) {
			pProbabilities[1 - flag][i] = 0;//�����Ϊ0
			//����������i=3,��γ���3=�ϴγ���2���ϴγ���1��
			//����������i=50,��γ���50=�ϴγ���49~44��
			//����������Ҫע��i��������С��ʱ����ʵ��������i�� 
			for(int j = 1; j <= i && j <= g_maxValue; ++j)//������ʵӦ��дj<i������j<=i,����p[flag][0]��0Ҳ��Ӱ�� 
				pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];//�������� 
		}

		flag = 1 - flag;//��ʶ��ת,���´�ѭ�������������ɫ��ת 
	}

	double total = pow((double)g_maxValue, number);//6����6^n����� 
	for(int i = number; i <= g_maxValue * number; ++i) {//�������п�������Ƶ�� 
		//�������,����ֱ����flag��Ϊ���һ��for���һ��ʹflag�Ѿ���ת�� 
		double ratio = (double)pProbabilities[flag][i] / total; 
		printf("%d: %e\n", i, ratio);
	}

	delete[] pProbabilities[0];
	delete[] pProbabilities[1];
}

int main() {
	PrintProbability_Solution2(3);
	return 0;
}
