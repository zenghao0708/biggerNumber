#include <stdio.h>
#include <stdlib.h>
/*
题目：
给定一个整数，找出下一个比该整数大且具有相同数字的最小数？
算法：
分三步：
1. 从低位往高位找（计低位的下标为0)，直到a[i]<a[i-1];
2. 从a[i-1]到a[0]中找出比a[i]大的而又是最小的那个数记为a[m]，且作为a[i]位；
3. 然后由a[i]和a[i-1]到a[0]组合一个最小的数(这一步很简单)；
如例子中34722641，发现第4位的2小于它后面的6,则从它后面的那几个数选出比它
要大的最小的那个数，即为4,是高几位已经确定：34724，余下的数字是2(a[i]),6,1，
组合一个最小的数即126，帮最终的结果为：34724126。
*/

int compare_int(const void * e1,const void * e2);

int * revert_num(int value);
int * get_little_big_num(int value);
int get_num_length(int value);

int * revert_num(int value)
{
	int *ptr=NULL,*old;
	int len=get_num_length(value);
	int tmp;
	ptr=(int *)malloc(sizeof(int) * len);
	old=ptr;
	do 
	{
		tmp=value%10;
		*(ptr++)=tmp;
		
	}while(value=value/10);
	return old;
}


int get_num_length(int value)
{
	int len=1;
	while ( (value=value/10) >= 1)
	{
		len++;
	}
	return len;
}

int * get_little_big_num(int value)
{
	int *ptr=revert_num(value);
	int len=get_num_length(value);
	int i=0,j;
	int tone;
	int little_num=9;
	int little_num_pos=0;
	while ( *(ptr+i) < *(ptr+i+1))
	{
		i++;
	}
	tone=*(ptr+i+1);
	
	for (j=0 ;j<=i;j++)
	{
		if ( *(ptr+j) > tone)
		{
			if (little_num > *(ptr+j) )
			{
				little_num=*(ptr+j);
				little_num_pos=j;
			}
		}
	}
	*(ptr+i+1)=little_num;
	*(ptr+little_num_pos)=tone;
	
	qsort(ptr,i+1,sizeof(int),compare_int);
	
	return ptr;
}

int compare_int(const void * e1,const void * e2)
{
	return *(int *)e1 < *(int *)e2;
}

int main(int argc,char argv[])
{
	int v;
	int * ptr=NULL;
	int len=0;
	int ret_value=0;

	printf("Please input a num:");
	scanf("%d",&v);
	ptr=get_little_big_num(v);
	
	len=get_num_length(v);
	
	while (len >0)
	{
		ret_value =*(ptr+(--len))+ ret_value*10;
	}
	printf("the value is:%d\n",ret_value);//34722641
	free(ptr);
	ptr =NULL;
	return 0;
}