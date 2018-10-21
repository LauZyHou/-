#include<bits/stdc++.h>
using namespace std;

//����������С 
int Min(int number1, int number2, int number3) {
	int min = (number1 < number2) ? number1 : number2;//min(n1,n2)
	min = (min < number3) ? min : number3;//min(min(n1,n2),n3)
	return min;
}

//����ҪѰ�ҵĳ�����˳����������ǵڼ���,���㲢���ظó��� 
int GetUglyNumber_Solution(int index) {
	if(index <= 0)//����Ϸ��� 
		return 0;

	int *pUglyNumbers = new int[index];//��index�������±�Ϊindex-1 
	pUglyNumbers[0] = 1;//1����С�ĳ��� 
	int nextUglyIndex = 1;//��һ��Ҫ�ҵĳ����ڳ��������±� 

	//��ʼ��T2,T3,T5�ĵ�ַ,����&pUglyNumbers[0]
	int *pMultiply2 = pUglyNumbers;
	int *pMultiply3 = pUglyNumbers;
	int *pMultiply5 = pUglyNumbers;

	//һֱ��,�����±�Ϊindex-1��,��nextUglyIndex=indexʱֹͣ 
	while(nextUglyIndex < index) {
		//min(T2,T3,T5)
		int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		pUglyNumbers[nextUglyIndex] = min;//������һ������ 

		//�����´�T2(�ĵ�ַ):T2*2Ҫ�պô����ǰ���������� 
		while(*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
			++pMultiply2;
		//�����´�T3(�ĵ�ַ):T3*3Ҫ�պô����ǰ���������� 
		while(*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
			++pMultiply3;
		//�����´�T5(�ĵ�ַ):T5*5Ҫ�պô����ǰ���������� 
		while(*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
			++pMultiply5;

		++nextUglyIndex;//�´�ѭ��Ҫ�ҵĳ����±�+1 
	}

	//Ҫ�ҵĳ�������pUglyNumbers[index-1] 
	int ugly = pUglyNumbers[nextUglyIndex - 1];
	delete[] pUglyNumbers;
	return ugly;
}

int main() {
	cout<<GetUglyNumber_Solution(1500)<<endl;//859963392
	return 0;
}
