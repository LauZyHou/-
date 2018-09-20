#include<bits/stdc++.h>
using namespace std;

// ����:
//        numbers:     Ҫ���ҵ������׵�ַ
//        index1:      ���ҵ���ʼ�α�
//        index2:      ���ҵĽ����α�
// ����ֵ:
//        �ҵ�����С����
int MinInOrder(int* numbers, int index1, int index2) {
	int result = numbers[index1];//����ʼ�α괦��ʼ
	//���������α귶Χ
	for(int i = index1 + 1; i <= index2; ++i) {
		//������ֱȵ�ǰresult��С����
		if(result > numbers[i])
			result = numbers[i];//��¼֮
	}
	return result;//�����ҵ��ľ�����С�� 
}


// ����:
//        numbers:     ��ת��������׵�ַ
//        length:      ����ĳ���
// ����ֵ:
//        �ҵ�����С����
int Min(int* numbers, int length) {
	//����Ϸ���У��
	if(numbers == nullptr || length <= 0)
		throw new exception();

	int index1 = 0;//��ʼ���α�P1
	int index2 = length - 1;//��ʼ���α�P2
	int indexMid = index1;//indexMid���ս�ָ����������С����,��ʼ��Ϊһ����
	//���������ѭ��ǰ�ж�,������������е�һ����С�����һ����,�Ϳ���ֱ�ӷ��ص�һ����
	while(numbers[index1] >= numbers[index2]) {
		//[�ҵ���С��������]
		//���index1��index2ָ�����ڵ�������
		//��index1ָ���һ����������������һ������
		//index2ָ��ڶ���������ĵ�һ������,Ҳ���������е���С����
		if(index2 - index1 == 1) {
			indexMid = index2;//��¼��index2Ϊ����
			break;
		}

		//����±�Ϊindex1��index2��indexMidָ��������������
		//��ֻ��˳�����,��Ϊ�޷��жϸ�������һ��
		//����ȷ��һ������[index1,inedx2]����α�������
		indexMid = (index1 + index2) / 2;
		if(numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
			return MinInOrder(numbers, index1, index2);//����˳����ҵĽ��

		//��С���ҷ�Χ
		//����м�����С��P1��,˵���ֽ���ں���
		if(numbers[indexMid] >= numbers[index1])
			index1 = indexMid;//���Խ�P1����
		//����м�����С��P2��,˵���ֽ����ǰ����
		else if(numbers[indexMid] <= numbers[index2])
			index2 = indexMid;//���Խ�P2ǰ��
	}
	return numbers[indexMid];//����,�м�������Ƿֽ��,��Ϊ����
}

int main(){
	int array[] = { 3, 4, 5, 1, 2 };
	try{
		cout<<Min(array,5)<<endl;
	}catch(...){
		cerr<<"Invalid parameters"<<endl;
	}
	return 0;
}

