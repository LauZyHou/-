#include<bits/stdc++.h>
using namespace std;

//���鳤Ϊlength��������������numbers,����ȱʧ������
//����Ӧ��ע��length������Ŀ�е�n-1
//��Ϊn������ȱ��1��ֻʣn-1��,ʵ�ʶ���Ͷ���n-1�������Ƕ���n�� 
int GetMissingNumber(const int* numbers, int length) {
	//����Ϸ��Լ�� 
	if(numbers == nullptr || length <= 0)
		return -1;

	int left = 0;//���ֲ�����λ�� 
	int right = length - 1;//���ֲ�����λ�� 
	while(left <= right) {//û�ҵ�ʱ��>�� 
		int middle = (right + left) >> 1;//�����е� 
		if(numbers[middle] != middle) {//������±겻ͬ
			//�±���0,��ȱ0
			//�±겻��0,�����һ�����ǲ��Ǻ������±���� 
			if(middle == 0 || numbers[middle - 1] == middle - 1)
				return middle;//�����,��ǰ�±����ȱ���Ǹ��� 
			right = middle - 1;//����,������ 
		} else//�е���±���ͬ 
			left = middle + 1;//������ 
	}

	//�ر�ע��,��ȱ���Ǹ�������n-1��ʱ��,�����ѭ���Ҳ���
	//һֱ������,����ҵ�left=length����right=length-1����ѭ�� 
	if(left == length)
		//�ر�ע��length����n-1,length-1�ɾ���n-2�� 
		return length; 

	//��Ч������,�������鲻�ǰ�Ҫ�������
	//���������ֲ���0��n-1��Χ֮��
	return -1;
}


int main() {
	int numbers[]={0,1,2,3,5,6,7};
	cout<<GetMissingNumber(numbers,7)<<endl;//4
	return 0;
}
