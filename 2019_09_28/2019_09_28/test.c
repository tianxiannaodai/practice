#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 

#include <stdio.h>
int add(int a, int b)
{
return a + b;
}
int sub(int a, int b)
{
return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int div(int a, int b)
{
	return a / b;
}
int main()
{
	int x, y;
	int input = 1; int ret = 0;
	int(*p[5])(int x, int y) = { 0, add, sub, mul, div }; //ת�Ʊ�
	while (input)
	{
		printf("*************************\n");
		printf("	1:add	2:sub	\n");
		printf("	3:mul	4:div	\n");
		printf("*************************\n");
		printf("��ѡ��");
		scanf("%d", &input);
		if ((input <= 4 && input >= 1))
		{
			printf("�����������"); 
			scanf("%d %d", &x, &y);
			ret = (*p[input])(x, y);
			printf("ret = %d\n", ret);
		}
		else
			printf("��������\n"); 
	}
	return 0;
}
#if 0
int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	return x / y;
}
int main()
{
	int x, y;
	int input = 1;
	int ret = 0;
	while (input)
	{
		printf("*************************\n");
		printf("	1:add	2:sub	\n");
		printf("	3:mul	4:div	\n");
		printf("*************************\n");
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("�����������");
			scanf("%d %d", &x, &y);
			ret = add(x, y);
		break; case 2:
			printf("�����������");
			scanf("%d %d", &x, &y);
			ret = sub(x, y);
		break; case 3:
			printf("�����������");
			scanf("%d %d", &x, &y);
			ret = mul(x, y);
		break; case 4:
			printf("�����������");
			scanf("%d %d", &x, &y);
			ret = div(x, y);
		break; default:
			printf("ѡ�����\n");
			break;
		}
		printf("ret = %d\n", ret);
	}
	return 0;
}


void test()
{
	printf("hehe\n");
}
int main()
{
	printf("%p\n", test);
	printf("%p\n", &test);
	return 0;
}


#include <stdio.h>
void print_arr1(int arr[3][4], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
void print_arr2(int(*arr)[4], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			//printf("%d ", arr[i][j]);
			//printf("%d", *((arr[i]+j)));
			printf("%4d", *(*(arr + i) + j));
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	/*printf("%d\n",arr);
	printf("%d\n",arr+1);
	printf("%d\n",arr[1]);
	printf("%d\n",arr[1]+1);
	printf("%d\n", *arr);
	printf("%d\n", *(arr + 1));
	printf("%d\n", *arr[1]);
	printf("%d\n", *(arr[1] + 1));*/
	print_arr2(arr, 3, 4);
	//������arr����ʾ��Ԫ�صĵ�ַ
	//���Ƕ�ά�������Ԫ���Ƕ�ά����ĵ�һ��
	//�������ﴫ�ݵ�arr����ʵ�൱�ڵ�һ�еĵ�ַ����һά����ĵ�ַ
	//��������ָ�������� print_arr2(arr, 3, 4);
	return 0;
}


int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int(*p)[10] = &arr;
	printf("%d", *((*p) + 2));
	system("pause");
	return 0;
}


int main()
{
	//����Ա��������
	char str1[] = "hello bit.";

	char str2[] = "hello bit.";

	char *str3 = "hello bit."; //�����rodata�Σ�ֻ�ܶ��������޸�

	char *str4 = "hello bit.";

	if (str1 == str2)
		printf("str1 and str2 are same\n"); else
		printf("str1 and str2 are not same\n");

	if (str3 == str4)
		printf("str3 and str4 are same\n"); else
		printf("str3 and str4 are not same\n");

	return 0;
	}
#endif