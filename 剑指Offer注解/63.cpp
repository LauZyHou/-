#include<bits/stdc++.h>
using namespace std;

//�ڳ�Ϊlength��numbers�����������Ե�����ֵ 
int MaxDiff(const int* numbers, unsigned length) {
	//������2��������̸����ֵ
	if(numbers == nullptr || length < 2)//����:����Ӧ��||������&&��ϵ 
		return 0;

	int min = numbers[0];//min����������С����,�����ʼ��Ϊ��һ������
	
	//ע��,��ȥ��¼�������,���Ǽ�¼��ֵ
	//Ҫ����ǲ�ֵ���,���������Ҳ��������С���ֵ����
	//ͬ����,�����ֵ��ȫ���ܺ���С�������һ����ռ
	//�������¼ǰ����������С,��Ϊ�˷���������ĳ������β������ֵ 
	//������������Щ"ĳ������β������ֵ"������һ�� 
	int maxDiff = numbers[1] - min;//������ֵ,��ʼ��Ϊǰ��������ֵ 

	for(int i = 2; i < length; ++i) {//��2�����ֿ�ʼһֱ����� 
		//ÿ��ȡ��ǰһ�����ֺ���С�Ƚϲ�����,���һ����û����Ϊ����� 
		if(numbers[i - 1] < min) 
			min = numbers[i - 1];//������С 

		int currentDiff = numbers[i] - min;//��ǰ���ֺ�ǰ�����С�Ĳ�ֵ 
		if(currentDiff > maxDiff)//������ָ����ֵ 
			maxDiff = currentDiff;//���²�ֵ 
	}
	//������һ�������,�͵õ�������ֵ 
	return maxDiff;
}

int main() {
	int numbers[] = { 4, 1, 3, 2, 5 };
	cout<<MaxDiff(numbers,sizeof(numbers)/sizeof(int))<<endl;//4
	return 0;
}
