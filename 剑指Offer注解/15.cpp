#include<bits/stdc++.h>
using namespace std;

//�ܸ����Թٴ�����ϲ�Ľⷨ 
int NumberOf1_Solution2(int n) {
	int count = 0;//���� 
	//ѭ��ֱ������������1ȫû��,�ͱ��0���� 
	while (n) {
		++count;//��¼���1 
		n = (n - 1) & n;//ȥ��������ұߵ�1 
	}
	return count;
}

int main() {
	cout<<NumberOf1_Solution2(11)<<endl;
	return 0;
}

//����ⷨ
int NumberOf1_Solution1(int n) {
	int count = 0;//��1�ĸ���
	unsigned int flag = 1;//Ҫ����ĳһλ�Ƿ�Ϊ1�Ĳ���ֵ,��ʼ�������λ,������1
	//������û�г���������λ��
	while (flag) {
		//�ò���ֵ����������,���Բ�����Ӧ��λ
		if (n & flag)//����Ϊ1,��һλΪ1
			count++;//��¼֮
		flag = flag << 1;//����ֵ����
	}
	//ѭ���Ĵ����������������Ƶ�λ��,���Ƴ��������λ����Ȼ��0�˳�ѭ����
	return count;
}

//����������ѭ���Ľⷨ
int NumberOf1_Solution0(int n) {
	int count=0;//����
	//ֻҪn������0
	while(n) {
		if(n & 1)//���n��1����Ϊ1,�����λΪ1
			count++;//��¼һ��
		n=n>>1;//����һλ�����λ����
		//���Ǹ���ʱ,��Ȼ����߻Ჹ1,��ʱ���ͣ��������
	}
	return count;
}





