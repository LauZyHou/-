#include<bits/stdc++.h>
using namespace std;
//�����ڵ�ָ��Ķ�����
struct BinaryTreeNode {
	int                    m_nValue;//���ֵ
	BinaryTreeNode*        m_pLeft;//������
	BinaryTreeNode*        m_pRight;//������
	BinaryTreeNode*        m_pParent;//�����
};

//�������ֵ,����һ�����������
BinaryTreeNode* CreateBinaryTreeNode(int value) {
	//�������������
	BinaryTreeNode* pNode = new BinaryTreeNode();
	//����ֵ,��������,������Ĭ��Ϊ��
	pNode->m_nValue = value;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;
	pNode->m_pParent = nullptr;
	return pNode;
}

//���ӽ��,�������ڵ�������������
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight) {
	if(pParent != nullptr) {//У�鸸�ڵ�������
		//ʹ���ڵ�ָ����������
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;

		//��������������ǿ�,��ô����ҲҪָ�򸸽��
		if(pLeft != nullptr)
			pLeft->m_pParent = pParent;
		if(pRight != nullptr)
			pRight->m_pParent = pParent;
	}
}

//���ָ���Ķ��������,�ⲿ�ֺ�ǰ���BinaryTreeһ��,û����
void PrintTreeNode(BinaryTreeNode* pNode) {
	if(pNode != nullptr) {//У��ý��ǿ�
		printf("value of this node is: %d\n", pNode->m_nValue);

		if(pNode->m_pLeft != nullptr)//���ӽ��
			printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
		else
			printf("left child is null.\n");

		if(pNode->m_pRight != nullptr)//���ӽ��
			printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
		else
			printf("right child is null.\n");
	} else {
		printf("this node is null.\n");
	}
	printf("\n");
}

//�������ڵ�,������ö�����
void PrintTree(BinaryTreeNode* pRoot) {
	PrintTreeNode(pRoot);//����������Ϣ

	if(pRoot != nullptr) {//У��������ǿ�
		//�ݹ�ص���������,���������������Ϣ
		if(pRoot->m_pLeft != nullptr)
			PrintTree(pRoot->m_pLeft);

		if(pRoot->m_pRight != nullptr)
			PrintTree(pRoot->m_pRight);
	}
}

//�������ڵ�,ɾ�����ö�����
void DestroyTree(BinaryTreeNode* pRoot) {
	if(pRoot != nullptr) {
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}

//����������ϵ�һ�����,�����������������һ���
BinaryTreeNode* GetNext(BinaryTreeNode* pNode) {
	if(pNode == nullptr)//�ǿ�У��
		return nullptr;

	BinaryTreeNode* pNext = nullptr;//Ҫ���ص���һ���
	//[1]�������������
	if(pNode->m_pRight != nullptr) {
		BinaryTreeNode* pRight = pNode->m_pRight;//������������ʼ
		//��ͣ����������,ֱ���ߵ�Ҷ��
		while(pRight->m_pLeft != nullptr)
			pRight = pRight->m_pLeft;
		pNext = pRight;//���������������Ҭ�Ӿ�������
	}
	//[2]���������������,����ǰ��㲻�Ǹ��ڵ�
	else if(pNode->m_pParent != nullptr) {
		//���������ƶ�ָ��
		BinaryTreeNode* pCurrent = pNode;//һ���ӵ�ǰ��㿪ʼ
		BinaryTreeNode* pParent = pNode->m_pParent;//һ�����丸��㿪ʼ
		//����Ľ��û�����ܸ�,������Ľ��ʼ�����������������ʱ
		while(pParent != nullptr && pCurrent == pParent->m_pRight) {
			//���������Ҫһֱ������
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}
		//����,����Ľ�㳬���ܸ�(��ʾ�Ѿ�û�������������һ�����)
		//����������Ľ���Ϊ���������������
		pNext = pParent;//������������,��������Ľ��Ϊ�����������һ���(���)
	}

	return pNext;
}

//            8
//        6      10
//       5 7    9  11
int main() {
	//������� 
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

	//���ӳ��� 
	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);
	
	//���������7�ĺ���Ӧ��8 
	cout<<GetNext(pNode7)->m_nValue<<endl;
	
	//���ٶ����� 
	DestroyTree(pNode8);
	return 0;
}
