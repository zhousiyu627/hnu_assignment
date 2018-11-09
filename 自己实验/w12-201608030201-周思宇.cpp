#include<iostream>
#include<set>
#include<cstring>
using namespace std;
void getset(string &a){
	set<char>A;
	char x;
	while((x=getchar())!='\n'){
		if(isdigit(x)||isalpha(x)){
			pair<set<char>::iterator,bool>r=A.insert(x);
			if(r.second)
				a+=*r.first;
		}
	}
} 
void getrela(int r[100][100],string a,int &count){
	memset(r,0,sizeof(r));
	int co,ro,sign=0;
	char p,q;
	string x;
	getline(cin,x);
	for(int i=0;i<x.size();i++){
		if(isdigit(x[i])||isalpha(x[i])){
			if(sign%2==0)
				p=x[i];
			else if(sign%2==1){
				q=x[i];
				for(int j=0;j<a.size();j++){
					if(p==a[j])
						ro=j;
					if(q==a[j])
						co=j;
				}
				r[ro][co]=1;
				count++;
			}
			sign++;
		}
	}
}
void rR(int M[100][100],int m[100][100],int n,int &count){
	memcpy(m,M,100*100);
	for(int i=0;i<n;i++){
		if(m[i][i]==0){
			m[i][i]=1;
			count++;
		}
	} 
}
void sR(int M[100][100],int m[100][100],int n,int &count){
	memcpy(m,M,100*100);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(m[i][j]==1&&m[j][i]==0){
				m[j][i]=1;
				count++;
			}
		} 
	}
}
void tR(int M[100][100],int m[100][100],int n,int &count){
	memcpy(m,M,100*100);
	for(int j=0;j<n;j++){//warshall 
		for(int i=0;i<n;i++){  
			if(m[i][j]==1){  
				for(int k=0;k<n;k++){  
					if(m[j][k]==1&&m[i][k]==0){
						m[i][k]=1;
						count++;
					}
				}
			}
		}
	}
} 
int matrixmulti(int M[100][100],int m[100][100],int T[100][100],int n){
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				T[i][j]+=M[i][k]*m[k][j];
				if(T[i][j]>=1){
					count++;
					break;
				}	
			}
		} 
	}
	return count;
}
void matrixplus(int M[100][100],int m[100][100],int n,int &count){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(M[i][j]==0&&m[i][j]==1){
				M[i][j]=1;
				count++;
			}
}
void printrela(int m[100][100],string a,int c){
	int count1=0;
	for(int i=0;i<a.size()&&count1!=c;i++){
		for(int j=0;j<a.size();j++){
			if(m[i][j]==1){
				count1++;
				cout<<'<'<<a[i]<<','<<a[j]<<'>'<<(count1==c?'\n':',');
			}
		}
	}
}
void printM(int m[100][100],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<m[i][j]<<' ';
		cout<<endl;
	}
}
void tr7(int M[100][100],string a,int count){
	int A[100][100],B[100][100],C[100][100],ca=count,cb=count,cc=count;
	memcpy(B,M,100*100);
	memcpy(C,M,100*100);
	for(int i=0;i<a.size()-1;i++){
		ca=cb;
		memcpy(A,B,100*100);
		memset(B,0,sizeof(B));
		cb=matrixmulti(A,M,B,a.size());
		printrela(A,a,ca);
		printrela(M,a,count);
		printrela(B,a,cb);
		matrixplus(C,B,a.size(),cc);
		cout<<endl;
	}
	cout<<"���ݹ�ϵ�հ�Ϊ:";
	printrela(C,a,cc);
	cout<<endl;
	cout<<"��żת��Ϊ����:"<<endl;;
	printM(C,a.size());
}
int main(){
	int r1[100][100],r2[100][100],c1=0,c2=0,choice;
	string a;
	printf("\n========================\n");
	printf("1...�������Ԫ��ֵ\n");
	printf("2...��ϵ�ĸ���\n");
	printf("3...�Է��հ�\n");
	printf("4...�ԳƱհ�\n");
	printf("5...��ż��ʽ�Ĺ�ϵת��ϵ����\n");
	printf("6...���þ������ϵ�ĸ���\n");
	printf("7...������ż��ʽ�ĸ����󴫵ݱհ�\n");
	printf("8...����warshall�㷨���󴫵ݱհ�\n");
	printf("0...�˳�\n========================\n");
	while(printf("����ѡ��")){
		scanf("%d",&choice);
		fflush(stdin);
		if(choice==0) break;
		switch(choice){
			case 1:{
				cout<<"���뼯��a"<<endl;
				getset(a);
				cout<<"�����ϵR1"<<endl; 
				getrela(r1,a,c1);
				cout<<"�����ϵR2"<<endl; 
				getrela(r2,a,c2);
				cout<<"A:";
				for(int i=0;i<a.size();i++)
					cout<<a[i]<<(i==a.size()-1?'\n':',');
				cout<<"��ϵR1"; 
				printrela(r1,a,c1);
				cout<<"��ϵR2"; 
				printrela(r2,a,c2);
				break;
			}
			case 2:{
				int T[100][100];
				int ct=matrixmulti(r1,r2,T,sizeof(a));
				cout<<"R1��R2:";
				printrela(T,a,ct);
				break;
			}
			case 3:{
				int RR[100][100],cR=c1;
				cout<<"R1���Է��հ���";
				rR(r1,RR,a.size(),cR);
				printrela(RR,a,cR);
				break;
			}
			case 4:{
				int SR[100][100],cS=c1;
				cout<<"R1�ĶԳƱհ���";
				sR(r1,SR,a.size(),cS);
				printrela(SR,a,cS);
				break;
			}
			case 5:{
				cout<<"R1����ż��";
				printrela(r1,a,c1);
				cout<<"R1�Ĺ�ϵ����"<<endl;
				printM(r1,a.size()); 
				break;
			}
			case 6:{
				int T[100][100];
				memset(T,0,sizeof(T));   
				cout<<"R1�ľ���"<<endl;
				printM(r1,a.size());
				cout<<"R2�Ĺ�ϵ����"<<endl;
				printM(r2,a.size()); 
				matrixmulti(r1,r2,T,a.size());
				cout<<"���Ϻ�ľ���"<<endl;
				printM(T,a.size()); 
				break;				
			}
			case 7:{
				tr7(r1,a,c1);
				break;
			}
			case 8:{
				int TR[100][100],cT=c1;
				cout<<"R1�Ĺ�ϵ����"<<endl;
				printM(r1,a.size());
				tR(r1,TR,a.size(),cT);
				cout<<"warshall��ľ���"<<endl;
				printM(TR,a.size());
				cout<<"R1�Ĵ��ݱհ���";
				printrela(TR,a,cT);
				break;
			}
		}
	}
	return 0;
}
/*
1
a,b,c,d,e
<a,b>;<b,c>;<a,d>;<c,e>;<e,a>;<d,b>
<b,a>;<c,b>;<d,a>;<e,c>;<a,e>;<b,d>
*/
