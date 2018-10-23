#include<bits/stdc++.h>
using namespace std;

//�ж�����num�ĵ�indexBitλ�ǲ���1
bool IsBit1(int num, unsigned int indexBit) {
	num = num >> indexBit;//indexBit��0��ʼ����,����indexBitʹ�������λ
	return (num & 1);//�����λ1���뼴��
}

//�ҵ�num���ұ������һ����1��λ
unsigned int FindFirstBitIs1(int num) {
	int indexBit = 0;//����(������Ҫ����λ)
	//��ǰ���λ��0,��Ҫ����λ��û�г�������λ��8x�ֽ���
	while(((num & 1) == 0) && (indexBit < 8 * sizeof(int))) {
		num = num >> 1;//����1λʹ��һλ��Ϊ���λ
		++indexBit;//�´�ѭ��Ҫ����λ
	}
	return indexBit;//�����λ������,���û�ҵ��Ǿ���8*sizeof(int)
}

//�ڶ�����������������ֻ����һ�ε�����,�������������ָʾ���ڴ�ռ�
void FindNumsAppearOnce(int data[], int length, int* num1, int* num2) {
	if(data == nullptr || length < 2)//����Ϸ��Լ��,����Ӧ��2������
		return;

	int resultExclusiveOR = 0;//���ܵ������,ע���ʼ����0���ں͵�һ�����ʱʹ�䲻��
	for(int i = 0; i < length; ++i)
		resultExclusiveOR ^= data[i];//������^�������

	//�ڽ��������͵���1����һλ,���ش�0��ʼ������λ��
	unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

	*num1 = *num2 = 0;//�������ֽ����ոո��ҵ�����һλ������
	for(int j = 0; j < length; ++j) {//�ٴα��������е�ÿ����
		if(IsBit1(data[j], indexOf1))//������������һλ��1
			*num1 ^= data[j];//�ͽ��������򵽵�һ��������
		else//��֮,���߼���������һ��������
			*num2 ^= data[j];//�����һ��������
	}
}

int main() {
	int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	int n1,n2;
	FindNumsAppearOnce(data,sizeof(data)/sizeof(int),&n1,&n2);
	cout<<n1<<","<<n2<<endl;//6,4
	return 0;
}
