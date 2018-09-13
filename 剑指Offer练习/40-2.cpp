#include<bits/stdc++.h>
#include "../Utilities/Array.h"
using namespace std;

//typedef������������:"typedef ���ӵĶ��� ����;"
//greater��ʾ�������ʹӴ�С����,����һ��Ԫ��һ��������
//set��multiset������ض�������ԭ��Ԫ������,���Ｔģ��������
typedef multiset<int, greater<int> >            intSet;
typedef multiset<int, greater<int> >::iterator  setIterator;

//��������,ȡ��С��k��Ԫ�ص�multiset����,k��ֵ
//�ҵ���������С��k��Ԫ��,���������й�������ʹ��
void GetLeastNumbers_Solution2(const vector<int>& data, intSet& leastNumbers, int k) {
	leastNumbers.clear();//�������
	//�������Ϸ���
	if(k < 1 || data.size() < k)
		return;
	//������ǰ�濪ʼ
	vector<int>::const_iterator iter = data.begin();
	for(; iter != data.end(); ++ iter) {//��������������
		if((leastNumbers.size()) < k)//���������û��
			leastNumbers.insert(*iter);//ֱ�Ӳ���������
		else {//��������Ѿ�����
			//ȡ����multiset�ĵ�һ��Ԫ��,���߼����ѵĶѶ�
			setIterator iterGreatest = leastNumbers.begin();
			//�����ǰ����������ѶѶ���С
			if(*iter < *(leastNumbers.begin())) {
				leastNumbers.erase(iterGreatest);//�ѶѶ��Ƴ�ȥ
				leastNumbers.insert(*iter);//�����Ž���
			}
		}
	}
}

int main() {
	int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
	//д��vector���� 
	vector<int> vectorData;
	for(int i = 0; i < 8; ++ i)
		vectorData.push_back(data[i]);
	//multiset���� 
	intSet leastNumbers;
	GetLeastNumbers_Solution2(vectorData,leastNumbers,4);
	//������������ǴӴ�С�����,ʹ���������ʱ���ܱ�֤���� 
	for(setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter)
		cout<<*iter<<"\t";
	return 0;
}
