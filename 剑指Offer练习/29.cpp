#include<bits/stdc++.h>
using namespace std;

/*���������ͼ*/
//-------------X
//\
//\
//\
//\
//Y
void PrintMatrixInCircle(int** numbers, int columns, int rows, int start);
void printNumber(int number);


// ����:
//        numbers:       ����(��ά����)���׵�ַ
//        columns:       �����ܵ�����
//        rows:          �����ܵ�����
// ���:
//        �������˳ʱ��Ȧ�ĺ���,�������(˳ʱ���ӡ����)
void PrintMatrixClockwisely(int** numbers, int columns, int rows) {
	//����Ϸ��Լ��
	if(numbers == nullptr || columns <= 0 || rows <= 0)
		return;

	int start = 0;//�ʼȦ����ʼ������Ͻ�(0,0)��ʼ

	//����:����ӡ���ʱ,��ʼ��ᳬ�����г���������һ��һ��
	while(columns > start * 2 && rows > start * 2) {
		//������˳ʱ��Ȧ
		PrintMatrixInCircle(numbers, columns, rows, start);
		//���������Ȧ,��ʼ���������ƶ�һ��,��Ϊ�µ�˳ʱ��Ȧ��ʼ��
		++start;
	}
}

// ����:
//        numbers:       ����(��ά����)���׵�ַ
//        columns:       �����ܵ�����
//        rows:          �����ܵ�����
//        start:         Ȧ����ʼ�������Ͻ�,�������(start,start)
// ���:
//        �����һ��˳ʱ��Ȧ
void PrintMatrixInCircle(int** numbers, int columns, int rows, int start) {
	//��ΪȦ��߽�ľ�����ȷ����,�Դ˼���Ȧ���½ǵ��������(endX,endY)
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;

	//�����Ҵ�ӡһ��,����ʲô�����Ҫ��ӡ��
	for(int i = start; i <= endX; ++i) {//x�������ʼ����β
		int number = numbers[start][i];//������ȷ��,�к�����
		printNumber(number);
	}

	//���ϵ��´�ӡһ��
	if(start < endY) {//ֻ�е����������ʼ������ֹ���Ϸ�ʱ����Ҫ��ӡ
		for(int i = start + 1; i <= endY; ++i) {//y�������ʼ����β
			int number = numbers[i][endX];//������ȷ��,�к�����
			printNumber(number);
		}
	}

	//���ҵ����ӡһ��
	if(start < endX && start < endY) {//�����������һ��,Ҫ����ֹ��ȷʵ������
		for(int i = endX - 1; i >= start; --i) {//x�����ĩβ����ʼ
			int number = numbers[endY][i];//������ȷ��,�к��ڼ�
			printNumber(number);
		}
	}

	//���µ��ϴ�ӡһ��
	if(start < endX && start < endY - 1) {//���һ��ҲҪ�������·�,�Ҹ߶����ٲ�һ�����Ӳ���Ҫ����
		for(int i = endY - 1; i >= start + 1; --i) {//y�����ĩβ����ʼ
			int number = numbers[i][start];//������ȷ��,�к��ڼ�
			printNumber(number);
		}
	}
}

//��ʽ�����
void printNumber(int number) {
	printf("%d\t", number);
}


/*
1    2    3    4    5
6    7    8    9    10
11   12   13   14   15
16   17   18   19   20
21   22   23   24   25
*/
int main() {
	int rows=5,columns=5;
	//��������(��ά����)����ʼ�� 
	int** numbers = new int*[rows]; 
	for(int i = 0; i < rows; ++i) {
		numbers[i] = new int[columns];
		for(int j = 0; j < columns; ++j) {
			numbers[i][j] = i * columns + j + 1;
		}
	}

	PrintMatrixClockwisely(numbers, columns, rows);
	
	return 0;
}
