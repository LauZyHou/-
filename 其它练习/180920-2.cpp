#include<iostream>
#include<string>
#include<cctype>//c������ctype.h 
using namespace std;
//cctype����string�ϵ���ϰ 

int main(){
	string s="OK 123\nABC ";
	
	//is alpha number,����ĸ������ʱ���ط�0ֵ 
	for(string::iterator it=s.begin();it!=s.end();it++){
		cout<<isalnum(*it)<<" ";//��ĸ������1,���ֶ�����4?? 
	}
	cout<<"\n";
	
	//is alpha,����ĸʱ���ط�0ֵ
	for(int i=0;i<s.size();i++){
		cout<<isalpha(s[i])<<" ";
	}
	cout<<"\n";
	
	
	return 0;
}
