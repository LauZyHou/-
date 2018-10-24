#include<bits/stdc++.h>
#include"../Utilities/Tree.h"
using namespace std;

//�ݹ麯��
//���pRoot��pNode��·��,�����·��������path��,�����Ƿ��ܵ���
bool GetNodePath(const TreeNode* pRoot, const TreeNode* pNode, list<const TreeNode*>& path) {
	if(pRoot == pNode)//�ݹ����:ͬһ���
		return true;

	path.push_back(pRoot);//�������·���ĵ�һ�����

	bool found = false;//���趨�ɲ��ɴ�

	//ǰ�����DFS,�����������ӽ��
	//����:��������cbegin()������begin()
	vector<TreeNode*>::const_iterator i = pRoot->m_vChildren.cbegin();
	while(!found && i < pRoot->m_vChildren.end()) {//�ҵ���,�����ӽ��ȫ�������˾��˳�
		found = GetNodePath(*i, pNode, path);//�ݹ��ȥ�����ӽ���ܷ��Ǹ�·��
		++i;
	}

	if(!found)//û�ҵ�
		path.pop_back();//�������㵯���ٻص���һ��

	return found;//�ص���һ��
}

//�õ�����·��path1��path2�����һ���������
const TreeNode* GetLastCommonNode
(
    const list<const TreeNode*>& path1,
    const list<const TreeNode*>& path2
) {
	//����·���Ŀ�ʼ֮��,����:����Ӧ��cbegin()������begin()
	list<const TreeNode*>::const_iterator iterator1 = path1.cbegin();
	list<const TreeNode*>::const_iterator iterator2 = path2.cbegin();

	const TreeNode* pLast = nullptr;//��¼���һ���������

	//������������û�ߵ���,����:����Ӧ��cend()������end()
	while(iterator1 != path1.cend() && iterator2 != path2.cend()) {
		if(*iterator1 == *iterator2)//��������ǵ�ַ,��ַһ������ͬһ�����
			pLast = *iterator1;//�������ΪĿǰ�ҵ������Ĺ������

		//����������ͬ��������
		iterator1++;
		iterator2++;
	}

	return pLast;//���õ��ľ������(���һ��)�������
}

//��pRootΪ����������pNode1��pNode2����͹������Ȳ�����
const TreeNode* GetLastCommonParent(const TreeNode* pRoot, const TreeNode* pNode1, const TreeNode* pNode2) {
	//����Ϸ��Լ��
	if(pRoot == nullptr || pNode1 == nullptr || pNode2 == nullptr)
		return nullptr;

	//��pNode1��·������
	list<const TreeNode*> path1;
	GetNodePath(pRoot, pNode1, path1);

	//��pNode2��·������
	list<const TreeNode*> path2;
	GetNodePath(pRoot, pNode2, path2);

	//������������һ��������㼴������
	return GetLastCommonNode(path1, path2);
}

// ��״��ͨ����
//              1
//            /   \
//           2     3
//       /       \
//      4         5
//     / \      / |  \
//    6   7    8  9  10
int main() {
	TreeNode* pNode1 = CreateTreeNode(1);
	TreeNode* pNode2 = CreateTreeNode(2);
	TreeNode* pNode3 = CreateTreeNode(3);
	TreeNode* pNode4 = CreateTreeNode(4);
	TreeNode* pNode5 = CreateTreeNode(5);
	TreeNode* pNode6 = CreateTreeNode(6);
	TreeNode* pNode7 = CreateTreeNode(7);
	TreeNode* pNode8 = CreateTreeNode(8);
	TreeNode* pNode9 = CreateTreeNode(9);
	TreeNode* pNode10 = CreateTreeNode(10);

	ConnectTreeNodes(pNode1, pNode2);
	ConnectTreeNodes(pNode1, pNode3);

	ConnectTreeNodes(pNode2, pNode4);
	ConnectTreeNodes(pNode2, pNode5);

	ConnectTreeNodes(pNode4, pNode6);
	ConnectTreeNodes(pNode4, pNode7);

	ConnectTreeNodes(pNode5, pNode8);
	ConnectTreeNodes(pNode5, pNode9);
	ConnectTreeNodes(pNode5, pNode10);
	
	cout<<GetLastCommonParent(pNode1,pNode6,pNode8)->m_nValue<<endl;//2
	return 0;
}
