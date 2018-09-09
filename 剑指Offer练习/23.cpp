#include<bits/stdc++.h>
#include "../Utilities/List.h"
using namespace std;

//���������ͷ���,�ÿ���ָ���ҵ����ڵ�һ�����,��������ڻ�����nullptr 
ListNode* MeetingNode(ListNode* pHead) {
	//����ǿ�У�� 
	if(pHead == nullptr)
		return nullptr;
	//��ָ��:��ʼ��ͷ����1��ָ�� 
	ListNode* pSlow = pHead->m_pNext;
	if(pSlow == nullptr)//ÿ�ζ�Ҫ�жϷǿ�,ȷ���л� 
		return nullptr;
	//��ָ��:��ʼ��ͷ����2��ָ�� 
	ListNode* pFast = pSlow->m_pNext;
	//ÿ���жϵ��·ǿ�,��������
	//ʵ���ϸ���û��Ҫ��ȥ�����ָ����,���ﻹ�Ǳ������ߵ�д�� 
	//[ע��]�л������������߾������ߵ��� 
	while(pFast != nullptr && pSlow != nullptr) {
		if(pFast == pSlow)//�����ָ������ 
			return pFast;//��ô�ô�һ���ǻ���һ���,���䷵�� 
		//��ָ��ÿ����һ�� 
		pSlow = pSlow->m_pNext;
		//��ָ��ÿ�������� 
		pFast = pFast->m_pNext;//��һ������ֱ����,��Ϊwhileѭ�����жϹ��� 
		if(pFast != nullptr)//�ڶ�������Ҫ���ж�һ�������� 
			pFast = pFast->m_pNext;
	}
	//���while�����˻�û����,˵�������˿�,����û�л� 
	return nullptr;
}

//��������ͷ���,�ҵ������л�����ʼ��� 
ListNode* EntryNodeOfLoop(ListNode* pHead) {
	//�ҵ����ڵ�ĳ����� 
	ListNode* meetingNode = MeetingNode(pHead); 
	if(meetingNode == nullptr)//���������nullptr 
		return nullptr;//˵�������ڻ�,�������Ҳ����nullptr 

	//�õ����н�����Ŀ
	int nodesInLoop = 1;//��1(�ո��ҵ���������)��ʼ���� 
	ListNode* pNode1 = meetingNode;//�ҵ��Ľ�����ڱ�ǵ���λ��,����һ���ܶ���ָ�� 
	//ֻҪ���������Ǳ��λ��,��˵��û����������� 
	while(pNode1->m_pNext != meetingNode) {
		pNode1 = pNode1->m_pNext;//�ܶ�ָ�������� 
		++nodesInLoop;//����+1 
	}
	
	//����,�Ѿ��õ��˻���(���н����),������nodesInLoop�� 

	//˫ָ�뷨,���ƶ�pNode1Ϊ���� 
	pNode1 = pHead;//��ͷ��㿪ʼ�ƶ� 
	for(int i = 0; i < nodesInLoop; ++i)//����Ϊ���н�����Ŀ
		pNode1 = pNode1->m_pNext;

	ListNode* pNode2 = pHead;//pNode2����ͷ���
	//����ָ��ͬʱ����ƶ�,ֱ������Ϊֹ 
	while(pNode1 != pNode2) {
		pNode1 = pNode1->m_pNext;
		pNode2 = pNode2->m_pNext;
	}
	//˫ָ��������λ�ü�Ϊ����Ļ�����ʼ��� 
	return pNode1;
}

int main() {
	//������� 
	ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
	//���ɴ�������,��5�ƻص�3�� 
    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode3);
	//������ʼ���,����� 
	PrintListNode(EntryNodeOfLoop(pNode1));
	//�������� 
    DestroyList(pNode1);
	return 0;
}
