#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;

//stack��queue��ϰ 
//cin.get(char)����char��,cin.getline(char*,����,������)

int main(){
	//stack
	stack<int> s;
	s.push(3);//push
	s.push(5);
	cout<<s.top()<<"\n";//ȡtop 
	s.pop();//pop
	cout<<s.top()<<"\n";
	cout<<s.size()<<"\n";//size
	cout<<s.empty()<<"\n";//empty�п� 
	
	string str(10,'-');
	cout<<str<<endl;
	
	//queue
	queue<int> q;
	q.push(3);//push
	q.push(5);
	cout<<q.front()<<"\n";//front��ͷ 
	cout<<q.back()<<"\n";//back��β
	cout<<boolalpha<<q.empty()<<"\n";//empty
	q.pop();//pop���� 
	cout<<q.size()<<"\n";//size
	
	//��cin�������ַ���ϰ 
	char next;
	do{
		cin.get(next);
		cout<<"-"<<next<<"-";//������и�"-\n-" 
	}while(next!='\n');
	
	cout<<str<<endl;
	
	//cin.getline(�ַ�ָ��(char*),�ַ�����N(int),������(char));
	//ֱ������N-1������������ָ���Ľ�����Ϊֹ������ָ������������Ĭ�Ͻ�����Ϊ'\n'
	char *c=new char[20];
	cin.getline(c,10,'p');
	printf("%s",c);
	
	return 0;
}
