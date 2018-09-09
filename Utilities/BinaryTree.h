//���������ṹ�� 
struct BinaryTreeNode 
{
    int                    m_nValue;//����ֵ 
    BinaryTreeNode*        m_pLeft;//��������ַ 
    BinaryTreeNode*        m_pRight;//��������ַ 
};

//�������ֵ,����һ����������� 
BinaryTreeNode* CreateBinaryTreeNode(int value);
//���ӽ��,�������ڵ������������� 
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
//���ָ���Ķ�������� 
void PrintTreeNode(const BinaryTreeNode* pNode);
//�������ڵ�,������ö����� 
void PrintTree(const BinaryTreeNode* pRoot);
//�������ڵ�,ɾ�����ö����� 
void DestroyTree(BinaryTreeNode* pRoot);
