#include<bits/stdc++.h>
#include "../Utilities/List.h"
using namespace std;

//��������ͷָ��,kֵ,���ص�����k�����ĵ�ַ
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	//����ǿ�У��
	if(pListHead == nullptr || k == 0)//"������0��"����˵��Ҳ�Ǵ����
		return nullptr;

	ListNode *pAhead = pListHead;//����ָ��
	ListNode *pBehind = nullptr;//����ָ��

	//����ָ��Ҫ����k-1��,����ѭ��k-1��
	for(unsigned int i = 0; i < k - 1; ++ i) {
		if(pAhead->m_pNext != nullptr)//Ҫ�ж���һ�����ǿ�
			pAhead = pAhead->m_pNext;//����������
		else//�����һ�����ȿ�
			return nullptr;//��ô˵������̫����,û��"������k��"
	}

	pBehind = pListHead;//����,����ָ���Ѿ�"����"����,����ָ��Ҫ���ϵ�һ�����
	while(pAhead->m_pNext != nullptr) {//ֱ������ָ���ߵ����һ��Ԫ����Ϊֹ
		//��ָ������,ÿ��ͬʱ�����һ��
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}
	//����,����ָ����ָ��Ϊ����
	return pBehind;
}

int main() {
	//���������� 
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);
	//���ӳ��� 
	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	//��ѯ������2����㲢��� 
	ListNode* pNode = FindKthToTail(pNode1, 2);
	PrintListNode(pNode);
	//�������� 
	DestroyList(pNode1);
	return 0;
}
