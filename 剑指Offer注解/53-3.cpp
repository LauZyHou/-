#include<bits/stdc++.h>
using namespace std;

//Ѱ�ҳ���Ϊlength����������numbers��ĳ�����±���ȵ�Ԫ��
int GetNumberSameAsIndex(const int* numbers, int length) {
	if(numbers == nullptr || length <= 0)//����Ϸ���
		return -1;
	//�������ҵ�
	int left = 0;
	int right = length - 1;
	//����
	while(left <= right) {
		//���ֻ��ֵ�,��ʵ����(right+left)>>2
		//�Ҿ���������������д�������ƾ����ܱ��������right+leftԽ��
		int middle = left + ((right - left) >> 1);
		//�е���±����
		if(numbers[middle] == middle)
			return middle;//�ҵ�
		//�е�ֵ���±��
		if(numbers[middle] > middle)
			right = middle - 1;//������
		else//���±�С
			left = middle + 1;//������
	}
	return -1;//û�ҵ�
}


int main() {
	int numbers[] = { -3, -1, 1, 3, 5 };
	cout<<GetNumberSameAsIndex(numbers,sizeof(numbers)/sizeof(int))<<endl;//3
	return 0;
}
