#include<bits/stdc++.h>
using namespace std;
/*
 ����һ���з�������������������ķ�תֵ��
*/
int main(){
	string a;
	cin>>a;
	int k=0;
	if(a[0]=='+'||a[0]=='-'){
		k=1;
		cout<<a[0];
	}
	bool weav=true;
	for(int i=a.length()-1;i>=k;i--){
		if(a[i]=='0'&&weav==true&&i!=k)
			continue;
		else
			weav=false;
		cout<<a[i];
	}
	return 0;
}
