#include<bits/stdc++.h>
#include "../Utilities/List.h"
using namespace std;

//Ҫɾ���Ľ�������ͷ���,����Ҫ����ͷ����ַ��ָ��
//����ɾ��ͷ���ʱ,ֻ���β�ָ��ĵ�ֵַ�޷�Ӱ�쵽������֪����ͷ����ַ 
void DeleteDuplication(ListNode** pHead) {
	//����ǿ�У�� 
	if(pHead == nullptr || *pHead == nullptr)
		return;
	//˫ָ���ʼ��:�ڶ�����ͷ��㿪ʼ,��һ��ָ����ǰ��Ľ��(һ��ʼû��) 
	ListNode* pPreNode = nullptr;//ǰһ��� 
	ListNode* pNode = *pHead;//[���½��]
	//������������ 
	while(pNode != nullptr) {
		ListNode *pNext = pNode->m_pNext;//̽��[���½��]����һ��� 
		bool needDelete = false;//[���½��]�Ƿ�Ҫ��ɾ�� 
		//�����һ������,�Һ�[���½��]ֵ��ͬ 
		if(pNext != nullptr && pNext->m_nValue == pNode->m_nValue)
			needDelete = true;//��ô[���½��]��Ҫɾ���� 
		//���̽��������[���½��]����Ҫɾ��
		if(!needDelete) {
			//��ô˫ָ�������һ�� 
			pPreNode = pNode;
			pNode = pNode->m_pNext;
		} else {//���̽��������[���½��]��Ҫ��ɾ��,��ʱҪ����ҵ���һ���� 
			int value = pNode->m_nValue;//��¼Ҫɾ������һ�����Ĺ�ֵͬ 
			ListNode* pToBeDel = pNode;//Ҫ��ɾ���Ľ���[���½��]��ʼ
			//������,ֻҪû����β,����ֵ��Ҫɾ���Ľ��һ�� 
			while(pToBeDel != nullptr && pToBeDel->m_nValue == value) {
				pNext = pToBeDel->m_pNext;//�Ȼ�ȡ��һ���,��ֹ��������ʧ 
				delete pToBeDel;//ɾ����ǰҪɾ���Ľ�� 
				pToBeDel = nullptr;
				pToBeDel = pNext;//Ҫɾ���Ľ����ָ��ԭ��һ��� 
			}
			//����,��һ������Ѿ�ɾ������ 
			if(pPreNode == nullptr)//���ǰһ���Ϊ��,��������ǰ�ý�� 
				*pHead = pNext;//˵���ո�ɾ�˿�ͷ��һ��,Ҫ��ͷ���ָ���·��ֵ�������ĵ�һ�� 
			else//����,ɾ���Ĳ��ǿ�ͷ��һ�� 
				pPreNode->m_pNext = pNext;//��ǰ�ý���nextָ���·��ֵĽ��,ά���������� 
			pNode = pNext;//��[���½��]ָ���·��ֵĽ�� 
		}
	}
}
