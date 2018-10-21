#include<bits/stdc++.h>
#include"../Utilities/List.h"
using namespace std;

//�������������
unsigned int GetListLength(ListNode* pHead) {
	unsigned int nLength = 0;
	ListNode* pNode = pHead;
	while(pNode != nullptr) {
		++nLength;
		pNode = pNode->m_pNext;
	}
	return nLength;
}

//Ѱ����������ĵ�һ���������
ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
	//�õ���������ĳ���
	unsigned int nLength1 = GetListLength(pHead1);
	unsigned int nLength2 = GetListLength(pHead2);
	int nLengthDif = nLength1 - nLength2;//���Ȳ�,�����в���

	//Ĭ����1��,��2��
	ListNode* pListHeadLong = pHead1;
	ListNode* pListHeadShort = pHead2;
	//�����2��
	if(nLength2 > nLength1) {
		//������
		pListHeadLong = pHead2;
		pListHeadShort = pHead1;
		nLengthDif = nLength2 - nLength1;
	}

	//���ڳ���������nLengthDif��
	for(int i = 0; i < nLengthDif; ++i)
		pListHeadLong = pListHeadLong->m_pNext;

	//Ȼ��ͬʱ�����������ϱ���:ֻҪ��������û������,�һ�û�ҵ��������
	while((pListHeadLong != nullptr) &&
	        (pListHeadShort != nullptr) &&
	        (pListHeadLong != pListHeadShort)) {
		//ͬ��ָ��������
		pListHeadLong = pListHeadLong->m_pNext;
		pListHeadShort = pListHeadShort->m_pNext;
	}

	//���صõ��ĵ�һ���������,���û����Ȼ����nullptrҲû����
	ListNode* pFisrtCommonNode = pListHeadLong;
	return pFisrtCommonNode;
}

// 1 - 2 - 3 \
//            6 - 7
//     4 - 5 /
int main() {
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);
	ListNode* pNode6 = CreateListNode(6);
	ListNode* pNode7 = CreateListNode(7);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode6);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);

	cout<<FindFirstCommonNode(pNode1,pNode4)->m_nValue<<endl;//6

	DestroyList(pNode1);
	DestroyList(pNode4);

	return 0;
}
