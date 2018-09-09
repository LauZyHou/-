#include "../Utilities/List.h"
#include<bits/stdc++.h>
using namespace std;

//�ǵݹ�ʵ�ַ������ 
void PrintListReversingly_Iteratively(ListNode* pHead)
{
	//����һ����Ž���ַ��STL����ջ 
    stack<ListNode*> nodes;

	//��ͷ��㿪ʼ 
    ListNode* pNode = pHead;
    while(pNode != nullptr)//ֱ���������,Ϊ�� 
    {
        nodes.push(pNode);//��ջ 
        pNode = pNode->m_pNext;//����� 
    }

	//ֻҪջ��Ϊ�� 
    while(!nodes.empty())
    {
        pNode = nodes.top();//ȡջ��Ԫ�� 
        printf("%d\t", pNode->m_nValue);//���ֵ 
        nodes.pop();//����ջ��Ԫ�� 
    }
}

//�ݹ�ʵ�ַ������ 
void PrintListReversingly_Recursively(ListNode* pHead)
{
	//���ͷ���ʵ���ǵ�ǰ��ʣ������ĵ�һ����� 
    if(pHead != nullptr)
    {
    	//ֻҪ����Ľ�㲻Ϊ�� 
        if (pHead->m_pNext != nullptr)
        {
        	//�ͽ��䵱��ͷ���,����������������Լ��γɵݹ� 
            PrintListReversingly_Recursively(pHead->m_pNext);
        }
 		//�ݹ���ջʱ�����ֵ,��ʵ���˷������ 
        printf("%d\t", pHead->m_nValue);
    }
}

int main(){
	//������� 
	ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
	//�������ӹ�ϵ,�γ����� 
    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	//ָ��ͷ��� 
	ListNode* pHead=pNode1;
	//���÷ǵݹ�� 
	PrintListReversingly_Iteratively(pHead);
    printf("\n");
    //���õݹ�� 
	PrintListReversingly_Recursively(pHead);
	return 0;
}
