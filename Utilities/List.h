//������ṹ�� 
struct ListNode
{
    int       m_nValue;//����ֵ 
    ListNode* m_pNext;//ָ����һ����ָ�� 
};

//�������ֵ,������㲢�����½���ַ 
ListNode* CreateListNode(int value);
//�����������,ʹ��һ������Ϊǰһ������next��� 
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
//������ 
void PrintListNode(ListNode* pNode);
//����ͷ���,����������� 
void PrintList(ListNode* pHead);
//������������ 
void DestroyList(ListNode* pHead);
//����һ��ֵ,����½�㵽����β�� 
void AddToTail(ListNode** pHead, int value);
//����һ��ֵ,ɾ����ֵ��Ӧ�������� 
void RemoveNode(ListNode** pHead, int value);
