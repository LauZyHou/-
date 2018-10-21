#include<bits/stdc++.h>
using namespace std;

// ����:
//        data:        һ�������������������
//        length:      ����ĳ���
//        k:           ҪѰ�ҵ����� 
//        start:       (��)������ʼλ���±� 
//        end:         (��)�������λ���±� 

//�ҵ������е�һ��k���±�,��������в�����k,����-1
int GetFirstK(const int* data, int length, int k, int start, int end) {
	if(start > end)
		return -1;

	int middleIndex = (start + end) / 2;//���ֲ���,�ָ�� 
	int middleData = data[middleIndex];//�ָ�㴦��ֵ 

	if(middleData == k) {//�ָ�㴦ֵ��k
		//�ָ�㲻��0,��ô��ǰ��һ�������������k,�����ǵ�һ��k 
		//�ָ����0��һ���ǵ�һ��k 
		if((middleIndex > 0 && data[middleIndex - 1] != k)
		        || middleIndex == 0)
			return middleIndex;//�ҵ��˵�һ��k 
		else//�����ǵ�һ��k,��һ��kһ��������� 
			end  = middleIndex - 1;
	} else if(middleData > k)//�ָ�㴦ֵ��k�� 
		end = middleIndex - 1;//��������,k���������һ������� 
	else//�ָ�㴦��kС 
		start = middleIndex + 1;//��������,k���������һ�����ұ� 
	
	//��������˵����û�ҵ���һ��k,�ݹ���ö��ֲ��� 
	return GetFirstK(data, length, k, start, end); 
}

//�ҵ����������һ��k���±�,��������в�����k,����-1
//GetLastK��GetFirstK��˼·һ�� 
int GetLastK(const int* data, int length, int k, int start, int end) {
	if(start > end)
		return -1;

	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];

	if(middleData == k) {//�ָ�㴦ֵ��k
		//�ָ�㲻��length-1(���һ����),��ô������ĵ�Ҫ����k���������һ��
		//�ָ����length-1,�����Ѿ�û��,��һ�������һ��k 
		if((middleIndex < length - 1 && data[middleIndex + 1] != k)
		        || middleIndex == length - 1)
			return middleIndex;
		else
			start  = middleIndex + 1;
	} else if(middleData < k)
		start = middleIndex + 1;
	else
		end = middleIndex - 1;

	return GetLastK(data, length, k, start, end);
}

//�ڳ�Ϊlength������data�����м���k���ֵĴ��� 
int GetNumberOfK(const int* data, int length, int k) {
	int number = 0;//�Ҳ�������0�� 

	if(data != nullptr && length > 0) {//����Ϸ��Լ�� 
		//�ҵ�һ��k���±�����һ��k���±� 
		int first = GetFirstK(data, length, k, 0, length - 1);
		int last = GetLastK(data, length, k, 0, length - 1);

		//����-1��֤ʵk�Ĵ�����,ʵ��������������ֻҪ��һ��������һ��һ������
		//��ΪֻҪ"��һ��k"����,��"���һ��k"һ������ 
		if(first > -1 && last > -1)
			number = last - first + 1;//����k֮��ȫ��k,��Ϊ�������������� 
	}

	return number;
}

int main() {
	int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
	cout<<GetNumberOfK(data,sizeof(data)/sizeof(int),3)<<endl;//4
	return 0;
}
