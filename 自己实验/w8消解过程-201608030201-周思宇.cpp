#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct tm
{
	char gs[120],gsLast[120],niyou[120];//ǰ������������
	int nLitter,nUsed,isLitter,isCond;//�����ĳ��ȣ��Ƿ�ʹ�ã��Ƿ�����ĸ���Ƿ�������ʽ 
};
void nonoop2(char aa[])
{
	//!!p=p
	int i=0,j=0;
	while(i<strlen(aa)-2)
	{
		//���ٻ���2���ַ�
		if(((i+1)<strlen(aa))&&(aa[i]=='!')&&(aa[i+1]=='!'))
		{
			j=i;
			while(j<strlen(aa)-2)
			{
				aa[j]=aa[j+2];
				j++;
			}
			aa[j]='\0';
			break;
		}
		else
		i++;
	}
}
void printYsh(struct tm tmrec[],int np)
{
	int i=0;
	for(i=0;i<np;i++)
	{
		if(tmrec[i].isLitter==1)
		printf("(%d)\t%sΪ��\t\t\t%s---����\n",i+1,tmrec[i].gs,tmrec[i].niyou);
		else if(tmrec[i].isCond==1)
		printf("(%d)\t%s+%sΪ��\t\t\t%s---��ȡʽ\n",i+1,tmrec[i].gs,tmrec[i].gsLast,tmrec[i].niyou);
		else
		printf("(%d)\t%sΪ��\t\t\t%s\n",i+1,tmrec[i].gs,tmrec[i].niyou);
	}
}
int setNiyou(struct tm tmrec[],int np,char ny0[],int j0,int j1,int nUsed0,int isCond0,int isLitter0)
{
	//���ַ���ny0��j0�������������
	char stmpj0[20],stmpj1[20];
	int nLen1=0,j=0,nLenj0=0,nLenj1=0;
	nLen1=strlen(ny0);
	itoa(j0+1,stmpj0,10);//��j0+1ת�����ַ���������stmpj0��
	nLenj0=strlen(stmpj0);//ǰһ������
	itoa(j1+1,stmpj1,10);
	nLenj1=strlen(stmpj1);//��һ������
	if(j0==-1)
	{
		for(j=0;j<nLen1;j++)
		tmrec[np].niyou[j]=ny0[j];
		tmrec[np].niyou[j]='\0';
	} 
	else if(j1==-1)//��ǰһ���������ý���
	{
		tmrec[np].niyou[0]='(';
		for(j=0;j<nLenj0;j++)
		tmrec[np].niyou[j+1]=stmpj0[j];
		tmrec[np].niyou[j+1]=')';
		
		for(j=0;j<nLen1;j++)
		tmrec[np].niyou[j+2+nLenj0]=ny0[j];
		tmrec[np].niyou[j+2+nLenj0]='\0';
	} 
	else
	{
		//��ǰ������������
		tmrec[np].niyou[0]='(';
		for(j=0;j<nLenj0;j++)
		tmrec[np].niyou[j+1]=stmpj0[j];
		tmrec[np].niyou[j+1]=')';
		
		tmrec[np].niyou[nLenj0+2]='(';
		for(j=0;j<nLenj1;j++)
		tmrec[np].niyou[nLenj0+j+3]=stmpj1[j];
		tmrec[np].niyou[nLenj0+j+3]=')';
		
		for(j=0;j<nLen1;j++)
		tmrec[np].niyou[nLenj1+nLenj0+j+4]=ny0[j];
		tmrec[np].niyou[nLenj1+nLenj0+j+4]='\0';
	}
	tmrec[np].nUsed=nUsed0;//����ǰ���δʹ�ù� nUsed0��int isCond0��int isLitter0��
	tmrec[np].isCond=isCond0;//������ʽ
	tmrec[np].isLitter=isLitter0;//������ 
}
int inputPrimary(struct tm gs0[])
{
	struct tm tmp;
	char pstate[120];
	char ny0[100]="ǰ������";
	char ny1[100]="����ʽת��Ϊ��ȡʽ";
	char ny2[100]="˫������������ȡʽ";
	//char ny3[100]="��ȡ������";
	//char ny3[100]="����ʽת��Ϊ��ȡʽ";
	//char ny4[100]="��ȡ�Ķ���";
	//char ny5[100]="˫�񶨵õ�"; 
	int i=0,j=0,nLen=0,k=0;
	int i0=0;//ԭʼ����
	printf("����һ��ǰ�������밴�س�������ֱ�ӻس������\n");
	printf("����+����*����-��˫=���񶨣���\n");
	printf("ǰ����ֻ��Ϊ˫����������������ȡʽ��\n");
	printf("��Ϊ2�������ĺ�ȡ��������2��ǰ�ᣬ����������ǰ�����룺\n");
	while(1)
	{
		gets(pstate);
		//fflush(stdin);
		nLen=strlen(pstate);
		if(nLen==0)
		break;
		//����nUsed��isLitter��isCond,nLitter
		//�ж��Ƿ�Ϊ���� 
		if(nLen==1)//��ע�������� 
		{
			gs0[i].nLitter=strlen(pstate);
			gs0[i].gs[0]=pstate[0];
			gs0[i].gs[1]='\0';
			gs0[i].gsLast[0]='\0';
			setNiyou(gs0,i,ny0,-1,-1,0,0,1);//ǰ�����ͣ��ޣ��ޣ�δʹ�ã���������ʽ�������� 
		}
		else if((nLen==2)&&pstate[0]=='!')//��ע��p
		{
			gs0[i].nLitter=strlen(pstate);
			gs0[i].gs[0]=pstate[0];
			gs0[i].gs[1]=pstate[1];
			gs0[i].gs[2]='\0';
			gs0[i].gsLast[0]='\0';
			setNiyou(gs0,i,ny0,-1,-1,0,0,1);//ǰ�����ͣ��ޣ��ޣ�δʹ�ã���������ʽ�������� 
		}
		else
		{
			for(j=0;j<nLen;j++)
			{
				if(pstate[j]=='-')//��ע����ʽp-q
				{
					gs0[i].nLitter=strlen(pstate);
					for(k=0;k<nLen;k++)
					gs0[i].gs[k]=pstate[k];//����ǰ����gs
					gs0[i].gs[k]='\0';
					//for(k=j+1;k<nLen;k++)
					//gs0[i].gsLast[k-j-1]=pstate[k];//���������gsLast
					gs0[i].gsLast[0]='\0';
					setNiyou(gs0,i,ny0,-1,-1,0,0,0);//ǰ�����ͣ��ޣ��ޣ�δʹ�ã�������ʽ����������
					//��ת������ʽ��p-qΪ��!p+q 
					i++;
					gs0[i].nLitter=gs0[i-1].nLitter;
					gs0[i].gs[0]='!';
					for(k=0;k<j;k++)
					gs0[i].gs[k+1]=pstate[k];//����ǰ����gs
					gs0[i].gs[k+1]='\0';
					nonoop2(gs0[i].gs);
					//gs0[i].gs[0]='!';
					for(k=j+1;k<nLen;k++)
					gs0[i].gsLast[k-j-1]=pstate[k];//���������gsLast
					gs0[i].gsLast[k-j-1]='\0';
					setNiyou(gs0,i,ny1,i-1,-1,0,1,0);//ǰ�����ͣ��ޣ��ޣ�δʹ�ã�������ʽ����������
					break; 
				}
				else if(pstate[j]=='=')//��ע����ʽp=q
				{
					//�ȱ���˫���� 
					gs0[i].nLitter=strlen(pstate);
					for(k=0;k<strlen(pstate);k++)
					gs0[i].gs[k]=pstate[k];//����ǰ����gs
					gs0[i].gs[k]='\0';
					gs0[i].gsLast[0]='\0';//gsLastΪ�� 
					setNiyou(gs0,i,ny0,-1,-1,0,0,0);//ǰ�����ͣ��ޣ��ޣ�δʹ�ã�������ʽ����������
					//p-q��!p+q 
					i++;
					gs0[i].nLitter=strlen(pstate);
					gs0[i].gs[0]='!';
					for(k=0;k<j;k++)
					gs0[i].gs[k+1]=pstate[k];//p��gs
					gs0[i].gs[k+1]='\0';
					for(k=j+1;k<nLen;k++)
					gs0[i].gsLast[k-j-1]=pstate[k];//q��gsLast
					gs0[i].gsLast[k-j-1]='\0';
					setNiyou(gs0,i,ny2,i-1,-1,0,1,0);//ǰ�����ͣ��ޣ��ޣ�δʹ�ã���������ʽ����������
					nonoop2(gs0[i].gs);//ȥ�����ܴ��ڵ�!! 
					//q-p=p+!q
					i++;
					gs0[i].nLitter=gs0[i-1].nLitter;
					for(k=0;k<j;k++)
					gs0[i].gs[k]=pstate[k];//����ǰ����gs
					gs0[i].gs[k]='\0';
					gs0[i].gsLast[0]='!';
					for(k=j+1;k<nLen;k++)
					gs0[i].gsLast[k-j-1+1]=pstate[k];//���������gsLast
					gs0[i].gsLast[k-j-1+1]='\0';
					setNiyou(gs0,i,ny2,i-2,-1,0,1,0);//ǰ�����ͣ��ޣ��ޣ�δʹ�ã�������ʽ����������
					nonoop2(gs0[i].gsLast);//ȥ�����ܴ��ڵ�!!
					break; 
				}
				else if(pstate[j]=='+')//��ע����ʽp+q
				{
					//�ȱ���˫���� 
					gs0[i].nLitter=strlen(pstate);
					for(k=0;k<j;k++)
					gs0[i].gs[k]=pstate[k];//˫����ȫ����gs
					gs0[i].gs[k]='\0';
					for(k=0;k<nLen;k++)
					gs0[i].gsLast[k-j-1]=pstate[k];//˫����ȫ����gs
					gs0[i].gsLast[k-j-1]='\0';
					setNiyou(gs0,i,ny0,-1,-1,0,1,0);//ǰ�����ͣ��ޣ��ޣ�δʹ�ã�������ʽ����������
					
					break; 
				}
			}
			if(j>=nLen)//��������ʽ��Ҳ�������֣�������ͨ������
			{
				gs0[i].nLitter=strlen(pstate);
				for(k=0;k<nLen;k++)
				gs0[i].gs[k]=pstate[k];//��ʽȫ��gs
				gs0[i].gs[k]='\0';
				gs0[i].gsLast[0]='\0';//gsLastΪ�մ�
				setNiyou(gs0,i,ny0,-1,-1,0,0,0);//ǰ�����ͣ��ޣ��ޣ�δʹ�ã���������ʽ���������� 
			}
		}
		i++;//��ǰ��ʽ�������Ժ�ָ��i��ֵ��1 
	}
	nLen=i;//���ַ����ĳ�������
	for(i=0;i<nLen-1;i++)
	{
		k=i;
		for(j=i+1;j<nLen-1;j++)
		if(gs0[k].nLitter>gs0[j].nLitter)
		k=j;
		if(k>i)
		{
			tmp=gs0[i];
			gs0[i]=gs0[k];
			gs0[k]=tmp;
		}
	}
	return nLen; 
}
int main()
{
	struct tm gs0[100];//����ǰ������
	char result0[128];//����
	struct tm tmrec[1024];//���1000��
	char stmp[128][128]; 
	char lastNiYou[128]="   ";//�ϸ�����ʽ������
	char ny01[100]="����";
	int i=0,k=0,j=0,j1=0,np=1,np0=0,isOk=0;
	int i0=0,nPosLitter[128]={0},nPosCond=0;//������ʼλ�ã��׸����ֵ�λ�ã�����ʽ��λ��
	//����ǰ������
	np0=inputPrimary(gs0);
	//�������
	printf("����Ҫ����Ľ��ۣ�����ֻ��ʽ���֣�\n"); 
	printf("��������ʽ����ȡʽ�����ֹ�ת��Ϊ��������ǰ����Ϊ����ǰ�᣺");
	gets(result0);
	fflush(stdin);
	for(i=0;i<np0;i++)//����ԭʼ��ʽת������tmrec��
	tmrec[i]=gs0[i];
	np=i;//������е�β��ָ�� 
	//nPosLitter[j]=0;//���ֵ�λ�ú�
	nPosCond=0;//������λ�ú�
	isOk=0;
	i0=-1;
	while(1)
	{
		i=i0+1;//Ѱ����һ�����֣�i����ʼλ�ã�np������ĳ���
		while((i<np)&&(tmrec[i].isLitter!=1))
		i++;
		if(i>=np)//�Ҳ������֣����޷����� 
		break;
		i0=i;//��¼��Դͷ��ѯ���׸����ֵ�λ�úţ��´δӴ˺�����Ѱ�� 
		nPosLitter[j1]=i;//��¼���ֵ�λ�� 
		strcpy(stmp[j1],tmrec[i].gs);//���浱ǰ���ֵ�����
		if(strcmp(result0,stmp[j1])==0)//�Ƴ�����ͬ��ԭʼ��������һ�� 
		{
			isOk=1;
			break;
		} 
		np0=np-1;
		while(np>np0)//�ӵ�ǰ���ֵ���һ��λ����Ѱ������ʽ����һ·������
		{
			np0=np;
			for(i=0;i<np;i++)//�ҵ�һ��û���ù�������ʽ
			if((tmrec[i].isCond==1)&&(tmrec[i].nUsed==0))
			break;
			if(i==np)//û���ҵ�������������е�����ʽ���õ��� 
			break;
			while(i<np) //���ҵ������������� 
			{
				if(tmrec[i].isCond==1)//��������ʽ
				{
					for(k=0;k<=j1;k++)
					if((strcmp(lastNiYou,tmrec[i].niyou)!=0)||((strcmp(lastNiYou,tmrec[i].niyou)==0)&&(tmrec[i].niyou[0]!='(')))
					{
						
						//�������������Դ����ͬ�����ߵ���ͬΪǰ������ʽ���Եģ����׸��ַ����ǣ�
						if((tmrec[i].gs[0]=='!')&&(stmp[k][0]!='!')&&(strlen(tmrec[i].gs)-strlen(stmp[k])==1))
						{
							//�����ȡʽ��ǰ����stem�������⣬�򽫺�����浽stme��
							j=0;
							while(j<strlen(stmp[k]))//���αȽ�ÿһ���ַ�
							{
								if(tmrec[i].gs[j+1]!=stmp[k][j])//��һ�������������Ƚ� 
								break;
								j++; 
							}
							if(j>=strlen(stmp[k]))//����ȵ��������ȣ�������������� 
							{
								strcpy(lastNiYou,tmrec[i].niyou);
								//tmrec[nPosLitter[k]].nUsed++;//��������ù�һ����
								tmrec[i].nUsed++;//�����ȡʽ�ù�һ����
								j1++; 
								strcpy(stmp[j1],tmrec[i].gsLast);//�������������浽�Ƶ�������
								strcpy(tmrec[np].gs,stmp[j1]);//����ǰ�Ƴ����Ľ����������
								tmrec[np].gsLast[0]='\0';//�����գ����浱ǰ����
								setNiyou(tmrec,np,ny01,nPosLitter[k],i,0,0,1);//ǰ�����ͣ��У��ޣ�δʹ�ã���������ʽ
								nPosLitter[j1]=np;
								np++;
								if(strcmp(result0,stmp[j1])==0)//�Ƴ�����ͬ��ԭʼ��������һ�� 
								{
									isOk=1;
									break;
								} 
							}
						}
						if((tmrec[i].gsLast[0]=='!')&&(stmp[k][0]!='!')&&(strlen(tmrec[i].gsLast)-strlen(stmp[k])==1))
						{
							//�����ȡʽ�ĺ����stem�������⣬�򽫺�����浽stme��
							j=0;
							while(j<strlen(stmp[k]))//���αȽ�ÿһ���ַ�
							{
								if(tmrec[i].gsLast[j+1]!=stmp[k][j])//��һ�������������Ƚ� 
								break;
								j++; 
							}
							if(j>=strlen(stmp[k]))//����ȵ��������ȣ�������������� 
							{
								strcpy(lastNiYou,tmrec[i].niyou);
								//tmrec[nPosLitter[j1]].nUsed++;//��������ù�һ����
								tmrec[i].nUsed++;//�����ȡʽ�ù�һ����
								j1++; 
								strcpy(stmp[j1],tmrec[i].gs);//�������������浽�Ƶ�������
								strcpy(tmrec[np].gs,stmp[j1]);//����ǰ�Ƴ����Ľ����������
								tmrec[np].gsLast[0]='\0';//�����գ����浱ǰ����
								setNiyou(tmrec,np,ny01,nPosLitter[k],i,0,0,1);//ǰ�����ͣ��У��ޣ�δʹ�ã���������ʽ
								nPosLitter[j1]=np;
								np++;
								if(strcmp(result0,stmp[j1])==0)//�Ƴ�����ͬ��ԭʼ��������һ�� 
								{
									isOk=1;
									break;
								} 
							}
						} 
						if((tmrec[i].gs[0]!='!')&&(stmp[k][0]=='!')&&(strlen(tmrec[i].gs)-strlen(stmp[k])==-1))
						{ 
							//�����ȡʽ��ǰ����stem�������⣬�򽫺�����浽stme��
							j=0;
							while(j<strlen(stmp[k]))//���αȽ�ÿһ���ַ�
							{
								if(tmrec[i].gs[j]!=stmp[k][j+1])//��һ�������������Ƚ� 
								break;
								j++; 
							}
							if(j>=strlen(stmp[k]))//����ȵ��������ȣ�������������� 
							{
								strcpy(lastNiYou,tmrec[i].niyou);
								//tmrec[nPosLitter[j1]].nUsed++;//��������ù�һ����
								tmrec[i].nUsed++;//�����ȡʽ�ù�һ����
								j1++; 
								strcpy(stmp[j1],tmrec[i].gsLast);//�������������浽�Ƶ�������
								strcpy(tmrec[np].gs,stmp[j1]);//����ǰ�Ƴ����Ľ����������
								tmrec[np].gsLast[0]='\0';//�����գ����浱ǰ����
								setNiyou(tmrec,np,ny01,nPosLitter[k],i,0,0,1);//ǰ�����ͣ��У��ޣ�δʹ�ã���������ʽ
								nPosLitter[j1]=np;
								np++;
								if(strcmp(result0,stmp[j1])==0)//�Ƴ�����ͬ��ԭʼ��������һ�� 
								{
									isOk=1;
									break;
								} 
							}
						}
						if((tmrec[i].gsLast[0]!='!')&&(stmp[k][0]=='!')&&(strlen(tmrec[i].gsLast)-strlen(stmp[k])==-1))
						{//printf("aaaa\n");
							//�����ȡʽ�ĺ����stem�������⣬�򽫺�����浽stme��
							j=0;
							while(j<strlen(stmp[k]))//���αȽ�ÿһ���ַ�
							{
								if(tmrec[i].gsLast[j]!=stmp[k][j+1])//��һ�������������Ƚ� 
								break;
								j++; 
							}
							if(j>=strlen(stmp[k]))//����ȵ��������ȣ�������������� 
							{
								strcpy(lastNiYou,tmrec[i].niyou);
								//tmrec[nPosLitter[j1]].nUsed++;//��������ù�һ����
								tmrec[i].nUsed++;//�����ȡʽ�ù�һ����
								j1++; 
								strcpy(stmp[j1],tmrec[i].gs);//�������������浽�Ƶ�������
								strcpy(tmrec[np].gs,stmp[j1]);//����ǰ�Ƴ����Ľ����������
								tmrec[np].gsLast[0]='\0';//�����գ����浱ǰ����
								setNiyou(tmrec,np,ny01,nPosLitter[k],i,0,0,1);//ǰ�����ͣ��У��ޣ�δʹ�ã���������ʽ
								nPosLitter[j1]=np;
								np++;
								if(strcmp(result0,stmp[j1])==0)//�Ƴ�����ͬ��ԭʼ��������һ�� 
								{
									isOk=1;
									break;
								} 
							}
						}
					}
					if(isOk==1)
					break;
				}
				i++;//�ж���һ�����ʽ�Ƿ�Ϊ�������Ƿ�Ϊ�����������ʽ 
			}
		}
		if(isOk==1)//�Գɹ��Ƶ�������������һ������ 
		break; 
	}
	if(isOk==1)
	printf("���Ƴ����ˣ�����������£�\n");
	else
	printf("���Ʋ�����������������£�\n");
	printYsh(tmrec,np); 
}
/*!s
q-s
p+q
*/ 
