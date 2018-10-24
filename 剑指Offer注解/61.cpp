#include<bits/stdc++.h>
using namespace std;

//�Ƚ�����ָ�����ݵĴ�С 
int Compare(const void *arg1, const void *arg2) {
	//�ȽϽ���ת��intָ���ȡ���ݵĴ�С 
	return *(int*) arg1 - *(int*) arg2;
}

//���볤Ϊlength��numbers�����ʾ���˿���,�ж��ǲ���˳�� 
bool IsContinuous(int* numbers, int length) {
	if(numbers == nullptr || length < 1)//����Ϸ��� 
		return false;
	
	//�˿���������Щ��,����ʱ�临�Ӷ���O(1)�Ķ�������O(nlogn) 
	qsort(numbers, length, sizeof(int), Compare);

	int numberOfZero = 0;//��С������Ŀ 
	int numberOfGap = 0;//��ȱ��Ŀ 

	//ͳ��������0�ĸ���
	for(int i = 0; i < length && numbers[i] == 0; ++i)
		++numberOfZero;

	//ͳ�������еļ����Ŀ
	int small = numberOfZero;//��ʼ��Ϊ��һ������ַ 
	int big = small + 1;//��ʼ��Ϊ���ڵĵڶ�������ַ 
	while(big < length) {//big=lengthʱͳ�Ƶ������һ�� 
		//���������,�ж���,��������˳��
		if(numbers[small] == numbers[big])
			return false;
		//��ȱ��+=�������������ֲ�-1,����(1,4)֮����������(2,3) 
		numberOfGap += numbers[big] - numbers[small] - 1;
		//��ǰ��һ��,��һ�� 
		small = big;
		++big;
	}
	//����,˵��û�ж���
	//�����ȱ����������0���������ܱ�����,��˳�� 
	return (numberOfGap > numberOfZero) ? false : true;
}

int main() {
	int numbers[] = { 1, 3, 0, 5, 0 };
	cout<<boolalpha<<IsContinuous(numbers,sizeof(numbers)/sizeof(int))<<endl;//true 
	return 0;
}
