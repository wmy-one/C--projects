#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu			    //����ṹ������
{
    char no[20];		    //ѧ��
    char name[20];		    //����
    char math[20];		  	//��ѧ�ɼ�
} st[10];
int menu();
void input();
void save(int);
void display();
void del();
void add();
void search();
void search_no();
void modify();
void paixu();      /*���������*/

int main()
{
    char select[10];
    int b;
    char a;
    for(;;)
    {
        do
        {
            menu();
            printf("��ѡ������Ҫ�����Ĳ���(1--8):\n");
            scanf("%s",select);

            b = atoi(select);
        }
        while((b < 1) || (b > 8));

        switch(b)
        {
        case 1:
            printf(" ����ѧ����Ϣ \n");
            input();
            break;
        case 2:
            printf(" ���ѧ����Ϣ\n");
            display();
            break;
        case 3:
            printf(" ��ѧ�Ų�ѯѧ����Ϣ \n");
            search();
            break;
        case 4:
            printf(" ɾ��ѧ����Ϣ \n");
            del();
            break;
        case 5:
            printf(" ���ѧ����Ϣ \n");
            add();
            break;
        case 6:
            printf(" �޸�ѧ����Ϣ \n");
            modify();
            break;
        case 7:
            printf("��ѧ����Ϣ���� \n");
            paixu();
            break;
        case 8:
            exit(0);
            break;
        default :
            break;
        }
        fflush(stdin);
	   do
	   { fflush(stdin);
		 printf("�Ƿ��������(y or n):\n");
         scanf("%c",&a);
	   }while((a!='y')&&(a!='n'));
        if(a=='y')
        {
            printf("���ٴ�ѡ������Ҫ�����Ĳ���(1--8):\n");
            fflush(stdin);
        }
        else
            exit(0);
    }
    return 0;
}

int menu() /*�˵�����*/
{
    system("cls");
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

void input() /*¼�뺯��*/
{
    int i,m,j,b;
	char a[10];
	printf("��������Ҫ������Ϣ��ѧ������(1--10):\n");
	do
	{
     scanf("%s",a);
	 m=atoi(a);
	 if((m<1)||(m>10))
	  printf("������ķ�����,��������Ӧ������:\n");
	}while((m<1)||(m>10));
    for (i=0; i<m; i++)
    {
        printf("������ѧ�ţ� ");
        scanf("%s",st[i].no);
        for(j=0; j<i; j++)
            if(strcmp(st[i].no,st[j].no)==0)
            {
                printf("ѧ���ظ�,����������:");
                scanf("%s",st[i].no);
                j=-1;
            }
        printf("����������:");
        scanf("%s",st[i].name);
		do
        { printf("��������ѧ�ɼ�(0~100)֮�����: ");
          scanf("%s",st[i].math);
          b=atoi(st[i].math);
		}while((b<=0)||(b>100));
        printf("\n");
    }
    printf("\n �������!\n");
    save(m);
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
    for (i=0; i<m; i++) /*���ڴ���ѧ������Ϣ����������ļ���ȥ*/
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

void display() /*�������*/
{
    int i;
    int m=load();
    printf("\n**********�����ѧ����Ϣ**********");
    printf("\n********************************\n");
    printf("|  ѧ��  |  ����  |��ѧ�ɼ�|\n");
    printf("|--------|--------|--------|\n");
    for(i=0; i<m; i++)
        printf("|%-8s|%-8s|%-8s|\n",st[i].no,st[i].name,st[i].math);
    printf("*************��ӭ����!************\n");
}

void del() /*ɾ������*/
{
    int m=load();
    int i,j,b,a;
    char no[20],n[10],t[10];
    printf("\n ԭ����ѧ����Ϣ:\n");
    display();
    printf("\n");
    printf("������Ҫɾ����ѧ����ѧ��:\n");
    scanf("%s",no);
    for(i=0;i<m;i++)
    {
        if(strcmp(st[i].no,no)==0)
        {
            printf("\n ���ҵ����ˣ�ԭʼ��¼Ϊ��\n");
            printf("\n********************************\n");
            printf("|  ѧ��  |  ����  |��ѧ�ɼ�|\n");
            printf("|--------|--------|--------|\n");
            printf("|%-8s|%-8s|%-8s|\n",st[i].no,st[i].name,st[i].math);
		    do
			{ printf("\n ȷʵҪɾ��������Ϣ�밴 1,��ɾ���밴 2\n");
              scanf("%s",n);
			  a=atoi(n);
			}while((a<1)||(a>2));
            if(a==1)
            {
                for(j=i; j<m-1; j++)
                {
                    strcpy(st[j].no,st[j+1].no);
                    strcpy(st[j].name,st[j+1].name);
                    strcpy(st[j].math,st[j+1].math);
                }
                m=m-1;
            }
            else break;
        }
      else if(i>=m-1) 
	  { printf("�޴�����Ϣ!");
        do
		{ printf("\n ����ɾ���밴 1������ɾ���밴 2\n");
          scanf("%s",t);
	      b=atoi(t);
		}while((b<1)||(b>2));
       switch(b)
	   {
         case 1:del();
             break;
         case 2:
            break;
        default :
             break;
	   }
	  }
    }
    printf("\n ���ɾ���������ѧ����Ϣ:\n");
    save(m); /*���ñ��溯��*/
    display(); /*�����������*/
}

void add()/*��Ӻ���*/
{
    FILE*fp;
	char h[10];
    int n,i,j,count=0,b;
    int m=load();
    printf("\n ԭ����ѧ����Ϣ:\n");
    display();
    printf("\n");
    fp=fopen("stu_list","a");
	do
	{
     printf("�����������ӵ�ѧ������:\n");
     scanf("%s",h);
	 n=atoi(h);
	}while((n<=0)||(n>10-m));
    for (i=m; i<(m+n); i++)
    {
        printf("\n ������������ѧ������Ϣ:\n");
        printf("������ѧ��: ");
        scanf("%s",st[i].no);
        for(j=0; j<i; j++)
            if(strcmp(st[i].no,st[j].no)==0)
            {
                printf("ѧ���ظ�,����������:");
                scanf("%s",st[i].no);
                j=-1;
            }
        printf("����������: ");
        scanf("%s",st[i].name);
        do
        { printf("��������ѧ�ɼ�(0~100)֮�����: ");
          scanf("%s",st[i].math);
          b=atoi(st[i].math);
		}while((b<=0)||(b>100));
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
    char t[10];
	int b;
    do
    {
        printf("\n ��ѧ�Ų�ѯ�밴 1;�������˵��밴 2\n");
        scanf("%s",t);
        b=atoi(t);
    }
    while((b<1)||(b>2));
    switch(b)
      {
        case 1:
            printf("��ѧ�Ų�ѯ\n");
            search_no();
            break;
        case 2:menu();
            break;
        default:
            break;
      }
}

void search_no()
{
    char no[20],t[10];
    int i,a;
    int m=load();
    printf("������Ҫ���ҵ�ѧ��:\n");
    scanf("%s",no);
    for(i=0; i<m; i++)
        if(strcmp(st[i].no,no)==0)
        {
            printf("\n ���ҵ����ˣ�ԭʼ��¼Ϊ��\n");
            printf("\n********************************\n");
            printf("|  ѧ��  |  ����  |��ѧ�ɼ�|\n");
            printf("|--------|--------|--------|\n");
            printf("|%-8s|%-8s|%-8s|\n",st[i].no,st[i].name,st[i].math);
        }
	do
	{printf("�������˵��밴 1,������ѯ�밴 2\n");
     scanf("%s",t);
     a=atoi(t);
	}while((a<1)||(a>2));
    switch(a)
    {
    case 1:
        menu();
        break;
    case 2:search_no();
        break;
    default:
        break;
    }
}

/*ð�ݷ�����ѧ�ɼ�����*/
void paixu() /*������*/
{
    int i,j;
    int m=load();
    struct stu p;
    for(i=1; i<m; i++)
    {
        for(j=0; j<m-i; j++)
		  if(atoi(st[j].math)>atoi(st[j+1].math))
            {
                p=st[j];
				st[j]=st[j+1];
				st[j+1]=p;
            }
    }
    save (m);
    printf("����ɹ�!\n");
}

void modify() /*�޸ĺ���*/
{
    char no[20],num[20],math[20],name[20];
	char c[10],n[10],t[10];
    int q,w,i,a,b=0,j;
    int m=load();
    printf("\n ԭ����ѧ����Ϣ:\n");
    display();
    printf("\n");
    printf("������Ҫ�޸ĵ�ѧ����ѧ��:\n");
    scanf("%s",num);
    for(i=0; i<m; i++)
    {
        if(strcmp(st[i].no,num)==0)
        {
            printf("\n ���ҵ����ˣ�ԭʼ��¼Ϊ��\n");
            printf("\n********************************\n");
            printf("|  ѧ��  |  ����  |��ѧ�ɼ�|\n");
            printf("|--------|--------|--------|\n");
            printf("|%-8s|%-8s|%-8s|\n",st[i].no,st[i].name,st[i].math);
            do
			{ printf("\n ȷʵҪ�޸Ĵ�����Ϣ�밴 1 ; ���޸��밴 2\n");
              scanf("%s",n);
			  q=atoi(n);
			}while((q<1)||(q>2));
            if(q==1)
            {  
				do
				{  printf("\n ��Ҫ�����޸ĵ�ѡ��\n 1.ѧ�� 2.���� 3.��ѧ�ɼ�\n");
                   printf("�����������޸ĵ���һ�����:\n");
                   scanf("%s",c);
				   w=atoi(c);
				}while((w<1)||(w>3)||(w>1&&w<2)||(w>2&&w<3));
             switch(w)
               {
                 case 1:
                    printf("ѧ�Ÿ�Ϊ: ");
                    scanf("%s",no);b++;
                   for(j=0; j<m; j++)
                        if(strcmp(no,st[j].no)==0)
						{
                           printf("ѧ���ظ�,����������:");
                           scanf("%s",no);
                           j=-1;
						}
                    strcpy(st[i].no,no);
                    break;
                 case 2:
                    printf("������Ϊ: ");
                    scanf("%s",name);b++;
                    strcpy(st[i].name,name);
                    break;
                 case 3:
                     printf("��ѧ�ɼ���Ϊ: ");
                     scanf("%s",math);b++;
                     strcpy(st[i].math,math);
                     break;
                }
			}
            else break;
        }
		else if(i>=m-1&&b==0) 
		{ printf("�޴�����Ϣ!");
		 do
		 { printf("\n �����޸��밴 1�������޸��밴 2\n");
           scanf("%s",t);
	       a=atoi(t);
		 }while((a<1)||(a>2));
       switch(a)
	   {
         case 1:modify(); break;
         case 2: break;
         default :break;   
	   }
		}
    }
    printf("\n ����޸ĺ������ѧ����Ϣ:\n");
    printf("\n");
    save(m);
    display();
}
