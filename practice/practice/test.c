


//���ʵ�֣�
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//�������� :
//1999 2299
//������� : 7
//
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int DifferentBit(int num1,int num2)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; i++)
	{
		if (((num1 >> i) & 1) != ((num2 >> i) & 1))
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int num1, num2;
	int total;
	printf("��������������");
	scanf("%d%d", &num1,&num2);
	total = DifferentBit(num1, num2);
	printf("�����Ʊ���й���%dλ��ͬ.",total);
	return 0;
}




#if 0
//���һ��������ÿһλ
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void Print(int num)
{
		if (num /10 > 0)
		{
			Print(num / 10);
		}
		printf("%d  ", num % 10);
}
int main()
{
	int num = 0;
	int	i = 0;
	printf("������һ����������");
	scanf("%d", &num);
	Print(num);
	return 0;
}





//.��ȡһ�������������������е�ż��λ������λ��
//�ֱ�������������С�
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int num = 0;
	int	i = 0;
	printf("������һ����������");
	scanf("%d", &num);
	printf("��������Ϊ��");
	for (i = 31; i >= 0; i -= 2)  
	{
		printf("%d ", (num >> i) & 1);    
	}
	printf("\n");
	printf("ż������Ϊ��");
	for (i = 30; i >= 0; i -= 2)   
	{
		printf("%d ", (num >> i) & 1);  
	}
	printf("\n");
	return 0;
}





//дһ���������ز����������� 1 �ĸ���
//���磺 15 0000 1111 4 �� 1
//����ԭ�ͣ�
//int count_one_bits(unsigned int value)
//{
//	// ���� 1��λ��
//}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
//��һ��
int count_one_bits_1(unsigned int value)
{
	int count = 0;
	while (value != 0)
	{
		count++;
		value = value & (value - 1);
	}
	return count;
}
//�ڶ���
int count_one_bits_2(unsigned int value)
{
	int count = 0;
	while (value != 0)
	{
		if ((value % 2) == 1)
		{
			count++;
		}
		value /= 2;;
	}
	return count;
}
//������
int count_one_bits_3(unsigned int value)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; i++)
	{
		if (((value >> i) & 1) == 1)
		{
			count++;
		}
	}
	return count;
}
int main()
{
	unsigned int num = 0;
	int count_1 = 0;
	int count_2 = 0;
	int count_3 = 0;
	printf("������һ����������");
	scanf("%d", &num);
	count_1 = count_one_bits_1(num);
	count_2 = count_one_bits_2(num);
	count_3 = count_one_bits_3(num);
	printf("������������ 1 �ĸ���Ϊ��%d\n", count_1);
	printf("������������ 1 �ĸ���Ϊ��%d\n", count_2);
	printf("������������ 1 �ĸ���Ϊ��%d", count_3);
	return 0;
}


void Print(int n)
{
	if (n / 10 != 0)
	{
		Print(n / 10);
	}
	printf("%d\n", n % 10);
}
int main()
{
	int n;
	scanf("%d", &n);
	Print(n);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int fun(int n)
{
	if (n == 1 || n == 0)
	{
		return 1;
	}
	return n * fun(n - 1);
}
int fun2(int n)
{
	int num = 1;
	for (int i = 1; i <= n; i++)
	{
		num *= i;
	}
	return num;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", fun(n));
	printf("%d", fun2(n));
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Strlen(char *str)
{
	if (*str == '\0')
	{
		return 0;
	}
	return  1 + Strlen(++str);
}
int Strlen2(char *str)
{
	int account = 0;
	while (*str != '\0')
	{
		account++;
		str++;
	}
	return account;
}
int main()
{
	char arr[] = "helloWorld";
	int num1 = Strlen(arr);
	int num2 = Strlen2(arr);
	printf("%d", num1);
	printf("%d", num2);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void reverse_string(char * string)
{
	if (*string == '\0')
		printf("%c", *string);
	else
	{
		reverse_string(++string);
		printf("%c", *(--string));
	}
}
int main()
{
	char arr[] = "HelloWorld";

	reverse_string(arr);
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int DigitSum(n)
{
	while (n / 10 != 0)
	{
		return n % 10 + DigitSum(n / 10);
	}
	return n;
}
int main()
{
	int num;
	int sum;
	printf("������num:");
	scanf("%d", &num);
	sum = DigitSum(num);
	printf("sum=%d\n", sum);
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int product(int n, int k)
{
	while (k > 1) {
		return n * product(n, k - 1);
	}
	return n;
}
int main()
{
	int k;
	int n;
	int num;
	printf("������n,k:");
	scanf("%d%d", &n, &k);
	num = product(n, k);
	printf("%d\n", num);
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//�ݹ�
int fibonacci(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}
//�ǵݹ�
int fabonacci2(int n)
{
	int n1 = 1;
	int n2 = 1;
	int n3 = 1;
	while (n > 2)
	{
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
		n--;
	}
	return n3;
}
int main()
{
	int n;
	int num1;
	int num2;
	printf("������n:");
	scanf("%d", &n);
	num1 = fibonacci(n);
	num2 = fabonacci2(n);
	printf("%d\n", num1);
	printf("%d\n", num2);
	system("pause");
	return 0;
}
#endif