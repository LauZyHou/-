#include<bits/stdc++.h>
using namespace std;

//�����small��big��stepΪ1������������
void PrintContinuousSequence(int small, int big) {
	for(int i = small; i <= big; ++ i)
		printf("%d ", i);
	printf("\n");
}

//Ѱ�Һ�Ϊsum��ȫ������������,������� 
void FindContinuousSequence(int sum) {
	if(sum < 3)//1+2����Ϊ3,С��3��û�� 
		return;

	int small = 1;//����ͷ���� 
	int big = 2;//����β���� 
	int middle = (1 + sum) / 2;//��ֹ����:small���ܳ������ֵ 
	int curSum = small + big;//���浱ǰ�����мӺ� 

	while(small < middle) {//��ֹ����small=middle
		//����"���к�̫С��"->"���к�ǡ��"ʱ,�������if���ж������ 
		if(curSum == sum)//�����ǰ�õ������кͺ�Ҫ�ҵ�һ�� 
			PrintContinuousSequence(small, big);//������� 

		//������к�̫���� 
		while(curSum > sum && small < middle) {
			//small��ǰ��,ͬ�����µ�ǰ���к� 
			curSum -= small;
			small ++;
			
			//����"���к�̫����"->"���к�ǡ��"ʱ,�������if���ж������
			//�ҵ���,������� 
			if(curSum == sum)
				PrintContinuousSequence(small, big);
		}

		//����,�����Ѿ��ҵ��������,Ҳ�������к�̫С��
		//�������������,��Ӧ����big������ 

		big ++;
		curSum += big;//ͬ�����µ�ǰ���к� 
	}
}

int main() {
	FindContinuousSequence(100);
	return 0;
}
