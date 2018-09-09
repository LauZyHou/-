#include<bits/stdc++.h>
using namespace std;

bool matchCore(const char* str, const char* pattern);

// ����:
//        str:       Ҫƥ����ַ����׵�ַ 
//        pattern:   Ҫƥ���ģʽ���׵�ַ 
// ����ֵ:
//        �ܷ�ƥ��ɹ� 
bool match(const char* str, const char* pattern) {
	//�ǿ�У�� 
	if(str == nullptr || pattern == nullptr)
		return false;
	//����ƥ��ĺ���,�ݹ�ؽ���ƥ�� 
	return matchCore(str, pattern);
}

// ����:
//        str:       Ҫƥ����ַ�(��)���׵�ַ 
//        pattern:   Ҫƥ���ģʽ(��)���׵�ַ 
// ����ֵ:
//        �Ӵ�λ������ܷ�ƥ��ɹ� 
bool matchCore(const char* str, const char* pattern) {
	if(*str == '\0' && *pattern == '\0')//��������������β 
		return true;//ƥ��ɹ� 

	if(*str != '\0' && *pattern == '\0')//���ģʽ���ȵ����β 
		return false;//ƥ��һ��ʧ��
	
	//��:����ַ����ȵ����β,��һ��ƥ��ʧ��,��Ϊ����ģʽ��ʣ��'a*'����'*'����ƥ��� 

	//���ģʽ����һ�ַ���'*',��ô��Ӱ�쵱ǰ�ַ���ƥ�䳤�� 
	if(*(pattern + 1) == '*') {
		//�����ǰģʽ�Ǻ��ַ���ƥ���,���ߵ�ǰģʽ��'.'��ƥ����һ�ַ� 
		if(*pattern == *str || (*pattern == '.' && *str != '\0'))//�������ǰ��ƥ��� 
			//��������ƥ�䷽ʽ
			//������ǰ�ַ����ϵ�'a',����ģʽ��'a*',��'*'ʹ'a'�ظ�1�� 
			return matchCore(str + 1, pattern + 2)
			       //������ǰ�ַ����ϵ�'a',���������'a'����ƥ��'a*',��'*'ʹ'a'�ظ�>1��  
			       || matchCore(str + 1, pattern)
			       //����ģʽ��'a*',��'*'ʹ'a'�ظ�0��
			       || matchCore(str, pattern + 2); 
		else//�����ǰģʽ����ƥ���ַ����ϵ�����ַ� 
			//��ʱ���'*'��ֻ����ʹǰ����ַ�'a'�ظ�0�ε�Ч�� 
			return matchCore(str, pattern + 2);
	}

	//�����Ǻ���û�и�'*'����� 

	//�����ǰģʽƥ���ַ�����λ�õ��ַ�('a'-'a'ƥ�����'a'-'.'ƥ��) 
	if(*str == *pattern || (*pattern == '.' && *str != '\0'))
		return matchCore(str + 1, pattern + 1);//ƥ��,��������ǰ��һ�� 
	
	//���˻�û�з���,˵�����(��)ƥ���Ѿ�ʧ�� 
	return false;
}

int main(){
	cout<<boolalpha<<match("aaca","ab*a*c*a")<<endl;
	return 0;
}
