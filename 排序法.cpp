√∞≈›∑®≈≈–Ú:
#include<stdio.h>
int main()
{
	int i,a[10]={34,56,4,10,77,51,93,30,5,52},b,j;
	for(i=1;i<10;i++)
      for(j=0;j<10-i;j++)
	     if(a[j]>a[j+1])
		 {
			 b=a[j];
			 a[j]=a[j+1];
			 a[j+1]=b;
		 }
	for(i=0;i<10;i++)
	 printf("%d ",a[i]);
	return 0;
}

—°‘Ò≈≈–Ú∑®:
#include<stdio.h>
int main()
{
	int i,a[10]={34,56,4,5,77,51,93,30,5,52},b,s,j;
	for(i=0;i<9;i++)
	{	s=i;
	 for(j=i+1;j<10;j++)
	 	if(a[j]<a[s])
			s=j;
		b=a[i];
		a[i]=a[s];
		a[s]=b;
	}
	for(i=0;i<10;i++)
	 printf("%d ",a[i]);
	return 0;
}

≤Â»Î≈≈–Ú∑®:
#include<stdio.h>
int main()
{
	int i,a[10]={34,56,4,10,77,51,93,30,5,52},b,s;
	for(i=1;i<10;i++)
    {	s=i;
	    b=a[i];
	 	while(s>0&&b<a[s-1])
		{	a[s]=a[s-1];
		    s--;
		}
		a[s]=b;
	}
	for(i=0;i<10;i++)
	 printf("%d ",a[i]);
	return 0;
}
	