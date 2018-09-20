#include<bits/stdc++.h>
using namespace std;

int compare(const void* strNumber1, const void* strNumber2);

//int��������ʮ���Ʊ�ʾ���ֻ��10λ
const int g_MaxNumberLength = 10;

//��[m][n]���ַ��� 
char* g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];
//��[n][m]���ַ��� 
char* g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];

//����������������鳤��,����ųɵ���С���� 
void PrintMinNumber(const int* numbers, int length) {
	if(numbers == nullptr || length <= 0)//����ǿ�У�� 
		return;

	//�洢����char����,����ռ���������������һ�� 
	char** strNumbers = (char**)(new int[length]);
	//������length���� 
	for(int i = 0; i < length; ++i) {
		//ÿ��������һ��char��������洢,+1��Ϊ�˴�'\0' 
		strNumbers[i] = new char[g_MaxNumberLength + 1];
		//������Ķ�Ӧλ�õ�����д����Ӧ���ַ����� 
		sprintf(strNumbers[i], "%d", numbers[i]);
	}

	//��strNumbers�е�Ԫ��(��char����)��������
	//�����Զ����compare����ָ����ȷ������ķ��� 
	qsort(strNumbers, length, sizeof(char*), compare);

	//�ź����,��˳����������� 
	for(int i = 0; i < length; ++i)
		printf("%s", strNumbers[i]);
	printf("\n");

	//�ͷŶѿռ� 
	for(int i = 0; i < length; ++i)
		delete[] strNumbers[i];
	delete[] strNumbers;
}

//���[strNumber1][strNumber2] > [strNumber2][strNumber1],����ֵ����0
//���[strNumber1][strNumber2] = [strNumber2][strNumber1],����ֵ����0
//���[strNumber1][strNumber2] < [strNumber2][strNumber1],����ֵС��0
int compare(const void* strNumber1, const void* strNumber2) {
	//[strNumber1][strNumber2]�����ȿ���1������2 
	strcpy(g_StrCombine1, *(const char**)strNumber1);
	strcat(g_StrCombine1, *(const char**)strNumber2);

	//[strNumber2][strNumber1]�����ȿ���2������1
	strcpy(g_StrCombine2, *(const char**)strNumber2);
	strcat(g_StrCombine2, *(const char**)strNumber1);
	
	//ֱ�ӵ����ַ����Ƚϵĺ��� 
	return strcmp(g_StrCombine1, g_StrCombine2);
}

int main(){
	int numbers[]={3,32,321};
	PrintMinNumber(numbers,sizeof(numbers)/sizeof(int));
	return 0;
}

