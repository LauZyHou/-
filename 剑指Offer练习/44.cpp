#include<bits/stdc++.h>
using namespace std;

int countOfIntegers(int digits);
int digitAtIndex(int index, int digits);
int beginNumber(int digits);

//����λ��index,�������������ҳ���index���ֲ����� 
int digitAtIndex(int index) {
	if(index < 0)//����Ϸ��Լ�� 
		return -1;

	int digits = 1;//��ǰ��һ������λ��,��ʼ��1λ�� 
	while(true) {
		int numbers = countOfIntegers(digits);//����digitsλ�����ж��ٸ� 
		if(index < numbers * digits)//���ʣ�µ�index�������������ֺ�
			//��ô����digitsλһ������ֺ������indexλ
			return digitAtIndex(index, digits);//���ú���Ѱ�Ҳ����� 
		//��������,û����if,˵���Ѿ��߳����������ֺ� 
		index -= digits * numbers;//��ʣindex=ԭindex-�������ֺ���������Ŀ 
		digits++;//���ּ���λ��+1
	}
	//�����޷����е�����,��Ϊ������int����ֵ 
	return -1;
}

//����digitsλһ������ֺ����ж������� 
int countOfIntegers(int digits) {
	if(digits == 1)//һλ����10�� 
		return 10;
	//��λ����99-10+1=90��;��λ����999-100+1=900��;��λ����9000��... 
	int count = (int) pow(10, digits - 1);
	return 9 * count;//��9*10^(digits-1)������ 
}

//���㷵��digitsλһ������ֺ������indexλ
int digitAtIndex(int index, int digits) {
	//�ȴ���ʼ���ֿ�ʼ,�����index/digits����ʵ������
	int number = beginNumber(digits) + index / digits;
	//Ȼ����Ե�������Ͱ�����Ҫ�ҵ�λ 
	//����һ��������������Ǵ�������ĵڼ�λ
	//��ÿ������λ��,��ȥindex������ 
	int indexFromRight = digits - index % digits;
	//�������ȡ����,�Ȱ�������������Գ�ȥ�� 
	for(int i = 1; i < indexFromRight; ++i)
		number /= 10;
	return number % 10;//Ȼ�������λ���������� 
}

//����digitsλ���ֺ��ĵ�һ����(���ǵ�һλ��) 
int beginNumber(int digits) {
	if(digits == 1)//1λ���ֺ���һ������0 
		return 0;
	//2λ��10,3λ��100,4λ��1000... 
	return (int) pow(10, digits - 1);
}

int main(){
	cout<<digitAtIndex(1001)<<endl;
	return 0;
}
