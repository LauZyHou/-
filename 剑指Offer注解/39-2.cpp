#include<bits/stdc++.h>
using namespace std;

//====================����2====================
int MoreThanHalfNum_Solution2(int* numbers, int length) {
	if(CheckInvalidArray(numbers, length))//�������Ϸ��� 
		return 0;

	int result = numbers[0];//����һ��ʼ�ǵ�һ������ 
	int times = 1;//������1
	//����ʣ�µ�������ս�� 
	for(int i = 1; i < length; ++i) {
		if(times == 0) {//�����������0��
			result = numbers[i];//���µ���ս����ֱ̨�ӵ�����
			times = 1;//����̨�����϶���1 
		} else if(numbers[i] == result)//���������ͬ��(����һ��) 
			times++;//����+1,�൱�ڸ�������HP 
		else//�����ͬ��(���ֲ�һ��) 
			times--;//��һ��,�൱��������1HP���1HP����ս�� 
	}

	//���ռ��һ���ҵ��������ǲ���ȷʵ����һ�� 
	if(!CheckMoreThanHalf(numbers, length, result))
		result = 0;

	return result;
}

int main() {



	return 0;
}
