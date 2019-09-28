#if 0
//1.调整数组使奇数全部都位于偶数前面。
//题目：
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void AdjustmentArray(int *arr, int arr_length);
int main()
{
	int arr[10];
	int i = 0;
	int arr_length=0;
	printf("请输入数组元素：\n");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	arr_length = sizeof(arr)/sizeof(arr[0]);
	printf("调整前：");
	for (i = 0; i < 10; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
	AdjustmentArray(arr, arr_length);
	printf("调整后：");
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


//杨氏矩阵
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int find(int arr[3][3], int *px, int * py, int key)
{
	int ret = 0;
    // i,j为右上角坐标
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
		printf("不存在!");
	}
	else
	{
		printf("存在");
	}

}
#endif