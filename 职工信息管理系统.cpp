#include <stdio.h>
 #include <windows.h>
 #include <string.h> 
#define N 100
 struct employee 
 { 
	 int num; 
	 char name[20];
	 char sex; 
	 char job[50];
     char depart[20];
	 int  id;
	 char marry[10];
	 int birth;
	 char xueli[30];
	 int wage;
	 char addr[30];
	 char tel[20];
 }em[100];    /*����һ���ṹ��*/ 
 int menu(); 
 int input();
 void save(int); 
 int display(); 
 void del();
 void add();
 void search(); 
 void search_num();
 void search_xueli();
 void search_tel();
 void modify();
 void paixu();
 void tongji();      /*���������*/

void main()
{menu();
 int n,flag;
 char a;
 do 
 { 
	 printf("��ѡ������Ҫ�����Ĳ���(1--9):\n");
	 scanf("%d",&n); 
	 if(n>=1&&n<=9)
{
		 flag=1;
		 break;
 }
	 else
	 {
		 flag=0;
	 printf("����������������ѡ��!");
 } 
} 
 while(flag==0); 
 while(flag==1) 
 { 
	 switch(n) 
	 { case 1:printf(" ����ְ����Ϣ \n");
	     printf("\n");
	     input();
	     break;
	 case 2:printf(" ���ְ����Ϣ\n");   
		 printf("\n");
		 display();
		 break; 
	 case 3:printf(" ��ְ���Ų�ѯְ����Ϣ \n");
		 printf("\n");
		 search();
		 break;
	 case 4:printf(" ɾ��ְ����Ϣ \n");
		 printf("\n");
		 del();
		 break; 
	 case 5:
		 printf(" ���ְ����Ϣ \n");
		 printf("\n");
		 add();
		 break;
	 case 6:printf(" �޸�ְ����Ϣ \n");
		 printf("\n");
		 modify();
		 break;
	 case 7:printf("��ְ����Ϣ���� \n");
		 printf("\n");
		 paixu();
		 break;
	 case 8:printf("ͳ�Ʋ�ͬ���ŵ����� \n");
		 printf("\n");
		 tongji ();
		 break;
	 case 9:exit(0);
		 break;
	 default :break; } 
	 getchar();
	 printf("\n");
	 printf("�Ƿ��������(y or n):\n");
	 scanf("%c",&a); 
	 if(a=='y')
	 { flag=1; system("cls"); /*����*/ 
	 menu(); /*���ò˵�����*/ 
	 printf("���ٴ�ѡ������Ҫ�����Ĳ���(1--9):\n"); 
	 scanf("%d",&n); 
	 printf("\n"); 
	 }
     else 
		 exit(0);
 }
}
 int menu() /*�˵�����*/ 
 {
	 printf(" ************��ӭ����ְ����Ϣ����ϵͳ**********\n"); 
	 printf(" 1.¼��ְ����Ϣ        "); 
	 printf(" 2.���ְ����Ϣ\n");
	 printf(" 3.��ѯְ����Ϣ        ");
	 printf(" 4.ɾ��ְ����Ϣ\n");
	 printf(" 5.���ְ����Ϣ        "); 
	 printf(" 6.�޸�ְ����Ϣ\n");
	 printf(" 7.��ְ����Ϣ����      ");
	 printf(" 8.ͳ�Ʋ�ͬ���ŵ�����\n");
	 printf(" 9.�˳�\n"); 
	 printf(" ********************ллʹ��******************\n");
	 printf("\n"); 
	 printf("\n");
	 return 0;
 } 
 int input() /*¼�뺯��*/ 
 { int b=123,h;
  printf("����������!\n");
   scanf("%d",&h);
   if(b==h)
   { int i,m; 
     printf("��������Ҫ������Ϣ��ְ������(1--100):\n"); 
     scanf("%d",&m);
    for (i=0;i<m;i++) 
	{
	 printf("������ְ���ţ� ");
	 scanf("%d",&em[i].num);
	 printf("����������:"); 
	 scanf("%s",em[i].name);
	 getchar();
	 printf("�������Ա�(f--Ů m--��): ");
	 scanf("%c",&em[i].sex);
	 printf("������ְ��: ");
	 scanf("%s",em[i].job);
     printf("�����벿��: ");
	 scanf("%s",em[i].depart);
	 printf("���������֤��: ");
	 scanf("%d",&em[i].id);
	 printf("��������(y--�� n--��): ");
	 scanf("%s",em[i].marry);
	  printf("�������������: ");
	 scanf("%d",&em[i].birth);
	 printf("������ѧ��: "); 
	 scanf("%s",em[i].xueli);
	 printf("�����빤��: ");
	 scanf("%d",&em[i].wage);
	 printf("������סַ: "); 
	 scanf("%s",em[i].addr);
     printf("������绰: "); 
     scanf("%s",em[i].tel);
     printf("\n");
	}
    printf("\n �������!\n");
    save(m);
   }
   else
   {
	   printf("�������! ����������!\n");
	   return menu ();
   }
 }

void save(int m) /*�����ļ�����*/
 { 
	int i; 
	FILE*fp;
	if ((fp=fopen("employee_list","wb"))==NULL) 
	{ 
		printf ("cannot open file\n");
		exit(0); 
}
	for (i=0;i<m;i++) /*���ڴ���ְ������Ϣ����������ļ���ȥ*/
		if (fwrite(&em[i],sizeof(struct employee),1,fp)!=1) 
			printf("file write error\n"); 
		fclose(fp); 
}

int load() /*���뺯��*/
 { 
	FILE*fp; 
	int i=0;
	if((fp=fopen("employee_list","rb"))==NULL) 
	{ 
		printf ("cannot open file\n"); 
		exit(0);
	} 
	else
	{ 
		do 
		{
			fread(&em[i],sizeof(struct employee),1,fp); 
			i++;
		} 
		while(feof(fp)==0);
	} 
	fclose(fp);
	return(i-1);
 }

int display() /*�������*/ 
{ 
	int i,b=123,h; 
	int m=load();
	printf("����������!\n");
	scanf("%d",&h);
	if(b==h)
	{
 printf("                                      ְ����Ϣ");
 printf("\n******************************************************************************\n");
 printf(" |ְ�����|����|�Ա�|ְ��|����|���֤��|���|��������|ѧ��  |����|��ַ  |�绰  |\n");
 printf(" |--------|----|----|----|----|--------|----|--------|------|----|------|------|\n");
 for(i=0;i<m;i++)
    {printf(" |%-8d|%-4s|%-4c|%-4s|%-4s|%-8d|%-4s|%-8d|",em[i].num,em[i].name,em[i].sex, em[i].job,em[i].depart,em[i].id,em[i].marry,em[i].birth);
     printf("%-6s|%-4d|%-6s|%-6s|\n",em[i].xueli,em[i].wage,em[i].addr,em[i].tel);
	}
 printf("*************************************��ӭ����!***********************************\n");
 getchar();
	}
	else
	{printf("�������! ����������!");
	return menu ();
	}
}

void del() /*ɾ������*/ 
{ 
	int m=load();
	int i,j,n,t,flag; 
	char name[20]; 
	printf("\n ԭ����ְ����Ϣ:\n"); 
	display(); 
	printf("\n"); 
	printf("������Ҫɾ����ְ��������:\n"); 
	scanf("%s",name); 
	for(flag=1,i=0;flag&&i<m;i++)
	{ 
		if(strcmp(em[i].name,name)==0) 
		{
		printf("\n ���ҵ����ˣ�ԭʼ��¼Ϊ��\n");
		 printf("\n********************************************************************************\n");
		 printf(" |ְ�����|����|�Ա�|ְ��|����|���֤��|���|��������|ѧ��  |����|��ַ  |�绰  |\n");
		 printf(" |--------|----|----|----|----|--------|----|--------|------|----|------|------|\n");
		 printf(" |%-8d|%-4s|%-4c|%-4s|%-4s|%-8d|%-4s|%-8d|",em[i].num,em[i].name,em[i].sex, em[i].job,em[i].depart,em[i].id,em[i].marry,em[i].birth);
		 printf("%-6s|%-4d|%-6s|%-6s|\n",em[i].xueli,em[i].wage,em[i].addr,em[i].tel);
		 printf("**************************************��ӭ����!***********************************\n");
		 printf("\n ȷʵҪɾ��������Ϣ�밴 1,��ɾ���밴 0\n");
		 scanf("%d",&n);
 if(n==1) 
 { 
	 for(j=i;j<m-1;j++) 
	 {
		 strcpy(em[j].name,em[j+1].name);
		 em[j].num=em[j+1].num;
		 em[j].sex=em[j+1].sex; 
		 strcpy(em[j].job,em[j+1].job);
		 strcpy(em[j].depart,em[j+1].depart);
		 em[j].id=em[j+1].id;
		 strcpy(em[j].marry,em[j+1].marry);
		 em[j].birth=em[j+1].birth;
		 strcpy(em[j].xueli,em[j+1].xueli);
		 em[j].wage=em[j+1].wage; 
		 strcpy(em[j].addr,em[j+1].addr); 
		 strcpy(em[j].tel,em[j+1].tel); } flag=0; 
}
 } 
} 
	if(!flag) m=m-1; 
	else printf("\n �Բ��𣬲��޴���!\n");
	printf("\n ���ɾ���������ְ����Ϣ:\n"); 
	save(m); /*���ñ��溯��*/ 
	display(); /*�����������*/ 
	printf("\n ����ɾ���밴 1������ɾ���밴 0\n"); 
	scanf("%d",&t); 
	switch(t) 
	{ 
	case 1:del();break; 
	case 0:break; 
	default :break; 
} }
void add()/*��Ӻ���*/ 
{ 
	FILE*fp;
	int n; 
	int count=0; 
	int i;
	int m=load();
	printf("\n ԭ����ְ����Ϣ:\n"); 
	display();
	printf("\n"); 
	fp=fopen("emploee_list","a");
	printf("�����������ӵ�ְ����:\n");
	scanf("%d",&n);
for (i=m;i<(m+n);i++) 
{
printf("\n ������������ְ������Ϣ:\n"); 
printf("������ְ����: "); 
scanf("%d",&em[i].num); 
printf("\n"); 
printf("����������: "); 
scanf("%s",em[i].name); 
getchar(); 
printf("�������Ա�(f--Ů m--��):  ");
scanf("%c",&em[i].sex);
 printf("������ְ��: ");
 scanf("%s",em[i].job);
 printf("�����벿��: ");
 scanf("%s",em[i].depart); 
 printf("���������֤��: ");
 scanf("%d",&em[i].id); 
 printf("��������(y--�� n--��): ");
 scanf("%s",em[i].marry); 
 printf("�������������: ");
 scanf("%d",&em[i].birth); 
 printf("������ѧ��: "); 
 scanf("%s",em[i].xueli);
 printf("�����빤��: ");
 scanf("%d",&em[i].wage); 
 printf("������סַ: "); 
 scanf("%s",em[i].addr);
 printf("������绰: ");
 scanf("%s",em[i].tel); 
 printf("\n");
 count=count+1; 
 printf("�����ӵ�����:\n");
 printf("%d\n",count); 
} 
printf("\n ������!\n"); 
m=m+count; 
printf("\n ������Ӻ������ְ����Ϣ:\n"); 
printf("\n"); 
save(m); 
display();
 fclose(fp);
 }
void search()/*��ѯ����*/ 
{ 
	int t,flag; 
	do 
	{
		printf("\n ��ְ���Ų�ѯ�밴 1; ��ѧ����ѯ�밴 2; ���绰�����ѯ�밴 3�� ���� �������밴 4\n"); 
		scanf("%d",&t);
if(t>=1&&t<=4) 
{ 
	flag=1; 
	break;
 }
 else 
 { 
	 flag=0;
	 printf("����������������ѡ��!"); 
} 
} 
	while(flag==0); 
	while(flag==1)
	{ 
		switch(t) 
		{ 
		case 1:printf("��ְ���Ų�ѯ\n");
			search_num();
			break;
		case 2:printf("��ѧ����ѯ\n");
			search_xueli();
			break;
		case 3:printf("���绰�����ѯ\n");
			search_tel();
			break; 
		case 4:main();
			break; 
		default:break; 
} 
} 
}


void search_num()
 { 
	int num; 
	int i,t; 
	int m=load();
	printf("������Ҫ���ҵ�ְ����:\n");
	scanf("%d",&num);
	for(i=0;i<m;i++) 
		if(num==em[i].num)
		{ 
			printf("\n              ���ҵ����ˣ����¼Ϊ:\n"); 
 printf("\n***************************************************************************\n");
 printf(" |ְ�����|����|�Ա�|ְ��|����|���֤��|���|��������|ѧ��  |����|��ַ  |�绰  |\n");
 printf(" |--------|----|----|----|----|--------|----|--------|------|----|------|------|\n");
 printf(" |%-8d|%-4s|%-4c|%-4s|%-4s|%-8d|%-4s|%-8d|",em[i].num,em[i].name,em[i].sex, em[i].job,em[i].depart,em[i].id,em[i].marry,em[i].birth);
 printf("%-6s|%-4d|%-6s|%-6s|\n",em[i].xueli,em[i].wage,em[i].addr,em[i].tel);
 printf("***********************************��ӭ����!*********************************\n");
    break; } 
		if(i==m) 
			printf("\n �Բ��𣬲��޴���\n"); 
		printf("\n");
		printf("���ز�ѯ�����밴 1,������ѯְ�����밴 2\n"); 
		scanf("%d",&t); 
		switch(t)
		{ 
		case 1:search();break; 
		case 2: break; 
		default:break; 
}
}
void search_xueli() 
{ 
	char xueli[30];
	int i,t;
	int m=load();
	printf("������Ҫ���ҵ�ѧ��:\n");
	scanf("%s",xueli); 
	for(i=0;i<m;i++)
		if(strcmp(em[i].xueli,xueli)==0) 
		{
			printf("\n                  ���ҵ������¼Ϊ:\n"); 
printf("\n***********************************************************************************\n");
 printf(" |ְ�����|����|�Ա�|ְ��|����|���֤��|���|��������|ѧ��  |����|��ַ  |�绰  |\n");
 printf(" |--------|----|----|----|----|--------|----|--------|------|-------|------|------|\n");
 printf(" |%-8d|%-4s|%-4c|%-4s|%-4s|%-8d|%-4s|%-8d|",em[i].num,em[i].name,em[i].sex,em[i].job,em[i].depart,em[i].id,em[i].marry,em[i].birth);
 printf("%-6s|%-4d|%-6s|%-6s|\n",em[i].xueli,em[i].wage,em[i].addr,em[i].tel);
 printf("*************************************��ӭ����!*************************************\n");
		} 
		if(i==m) 
			printf("\n �Բ��𣬲��޴���\n");
		printf("\n"); 
		printf("���ز�ѯ�����밴 1,������ѯѧ���밴 2\n"); 
		scanf("%d",&t);
		switch(t)
		{ 
		case 1:search();break;
		case 2:break;
default :break; 
}
 }

void search_tel() 
{ 
	
	char tel[20]; 
	int i, t; 
	int m=load();
	printf("������Ҫ���ҵĵ绰����:\n");
	scanf("%s",tel); 
	for(i=0;i<m;i++)
		if(strcmp(tel,em[i].tel)==0)
		{
			printf("\n               ���ҵ����ˣ����¼Ϊ:\n");
    printf("\n************************************************************************\n");
 printf(" |ְ�����|����|�Ա�|ְ��|����|���֤��|���|��������|ѧ��  |����|��ַ  |�绰  |\n");
 printf(" |--------|----|----|----|----|--------|----|--------|------|----|------|------|\n");
 printf(" |%-8d|%-4s|%-4c|%-4s|%-4s|%-8d|%-4s|%-8d|",em[i].num,em[i].name,em[i].sex, em[i].job,em[i].depart,em[i].id,em[i].marry,em[i].birth);
 printf("%-6s|%-4d|%-6s|%-6s|\n",em[i].xueli,em[i].wage,em[i].addr,em[i].tel);
 printf("********************************��ӭ����!********************************\n");
 break; 
} 
		if(i==m) 
			printf("\n �Բ��𣬲��޴���\n"); 
		printf("\n"); 
		printf("���ز�ѯ�����밴 1,������ѯ�绰�����밴 2\n"); 
		scanf("%d",&t);
		switch(t)
		{ 
		case 1:search();break; 
		case 2:break; 
		default :break; 
} 
}
/*ð�ݷ�����������*/
void paixu() /*������*/
{
   int i,j;
   int m=load();
   struct employee works;
   for(i=1;i<m;i++)
   {for(j=0;j<m-i;j++)
  if(em[j].wage>em[j+1].wage)
  {works.num=em[j].num;                strcpy(works.name,em[j].name);
   works.sex=em[j].sex;                strcpy(works.job,em[j].job);
  strcpy(works.depart,em[j].depart);   works.id=em[j].id;
  strcpy(works.marry,em[j].marry);     works.birth=em[j].birth;
  strcpy(works.xueli,em[j].xueli);     works.wage=em[j].wage;
  strcpy(works.addr,em[j].addr);       strcpy(works.tel,em[j].tel);
  em[j].num=em[j+1].num;               strcpy(em[j].name,em[j+1].name);
  em[j].sex=em[j+1].sex;               strcpy(em[j].job,em[j+1].job);
  strcpy(em[j].depart,em[j+1].depart); em[j].id=em[j+1].id;
  strcpy(em[j].marry,em[j+1].marry);   em[j].birth=em[j+1].birth;
  strcpy(em[j].xueli,em[j+1].xueli);   em[j].wage=em[j+1].wage;
  strcpy(em[j].addr,em[j+1].addr);     strcpy(em[j].tel,em[j+1].tel);
  em[j+1].num=works.num;               strcpy(em[j+1].name,works.name);
  em[j+1].sex=works.sex;               strcpy(em[j+1].job,works.job);
  strcpy(em[j+1].depart,works.depart); em[j+1].id=works.id;
  strcpy(em[j+1].marry,works.marry);   em[j+1].birth=works.birth;  
  strcpy(em[j+1].xueli,works.xueli);   em[j+1].wage=works.wage; 
  strcpy(em[j+1].addr,works.addr);     strcpy(em[j+1].tel,works.tel);
  }
}
save (m);
printf("����ɹ�!\n");
}

void tongji()
{
 int i,j,t;
 int m=load();
 printf("\n               ���ҵ����ˣ����¼Ϊ:\n");
 printf("\n*********************************************************************\n");
 printf("|  ����  | ����  |\n");
 printf("|--------|-------|\n");
 for(i=0;i<m;i++)
 {   t=1;
	 for(j=i+1;j<m;j++)
	 {if(strcmp(em[i].depart,em[j].depart)==0)
	    t++;
	  if(j==m-1)
	  printf("|%-8s|%-7d|\n",em[i].depart,t);
	 }
 }   
 printf("********************************��ӭ����!********************************\n");
}
void modify() /*�޸ĺ���*/ 
{ 
	int num; 
	char name[20];
	char sex; 
	char job[50];
    char depart[20];
	int  id;
	char marry[10];
	int birth;
	char xueli[30];
	int wage;
	char addr[30];
	char tel[20];
	int b,c,i,n,t,flag;
	int m=load();
 printf("\n ԭ����ְ����Ϣ:\n"); 
 display(); 
 printf("\n"); 
 printf("������Ҫ�޸ĵ�ְ��������:\n");
 scanf("%s",name); 
 for(flag=1,i=0;flag&&i<m;i++) 
 { 
	 if(strcmp(em[i].name,name)==0)
	 { 
		 printf("\n ���ҵ����ˣ�ԭʼ��¼Ϊ��\n");
	printf("\n**********************************************************************\n");
 printf(" |ְ�����|����|�Ա�|ְ��|����|���֤��|���|��������|ѧ��  |����|��ַ  |�绰  |\n");
 printf(" |--------|----|----|----|----|--------|----|--------|------|----|------|------|\n");
 printf(" |%-8d|%-4s|%-4c|%-4s|%-4s|%-8d|%-4s|%-8d|",em[i].num,em[i].name,em[i].sex, em[i].job,em[i].depart,em[i].id,em[i].marry,em[i].birth);
 printf("%-6s|%-4d|%-6s|%-6s|\n",em[i].xueli,em[i].wage,em[i].addr,em[i].tel);
 printf("********************************��ӭ����!*********************************\n");
    printf("\n ȷʵҪ�޸Ĵ�����Ϣ�밴 1 ; ���޸��밴 0\n"); 
scanf("%d",&n);
 if(n==1)
 { 
	 printf("\n ��Ҫ�����޸ĵ�ѡ��\n 1.ְ���� 2.���� 3.�Ա� 4.ְ��5.���� 6.���֤�� 7.��� 8.�������� 9. ѧ�� 10.���� 11.סַ 12.�绰\n");
	 printf("�����������޸ĵ���һ�����:\n"); 
	 scanf("%d",&c); 
	 if(c>12||c<1) 
		 printf("\n ѡ�����������ѡ��!\n"); 
 } flag=0; 
	 } 
 } 
 if(flag==1)
	 printf("\n �Բ��𣬲��޴���!\n"); 
 do 
 { 
	 switch(c) /*��Ϊ���ҵ��� i ��ְ��ʱ,for ���� i �Լ��� 1,���������Ӧ�ðѸ� �����Ϣ��ֵ���� i-1 ����*/ 
	 {
		 case 1:printf("ְ���Ÿ�Ϊ: "); 
				 scanf("%d",&num);
				 em[i-1].num=num;
				 break; 
		 case 2:printf("������Ϊ: "); 
				 scanf("%s",name); 
				 strcpy(em[i-1].name,name); 
				 break; 
		 case 3:printf("�Ա��Ϊ: ");
				 getchar(); 
				 scanf("%c",&sex); 
				 em[i-1].sex=sex; 
				 break; 
		case 4:printf("ְ�Ƹ�Ϊ: "); 
				 scanf("%s",job); 
				 strcpy(em[i-1].job,job);
				 break;
		case 5:printf("���Ÿ�Ϊ: "); 
				 scanf("%s",depart); 
				 strcpy(em[i-1].depart,depart);
				 break;
		case 6:printf("���֤�Ÿ�Ϊ: "); 
				 scanf("%d",&id); 
				 em[i-1].id=id;
				 break; 
		case 7:printf("����Ϊ: "); 
				 scanf("%s",marry); 
				 strcpy(em[i-1].marry,marry);
				 break;
		case 8:printf("�������ڸ�Ϊ: "); 
				 scanf("%d",&birth); 
				 em[i-1].birth=birth;
				 break; 
		case 9:printf("ѧ����Ϊ: ");
				 scanf("%s",xueli);
				 strcpy(em[i-1].xueli,xueli); 
				 break; 
		case 10:printf("���ʸ�Ϊ: "); 
				 scanf("%d",&wage);
				 break; 
		case 11:printf("סַ��Ϊ: "); 
				 scanf("%s",addr);
				 strcpy(em[i-1].addr,addr);
				 break; 
		case 12:printf("�绰��Ϊ: "); 
				 scanf("%s",tel); 
				 strcpy(em[i-1].tel,tel); 
				 break; 
	 } 
	 printf("\n"); 
	 printf("\n �Ƿ�ȷ�����޸ĵ���Ϣ?\n �� �밴 1 ; ��,�����޸� �밴 2: \n"); 
	 scanf("%d",&b); 
 } 
 while(b==2);
 printf("\n ����޸ĺ������ְ����Ϣ:\n");
 printf("\n");
 save(m); 
 display(); 
 printf("\n �����޸��밴 1�������޸��밴 0\n");
 scanf("%d",&t);
 switch(t) 
 { 
 case 1:modify();
	 break; 
 case 0:break;
 default :break; 
} 
}
