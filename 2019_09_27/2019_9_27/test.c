#if 0
//1.��������ʹ����ȫ����λ��ż��ǰ�档
//��Ŀ��
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void AdjustmentArray(int *arr, int arr_length);
int main()
{
	int arr[10];
	int i = 0;
	int arr_length=0;
	printf("����������Ԫ�أ�\n");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	arr_length = sizeof(arr)/sizeof(arr[0]);
	printf("����ǰ��");
	for (i = 0; i < 10; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
	AdjustmentArray(arr, arr_length);
	printf("������");
	for (i = 0; i < 10; i++)
	{
		printf("%d", arr[i]);
	}
	return 0;
}
void AdjustmentArray(int *arr, int arr_length)
{
	int *p;
	p = arr + arr_length;
	int temp;
	while (arr < p)
	{
		if (((*arr) & 1) == 1)
		{
			arr++;
			continue;
		}
		if (((*p) & 1) == 0)
		{
			p--;
			continue;
		}
		temp = *arr;
		*arr = *p;
		*p = temp;
		arr++;
		p--;
	}
}


//���Ͼ���
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int find(int arr[3][3], int *px, int * py, int key)
{
	int ret = 0;
    // i,jΪ���Ͻ�����
	int i =0;
	int j = *py - 1;
	while (i < *px && j >= 0)
	{
		if (key == arr[i][j])
		{
			ret = 1;
			break;
		}
		else if (arr[i][j] > key)
		{
			--j;
		}
		else
		{
			++i;
		}
	}
	return ret;
}
int main()
{
	int result = 0;
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int x = 3;
	int y = 3;
	result= find(arr, &x, &y, 4);
	if (result == 0)
	{
		printf("������!");
	}
	else
	{
		printf("����");
	}

}
#endif