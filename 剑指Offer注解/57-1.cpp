#include<bits/stdc++.h>
using namespace std;

//�ڳ�Ϊlength��data�������Һ�Ϊsum��һ������,����*num1��*num2��,�ҵ�����true 
bool FindNumbersWithSum(int data[], int length, int sum,
                        int* num1, int* num2) {
	bool found = false;//ָʾ�Ƿ��ҵ� 
	if(length < 1 || num1 == nullptr || num2 == nullptr)//����Ϸ��Լ�� 
		return found;

	int ahead = length - 1;//�ұߵ��α� 
	int behind = 0;//��ߵ��α� 

	while(ahead > behind) {//�α껹δ����,���Լ����� 
		long long curSum = data[ahead] + data[behind];//�Ӻ�,int+int�������������long long 

		if(curSum == sum) {//������������ȼ��ҵ��� 
			//������д��ȥ 
			*num1 = data[behind];
			*num2 = data[ahead];
			found = true;//ָʾ�ҵ��� 
			break;//����ѭ�� 
		} else if(curSum > sum)//̫���� 
			ahead --;//�ұ��α����� 
		else//̫С�� 
			behind ++;//����α����� 
	}
	return found;//ָʾ��û�ҵ� 
}


int main() {
	int data[] = {1, 2, 4, 7, 11, 15};
	int n1,n2;
	if(FindNumbersWithSum(data,sizeof(data)/sizeof(int),15,&n1,&n2))
		cout<<n1<<","<<n2<<endl;//4,11
	return 0;
}
