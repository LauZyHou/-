#include<bits/stdc++.h>
#include "../Utilities/List.h"
using namespace std;

//��������������(��ͷ���),�����ĿҪ��ĺϲ�,���غϲ����ͷ���
ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
	//�ر�ĵݹ����,ĳһ������Ϊ��ʱֱ�ӷ�����һ������(�������ȷ��صڶ���)
	if(pHead1 == nullptr)
		return pHead2;
	else if(pHead2 == nullptr)
		return pHead1;
	//�������Ϊ��,��Ҫ���ϲ�����
	ListNode* pMergedHead = nullptr;//�ϲ��������ͷ���
	//���1��ͷ��2��ͷС
	if(pHead1->m_nValue < pHead2->m_nValue) {
		pMergedHead = pHead1;//��ô1��ͷҪ��ǰ��
		//��nextָ�����ȥ��ͷ��1����ԭ����2���ϲ��������
		pMergedHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
	} else {//���2��ͷ��1��ͷС,��������ͷһ����
		pMergedHead = pHead2;//��ô2��ͷ����ǰ��(һ����ʱ��˭��ok)
		//��nextָ�����ȥ��ͷ��2����ԭ����1���ϲ��������
		pMergedHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
	}
	//����,�����������Ѿ��ϲ����,�ٷ��غϲ��������ͷ
	return pMergedHead;
}

int main() {
	//��������1 
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode5 = CreateListNode(5);
	ConnectListNodes(pNode1, pNode3);
	ConnectListNodes(pNode3, pNode5);
	//��������2 
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode6 = CreateListNode(6);
	ConnectListNodes(pNode2, pNode4);
	ConnectListNodes(pNode4, pNode6);
	//���ñ���ĺϲ�
	ListNode* pNewHead=Merge(pNode1,pNode2);
	//��������� 
	PrintList(pNewHead);
	DestroyList(pNewHead);
	return 0; 
}
