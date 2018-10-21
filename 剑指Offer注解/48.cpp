#include<bits/stdc++.h>
using namespace std;

//���������string������,�����������������f(i)��ֵ 
int longestSubstringWithoutDuplication(const string& str) {
	int curLength = 0;//��ǰ�ҵ��ĳ���,����ǰ��f(i) 
	int maxLength = 0;//����ǰΪֹ,����f(i) 

	int* position = new int[26];//��26����ĸ"��һ�γ��ֵ�λ���±�"
	for(int i = 0; i < 26; ++i) 
		position[i] = -1;//��ʼ��Ϊ-1,��ʾ"֮ǰû���ֹ�" 

	for(int i = 0; i < str.length(); ++i) {//�����ַ��� 
		int prevIndex = position[str[i] - 'a'];//��λ���ַ���һ�γ��ֵ�λ���±� 
		if(prevIndex < 0 || i - prevIndex > curLength)//����ٻ�� 
			++curLength;//f(i)=f(i-1)+1
			//���������������ʱ,curLength�ǵ������ӵ�
			//���Բ���Ҫ����©��¼���м���ֵ�ĳЩ�����ߴ�ĳ���
			//�����ܳ���,��Ϊ�ǵ������ӵ�(�������پͲ���)
			//��ʱ����maxLength�����õĸ���,��Ϊ������Ҳ�ᱻ����ĸ��¸��ǵ� 
		else {//����� 
			if(curLength > maxLength)//�������f(i) 
				maxLength = curLength;
			curLength = i - prevIndex;//f(i)=d
		}
		position[str[i] - 'a'] = i;
	}
	//���ո���һ�����f(i),��Ϊ����������ٻ��ߢڽ��� 
	if(curLength > maxLength)
		maxLength = curLength;

	delete[] position;
	return maxLength;
}

int main() {
	string ok="abcacfrar";
	printf("%d\n",longestSubstringWithoutDuplication(ok));//4
	return 0;
}
