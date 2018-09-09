#include<bits/stdc++.h>
#include "../Utilities/List.h"
using namespace std;

//��������,�����ת�������(ԭ����β��㽫��Ϊͷ���)
ListNode* ReverseList(ListNode* pHead) {
	ListNode* pReversedHead = nullptr;//��ת�������ͷ���
	ListNode* pNode = pHead;//[��ǰ���]��ͷ��㿪ʼ
	ListNode* pPrev = nullptr;//[��ǰ���]��[ǰһ���]
	//ֻҪû�߳�����
	while(pNode != nullptr) {
		ListNode* pNext = pNode->m_pNext;//��¼[��һ���],��ֹ�ڴ�й¶

		if(pNext == nullptr)//����Ѿ�û����һ���Ļ�
			pReversedHead = pNode;//[��ǰ���]���Ѿ������շ�ת�������ͷ

		pNode->m_pNext = pPrev;//��[��ǰ���]��nextָ��ǰһ���,������ת
		//[��ǰ���]��[ǰһ���]��Ҫ�����
		pPrev = pNode;
		pNode = pNext;
	}
	return pReversedHead;
}

int main() {
	//������� 
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
	//���
	PrintList(pNode1);
	//��ת 
	ListNode* pReversedHead=ReverseList(pNode1);
	//���������
	PrintList(pReversedHead);
	DestroyList(pReversedHead); 
	return 0;
}
