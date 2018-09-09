#include "list.h"
#include <stdio.h>
#include <stdlib.h>

//�������ֵ,������㲢�����½���ַ
ListNode* CreateListNode(int value) {
	ListNode* pNode = new ListNode();//�������
	pNode->m_nValue = value;//����ֵ
	pNode->m_pNext = nullptr;//����nextΪ��
	return pNode;//���ظý��ĵ�ַ
}

//�����������,ʹ��һ������Ϊǰһ������next���
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext) {
	//ǰһ����㲻����Ϊ��,���Ϊ��û�취ָ�����Ľ��
	if(pCurrent == nullptr) {
		printf("Error to connect two nodes.\n");
		exit(1);
	}

	//ʹ��ָ�����Ľ��(����Ϊ��)
	pCurrent->m_pNext = pNext;
}

//������
void PrintListNode(ListNode* pNode) {
	if(pNode == nullptr)//�п�
		printf("The node is nullptr\n");
	else//�ǿ�ʱ������ֵ
		printf("The key in node is %d.\n", pNode->m_nValue);
}

//����ͷ���,����������� 
void PrintList(ListNode* pHead) {
	printf("PrintList starts.\n");

	//��Ӧֱ�Ӳ���ͷ���,����һ��ָ��ָ��ͷ��� 
	ListNode* pNode = pHead;
	//���ǿ�,��δ������� 
	while(pNode != nullptr) {
		printf("%d\t", pNode->m_nValue);//�������ֵ 
		pNode = pNode->m_pNext;//ָ������ƶ� 
	}

	printf("\nPrintList ends.\n");
}

//������������ 
void DestroyList(ListNode* pHead) {
	//�Ӵ�ͷ��㿪ʼɾ�� 
	ListNode* pNode = pHead;
	//����Ϊ��ʱ,����ɾ��û���� 
	while(pNode != nullptr) {
		//��ͷ���ָ����һ��� 
		pHead = pHead->m_pNext;
		//���ոյ�ͷ��㱻��ʱָ���¼,����ɾ�� 
		delete pNode;
		//��ʱָ����ָ���������ͷ��� 
		pNode = pHead;
	}
	//�������,����ʱ�Ѿ�ɾ�������н�� 
}

//����һ��ֵ,����½�㵽����β�� 
//pHead��ָ��ͷ���ָ���ָ�� 
void AddToTail(ListNode** pHead, int value) {
	//�ȴ����½��,��������ֵ 
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	//���ͷ���ָ��Ϊ��,˵��û��ͷ��� 
	if(*pHead == nullptr) {
		*pHead = pNew;//��ʱ������ͳ�Ϊͷ��� 
	} else {
		//����Ҫ����������ӵ���ǰͷ������������β�� 
		ListNode* pNode = *pHead;//ȡ��ͷ����ַ 
		//�����,ֱ��nextΪ��,��ǰ���������һ����� 
		while(pNode->m_pNext != nullptr)
			pNode = pNode->m_pNext;
		//�����һ������nextָ������´����Ľ�� 
		pNode->m_pNext = pNew;
	}
}

//����һ��ֵ,ɾ����ֵ��Ӧ��������
//pHead��ָ��ͷ���ָ���ָ��
void RemoveNode(ListNode** pHead, int value) {
	//�ǿ�У�� 
	if(pHead == nullptr || *pHead == nullptr)
		return;
	
	//��ָ��Ҫ��ɾ���Ľ���ָ�� 
	ListNode* pToBeDeleted = nullptr;
	//���Ҫ��ɾ���Ľ����ͷ��� 
	if((*pHead)->m_nValue == value) {
		pToBeDeleted = *pHead;//��¼Ҫɾ���Ľ�� 
		*pHead = (*pHead)->m_pNext;//��ͷ���ָ���������һ��� 
	} else {
		//��ͷ��㿪ʼ 
		ListNode* pNode = *pHead;
		//�����,ֻҪ��һ���ǿ�,����һ��㲻��Ҫɾ���Ľ�� 
		while(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
			pNode = pNode->m_pNext;//����Щ������� 
		
		//����һ������Ҫɾ���Ľ��ʱ,˵���ҵ���Ҫɾ���Ľ�� 
		if(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value) {
			pToBeDeleted = pNode->m_pNext;//��¼Ҫɾ���Ľ��
			//����ǰ������һ���ָ��Ҫɾ��������һ���,ά����������
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	//�����¼�Ľ�����,��������Ҫɾ���Ľ�� 
	if(pToBeDeleted != nullptr) {
		delete pToBeDeleted;//����ɾ������ 
		pToBeDeleted = nullptr;
	}
}
