#include<iostream>
#include<string>
using namespace std;

//string��ϰ 

int main(){
	string s1;
	string s2=s1;
	string s3="OK 123\nABC ";
	string s4(s3);
	string s5(10,'a');//ֻ����char 
	string s6("����");
	string* s7=new string(3,'b');
	cout<<s1<<"\n"<<s2<<"\n"<<s3<<"\n"<<s4<<"\n"<<s5<<"\n"<<s6<<"\n"<<*s7<<endl;
	
	string s8(20,'-');
	cout<<s8<<endl;
	
	//ƴ�� 
	string s9=s6+*s7;
	cout<<s9<<endl;
	
	//����,�Կհ׷�(��������)�ָ� 
//	cin>>s1>>s2;
//	cout<<s1<<"\t"<<s2<<endl;
	
	//����,���Ƕ���һ��
//	getline(cin,s1);
//	cout<<s1<<endl;
//	getline(cin,s1);
//	cout<<s1<<endl;
	 
	//string������ַ���ֵ���ַ�����ֵ����һ�������ʹ��ʱ
	//����ȷ��+��������������������һ����string
	//+�����ϵ�!!!!!!!!!!! 
	s1=s6+"����"+"����";
	cout<<s1<<endl;//������������ 
	
	//��������
	int len=s1.size();
	cout<<"������"<<len<<endl;
	for(int i=0;i<len;i++)
		cout<<s1[i];
	cout<<"\n";
	
	//���������� 
	for(string::iterator it=s1.begin();it!=s1.end();it++){
		cout<<*it;
		*it='6';
	}
	cout<<"\n";
	
	//ʹ��const_iteratorʹ�÷���Ԫ��ʱ���ܶ�����д
	//�������ָ����˼���
	for(string::const_iterator it=s1.begin();it!=s1.end();it++){
		cout<<*it;//����ܶ�6,һ�����Ŀ���ռ����ASCII���ַ� 
		//������*it=����д��ֵ 
	}
	cout<<"\n";	
	
	//�����Ӵ�
	size_t found1=s1.find("56");//std::size_t����,find()���� 
	size_t found2=s3.find(" 1");
	if(found1!=string::npos)//string::npos��ʾ�Ҳ��� 
		cout<<found1<<endl;
	if(found2!=string::npos)
		cout<<found2<<endl;//�����һ���ҵ�����ʼ�±� 
	
	return 0;
}
