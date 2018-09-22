#include<iostream>
#include<vector>
using namespace std;

//vector��ϰ 

int main(){
	vector<int> v1;
	vector<int> v2(5);//��ʼ��С
	cout<<v1.size()<<"\t"<<v2.size()<<endl; 
	vector<int> v3(3,4);//��ʼ��С3,����ÿ������4
	
	for(int i=0;i<3;i++)
		cout<<v3[i];
	cout<<endl;
	
	vector<int> v4(v3.begin(),v3.begin()+1);//��v3��һ���ֹ���v4 
	cout<<v4.size()<<endl;
	
	int a[]={1,2,3,4,5};
	vector<int> v5(a+1,a+3);//�������鹹��v5 
	
	//size()����ʵ��С,capacity()������Ĵ�С
	//resize()�޸�ǰ��,reserve()�޸ĺ���(���ռ���Ұ��)
	cout<<v5.size()<<"\t"<<v5.capacity()<<endl;
	v5.resize(10);
	cout<<v5.size()<<"\t"<<v5.capacity()<<endl;//capacity������size��󳬳�capacity�����һ���� 
	v5.reserve(20);
	cout<<v5.size()<<"\t"<<v5.capacity()<<endl;
	
	vector<int> v6(a+1,a+4);//������a+4���λ�� 
	
	v6.push_back(6);//β��
	v6.erase(v6.begin()+2);//����λ��ɾ��(���������)
	for(vector<int>::const_iterator it=v6.cbegin();it!=v6.cend();it++)//��c��const�� 
		cout<<*it<<"\t";
	cout<<"\n";
	//2,3,6
		
	v6.pop_back();//βɾ
	v6.insert(v6.cbegin()+1,8);//����λ�ò��� 
	for(vector<int>::const_iterator it=v6.cbegin();it!=v6.cend();it++) 
		cout<<*it<<"\t";
	cout<<"\n";
	
	//2,8,3
	
	v6.swap(v3);//v6��v3�ཻ��
	for(vector<int>::const_iterator it=v6.cbegin();it!=v6.cend();it++) 
		cout<<*it<<"\t";
	cout<<"\n";
	
	//���ʵ�һ�������һ��Ԫ��
	cout<<v3.front()<<"\t"<<v3.back()<<endl;
	
	//���
	v6.clear();
	cout<<v6.size()<<"\t"<<v6.capacity()<<endl;//capacity���� 
	return 0;
}
