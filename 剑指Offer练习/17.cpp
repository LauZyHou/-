#include<bits/stdc++.h>
using namespace std;

void PrintNumber(char* number);
bool Increment(char* number);
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);

// ====================����һ====================
void Print1ToMaxOfNDigits_1(int n) {
	if (n <= 0)//λ�����ܷ���
		return;
	//��ʼ��nλ���ռ�
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	//����û��������nλ��,��������1 
	while (!Increment(number)) {
		PrintNumber(number);//��������ĺ��� 
	}
	//�����nλ���Ŀռ� 
	delete[]number;
}

//numberΪ�ַ������ʾ�Ĵ���,����������1,���ʱ����true
bool Increment(char* number) {
	bool isOverflow = false;//�Ƿ���� 
	int nTakeOver = 0;//��ǰ��һλҪ���ϵ�,������һλ�Ľ�λ�� 
	int nLength = strlen(number);//�ַ�����ĳ���,�������ж���λ 
	//�ӵ�λ(��)���λ(ǰ)���� 
	for (int i = nLength - 1; i >= 0; i--) {
		//��ǰ��һλ����ֵ=��ֵ+��λ�� 
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)//��������λ 
			nSum++;//��Ҫ�����ֵ��1,��Ϊ����Ĳ�������������+1 
		//����Ѿ�����10��(ʵ��������������10),�������˽�λ 
		if (nSum >= 10) {
			if (i == 0)//����������λ�Ϸ����� 
				isOverflow = true;//˵���Ѿ������,���һ�� 
				//�Ѿ������λ��,��breakҲ�����ѭ�� 
			else {//����,��Ҫ����λ���� 
				nSum -= 10;//��λֻ������ͷ(��ʵ���Ǳ�λ���0) 
				nTakeOver = 1;//��λֵ���ó�1 
				number[i] = '0' + nSum;//���õ�ǰλ����ֵ,������ѭ��,��Ϊ��λҲ���ܽ�λ 
			}
		} else {//��������ڽ�λ 
			number[i] = '0' + nSum;//���õ�ǰλ����ֵ 
			break;//����Ҫ��ѭ����,��Ϊ��λҲ�������ٽ�λ�� 
		}
	}
	return isOverflow;
}

// ====================������====================
void Print1ToMaxOfNDigits_2(int n) {
	if (n <= 0)//λ�����ܷ���
		return;
	//��ʼ��nλ���ռ�,����Ҫ��0,��Ϊ��ʹ��ȫ������ʵ�� 
	char* number = new char[n + 1];
	number[n] = '\0';

	for (int i = 0; i < 10; ++i) {
		number[0] = i + '0';//���λ��0��9����һ�� 
		Print1ToMaxOfNDigitsRecursively(number, n, 0);//�ݹ�ص���ȫ���еĺ������ 
	}
	//�����nλ���Ŀռ� 
	delete[] number;
}

//numberΪ�ַ������ʾ�Ĵ���,lengthΪ������Чλ��,indexΪ��ǰ�����õ�λ�� 
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index) {
	if (index == length - 1) {//����Ѿ����õ������һλ 
		PrintNumber(number);//ֱ�ӵ�������������� 
		return;//��ʱ�ǵݹ���� 
	}
	//����,��Ȼû�����õ����һλ,��Ҫ����һλ���øú�����ȫ���� 
	for (int i = 0; i < 10; ++i) {
		number[index + 1] = i + '0';//����һλ��0��9����һ�� 
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);//�ݹ���� 
	}
}

// ====================��������====================
//�ַ���number��ʾһ�����֣����������ɸ�0��ͷ
//��ӡ��������֣������Կ�ͷ��0
void PrintNumber(char* number) {
	bool isBeginning0 = true;//��¼�Ƿ񻹴����ײ�������0��,Ĭ���� 
	int nLength = strlen(number);//�ַ�������
	//�Ӹ�λ���λ��ÿһλ 
	for (int i = 0; i < nLength; ++i) {
		//����������ɸ�0��,�ҵ�һ�������˷�0�� 
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;//��ôҪ�������ʶ��Ϊfalse,��ʾ�Ѿ��߳���0�� 
		//ֻҪ������0���� 
		if (!isBeginning0) {
			printf("%c", number[i]);//������ʲô���ֶ�Ҫ���,0��֮���ǿ�����0�� 
		}
	}
	printf("\t");
}

int main(){
	Print1ToMaxOfNDigits_1(2);
	Print1ToMaxOfNDigits_2(2);
	return 0;
}
