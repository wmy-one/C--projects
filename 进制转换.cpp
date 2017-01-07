//十进制转换为二进制：
#include<stdio.h>
void f(int a)
{
	int b[100]={0},i=0;
	if(a==0)
		b[i]=a;
	while(a>0)
	{
		 b[i]=a%2;
		 a=a/2;
		 i++;
		 if(a==0)
		 {	b[i+1]=a;
		    break;
		 }
	}
	for(i=i;i>=0;i--)
		printf("%d",b[i]);
}
int main()
{
	int m;
	printf("请输入十进制数:");
	scanf("%d",&m);
	f(m);
	printf("\n");
	return 0;
}

//n进制转换为m进制代码：
#include<stdio.h>
void f(int a)
{
	int b[100]={0},i=0;
	if(a==0)
		b[i]=a;
	while(a>0)
	{
		 b[i]=a%2;
		 a=a/2;
		 i++;
		 if(a==0)
		 {	b[i+1]=a;
		    break;
		 }
	}
	for(i=i;i>=0;i--)
		printf("%d",b[i]);
}

int d(int a,int y)
{
	int b=1,i;
   for(i=1;i<=y;i++)
	   b*=a;
  return b;
}

void p(int b,int n)
{ 
   int a[100],i,c=0;
   for(i=0;i>=0;i++)
   {a[i]=b%10;
    c+=a[i]*d(n,i);
    b=b/10;
    if(b/10==0)
	{ a[i]=b%10;
      c+=a[i]*d(n,i+1);
		f(c);
		break;
	}
   }
}

int main()
{
	int m,n;
	printf("请输入n进制数m和该进制n:");
	scanf("%d%d",&m,&n);
	p(m,n);
	printf("\n");
	return 0;
}

