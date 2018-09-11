#include <cstdio>
#include "ComplexList.h"

//����ָ��Value�Ľ��:�������,�趨ֵ,���� 
ComplexListNode* CreateNode(int nValue) {
	ComplexListNode* pNode = new ComplexListNode();

	pNode->m_nValue = nValue;
	pNode->m_pNext = nullptr;
	pNode->m_pSibling = nullptr;

	return pNode;
}

//��������ϵ 
void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling) {
	if(pNode != nullptr) {//���Ҫ���ù�ϵ�Ľ��ǿ� 
		pNode->m_pNext = pNext;
		pNode->m_pSibling = pSibling;
	}
}

//����������� 
void PrintList(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;
	while(pNode != nullptr) {
		printf("The value of this node is: %d.\n", pNode->m_nValue);
		//�����ʱ�������е���Ҳ���,next������� 
		if(pNode->m_pSibling != nullptr) 
			printf("The value of its sibling is: %d.\n", pNode->m_pSibling->m_nValue);
		else
			printf("This node does not have a sibling.\n");
		printf("\n");
		//��Ϊ�������ʱ���Ǵ�ǰ���next����·�� 
		pNode = pNode->m_pNext;
	}
}
