
//��һ���ַ����������Ϊ:"student a am i",
//	���㽫��������ݸ�Ϊ"i am a student".
//	Ҫ��
//	����ʹ�ÿ⺯����
//	ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>            
//����ÿһ������
void my_reverse(char *left, char *right) 
{
	assert(left!=0);      
	assert(right != 0);
	char tmp = NULL;
	while (left < right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

//���ַ������ȵĺ���
int my_strlen(char *str)   
{
	int count = 0;
	while (*str++)
	{
		count++;
	}
	return count;
}

//���������ַ���
void reverse_str(char arr[])    
{
	char *start = arr;
	int len = my_strlen(arr);
	char *end = arr + len- 1;  
	char *curr = NULL;
	if ((arr == NULL) || (arr[0] == '\0'))
	{
		return;            
	}
	my_reverse(start, end);
	while (*arr)              
	{
		curr = arr;
		while ((*arr != '\0') && (*arr != ' ')) 
		{
			arr++;
		}
		end = arr - 1;        
		my_reverse(curr, end);
		if (*arr == ' ')        
		{
			arr++;
		}
	}
}
int main()
{
	char arr[] = "student a am i";
	reverse_str(arr);
	printf("%s\n", arr);
	system("pause");
	return 0;
}




#if 0
//���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ�
//�����������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[] = { 1, 1, 2, 2, 3, 3, 4, 4, 5,5,6 };
	int num = sizeof(arr) / sizeof(arr[0]);
	int i = 1;
	int ret = arr[0];
	for (i = 1; i < num; i++)
	{
		ret ^= arr[i];/*����������ͬ����λ�����Ϊ0�������ų��ɶԵ���������ֻ����һ�ε���*/
	}
	printf("%d\n", ret);
	system("pause");
	return 0;
}




//��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int avg = 0;
	printf("������a��b��ֵ��");
	scanf("%d%d",&a,&b);
	avg = (a + b) >> 1;
	printf("(%d+%d)/2=%d",a,b,avg);
}



//��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵ��value�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832



#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//����һ
unsigned int reverse_bit(unsigned int value)
{
	int last_bit = 0;
	int i = 0;
	int result = 0;
	for (i = 0; i < 32; i++)
	{
		result = result << 1;
		last_bit = value & 1;
		result = result | last_bit;
		value = value >> 1;
	}
	return result;
}

//������
unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
	int result = 0;
	while (i < 32)
	{
		if ((value >> i) & 1)//�����λ��ʼ����Ƿ�Ϊ1
		{
			result |= 1 << (31 - i);//��λΪ1�Ļ�  �Ѷ�Ӧ�ĸ�λ��Ϊ1
		}
		i++;
	}
	return result;
}


int main() 
{
	int num = 0;
	int result;
	printf("������һ����:");
	scanf("%d", &num);
	result=reverse_bit(num);
	printf("��ת��%d", result);
	return 0;
}





//����Ļ�ϴ�ӡ������ǡ�
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main() {

	int a[10][10] = { 0 };
	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < i; j++) 
		{
			if (i == 1)
			{
				printf("%4d\n", a[1][1] = 1);
			}
			else 
			{
				if ((j == 1) || (i == j)) 
				{
					printf("%4d", a[i][j] = 1);
				}
				else 
				{
					printf("%4d", a[i][j] = a[i - 1][j - 1] + a[i - 1][j]);
				}
			}
		}
		printf("\n");

	}

	system("pause");
	return 0;
}

//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4����
//���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ�
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�


#include<stdio.h>
#include<stdlib.h>
int main()
{
	int murderer = 0;
	for (murderer = 'A'; murderer <= 'D'; murderer++)
	{
		if ((murderer!='A')+(murderer=='C')+(murderer=='D')+(murderer!='D')==3)
		{
			printf("������%c\n", murderer);
		}
	}
		
	return 0;
}



//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ��������
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a;
	int b;
	int c;
	int d;
	int e;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if (a*b*c*d*e == 120 &&
							(((b == 2) ^ (a == 3)) &&
							((b == 2) ^ (e == 4)) &&
							((c == 1) ^ (d == 2)) &&
							((c == 5) ^ (d == 3)) &&
							((e == 4) ^ (a == 1)))
							)//�ж�a b c d e������ͬ
						{
							printf("a�ǣ�%d\nb�ǣ�%d\nc�ǣ�%d\nd�ǣ�%d\ne�ǣ�%d\n", a, b, c, d, e);
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}
#endif