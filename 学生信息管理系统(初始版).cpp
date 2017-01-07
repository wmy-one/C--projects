#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
 struct stu			    //����ṹ������
{char no[10];		    //ѧ��
 char name[10];		    //����
 char math[10];		  	//��ѧ�ɼ�
}st[10];
 int menu(); 
 int input();
 void save(int); 
 int display(); 
 void del();
 void add();
 void search(); 
 void search_no();
 void modify();
 void paixu();      /*���������*/

void main()
{menu();
 int n,flag;
 char a;
 do 
 {   printf("��ѡ������Ҫ�����Ĳ���(1--8):\n");
	 scanf("%d",&n); 
	 if(n>=1&&n<=8)
	 {   flag=1;
		 break;
	 }
	 else
	 {  flag=0;
	    printf("����������������ѡ��!");
	 } 
}while(flag==0); 

while(flag==1) 
 { 
	 switch(n) 
	 { case 1:printf(" ����ѧ����Ϣ \n");
	     input();
	     break;
	 case 2:printf(" ���ѧ����Ϣ\n");   
		 display();
		 break; 
	 case 3:printf(" ��ѧ�Ų�ѯѧ����Ϣ \n");
		 search();
		 break;
	 case 4:printf(" ɾ��ѧ����Ϣ \n");
		 del();
		 break; 
	 case 5:
		 printf(" ���ѧ����Ϣ \n");
		 add();
		 break;
	 case 6:printf(" �޸�ѧ����Ϣ \n");
		 modify();
		 break;
	 case 7:printf("��ѧ����Ϣ���� \n");
		 paixu();
		 break;
	 case 8:exit(0);
		 break;
	 default :break; 
	 } 
	 getchar();
	 printf("�Ƿ��������(y or n):\n");
	 scanf("%c",&a); 
	 if(a=='y')
	 { flag=1; system("cls"); /*����*/ 
	 menu(); /*���ò˵�����*/ 
	 printf("���ٴ�ѡ������Ҫ�����Ĳ���(1--8):\n"); 
	 scanf("%d",&n); 
	 printf("\n"); 
	 }
     else 
		 exit(0);
 }
}

int menu() /*�˵�����*/ 
 {
	 printf("\n\n************��ӭ����ѧ����Ϣ����ϵͳ**********\n"); 
	 printf(" 1.¼��ѧ����Ϣ        "); 
	 printf(" 2.���ѧ����Ϣ\n");
	 printf(" 3.��ѯѧ����Ϣ        ");
	 printf(" 4.ɾ��ѧ����Ϣ\n");
	 printf(" 5.���ѧ����Ϣ        "); 
	 printf(" 6.�޸�ѧ����Ϣ\n");
	 printf(" 7.��ѧ����Ϣ����      ");
	 printf(" 8.�˳�\n"); 
	 printf(" ********************ллʹ��******************\n"); 
	 return 0;
 } 

int input() /*¼�뺯��*/ 
 {
    int i,m,j; 
     printf("��������Ҫ������Ϣ��ѧ������(1--10):\n"); 
     scanf("%d",&m);
    for (i=0;i<m;i++) 
	{printf("������ѧ�ţ� ");
	 scanf("%s",st[i].no);
	 for(j=0;j<i;j++)
	   if(strcmp(st[i].no,st[j].no)==0)
	   {  printf("ѧ���ظ�,����������:");
	      scanf("%s",st[i].no);	
		  j=-1;
	   } 
	 printf("����������:"); 
	 scanf("%s",st[i].name);
	 printf("��������ѧ�ɼ�(0~100)֮�����: ");
	 scanf("%s",st[i].math);
     printf("\n");
	}
    printf("\n �������!\n");
    save(m);
return menu ();
 }

void save(int m) /*�����ļ�����*/
 { 
	int i; 
	FILE*fp;
	if ((fp=fopen("stu_list","wb"))==NULL) 
	{ 
		printf ("cannot open file\n");
		exit(0); 
}
	for (i=0;i<m;i++) /*���ڴ���ѧ������Ϣ����������ļ���ȥ*/
		if (fwrite(&st[i],sizeof(struct stu),1,fp)!=1) 
			printf("file write error\n"); 
		fclose(fp); 
}

int load() /*���뺯��*/
 { 
	FILE*fp; 
	int i=0;
	if((fp=fopen("stu_list","rb"))==NULL) 
	{ 
		printf ("cannot open file\n"); 
		exit(0);
	} 
	else
	{ 
		do 
		{
			fread(&st[i],sizeof(struct stu),1,fp); 
			i++;
		} 
		while(feof(fp)==0);
	} 
	fclose(fp);
	return(i-1);
 }

int display() /*�������*/ 
{ 
	int i; 
	int m=load();
 printf("\n**********�����ѧ����Ϣ**********");
 printf("\n********************************\n");
 printf("|  ѧ��  |  ����  |��ѧ�ɼ�|\n");
 printf("|--------|--------|--------|\n");
 for(i=0;i<m;i++)
    printf("|%-8s|%-8s|%-8s|\n",st[i].no,st[i].name,st[i].math);
 printf("*************��ӭ����!************\n");
return menu ();
}

void del() /*ɾ������*/ 
{ 
	int m=load();
	int i,j,n,t; 
	char name[20]; 
	printf("\n ԭ����ѧ����Ϣ:\n"); 
	display(); 
	printf("\n"); 
	printf("������Ҫɾ����ѧ��������:\n"); 
	scanf("%s",name); 
	for(i=0;i<m;i++)
	{ 
		if(strcmp(st[i].name,name)==0) 
		{
		printf("\n ���ҵ����ˣ�ԭʼ��¼Ϊ��\n");
		printf("\n********************************\n");
        printf("|  ѧ��  |  ����  |��ѧ�ɼ�|\n");
        printf("|--------|--------|--------|\n");
        printf("|%-8s|%-8s|%-8s|\n",st[i].no,st[i].name,st[i].math);
		 printf("\n ȷʵҪɾ��������Ϣ�밴 1,��ɾ���밴 0\n");
		 scanf("%d",&n);
      if(n==1) 
	  { 
	    for(j=i;j<m-1;j++) 
		{
		 strcpy(st[j].no,st[j+1].no);
		 strcpy(st[j].name,st[j+1].name);
		 strcpy(st[j].math,st[j+1].math);
		}
		m=m-1;
	  }
	  else break;
 } 
} 
	printf("\n ���ɾ���������ѧ����Ϣ:\n"); 
	save(m); /*���ñ��溯��*/ 
	display(); /*�����������*/ 
	printf("\n ����ɾ���밴 1������ɾ���밴 0\n"); 
	scanf("%d",&t); 
	switch(t) 
	{ 
	case 1:del();break; 
	case 0:break; 
	default :break; 
	} 
}

void add()/*��Ӻ���*/ 
{ 
	FILE*fp;
	int n,i,j,count=0; 
	int m=load();
	printf("\n ԭ����ѧ����Ϣ:\n"); 
	display();
	printf("\n"); 
	fp=fopen("stu_list","a");
	printf("�����������ӵ�ѧ������:\n");
	scanf("%d",&n);
for (i=m;i<(m+n);i++) 
{
printf("\n ������������ѧ������Ϣ:\n"); 
printf("������ѧ��: "); 
scanf("%s",st[i].no); 
for(j=0;j<i;j++)
  if(strcmp(st[i].no,st[j].no)==0)
  {printf("ѧ���ظ�,����������:");
   scanf("%s",st[i].no);
   j=-1;
  }
printf("����������: "); 
scanf("%s",st[i].name);  
printf("��������ѧ�ɼ�(0~100): ");
 scanf("%s",st[i].math);
 count=count+1; 
 printf("�����ӵ�����:\n");
 printf("%d\n",count); 
} 
printf("\n ������!\n"); 
m=m+count; 
printf("\n ������Ӻ������ѧ����Ϣ:\n"); 
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
		printf("\n ��ѧ�Ų�ѯ�밴 1;�����������밴 2\n"); 
		scanf("%d",&t);
if(t>=1&&t<=2) 
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
		case 1:printf("��ѧ�Ų�ѯ\n");
			search_no();
			break;
		case 2:main();
			break; 
		default:break; 
		} 
	} 
}

void search_no()
{   char no[10];
	int i,t; 
	int m=load();
	printf("������Ҫ���ҵ�ѧ��:\n");
	scanf("%s",no);
	for(i=0;i<m;i++) 
		if(strcmp(st[i].no,no)==0)
		{ 
		printf("\n ���ҵ����ˣ�ԭʼ��¼Ϊ��\n");
		printf("\n********************************\n");
        printf("|  ѧ��  |  ����  |��ѧ�ɼ�|\n");
        printf("|--------|--------|--------|\n");
        printf("|%-8s|%-8s|%-8s|\n",st[i].no,st[i].name,st[i].math);
		} 
		printf("���ز�ѯ�����밴 1,������ѯѧ���밴 2\n"); 
		scanf("%d",&t); 
		switch(t)
		{ 
		case 1:search();break; 
		case 2: break; 
		default:break; 
		}
}

/*ð�ݷ�����������*/
void paixu() /*������*/
{
   int i,j;
   int m=load();
   struct stu p;
   for(i=1;i<m;i++)
   {for(j=0;j<m-i;j++)
      if(strcmp(st[j].math,st[j+1].math)>0)
	  { strcpy(p.no,st[j].no);
	    strcpy(p.name,st[j].name);
        strcpy(p.math,st[j].math);
		strcpy(st[j].no,st[j+1].no);
	    strcpy(st[j].name,st[j+1].name);
        strcpy(st[j].math,st[j+1].math);
        strcpy(st[j+1].no,p.no);
	    strcpy(st[j+1].name,p.name);
        strcpy(st[j+1].math,p.math);
	  }
   }
save (m);
printf("����ɹ�!\n");
}

void modify() /*�޸ĺ���*/ 
{ 
	char no[10],name[10],math[10]; 
	int b,c,i,n,t;
	int m=load();
 printf("\n ԭ����ѧ����Ϣ:\n"); 
 display(); 
 printf("\n"); 
 printf("������Ҫ�޸ĵ�ѧ��������:\n");
 scanf("%s",name); 
 for(i=0;i<m;i++) 
 { 
	 if(strcmp(st[i].name,name)==0)
	 { 
		printf("\n ���ҵ����ˣ�ԭʼ��¼Ϊ��\n");
		printf("\n********************************\n");
        printf("|  ѧ��  |  ����  |��ѧ�ɼ�|\n");
        printf("|--------|--------|--------|\n");
        printf("|%-8s|%-8s|%-8s|\n",st[i].no,st[i].name,st[i].math);
        printf("\n ȷʵҪ�޸Ĵ�����Ϣ�밴 1 ; ���޸��밴 0\n"); 
        scanf("%d",&n);
      if(n==1)
	  { 
	   printf("\n ��Ҫ�����޸ĵ�ѡ��\n 1.ѧ�� 2.���� 3.��ѧ�ɼ�\n");
	   printf("�����������޸ĵ���һ�����:\n"); 
	   scanf("%d",&c); 
	   if(c>3||c<1) 
		 printf("\n ѡ�����������ѡ��!\n"); 
	   do 
		 { 
	       switch(c) 
		   {
		    case 1:printf("ѧ�Ÿ�Ϊ: "); 
				 scanf("%s",no);
				 strcpy(st[i].no,no);
				 break; 
		    case 2:printf("������Ϊ: "); 
				 scanf("%s",name); 
				 strcpy(st[i].name,name); 
				 break; 
		   case 3:printf("��ѧ�ɼ���Ϊ: "); 
				 scanf("%s",math);
				 strcpy(st[i].math,math);
				 break;
		   } 
	        printf("\n"); 
	        printf("\n �Ƿ�ȷ�����޸ĵ���Ϣ?\n �� �밴 1 ; ��,�����޸� �밴 2: \n"); 
	        scanf("%d",&b); 
		 }while(b==2);
	  }
	else break;
	 }
 } 
 printf("\n ����޸ĺ������ѧ����Ϣ:\n");
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
