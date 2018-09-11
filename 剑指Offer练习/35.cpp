#include<bits/stdc++.h>
#include "../Utilities/ComplexList.h"
using namespace std;

void CloneNodes(ComplexListNode* pHead);
void ConnectSiblingNodes(ComplexListNode* pHead);
ComplexListNode* ReconnectNodes(ComplexListNode* pHead);

//[�ܵĺ���]����һ����������,����ԭ������ͷ,���ظ��ƺ������ͷ
ComplexListNode* Clone(ComplexListNode* pHead) {
	CloneNodes(pHead);//��һ��O(n)ɨ��,����¡�ϲ�
	ConnectSiblingNodes(pHead);//�ڶ���O(n)ɨ��,����Sibling��
	//Ϊʲô����һ��ɨ��?��Ϊ��һ��ɨ��ʱ�����Ľ�㻹û��¡����
	//���Sibling��ָ�����Ľ��,��û������Sibling��

	return ReconnectNodes(pHead);//������O(n)ɨ��,�𿪸��2������
}

//[��¡�ϲ�]�Ը��������ÿ������¡,�������ԭ���֮next��ԭnext֮ǰ
void CloneNodes(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;//��ͷ��㿪ʼ
	//����next��
	while(pNode != nullptr) {
		//���Ƶ�ǰ���
		ComplexListNode* pCloned = new ComplexListNode();
		pCloned->m_nValue = pNode->m_nValue;
		pCloned->m_pNext = pNode->m_pNext;//ע����nextҲָ��ǰ��next
		pCloned->m_pSibling = nullptr;//Ψ���������ָ����ʱ�ÿ�
		//��ԭ����nextָ���¿�¡�Ľ��,���Կ�¡�Ľ����next�����Ǳ���������
		pNode->m_pNext = pCloned;
		//����next��
		pNode = pCloned->m_pNext;
	}
}

//����Sibling��,����[��¡�ϲ�]�������(next���Ѿ������������)
void ConnectSiblingNodes(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;//��ͷ��㿪ʼ
	//һֱ����next����
	while(pNode != nullptr) {
		//��¡�Ľ��������ԭ���ĺ���һ��
		ComplexListNode* pCloned = pNode->m_pNext;
		//����Ҫ��¡��Sibling��,ֻҪԭ����Sibling��ǿ�
		if(pNode->m_pSibling != nullptr) {
			//��ôSibling����ָ���Ǹ����ĺ�һ�����Ҳ�������¡���
			//���Ա����Ŀ�¡����Sibling��ָ��ԭ����Sibling���next
			pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
		}
		//һֱ����next����
		pNode = pCloned->m_pNext;
	}
}

//������������,��֮ǰ��ԭ��������
//�����µĿ�¡������Ҳά����,Ȼ�󷵻�֮
ComplexListNode* ReconnectNodes(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;//ԭ�����ϵ��α�ָ��,��[�ϲ�����]ͷ��ʼ
	ComplexListNode* pClonedHead = nullptr;//��¡�����ͷ
	ComplexListNode* pClonedNode = nullptr;//��¡�����ϵ��α�ָ��

	if(pNode != nullptr) {//�����Ƿ�ֹ��ָ���쳣
		//��¡����ͷ�����ϵ��α궼��ʼ��Ϊ[�ϲ�����]�ĵڶ������
		pClonedHead = pClonedNode = pNode->m_pNext;
		//ԭ�����next,��[�ϲ�����]�����¡����next
		pNode->m_pNext = pClonedNode->m_pNext;
		//ԭ����ָ�������
		pNode = pNode->m_pNext;
	}

	//����,[ԭ����ָ��]��[��¡����ָ��]����һ����λ
	//�����[ԭ����ָ��]��ʵ�Ƕ�Ӧ��ǰ[��¡����ָ��]��ָԪ�ص���һ��Ԫ��
	//����[ԭ����ָ��]�ͺ���һ����λ��[��¡����ָ��]������[�ϲ�������]

	//ֻҪ[ԭ����ָ��]û����,Ҳ��û�б�����
	while(pNode != nullptr) {
		//[��¡����ָ��]��nextҲ������ǰ���[ԭ����ָ��]��next
		pClonedNode->m_pNext = pNode->m_pNext;
		//[��¡����ָ��]�����
		pClonedNode = pClonedNode->m_pNext;

		//����,[��¡����ָ��]�ֺ�[ԭ����ָ��]ָ���Ԫ�����Ӧ��
		//����[��¡����ָ��]������[�ϲ�������]
		//[ԭ����ָ��]Ҫά��next��(��������),Ҫ�������[��¡����ָ��]

		//[ԭ����ָ��]��next�����[��¡����ָ��]����һ��
		pNode->m_pNext = pClonedNode->m_pNext;
		//[ԭ����ָ��]������
		pNode = pNode->m_pNext;
	}

	return pClonedHead;//���շ���[��¡����ͷ]
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
int main() {
	ComplexListNode* pNode1 = CreateNode(1);
	ComplexListNode* pNode2 = CreateNode(2);
	ComplexListNode* pNode3 = CreateNode(3);
	ComplexListNode* pNode4 = CreateNode(4);
	ComplexListNode* pNode5 = CreateNode(5);

	BuildNodes(pNode1, pNode2, pNode3);
	BuildNodes(pNode2, pNode3, pNode5);
	BuildNodes(pNode3, pNode4, nullptr);
	BuildNodes(pNode4, pNode5, pNode2);
	
	ComplexListNode* newNode=Clone(pNode1);
	
	PrintList(newNode);

	return 0;
}
