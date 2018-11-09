#include<stdio.h>
#include<string.h>
void rule1(char a[],int i)
{
	//如果是单个字符，合法表达式则为1
	if((a[i]>='a')&&a[i]<='z')
	a[i]='1';
	//若为常量，则合法表达式为1
	else if(a[i]=='0')
	a[i]='1'; 
}
void rule2(char a[],int i)
{
	int n=strlen(a);
	//如果当前位置起形如“！1”则换成“1”
	if((i+1<n)&&(a[i]=='!')&&(a[i+1]=='1'))
	{
		a[i]='1';
		i++;
		while(a[i+1]!='\0')
		{
			a[i]=a[i+1];//后面的字符往前移1格
			i++; 
		}
		a[i]='\0';
	}
	//如果当前位置起形如“（1）”则换成“1”
	else if((i+2<n)&&(a[i]=='(')&&(a[i+1]=='1')&&a[i+2]==')')
	{
		a[i]='1';
		i++;
		while(a[i+2]!='\0')
		{
			a[i]=a[i+2];
			i++;
		}
		a[i]='\0';
	} 
}
void rule3(char a[],int i)
{
	//1+1,1*1,1-1,1=1均换成1
	int n=strlen(a);
	if((i+2<n)&&(a[i]=='1')&&((a[i+1]=='*')||(a[i+1]=='=')||(a[i+1]=='-')||(a[i+1]=='+'))&&(a[i+2]=='1'))
	{
		a[i]='1';
		//后面的字符往前移2格
		i++;
		while(a[i+2]!='\0')
		{
			a[i]=a[i+2];
			i++;
		} 
		a[i]='\0';
	}
}
int main()
{
	char pstate[120],pstate0[120];
	int i=0,nold=1,nnew=0;
	printf("请输入公式（析+，合*，条-，双=，否定！，01）：\n");
	gets(pstate0);
	fflush(stdin);
	for(i=0;i<strlen(pstate0);i++)
	pstate[i]=pstate0[i];
	pstate[i]='\0';
	for(i=0;i<strlen(pstate);i++)
	rule1(pstate,i);
	printf("规则1后：%s\n",pstate);
	while(nnew<nold)
	{
		nold=strlen(pstate);
		//使用规则2对字串进行处理，会改变长度
		for(i=0;i<strlen(pstate);i++)
		rule2(pstate,i);
		printf("规则2后：%s\n",pstate);
		for(i=0;i<strlen(pstate);i++)
		rule3(pstate,i);
		printf("规则3后：%s\n",pstate);
		nnew=strlen(pstate);
		//if(nnew==1&&pstate=='1')
		//break;
	}
	if((pstate[0]=='1')&&(strlen(pstate)==1))
	printf("%s is valid\n",pstate0);
	else
	printf("%s is invalid\n",pstate0);
	return 0;
}
