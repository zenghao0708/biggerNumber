#include <stdio.h>
#include <stdlib.h>
/*
��Ŀ��
����һ���������ҳ���һ���ȸ��������Ҿ�����ͬ���ֵ���С����
�㷨��
��������
1. �ӵ�λ����λ�ң��Ƶ�λ���±�Ϊ0)��ֱ��a[i]<a[i-1];
2. ��a[i-1]��a[0]���ҳ���a[i]��Ķ�������С���Ǹ�����Ϊa[m]������Ϊa[i]λ��
3. Ȼ����a[i]��a[i-1]��a[0]���һ����С����(��һ���ܼ�)��
��������34722641�����ֵ�4λ��2С���������6,�����������Ǽ�����ѡ������
Ҫ�����С���Ǹ�������Ϊ4,�Ǹ߼�λ�Ѿ�ȷ����34724�����µ�������2(a[i]),6,1��
���һ����С������126�������յĽ��Ϊ��34724126��
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