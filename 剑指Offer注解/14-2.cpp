#include<bits/stdc++.h>
using namespace std;

//�������ӵĳ���,������˻� 
int maxProductAfterCutting_solution2(int length) {
	if(length < 2)//��ΪҪ�󳤶�n>1,�������ﷵ��0��ʾ����Ƿ� 
		return 0;
	if(length == 2)//����Ϊ2ʱ,��ΪҪ����¶���m>1,���������1x1=1 
		return 1;
	if(length == 3)//����Ϊ3ʱ,��ΪҪ����¶���m>1,���������1x2=2 
		return 2;

	//�����ܶ�ؼ�ȥ����Ϊ3�����Ӷ�,�����Ǽ���һ���ܼ������ٸ�3 
	int timesOf3 = length / 3;

	//���������ʣ�µĳ���Ϊ4��ʱ��,�����ټ�ȥ����Ϊ3�����ӶΡ�
	//��ʱ���õķ����ǰ����Ӽ��ɳ���Ϊ2������,��Ϊ2*2>3*1��
	if(length - timesOf3 * 3 == 1)//������ֻʣһ��1 
		timesOf3 -= 1;//��Ҫ����һ��3 

	//��֤ʣ�µ�һ����4����2����0,����һ���ܼ�������2��(ֻ��2/1/0�������) 
	int timesOf2 = (length - timesOf3 * 3) / 2;
	
	//3�Ķ��ٸ�3����,�ٳ���2�Ķ��ٸ�2����,����̰��ѡ������Ž� 
	return (int) (pow(3, timesOf3)) * (int) (pow(2, timesOf2));
}

int main(){
	cout<<maxProductAfterCutting_solution2(9)<<endl;
	return 0;
}
