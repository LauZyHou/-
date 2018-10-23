#include<bits/stdc++.h>
using namespace std;

//��ת��pBegin��pEnd���ַ���
void Reverse(char *pBegin, char *pEnd) {
	if(pBegin == nullptr || pEnd == nullptr)//����Ϸ��Լ��
		return;

	while(pBegin < pEnd) {
		//�����Գ�λ�õ��ַ�
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
		//�ԳƵ����м��ƶ�
		pBegin ++, pEnd --;
	}
}

//�����ַ���,����λ����n 
char* LeftRotateString(char* pStr, int n) {
	if(pStr != nullptr) {//�ַ������ܴ���ָ�� 
		int nLength = static_cast<int>(strlen(pStr));//���� 
		if(nLength > 0 && n > 0 && n < nLength) {//n��nLength�ĺϷ��� 
			//��ߵ��Ӵ� 
			char* pFirstStart = pStr;
			char* pFirstEnd = pStr + n - 1;
			//�ұߵ��Ӵ� 
			char* pSecondStart = pStr + n;
			char* pSecondEnd = pStr + nLength - 1;

			//��ת�ַ�����ǰ��n���ַ�
			Reverse(pFirstStart, pFirstEnd);
			//��ת�ַ����ĺ��沿��
			Reverse(pSecondStart, pSecondEnd);
			//��ת�����ַ���
			Reverse(pFirstStart, pSecondEnd);
		}
	}
	return pStr;
}

int main() {
	char input[] = "abcdefg";
	printf("%s\n",LeftRotateString(input,2));//cdefgab
	return 0;
}
