#include<bits/stdc++.h>
using namespace std;

int g_maxValue = 6;//�������� 

//�ݹ麯��:�ݹ����ÿ���ó�һ������,������֧,����Ƶ������ 
// ����:
//        original:       �������� 
//        current:        ��ǰδ����������� 
//        sum:            ǰ����Ѿ�����õ��������ܺ�
//        pProbabilities: Ҫ���µ�Ƶ������ 
void Probability(int original, int current, int sum,
                 int* pProbabilities) {
	if(current == 0) {//�ݹ����:��������Ѿ�������� 
		pProbabilities[sum - original]++;//����Ƶ������,����Ӧλ�ô�+1 
	} else {//�����ʣ������� 
		for(int i = 1; i <= g_maxValue; ++i) {//���ó�һ������,�����ÿ��ȡֵ
			//�ݹ�����Ը���Ƶ������,ÿ����֧�е�ǰ��������ȥ�������
			//���������Ǿֲ��Զ�����,���Ը���Ϊ��ǰ����+֮ǰ����ĵ����� 
			Probability(original, current - 1, i + sum, pProbabilities);
		}
	}
}

//�ݹ�����
//����number�����ӳ��ϵ����͵����п���ֵ���ֵĸ���,������pProbabilities������
void Probability(int number, int* pProbabilities) {
	for(int i = 1; i <= g_maxValue; ++i)//�Ե�һ�����ӵ�g_maxValue��ȡֵ 
		Probability(number, number-1, i, pProbabilities);//�ֱ���õݹ麯��ȥ����Ƶ������ 
}

//��ӡnumber�����ӳ��ϵ����͵����п���ֵ���ֵĸ��� 
void PrintProbability_Solution1(int number) {
	if(number < 1)//����1������ 
		return;

	int maxSum = number * g_maxValue;//���ܳ��ֵ������� 
	int* pProbabilities = new int[maxSum - number + 1];//������number~maxSum,�������鳤n-m+1 
	for(int i = number; i <= maxSum; ++i)
		pProbabilities[i - number] = 0;//�ܵ���Ϊi��Ƶ���ᱣ����i-number�� 

	//����number�����ӳ��ϵ����͵����п���ֵ���ֵĸ���,������pProbabilities������ 
	Probability(number, pProbabilities);

	int total = pow((double)g_maxValue, number);//n�����ӵ����е�����������Ϊg_maxValue��n�η� 
	for(int i = number; i <= maxSum; ++i) {//��ÿ�����ܵĵ��� 
		double ratio = (double)pProbabilities[i - number] / total;//�������=Ƶ��/���� 
		printf("%d: %e\n", i, ratio);//��ӡ 
	}
	delete[] pProbabilities;//���ٶѿռ��Ƶ������ 
}

int main() {
	PrintProbability_Solution1(3);
	return 0;
}
