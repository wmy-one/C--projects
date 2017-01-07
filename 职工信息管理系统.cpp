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
 }em[100];    /*定义一个结构体*/ 
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
 void tongji();      /*定义各函数*/

void main()
{menu();
 int n,flag;
 char a;
 do 
 { 
	 printf("请选择你需要操作的步骤(1--9):\n");
	 scanf("%d",&n); 
	 if(n>=1&&n<=9)
{
		 flag=1;
		 break;
 }
	 else
	 {
		 flag=0;
	 printf("您输入有误，请重新选择!");
 } 
} 
 while(flag==0); 
 while(flag==1) 
 { 
	 switch(n) 
	 { case 1:printf(" 输入职工信息 \n");
	     printf("\n");
	     input();
	     break;
	 case 2:printf(" 浏览职工信息\n");   
		 printf("\n");
		 display();
		 break; 
	 case 3:printf(" 按职工号查询职工信息 \n");
		 printf("\n");
		 search();
		 break;
	 case 4:printf(" 删除职工信息 \n");
		 printf("\n");
		 del();
		 break; 
	 case 5:
		 printf(" 添加职工信息 \n");
		 printf("\n");
		 add();
		 break;
	 case 6:printf(" 修改职工信息 \n");
		 printf("\n");
		 modify();
		 break;
	 case 7:printf("对职工信息排序 \n");
		 printf("\n");
		 paixu();
		 break;
	 case 8:printf("统计不同部门的人数 \n");
		 printf("\n");
		 tongji ();
		 break;
	 case 9:exit(0);
		 break;
	 default :break; } 
	 getchar();
	 printf("\n");
	 printf("是否继续进行(y or n):\n");
	 scanf("%c",&a); 
	 if(a=='y')
	 { flag=1; system("cls"); /*清屏*/ 
	 menu(); /*调用菜单函数*/ 
	 printf("请再次选择你需要操作的步骤(1--9):\n"); 
	 scanf("%d",&n); 
	 printf("\n"); 
	 }
     else 
		 exit(0);
 }
}
 int menu() /*菜单函数*/ 
 {
	 printf(" ************欢迎进入职工信息管理系统**********\n"); 
	 printf(" 1.录入职工信息        "); 
	 printf(" 2.浏览职工信息\n");
	 printf(" 3.查询职工信息        ");
	 printf(" 4.删除职工信息\n");
	 printf(" 5.添加职工信息        "); 
	 printf(" 6.修改职工信息\n");
	 printf(" 7.对职工信息排序      ");
	 printf(" 8.统计不同部门的人数\n");
	 printf(" 9.退出\n"); 
	 printf(" ********************谢谢使用******************\n");
	 printf("\n"); 
	 printf("\n");
	 return 0;
 } 
 int input() /*录入函数*/ 
 { int b=123,h;
  printf("请输入密码!\n");
   scanf("%d",&h);
   if(b==h)
   { int i,m; 
     printf("请输入需要创建信息的职工人数(1--100):\n"); 
     scanf("%d",&m);
    for (i=0;i<m;i++) 
	{
	 printf("请输入职工号： ");
	 scanf("%d",&em[i].num);
	 printf("请输入姓名:"); 
	 scanf("%s",em[i].name);
	 getchar();
	 printf("请输入性别(f--女 m--男): ");
	 scanf("%c",&em[i].sex);
	 printf("请输入职称: ");
	 scanf("%s",em[i].job);
     printf("请输入部门: ");
	 scanf("%s",em[i].depart);
	 printf("请输入身份证号: ");
	 scanf("%d",&em[i].id);
	 printf("请输入婚否(y--是 n--否): ");
	 scanf("%s",em[i].marry);
	  printf("请输入出身年月: ");
	 scanf("%d",&em[i].birth);
	 printf("请输入学历: "); 
	 scanf("%s",em[i].xueli);
	 printf("请输入工资: ");
	 scanf("%d",&em[i].wage);
	 printf("请输入住址: "); 
	 scanf("%s",em[i].addr);
     printf("请输入电话: "); 
     scanf("%s",em[i].tel);
     printf("\n");
	}
    printf("\n 创建完毕!\n");
    save(m);
   }
   else
   {
	   printf("密码错误! 请重新输入!\n");
	   return menu ();
   }
 }

void save(int m) /*保存文件函数*/
 { 
	int i; 
	FILE*fp;
	if ((fp=fopen("employee_list","wb"))==NULL) 
	{ 
		printf ("cannot open file\n");
		exit(0); 
}
	for (i=0;i<m;i++) /*将内存中职工的信息输出到磁盘文件中去*/
		if (fwrite(&em[i],sizeof(struct employee),1,fp)!=1) 
			printf("file write error\n"); 
		fclose(fp); 
}

int load() /*导入函数*/
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

int display() /*浏览函数*/ 
{ 
	int i,b=123,h; 
	int m=load();
	printf("请输入密码!\n");
	scanf("%d",&h);
	if(b==h)
	{
 printf("                                      职工信息");
 printf("\n******************************************************************************\n");
 printf(" |职工编号|姓名|性别|职称|部门|身份证号|婚否|出生年月|学历  |工资|地址  |电话  |\n");
 printf(" |--------|----|----|----|----|--------|----|--------|------|----|------|------|\n");
 for(i=0;i<m;i++)
    {printf(" |%-8d|%-4s|%-4c|%-4s|%-4s|%-8d|%-4s|%-8d|",em[i].num,em[i].name,em[i].sex, em[i].job,em[i].depart,em[i].id,em[i].marry,em[i].birth);
     printf("%-6s|%-4d|%-6s|%-6s|\n",em[i].xueli,em[i].wage,em[i].addr,em[i].tel);
	}
 printf("*************************************欢迎光临!***********************************\n");
 getchar();
	}
	else
	{printf("密码错误! 请重新输入!");
	return menu ();
	}
}

void del() /*删除函数*/ 
{ 
	int m=load();
	int i,j,n,t,flag; 
	char name[20]; 
	printf("\n 原来的职工信息:\n"); 
	display(); 
	printf("\n"); 
	printf("请输入要删除的职工的姓名:\n"); 
	scanf("%s",name); 
	for(flag=1,i=0;flag&&i<m;i++)
	{ 
		if(strcmp(em[i].name,name)==0) 
		{
		printf("\n 已找到此人，原始记录为：\n");
		 printf("\n********************************************************************************\n");
		 printf(" |职工编号|姓名|性别|职称|部门|身份证号|婚否|出生年月|学历  |工资|地址  |电话  |\n");
		 printf(" |--------|----|----|----|----|--------|----|--------|------|----|------|------|\n");
		 printf(" |%-8d|%-4s|%-4c|%-4s|%-4s|%-8d|%-4s|%-8d|",em[i].num,em[i].name,em[i].sex, em[i].job,em[i].depart,em[i].id,em[i].marry,em[i].birth);
		 printf("%-6s|%-4d|%-6s|%-6s|\n",em[i].xueli,em[i].wage,em[i].addr,em[i].tel);
		 printf("**************************************欢迎光临!***********************************\n");
		 printf("\n 确实要删除此人信息请按 1,不删除请按 0\n");
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
	else printf("\n 对不起，查无此人!\n");
	printf("\n 浏览删除后的所有职工信息:\n"); 
	save(m); /*调用保存函数*/ 
	display(); /*调用浏览函数*/ 
	printf("\n 继续删除请按 1，不再删除请按 0\n"); 
	scanf("%d",&t); 
	switch(t) 
	{ 
	case 1:del();break; 
	case 0:break; 
	default :break; 
} }
void add()/*添加函数*/ 
{ 
	FILE*fp;
	int n; 
	int count=0; 
	int i;
	int m=load();
	printf("\n 原来的职工信息:\n"); 
	display();
	printf("\n"); 
	fp=fopen("emploee_list","a");
	printf("请输入想增加的职工数:\n");
	scanf("%d",&n);
for (i=m;i<(m+n);i++) 
{
printf("\n 请输入新增加职工的信息:\n"); 
printf("请输入职工号: "); 
scanf("%d",&em[i].num); 
printf("\n"); 
printf("请输入姓名: "); 
scanf("%s",em[i].name); 
getchar(); 
printf("请输入性别(f--女 m--男):  ");
scanf("%c",&em[i].sex);
 printf("请输入职称: ");
 scanf("%s",em[i].job);
 printf("请输入部门: ");
 scanf("%s",em[i].depart); 
 printf("请输入身份证号: ");
 scanf("%d",&em[i].id); 
 printf("请输入婚否(y--是 n--否): ");
 scanf("%s",em[i].marry); 
 printf("请输入出身年月: ");
 scanf("%d",&em[i].birth); 
 printf("请输入学历: "); 
 scanf("%s",em[i].xueli);
 printf("请输入工资: ");
 scanf("%d",&em[i].wage); 
 printf("请输入住址: "); 
 scanf("%s",em[i].addr);
 printf("请输入电话: ");
 scanf("%s",em[i].tel); 
 printf("\n");
 count=count+1; 
 printf("已增加的人数:\n");
 printf("%d\n",count); 
} 
printf("\n 添加完毕!\n"); 
m=m+count; 
printf("\n 浏览增加后的所有职工信息:\n"); 
printf("\n"); 
save(m); 
display();
 fclose(fp);
 }
void search()/*查询函数*/ 
{ 
	int t,flag; 
	do 
	{
		printf("\n 按职工号查询请按 1; 按学历查询请按 2; 按电话号码查询请按 3； 进入 主函数请按 4\n"); 
		scanf("%d",&t);
if(t>=1&&t<=4) 
{ 
	flag=1; 
	break;
 }
 else 
 { 
	 flag=0;
	 printf("您输入有误，请重新选择!"); 
} 
} 
	while(flag==0); 
	while(flag==1)
	{ 
		switch(t) 
		{ 
		case 1:printf("按职工号查询\n");
			search_num();
			break;
		case 2:printf("按学历查询\n");
			search_xueli();
			break;
		case 3:printf("按电话号码查询\n");
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
	printf("请输入要查找的职工号:\n");
	scanf("%d",&num);
	for(i=0;i<m;i++) 
		if(num==em[i].num)
		{ 
			printf("\n              已找到此人，其记录为:\n"); 
 printf("\n***************************************************************************\n");
 printf(" |职工编号|姓名|性别|职称|部门|身份证号|婚否|出生年月|学历  |工资|地址  |电话  |\n");
 printf(" |--------|----|----|----|----|--------|----|--------|------|----|------|------|\n");
 printf(" |%-8d|%-4s|%-4c|%-4s|%-4s|%-8d|%-4s|%-8d|",em[i].num,em[i].name,em[i].sex, em[i].job,em[i].depart,em[i].id,em[i].marry,em[i].birth);
 printf("%-6s|%-4d|%-6s|%-6s|\n",em[i].xueli,em[i].wage,em[i].addr,em[i].tel);
 printf("***********************************欢迎光临!*********************************\n");
    break; } 
		if(i==m) 
			printf("\n 对不起，查无此人\n"); 
		printf("\n");
		printf("返回查询函数请按 1,继续查询职工号请按 2\n"); 
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
	printf("请输入要查找的学历:\n");
	scanf("%s",xueli); 
	for(i=0;i<m;i++)
		if(strcmp(em[i].xueli,xueli)==0) 
		{
			printf("\n                  已找到，其记录为:\n"); 
printf("\n***********************************************************************************\n");
 printf(" |职工编号|姓名|性别|职称|部门|身份证号|婚否|出生年月|学历  |工资|地址  |电话  |\n");
 printf(" |--------|----|----|----|----|--------|----|--------|------|-------|------|------|\n");
 printf(" |%-8d|%-4s|%-4c|%-4s|%-4s|%-8d|%-4s|%-8d|",em[i].num,em[i].name,em[i].sex,em[i].job,em[i].depart,em[i].id,em[i].marry,em[i].birth);
 printf("%-6s|%-4d|%-6s|%-6s|\n",em[i].xueli,em[i].wage,em[i].addr,em[i].tel);
 printf("*************************************欢迎光临!*************************************\n");
		} 
		if(i==m) 
			printf("\n 对不起，查无此人\n");
		printf("\n"); 
		printf("返回查询函数请按 1,继续查询学历请按 2\n"); 
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
	printf("请输入要查找的电话号码:\n");
	scanf("%s",tel); 
	for(i=0;i<m;i++)
		if(strcmp(tel,em[i].tel)==0)
		{
			printf("\n               已找到此人，其记录为:\n");
    printf("\n************************************************************************\n");
 printf(" |职工编号|姓名|性别|职称|部门|身份证号|婚否|出生年月|学历  |工资|地址  |电话  |\n");
 printf(" |--------|----|----|----|----|--------|----|--------|------|----|------|------|\n");
 printf(" |%-8d|%-4s|%-4c|%-4s|%-4s|%-8d|%-4s|%-8d|",em[i].num,em[i].name,em[i].sex, em[i].job,em[i].depart,em[i].id,em[i].marry,em[i].birth);
 printf("%-6s|%-4d|%-6s|%-6s|\n",em[i].xueli,em[i].wage,em[i].addr,em[i].tel);
 printf("********************************欢迎光临!********************************\n");
 break; 
} 
		if(i==m) 
			printf("\n 对不起，查无此人\n"); 
		printf("\n"); 
		printf("返回查询函数请按 1,继续查询电话号码请按 2\n"); 
		scanf("%d",&t);
		switch(t)
		{ 
		case 1:search();break; 
		case 2:break; 
		default :break; 
} 
}
/*冒泡法按工资排序*/
void paixu() /*排序函数*/
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
printf("排序成功!\n");
}

void tongji()
{
 int i,j,t;
 int m=load();
 printf("\n               已找到此人，其记录为:\n");
 printf("\n*********************************************************************\n");
 printf("|  部门  | 人数  |\n");
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
 printf("********************************欢迎光临!********************************\n");
}
void modify() /*修改函数*/ 
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
 printf("\n 原来的职工信息:\n"); 
 display(); 
 printf("\n"); 
 printf("请输入要修改的职工的姓名:\n");
 scanf("%s",name); 
 for(flag=1,i=0;flag&&i<m;i++) 
 { 
	 if(strcmp(em[i].name,name)==0)
	 { 
		 printf("\n 已找到此人，原始记录为：\n");
	printf("\n**********************************************************************\n");
 printf(" |职工编号|姓名|性别|职称|部门|身份证号|婚否|出生年月|学历  |工资|地址  |电话  |\n");
 printf(" |--------|----|----|----|----|--------|----|--------|------|----|------|------|\n");
 printf(" |%-8d|%-4s|%-4c|%-4s|%-4s|%-8d|%-4s|%-8d|",em[i].num,em[i].name,em[i].sex, em[i].job,em[i].depart,em[i].id,em[i].marry,em[i].birth);
 printf("%-6s|%-4d|%-6s|%-6s|\n",em[i].xueli,em[i].wage,em[i].addr,em[i].tel);
 printf("********************************欢迎光临!*********************************\n");
    printf("\n 确实要修改此人信息请按 1 ; 不修改请按 0\n"); 
scanf("%d",&n);
 if(n==1)
 { 
	 printf("\n 需要进行修改的选项\n 1.职工号 2.姓名 3.性别 4.职称5.部门 6.身份证号 7.婚否 8.出身年月 9. 学历 10.工资 11.住址 12.电话\n");
	 printf("请输入你想修改的那一项序号:\n"); 
	 scanf("%d",&c); 
	 if(c>12||c<1) 
		 printf("\n 选择错误，请重新选择!\n"); 
 } flag=0; 
	 } 
 } 
 if(flag==1)
	 printf("\n 对不起，查无此人!\n"); 
 do 
 { 
	 switch(c) /*因为当找到第 i 个职工时,for 语句后 i 自加了 1,所以下面的应该把改 后的信息赋值给第 i-1 个人*/ 
	 {
		 case 1:printf("职工号改为: "); 
				 scanf("%d",&num);
				 em[i-1].num=num;
				 break; 
		 case 2:printf("姓名改为: "); 
				 scanf("%s",name); 
				 strcpy(em[i-1].name,name); 
				 break; 
		 case 3:printf("性别改为: ");
				 getchar(); 
				 scanf("%c",&sex); 
				 em[i-1].sex=sex; 
				 break; 
		case 4:printf("职称改为: "); 
				 scanf("%s",job); 
				 strcpy(em[i-1].job,job);
				 break;
		case 5:printf("部门改为: "); 
				 scanf("%s",depart); 
				 strcpy(em[i-1].depart,depart);
				 break;
		case 6:printf("身份证号改为: "); 
				 scanf("%d",&id); 
				 em[i-1].id=id;
				 break; 
		case 7:printf("婚否改为: "); 
				 scanf("%s",marry); 
				 strcpy(em[i-1].marry,marry);
				 break;
		case 8:printf("出生日期改为: "); 
				 scanf("%d",&birth); 
				 em[i-1].birth=birth;
				 break; 
		case 9:printf("学历改为: ");
				 scanf("%s",xueli);
				 strcpy(em[i-1].xueli,xueli); 
				 break; 
		case 10:printf("工资改为: "); 
				 scanf("%d",&wage);
				 break; 
		case 11:printf("住址改为: "); 
				 scanf("%s",addr);
				 strcpy(em[i-1].addr,addr);
				 break; 
		case 12:printf("电话改为: "); 
				 scanf("%s",tel); 
				 strcpy(em[i-1].tel,tel); 
				 break; 
	 } 
	 printf("\n"); 
	 printf("\n 是否确定所修改的信息?\n 是 请按 1 ; 不,重新修改 请按 2: \n"); 
	 scanf("%d",&b); 
 } 
 while(b==2);
 printf("\n 浏览修改后的所有职工信息:\n");
 printf("\n");
 save(m); 
 display(); 
 printf("\n 继续修改请按 1，不再修改请按 0\n");
 scanf("%d",&t);
 switch(t) 
 { 
 case 1:modify();
	 break; 
 case 0:break;
 default :break; 
} 
}
