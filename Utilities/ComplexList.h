#pragma once

//��������Ľ��
struct ComplexListNode {
	//��ͨ������е�ֵ��next�� 
	int                 m_nValue;
	ComplexListNode*    m_pNext;
	//����������һ��ָ����������� 
	ComplexListNode*    m_pSibling;
};

//����ָ��Value���½�� 
ComplexListNode* CreateNode(int nValue); 
//��������ϵ 
void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling);
//����������� 
void PrintList(ComplexListNode* pHead);
