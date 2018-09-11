#include<bits/stdc++.h>
#include "../Utilities/BinaryTree.h"
using namespace std;

//�������(��)��������,���뷴��ʹ�õ������������
void Serialize(const BinaryTreeNode* pRoot, ostream& stream) {
	if(pRoot == nullptr) {//���������Ϊ��
		stream << "$,";//��ôҲҪʹ��һ������Ǻż�¼,д�������
		return;//�ս��û����������,ֱ�ӷ���
	}
	//����,�ǿ�,�������ֵд�������
	stream << pRoot->m_nValue << ',';
	//ǰ�����:��-��-��,�ֱ�����������������л�
	//�б�����ǰ����Щ��,������ⲻ���ǿ�У��,��Ϊ��ҲҪ�����л���¼!
	Serialize(pRoot->m_pLeft, stream);
	Serialize(pRoot->m_pRight, stream);
}

//���������г��Զ�ȡһ������,����ַд��
//�����Ƿ�ɹ���ȡ��д��������һ������
bool ReadStream(istream& stream, int* number) {
	if(stream.eof())//����Ѿ�������������β
		return false;//���ö���,������

	char buffer[32];//���ڴ洢������������
	buffer[0] = '\0';//��ͷ��Ϊ'\0'������,�������û��������Ҳ����������

	char ch;
	stream >> ch;//���������ж���һ���ַ�
	int i = 0;//�α껹�Ǵ�0��ʼ,���������Ч�ַ��Ḳ�ǵ�ǰ���'\0'
	//ֻҪû����������,����û�����Ĳ��Ƿָ���,��һֱ���¶�
	while(!stream.eof() && ch != ',') {
		buffer[i++] = ch;
		stream >> ch;
	}
	//����,�����Ѿ�������һЩ����,����Ƿ�Ϊ����
	//ע��,���û��������,buffer�п�ͷ����'\0'������
	bool isNumeric = false;
	//�����������Ч���ַ�(i>0),���Ҷ����Ĳ��ǿս��(buffer[0]!='$')
	if(i > 0 && buffer[0] != '$') {
		*number = atoi(buffer);//���ַ���ת��������,����ַ����
		isNumeric = true;
	}
	//��ʵֱ����if��return true,��if����return false�ͺ���
	//û��Ҫ��˸��������¼,���ﻹ�Ǳ������ߵ�д��
	return isNumeric;
}


//�ݹ麯��,�������(��)�������ָ������ĵ�ַ,������������
//���������еĶ������з����л�д����ڵ�ָ����,�γɶ�����
void Deserialize(BinaryTreeNode** pRoot, istream& stream) {
	int number;//��ǰ��ȡ��������
	//����ܴ��������гɹ���ȡ��һ�����ֵ�number��
	if(ReadStream(stream, &number)) {
		//˵����ζ�����һ����ʵ���ڵĽ��
		//Ϊ��ǰ�ڵ����ռ�,����*pRoot���ǵ�ǰ����ָ��(����ָ��ȡ��һ�ε�ַ)
		*pRoot = new BinaryTreeNode();
		//����ֵ
		(*pRoot)->m_nValue = number;
		//��Ϊ��ǰ�����,��������������������û������,������Ϊ��
		(*pRoot)->m_pLeft = nullptr;
		(*pRoot)->m_pRight = nullptr;
		//�������������ֱ����л�,�������һ�µ�һ��������ô����
		//����"(*pRoot)"��ȡ������ָ�����
		//Ȼ��"->m_pLeft"��ȡ��������ָ��
		//Ȼ����ȡ"&"Ҳ�͵õ��˱��ڵ��������ָ��ĵ�ַ,���Դ���ݹ麯����
		Deserialize(&((*pRoot)->m_pLeft), stream);
		Deserialize(&((*pRoot)->m_pRight), stream);
	}
}

//            8
//        6      10
//       5 7    9  11
int main() {
	//����һ�ö�����
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);
	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);
	//�����һ��
	BinaryTreeNode* pRoot=pNode8;
	PrintTree(pRoot);
	//�������л����ļ���
	//[����]����ԭ��д����char* fileName,�ⲻ��C++���е��÷�
	char fileName[] = "test.txt"; 
	ofstream fileOut;//ofstream��Output File Stream�ļ������
	//ofstreamҲ��ostream��һ��,����ֱ�Ӵ���
	fileOut.open(fileName);//���ļ�
	Serialize(pRoot, fileOut);//���л�
	fileOut.close();//�ر��ļ�
	//���л���ɺ����������ڴ��ڴ�������
	DestroyTree(pNode8);

	//��ʱ,�ڴ����Ѿ�û���������
	cout<<"--------------------------------"<<endl;

	//���ļ��з����л�
	ifstream fileIn2;//ifstream��Iutput File Stream�ļ�������
	fileIn2.open(fileName);//���ļ� 
	BinaryTreeNode* pNewRoot = nullptr;
	Deserialize(&pNewRoot, fileIn2);//����,������ڵ�ָ��ĵ�ַ 
	fileIn2.close();//�ر��ļ� 
	//�����һ��
	PrintTree(pNewRoot);
	//���� 
	DestroyTree(pNewRoot);

	return 0;
}
