#include<iostream>
#include<cstdio>
#include<cstring>
//#include<fstream>
using namespace std;

//ͳ���ļ��е�����Ŀ 

char buffer[256];

int main(){
	FILE *fp;//C�����ļ���д 
	fp=fopen("./2.txt","r");
	if(!fp){
		cout<<"û��"<<endl;
	}
	int a[3];
	memset(a,0,sizeof(int)*3);
	while(fscanf(fp,"%s",buffer)>0){//û�����ļ�β 
		if(0==strcmp(buffer,"ok1"))
			a[0]++;
		else if(0==strcmp(buffer,"ok2"))
			a[1]++;
		else if(0==strcmp(buffer,"ok3"))
			a[2]++;
	}
	cout<<"ok1:"<<a[0]<<"\tok2:"<<a[1]<<"\tok3:"<<a[2]<<endl;
	fclose(fp);//���ļ� 
	return 0;
}
