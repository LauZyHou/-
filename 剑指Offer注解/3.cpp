#include<bits/stdc++.h>
using namespace std;

// ����:
//        numbers:     һ����������
//        length:      ����ĳ���
//        duplication: (���) �����е�һ���ظ�������
// ����ֵ:
//        true  - ������Ч�����������д����ظ�������
//        false - ������Ч������������û���ظ�������
bool duplicate(int numbers[], int length, int* duplication) {
	//nullptr��C++11�еĿ�ָ��,�����Ǽ���������Ч��
	if(numbers == nullptr || length <= 0)
		return false;

	//����Ҳ�Ǽ�����������Ƿ����ֵ����0~n-1֮����һҪ��
	for(int i = 0; i < length; ++i) {
		if(numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}

	//����,�Ϸ��Լ�����,������������
	for(int i = 0; i < length; ++i) {
		//ֻҪ��ǰ����������±겻��,��m��Ϊi,��һֱѭ��
		while(numbers[i] != i) {
			//�ڽ���֮ǰ,���ж�һ�������Ƿ��ظ�(���)
			if(numbers[i] == numbers[numbers[i]]) {
				//������,��˵���ҵ�������ظ�Ԫ��,��ôͨ��ָ�봫��
				*duplication = numbers[i];
				//�ҵ�һ���ͽ����ó���,��Ϊ��Ŀ����ֻ������һ��
				return true;
			}

			//����,˵���жϲ����,Ҫ�����ǽ����Խ���ǰ��m������ȷ��λ��
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
		//�����ǰ��������±����,��ȥ˳��ؿ���һ����
		//������������û��i�����,��ô�����λ���ϵĲ��Ͻ���һ�����Է����ظ�����
	}

	//������������궼û��return,��ʱ�Ѿ�ȫ������(��0��n-1),û���ظ�����
	return false;
}

int main() {
	int a[7]= {3,1,2,0,2,5,3};
	int *p=new int();
	//boolalpha���ὫboolֵתΪ1/0��� 
	cout<<boolalpha<<duplicate(a,6,p)<<endl;
	if(nullptr==p)
		cout<<"û���ظ�����"<<endl;
	else
		cout<<"�ظ���������"<<*p<<endl;
	delete p;
	return 0;
}
