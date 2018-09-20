#include<bits/stdc++.h>
#include "../Utilities/Array.h"
using namespace std;

//���볤Ϊn��input����,����С��k������д�볤Ϊk��output����
void GetLeastNumbers_Solution1(int* input, int n, int* output, int k) {
	//�ǿ�У��,ע��k�ǲ��ܴ���n��
	if(input == nullptr || output == nullptr || k > n || n <= 0 || k <= 0)
		return;
	//�ȴ�ͷ��β�������һ��
	int start = 0;
	int end = n - 1;
	int index = Partition(input, n, start, end);
	//�����ֵ���λ�ò��ǵ�k��λ��(��0��ʼ�±�k-1)
	while(index != k - 1) {
		if(index > k - 1) {//�������
			//������߼�����������
			end = index - 1;
			index = Partition(input, n, start, end);
		} else {//���С��
			//�����ұ߼�����������
			start = index + 1;
			index = Partition(input, n, start, end);
		}
	}
	//�����Ժ�,����ߵ�k�����־�����С��k������
	for(int i = 0; i < k; ++i)
		output[i] = input[i];
}

int main() {
	int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
	int out[4];
	GetLeastNumbers_Solution1(data,8,out,4);
	for(int i=0;i<4;i++)
		cout<<out[i]<<"\t";
	return 0;
}
