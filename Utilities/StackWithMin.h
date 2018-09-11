#pragma once		//�ɱ�������ֻ֤����һ�θ��ļ� 

#include <stack>	//STLջ 
#include <assert.h>	//����:�ж��߼����ʽ����� 

//������:����Min������ջ 
template <typename T> class StackWithMin {
	public:
		StackWithMin() {}//������ 
		//���ﶨ�������������,���ñ����ഴ�����������������ʱ
		//�������������������������,�������û�����������
		//������ֻ���û������������ 
		//��һ���಻������Ϊ����,��Ҫ���鹹�����黯
		//��Ϊ�����麯���ͻ�Ϊ������һ���麯����,ʹ������������ 
		virtual ~StackWithMin() {} 

		T& top();//ȡջ��Ԫ��
		//const T&��ʾ���ص�T���������ǳ�����,�����޸�
		//const���ڳ�Ա��������,�øú�����Ȩ��Ϊֻ��
		//Ҳ����˵��û��ȥ�ı�non-static��Ա������ֵ
		//ͬʱ,���һ������Ϊconst,��ֻ��Ȩ������const��Ա�����Ա�֤���޸�non-static��Ա 
		const T& top() const;

		void push(const T& value);//��ջ 
		void pop();//��ջ 

		const T& min() const;//��ȡջ����Сֵ 

		bool empty() const;//�ж�ջ�Ƿ�Ϊ�� 
		size_t size() const;//��ȡջ�Ĵ�С 

	private:
		std::stack<T>   m_data;//����ջ,���ջ������Ԫ��
		std::stack<T>   m_min;//����ջ,ͬ������ջ����СԪ��״̬ 
};

//��ջ 
template <typename T> void StackWithMin<T>::push(const T& value) {
	//����Ԫ����ӵ�����ջ
	m_data.push(value);

	//����Ԫ�ر�֮ǰ����СԪ��Сʱ
	//ѹ�����Ԫ��ʹ�õ�ǰջ�е���СԪ��"״̬"�ı��� 
	if(m_min.size() == 0 || value < m_min.top())
		m_min.push(value);//����Ԫ�ز��븨��ջ��
	else//����
		m_min.push(m_min.top());//��֮ǰ����СԪ���ظ����븨��ջ��
}

//��ջ 
template <typename T> void StackWithMin<T>::pop() {
	//����,���ó�ջʱ����ջ��Ԫ��һ������>0��
	//�����ֵΪ��(��Ϊ0),��ô������stderr��ӡһ��������Ϣ
	//Ȼ��ͨ������abort����ֹ��������
	assert(m_data.size() > 0 && m_min.size() > 0);
	//����ջͬ���� 
	m_data.pop();
	m_min.pop();
}

//ȡ��С 
template <typename T> const T& StackWithMin<T>::min() const {
	assert(m_data.size() > 0 && m_min.size() > 0);//ȡ��Сʱջ��Ҳһ����Ԫ�� 
	//����ջջ�����ǵ�ǰջ״̬�µ�ջ����СԪ�� 
	return m_min.top();
}

/*���¶���ֱ�ӵ���STLջ�Ĳ�������*/

template <typename T> T& StackWithMin<T>::top() {
	return m_data.top();
}

template <typename T> const T& StackWithMin<T>::top() const {
	return m_data.top();
}

template <typename T> bool StackWithMin<T>::empty() const {
	return m_data.empty();
}

template <typename T> size_t StackWithMin<T>::size() const {
	return m_data.size();
}
