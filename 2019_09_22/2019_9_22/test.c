
//有一个字符数组的内容为:"student a am i",
//	请你将数组的内容改为"i am a student".
//	要求：
//	不能使用库函数。
//	只能开辟有限个空间（空间个数和字符串的长度无关）。

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>            
//逆置每一个单词
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

//求字符串长度的函数
int my_strlen(char *str)   
{
	int count = 0;
	while (*str++)
	{
		count++;
	}
	return count;
}

//逆置整个字符串
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
//编程实现：
//一组数据中只有一个数字出现了一次。
//其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
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
		ret ^= arr[i];/*若两个数相同，按位异或则为0，即可排除成对的数，留下只出现一次的数*/
	}
	printf("%d\n", ret);
	system("pause");
	return 0;
}




//不使用（a + b） / 2这种方式，求两个数的平均值。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int avg = 0;
	printf("请输入a和b的值：");
	scanf("%d%d",&a,&b);
	avg = (a + b) >> 1;
	printf("(%d+%d)/2=%d",a,b,avg);
}



//编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值是value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832



#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//方法一
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

//方法二
unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
	int result = 0;
	while (i < 32)
	{
		if ((value >> i) & 1)//从最低位开始检测是否为1
		{
			result |= 1 << (31 - i);//低位为1的话  把对应的高位改为1
		}
		i++;
	}
	return result;
}


int main() 
{
	int num = 0;
	int result;
	printf("请输入一个数:");
	scanf("%d", &num);
	result=reverse_bit(num);
	printf("翻转后：%d", result);
	return 0;
}





//在屏幕上打印杨辉三角。
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

//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个。
//嫌疑犯的一个。以下为4个嫌疑犯的供词。
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。


#include<stdio.h>
#include<stdlib.h>
int main()
{
	int murderer = 0;
	for (murderer = 'A'; murderer <= 'D'; murderer++)
	{
		if ((murderer!='A')+(murderer=='C')+(murderer=='D')+(murderer!='D')==3)
		{
			printf("凶手是%c\n", murderer);
		}
	}
		
	return 0;
}



//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
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
							)//判断a b c d e各不相同
						{
							printf("a是：%d\nb是：%d\nc是：%d\nd是：%d\ne是：%d\n", a, b, c, d, e);
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