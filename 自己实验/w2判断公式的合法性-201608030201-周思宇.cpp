#include<stdio.h>
#include<string.h>
void rule1(char a[],int i)
{
	//����ǵ����ַ����Ϸ����ʽ��Ϊ1
	if((a[i]>='a')&&a[i]<='z')
	a[i]='1';
	//��Ϊ��������Ϸ����ʽΪ1
	else if(a[i]=='0')
	a[i]='1'; 
}
void rule2(char a[],int i)
{
	int n=strlen(a);
	//�����ǰλ�������硰��1���򻻳ɡ�1��
	if((i+1<n)&&(a[i]=='!')&&(a[i+1]=='1'))
	{
		a[i]='1';
		i++;
		while(a[i+1]!='\0')
		{
			a[i]=a[i+1];//������ַ���ǰ��1��
			i++; 
		}
		a[i]='\0';
	}
	//�����ǰλ�������硰��1�����򻻳ɡ�1��
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
	//1+1,1*1,1-1,1=1������1
	int n=strlen(a);
	if((i+2<n)&&(a[i]=='1')&&((a[i+1]=='*')||(a[i+1]=='=')||(a[i+1]=='-')||(a[i+1]=='+'))&&(a[i+2]=='1'))
	{
		a[i]='1';
		//������ַ���ǰ��2��
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
	printf("�����빫ʽ����+����*����-��˫=���񶨣���01����\n");
	gets(pstate0);
	fflush(stdin);
	for(i=0;i<strlen(pstate0);i++)
	pstate[i]=pstate0[i];
	pstate[i]='\0';
	for(i=0;i<strlen(pstate);i++)
	rule1(pstate,i);
	printf("����1��%s\n",pstate);
	while(nnew<nold)
	{
		nold=strlen(pstate);
		//ʹ�ù���2���ִ����д�����ı䳤��
		for(i=0;i<strlen(pstate);i++)
		rule2(pstate,i);
		printf("����2��%s\n",pstate);
		for(i=0;i<strlen(pstate);i++)
		rule3(pstate,i);
		printf("����3��%s\n",pstate);
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
