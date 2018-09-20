#include<bits/stdc++.h>
#include "../Utilities/List.h"
using namespace std;

// ����:
//        pListHead:      ָ��ͷ���ָ���ָ�� 
//        pToBeDeleted:   ָ��Ҫɾ���Ľ���ָ�� 
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted) {
	if(!pListHead || !pToBeDeleted)//����ǿռ��� 
		return;

	//next�ǿ�,˵��Ҫɾ���Ľ�㲻��β���
	if(pToBeDeleted->m_pNext != nullptr) {
		ListNode* pNext = pToBeDeleted->m_pNext;//��¼��һ����ַ 
		pToBeDeleted->m_nValue = pNext->m_nValue;//����ֵ���ǵ���ǰ��� 
		pToBeDeleted->m_pNext = pNext->m_pNext;//����ǰ����nextָ��ԭ��һ����next,�ƹ�ԭ��һ��� 
		delete pNext;//ɾ���ոճ�������ԭ��һ��㼴�� 
		pNext = nullptr;
	}
	//û�����ϸ�if��˵����β���,���ͬʱ����ͷ��� 
	else if(*pListHead == pToBeDeleted) {
		delete pToBeDeleted;//Ҳ��˵��ֻ����һ�����,ֱ�ӽ���ɾ������ 
		pToBeDeleted = nullptr;
		*pListHead = nullptr;
	}
	//���һ�������,�������в�ֹһ������������ɾ��β��� 
	else {
		ListNode* pNode = *pListHead;//��ͷ��㿪ʼ
		//����������,ֱ���ߵ�Ҫɾ���Ľ���ǰһ����� 
		while(pNode->m_pNext != pToBeDeleted) { 
			pNode = pNode->m_pNext;
		}
		//���ý��nextָ���,��Ϊβ��� 
		pNode->m_pNext = nullptr;
		delete pToBeDeleted;//Ȼ��ɾ�����β��� 
		pToBeDeleted = nullptr;
	}
}
