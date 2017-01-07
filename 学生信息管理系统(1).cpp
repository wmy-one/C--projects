#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu			    //定义结构体类型
{
    char no[20];		    //学号
    char name[20];		    //姓名
    char math[20];		  	//数学成绩
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
void paixu();      /*定义各函数*/

int main()
{
    char select[10];
    int n;
    char a;
    for(;;)
    {
        do
        {
            menu();
            printf("请选择你需要操作的步骤(1--8):\n");
            scanf("%s",select);

            n = atoi(select);
        }
        while((n < 1) || (n > 8));

        switch(n)
        {
        case 1:
            printf(" 输入学生信息 \n");
            input();
            break;
        case 2:
            printf(" 浏览学生信息\n");
            display();
            break;
        case 3:
            printf(" 按学号查询学生信息 \n");
            search();
            break;
        case 4:
            printf(" 删除学生信息 \n");
            del();
            break;
        case 5:
            printf(" 添加学生信息 \n");
            add();
            break;
        case 6:
            printf(" 修改学生信息 \n");
            modify();
            break;
        case 7:
            printf("对学生信息排序 \n");
            paixu();
            break;
        case 8:
            exit(0);
            break;
        default :
            break;
        }
        fflush(stdin);
        printf("是否继续进行(y or n):\n");
        scanf("%c",&a);
        if(a=='y')
        {
            printf("请再次选择你需要操作的步骤(1--8):\n");
            fflush(stdin);
        }
        else
            exit(0);
    }
    return 0;
}

int menu() /*菜单函数*/
{
    system("cls");
    printf("\n\n************欢迎进入学生信息管理系统**********\n");
    printf(" 1.录入学生信息        ");
    printf(" 2.浏览学生信息\n");
    printf(" 3.查询学生信息        ");
    printf(" 4.删除学生信息\n");
    printf(" 5.添加学生信息        ");
    printf(" 6.修改学生信息\n");
    printf(" 7.对学生信息排序      ");
    printf(" 8.退出\n");
    printf(" ********************谢谢使用******************\n");
    return 0;
}

void input() /*录入函数*/
{
    int i,m,j;
    printf("请输入需要创建信息的学生人数(1--10):\n");
    scanf("%d",&m);
    for (i=0; i<m; i++)
    {
        printf("请输入学号： ");
        scanf("%s",st[i].no);
        for(j=0; j<i; j++)
            if(strcmp(st[i].no,st[j].no)==0)
            {
                printf("学号重复,请重新输入:");
                scanf("%s",st[i].no);
                j=-1;
            }
        printf("请输入姓名:");
        scanf("%s",st[i].name);
        printf("请输入数学成绩(0~100)之间的数: ");
        scanf("%s",st[i].math);
        printf("\n");
    }
    printf("\n 创建完毕!\n");
    save(m);
}

void save(int m) /*保存文件函数*/
{
    int i;
    FILE*fp;
    if ((fp=fopen("stu_list","wb"))==NULL)
    {
        printf ("cannot open file\n");
        exit(0);
    }
    for (i=0; i<m; i++) /*将内存中学生的信息输出到磁盘文件中去*/
        if (fwrite(&st[i],sizeof(struct stu),1,fp)!=1)
            printf("file write error\n");
    fclose(fp);
}

int load() /*导入函数*/
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

void display() /*浏览函数*/
{
    int i;
    int m=load();
    printf("\n**********请浏览学生信息**********");
    printf("\n********************************\n");
    printf("|  学号  |  姓名  |数学成绩|\n");
    printf("|--------|--------|--------|\n");
    for(i=0; i<m; i++)
        printf("|%-8s|%-8s|%-8s|\n",st[i].no,st[i].name,st[i].math);
    printf("*************欢迎光临!************\n");
}

void del() /*删除函数*/
{
    int m=load();
    int i,j,n,t;
    char name[20];
    printf("\n 原来的学生信息:\n");
    display();
    printf("\n");
    printf("请输入要删除的学生的姓名:\n");
    scanf("%s",name);
    for(i=0; i<m; i++)
    {
        if(strcmp(st[i].name,name)==0)
        {
            printf("\n 已找到此人，原始记录为：\n");
            printf("\n********************************\n");
            printf("|  学号  |  姓名  |数学成绩|\n");
            printf("|--------|--------|--------|\n");
            printf("|%-8s|%-8s|%-8s|\n",st[i].no,st[i].name,st[i].math);
            printf("\n 确实要删除此人信息请按 1,不删除请按 0\n");
            scanf("%d",&n);
            if(n==1)
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
    }
    printf("\n 浏览删除后的所有职工信息:\n");
    save(m); /*调用保存函数*/
    display(); /*调用浏览函数*/
    printf("\n 继续删除请按 1，不再删除请按 0\n");
    scanf("%d",&t);
    switch(t)
    {
    case 1:
        del();
        break;
    case 0:
        break;
    default :
        break;
    }
}

void add()/*添加函数*/
{
    FILE*fp;
    int n,i,j,count=0;
    int m=load();
    printf("\n 原来的学生信息:\n");
    display();
    printf("\n");
    fp=fopen("stu_list","a");
    printf("请输入想增加的学生人数:\n");
    scanf("%d",&n);
    for (i=m; i<(m+n); i++)
    {
        printf("\n 请输入新增加学生的信息:\n");
        printf("请输入学号: ");
        scanf("%s",st[i].no);
        for(j=0; j<i; j++)
            if(strcmp(st[i].no,st[j].no)==0)
            {
                printf("学号重复,请重新输入:");
                scanf("%s",st[i].no);
                j=-1;
            }
        printf("请输入姓名: ");
        scanf("%s",st[i].name);
        printf("请输入数学成绩(0~100): ");
        scanf("%s",st[i].math);
        count=count+1;
        printf("已增加的人数:\n");
        printf("%d\n",count);
    }
    printf("\n 添加完毕!\n");
    m=m+count;
    printf("\n 浏览增加后的所有学生信息:\n");
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
        printf("\n 按学号查询请按 1;进入主函数请按 2\n");
        scanf("%d",&t);
        if(t>=1&&t<=2)
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
        case 1:
            printf("按学号查询\n");
            search_no();
            break;
        case 2:
            main();
            break;
        default:
            break;
        }
    }
}

void search_no()
{
    char no[20];
    int i,t;
    int m=load();
    printf("请输入要查找的学号:\n");
    scanf("%s",no);
    for(i=0; i<m; i++)
        if(strcmp(st[i].no,no)==0)
        {
            printf("\n 已找到此人，原始记录为：\n");
            printf("\n********************************\n");
            printf("|  学号  |  姓名  |数学成绩|\n");
            printf("|--------|--------|--------|\n");
            printf("|%-8s|%-8s|%-8s|\n",st[i].no,st[i].name,st[i].math);
        }
    printf("返回查询函数请按 1,继续查询职工号请按 2\n");
    scanf("%d",&t);
    switch(t)
    {
    case 1:
        search();
        break;
    case 2:
        break;
    default:
        break;
    }
}

/*冒泡法按工资排序*/
void paixu() /*排序函数*/
{
    int i,j;
    int m=load();
    struct stu p;
    for(i=1; i<m; i++)
    {
        for(j=0; j<m-i; j++)
            if(strcmp(st[j].math,st[j+1].math)>0)
            {
                strcpy(p.no,st[j].no);
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
    printf("排序成功!\n");
}

void modify() /*修改函数*/
{
    char no[20],name[20],math[20];
    int b,c,i,n,t;
    int m=load();
    printf("\n 原来的学生信息:\n");
    display();
    printf("\n");
    printf("请输入要修改的学生的姓名:\n");
    scanf("%s",name);
    for(i=0; i<m; i++)
    {
        if(strcmp(st[i].name,name)==0)
        {
            printf("\n 已找到此人，原始记录为：\n");
            printf("\n********************************\n");
            printf("|  学号  |  姓名  |数学成绩|\n");
            printf("|--------|--------|--------|\n");
            printf("|%-8s|%-8s|%-8s|\n",st[i].no,st[i].name,st[i].math);
            printf("\n 确实要修改此人信息请按 1 ; 不修改请按 0\n");
            scanf("%d",&n);
            if(n==1)
            {
                printf("\n 需要进行修改的选项\n 1.学号 2.姓名 3.数学成绩\n");
                printf("请输入你想修改的那一项序号:\n");
                scanf("%d",&c);
                if(c>3||c<1)
                    printf("\n 选择错误，请重新选择!\n");
                do
                {
                    switch(c)
                    {
                    case 1:
                        printf("学号改为: ");
                        scanf("%s",no);
                        strcpy(st[i].no,no);
                        break;
                    case 2:
                        printf("姓名改为: ");
                        scanf("%s",name);
                        strcpy(st[i].name,name);
                        break;
                    case 3:
                        printf("数学成绩改为: ");
                        scanf("%s",math);
                        strcpy(st[i].math,math);
                        break;
                    }
                    printf("\n");
                    printf("\n 是否确定所修改的信息?\n 是 请按 1 ; 不,重新修改 请按 2: \n");
                    scanf("%d",&b);
                }
                while(b==2);
            }
            else break;
        }
    }
    printf("\n 浏览修改后的所有学生信息:\n");
    printf("\n");
    save(m);
    display();
    printf("\n 继续修改请按 1，不再修改请按 0\n");
    scanf("%d",&t);
    switch(t)
    {
    case 1:
        modify();
        break;
    case 0:
        break;
    default :
        break;
    }
}
