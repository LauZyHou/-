#include<bits/stdc++.h>
using namespace std;
//B���������
int t,n;
int a[1010];
int i,j,maxi;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		i=j=0;//i+1,j+1����Ŀ����
		maxi=0;
		while(i<n && j<n){
			if(a[i]<=i){//������Ҫa[i]>=(i+1) 
				i+=1;
				continue;
			}
			if(j<i){//j��ǰ 
				j=i;
			}
			if(){
				// FIXME
			}
			
			
		}
	}
	
	return 0;
}
