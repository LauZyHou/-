#include<bits/stdc++.h>
using namespace std;

//��������ʹ��ڴ�С,����������ڵ����ֵ���� 
vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
	vector<int> maxInWindows;//�������ڵ����ֵ���� 
	if(num.size() >= size && size >= 1) {//����Ҫ�ȴ��ڴ�,����Ҫ������1 
		deque<int> index;//˫�˶���,���ڼ�¼�����п��ܵ����ֵ�����������±� 

		//���ڳ�ʼ״̬�»Ḳ�������ǰsize��λ�� 
		for(unsigned int i = 0; i < size; ++i) {
			//����µ�������ֱȴ����е�һЩ���ִ�
			//ע���Ǳ�β����һЩ���ִ�
			//����[4213]...,�Ƚ�4;
			//����2��β��4С���ڻ����п��ܳ�Ϊ���,β��2
			//����1��β��2С���ڻ����п��ܳ�Ϊ���,β��1
			//����3��β��1��,��ΪֻҪ1���ڴ�����3һ����
			//����һ���ֲ���1�����,��1βɾ
			//ͬ��,��������2,��2βɾ
			//��������4,3��4С,4����ȥ��3���ܻ������ 
			while(!index.empty() && num[i] >= num[index.back()])//���ڵ�ʱ��Ҳɾ��Ӱ��,�൱���ô���α��� 
				index.pop_back();
			//β��������һ��������,����ǰ��ķ�������
			//��Ϊ�����ܸ���ǰ����������ж�������Լ�û�г�Ϊ���Ŀ���
			//ֻ�������´�forѭ���п����������Ҹ��������,���ܶ϶��Լ�û�п���������� 
			index.push_back(i);
		}
		
		//ǰ���ʼ���жϹ���0~size-1λ��,�������ǻ�������
		//����sizeλ�õ�����num.size()-1����β
		for(unsigned int i = size; i < num.size(); ++i) {
			//��ÿ�λ���֮ǰд�뵱ǰ���ڵ����ֵ
			//���±�Ϊindex��ͷ������Ԫ�� 
			maxInWindows.push_back(num[index.front()]);
			
			//������ǰ����(û���κδ���),�����ڽ�����Ҫʹ��i��ֵ��
			//���߿���˵for���++i���Ǵ�����ǰ����1
			//������Ҳ���������һ����"����֮ǰд��"
			
			//������,��ͬ�����߼����������ֵ�±��˫�˶��� 
			while(!index.empty() && num[i] >= num[index.back()])
				index.pop_back();
			//�����ǰ˫�˶��е����ֵ�±겻������ǰ�±��ȥ�������ڴ�С 
			if(!index.empty() && index.front() <= (int) (i - size))
				index.pop_front();//��˵��������ֵ�պû�������,����ɾ�� 
			
			//��ǰ�����Ƶ�,����ǰλ�õ��±�ѹ��
			//ֻ�к������������ֲ�����̭�Լ����ʸ� 
			index.push_back(i);
		}
		//���һ�λ�����ûд��,�������ֵд�� 
		maxInWindows.push_back(num[index.front()]);
	}
	return maxInWindows;//���ػ������ڵ����ֵ���� 
}

int main() {
	int num[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
	vector<int> vPut;
	for(unsigned int i=0;i<sizeof(num)/sizeof(int);i++){
		vPut.push_back(num[i]);
	}
	vector<int> vGet=maxInWindows(vPut,3);
	for(vector<int>::const_iterator cit=vGet.cbegin();cit!=vGet.cend();cit++){
		cout<<*cit<<"\t";//4 4 6 6 6 5
	}
	return 0;
}
