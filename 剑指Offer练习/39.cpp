#include<bits/stdc++.h>
#include "../Utilities/Array.h"
using namespace std;

//ȫ�ֱ���,����ָʾ�Ƿ����
bool g_bInputInvalid = false;

//��������Ƿ�Ϸ�
bool CheckInvalidArray(int* numbers, int length) {
	g_bInputInvalid = false;
	if(numbers == nullptr && length <= 0)//���鲻�Ϸ�ʱ
		g_bInputInvalid = true;//ͬ�������ȫ�ֱ���������ָʾ

	return g_bInputInvalid;
}

//ȷ��number�ڳ�Ϊlength��numbers�������Ƿ񳬹�һ��
bool CheckMoreThanHalf(int* numbers, int length, int number) {
	//ͳ��number�������г��ֵĴ���
	int times = 0;
	for(int i = 0; i < length; ++i) {
		if(numbers[i] == number)
			times++;
	}

	bool isMoreThanHalf = true;
	//���û�г���һ��
	if(times * 2 <= length) {
		g_bInputInvalid = true;//��ȫ�ֱ���������ָʾ
		isMoreThanHalf = false;
	}

	return isMoreThanHalf;
}

//�����������ֵ���д��һ����������Ժͷ�������,������������ظ����� 

//====================����1====================
int MoreThanHalfNum_Solution1(int* numbers, int length) {
	if(CheckInvalidArray(numbers, length))
		return 0;
	//���ȵ�һ��,������λ�����ֵ�λ�� 
	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	//�������һ��,���ػ��ֺ������λ�� 
	int index = Partition(numbers, length, start, end);
	cout<<"����λ����"<<index<<",ֵ��"<<numbers[index]<<endl;
	//ֻҪ���ֺ�����λ��λ��,��һֱѭ��
	//ע��:���Partitionÿ�λ��ֽ�>=���Ķ������ұ�
	//�����ұߵ���������ܶ�,�ر��������������ִ���һ�����ֵ���������� 
	//�����ں����ĵݹ���,�������Ҳ��ȫ������
	//�������һ��ÿ�λ��ֵ�λ�ÿ�һ�������е���Ĳ��ҷ�ʽ���� 
	while(index != middle) {
		if(index > middle) {//�������λ���� 
			end = index - 1;//�ͼ���������� 
			index = Partition(numbers, length, start, end);
			cout<<"����λ����"<<index<<",ֵ��"<<numbers[index]<<endl;
		} else {//�������λ��С 
			start = index + 1;//�ͼ������ұ��� 
			index = Partition(numbers, length, start, end);
			cout<<"����λ����"<<index<<",ֵ��"<<numbers[index]<<endl;
		}
	}

	int result = numbers[middle];//���ս�����ǻ������м�λ��ʱ(��λ��)
	//���Ҫ���һ���ǲ���ȷʵ����һ��,��O(n)ʱ�䲻������ʱ�临�Ӷ� 
	if(!CheckMoreThanHalf(numbers, length, result))
		result = 0;
	return result;
}

int main() {
	int numbers[]={1,2,3,2,2,2,2,2,2,2,2,2,5,4,2};
	MoreThanHalfNum_Solution1(numbers,15);
	return 0;
}
