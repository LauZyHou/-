#include<bits/stdc++.h>
using namespace std;

//0~n-1,ÿ��ɾ����m������,�������ʣ�µ����� 
int LastRemaining_Solution1(unsigned int n, unsigned int m) {
	if(n < 1 || m < 1)//n��m��ӦΪ�� 
		return -1;

	unsigned int i = 0;//�α� 

	list<int> numbers;//�����ֵ����� 
	for(i = 0; i < n; ++ i)//�������д浽��������� 
		numbers.push_back(i);

	list<int>::iterator current = numbers.begin();//������������ͷ��ʼ 
	while(numbers.size() > 1) {//������������һ��Ԫ�� 
		for(int i = 1; i < m; ++ i) {//"��m��"����Ҫ�����m-1�� 
			current ++;
			if(current == numbers.end())//�߳�β(endû������) 
				current = numbers.begin();//�ͻص�ͷ�� 
		}

		list<int>::iterator next = ++ current;//Ҫɾ�����ֵ���һ������ 
		if(next == numbers.end())//����,ģ�⻷�νṹ 
			next = numbers.begin();

		-- current;//�������ص����Ҫɾ�������� 
		numbers.erase(current);//����ɾ�� 
		current = next;//������ָ��ո�ɾ�����ֵ���һ������ 
	}//�����ظ��������,ֱ��������ֻʣ��һ������Ϊֹ  
	return *(current);//�������Ψһ������ 
}

int main() {
	cout<<LastRemaining_Solution1(4000,997)<<endl;//1027
	return 0;
}
