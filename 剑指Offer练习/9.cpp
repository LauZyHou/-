#include<bits/stdc++.h>
using namespace std;

//���Ͷ�����
template <typename T> class CQueue {
	public:
		CQueue(void);
		~CQueue(void);

		//�ڶ���ĩβ���һ��Ԫ��
		void appendTail(const T& node);

		//�ڶ���ͷ��ɾ��һ��Ԫ��
		T deleteHead();

	private:
		//�ṩ����STLջ
		stack<T> stack1;
		stack<T> stack2;
};

//���캯��
template <typename T> CQueue<T>::CQueue(void) {
}

//��������
template <typename T> CQueue<T>::~CQueue(void) {
}

//���߼���β���һ��Ԫ��
template<typename T> void CQueue<T>::appendTail(const T& element) {
	stack1.push(element);//ֱ����ӵ�Aջ��
}

//���߼���ͷɾ��һ��Ԫ��
template<typename T> T CQueue<T>::deleteHead() {
	//���Bջ��û�ж���
	if(stack2.size()<= 0) {
		//����Aջ�������Ԫ��
		while(stack1.size()>0) {
			T& data = stack1.top();//������ȡջ��Ԫ��,��Ȼһ��pop����û��
			stack1.pop();//����Aջ��Ԫ��
			stack2.push(data);//ѹ��Bջ
		}
		//����,Aջ���Ԫ�ط���ѹ����Bջ
	}

	//���Bջ�ﻹ��û�ж���,��ʱAջ��Ҳһ��û����,˵�����о���Ϊ��
	if(stack2.size() == 0)
		throw new exception();

	//�����Bջ�е���ջ��Ԫ��,���Ƕ��е�ͷԪ��
	T head = stack2.top();//��ȡ
	stack2.pop();//�ٵ�

	return head;//���ظո�ɾ����Ԫ�� 
}

int main(int argc, char* argv[]) {
	//���Ͳ���Ϊchar,�����Զ������
	CQueue<char> queue;

	//�ڶ��������Ԫ��
	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');
	
	try {
		//ɾ�������
		char head = queue.deleteHead();
		cout<<"head="<<head<<endl;

		head = queue.deleteHead();
		cout<<"head="<<head<<endl;
	} catch(exception& exception) {
		cerr<<"queue is empty"<<endl;
	}
	return 0;
}
