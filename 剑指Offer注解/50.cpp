#include<bits/stdc++.h>
using namespace std;

//�����ַ������ַ,���Ѱ�ҵ��ĵ�һ��ֻ����һ�ε��ַ� 
char FirstNotRepeatingChar(const char* pString) {
	if(pString == nullptr)//�մ�û��ֻ����һ�ε��ַ�
		//ʵ������Ҳ�Ǹ�ASCII�ַ�,��������Ϊ�ַ�����β
		return '\0';//�����������,Ҳȷʵ�����϶�'\0'�ǵ�һ�γ���һ�ε� 

	const int tableSize = 256;//�ַ����С 
	unsigned int hashTable[tableSize];//�����ַ���,�ַ����ִ�������Ϊ�� 
	for(unsigned int i = 0; i < tableSize; ++i)//ȫ����ʼ��Ϊ����0�� 
		hashTable[i] = 0;

	const char* pHashKey = pString;//ָ����ַ����׿�ʼ 
	while(*(pHashKey) != '\0')//��һ�α��������ַ���,���ִ�����¼������ 
		hashTable[*(pHashKey++)] ++;//hashTable[*pHashKey]++,pHashKey++

	pHashKey = pString;//�ٴδ�ͷ��ʼ 
	while(*pHashKey != '\0') {//���������ַ��� 
		if(hashTable[*pHashKey] == 1)//�ҵ���һ������һ�ε��ַ� 
			return *pHashKey;//����ֱ�ӷ��� 
		//��ǰ�ַ���ֹ����һ��,��������һ�� 
		pHashKey++;
	}
	//û�ҵ�ֻ����һ�ε��ַ� 
	return '\0';//Ҳ������Ϊ�Ǵ�������һ��ֻ����һ�� 
}

int main() {
	cout<<FirstNotRepeatingChar("google")<<endl;//l
	return 0;
}
