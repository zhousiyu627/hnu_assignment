#include<iostream>
using namespace std;
long long InputSet(string str)
{
	int i,k;
	long long c=0,y=1;
	for(i=0;i<str.length();i++)
	{		
		if((str[i]>='0')&&(str[i]<='9'))k=str[i]-'0';
		else if((str[i]>='a')&&(str[i]<='z'))k=str[i]-'a'+10;
		else if((str[i]>='A')&&(str[i]<='Z'))k=str[i]-'A'+10+26;
		else k=-1;
		if(k>=0)c=(c|y<<k);
	}
	return c;
}

char SetI2C(int i)
{
	char c;
	if(i<10)c='0'+i;
	else if(i<36)c='a'+i-10;
	else c='A'-10-26+i;
	return c;
}

string OutputSet(long long a)
{
	string str="";
	long long y=1;
	for(int i=0;i<62;i++)
	{
		if(a&(y<<i))str=str+SetI2C(i)+',';
	}	
	return (str=="")?"":str.substr(0,str.length()-1);
}

string OutputSetDCL(long long a,long long b)
{
	string str="";
	char ca,cb;
	long long c,y=1;
	int i,j;
	for(i=0;i<62;i++)
	{
		if(!(a&(y<<i)))continue;
		ca=SetI2C(i);
		for(j=0;j<62;j++)
		{
			if(b&(y<<j))str=str+'<'+ca+','+SetI2C(j)+">,";
		}
	}
	return (str=="")?"":str.substr(0,str.length()-1);
}

int main()
{
	long long a=0,b=0;
    string sa,sb;
    cout<<"���뼯��A:"<<endl;
	cin>>sa;
	a=InputSet(sa);
    cout<<"���뼯��B:"<<endl;
	cin>>sb;
	b=InputSet(sb);
	cout<<"A:"<<OutputSet(a)<<endl;
	cout<<"B:"<<OutputSet(b)<<endl;
	cout<<"���ϵĽ�:"<<OutputSet(a&b)<<endl;
	cout<<"���ϵĲ�:"<<OutputSet(a|b)<<endl;
	cout<<"���ϵĲ�:"<<OutputSet(a&~(a&b))<<endl;
	cout<<"���ϵĶԳƲ�:"<<OutputSet((a|b)&~(a&b))<<endl;
	cout<<"����A��B�ĵѿ�����:"<<endl;
	cout<<OutputSetDCL(a,b);
	return 0;	
}
