#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
#if 0
//求字符串长度 strlen();
//size_t strlen ( const char * str );
//字符串已经 '\0' 作为结束标志;
//strlen函数返回的是在字符串中 '\0' 前面出现的字符个数（不包含 '\0' );
//参数指向的字符串必须要以  '\0' 结束;
//注意函数的返回值为size_t，是无符号的（ 易错 ）; 
//学会strlen函数的模拟实现;

//strlen函数的模拟实现;
//第一种：计数方式
int my_strlen(const char * str)
{
	assert(str);
	int count = 0;
	while (*str)
	{
		++count;
		++str;
	}
	return count;
}
//第二种：递归
int my_strlen(const char * str)
{
	assert(str);
	if (*str == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + strlen(str + 1);
	}
	
}
//第三种：指针相减
int my_strlen(const char * str)
{
	assert(str);
	const char*end = str;
	while (*end)
	{
		++end;
	}
	return end-str;
}
int main()
{
	char* p = "hello world";
	printf("%d",my_strlen(p));
	return 0;
}
#endif

#if 0
//字符串复制 strcpy（）
//源字符串必须以 '\0' 结束。
//会将源字符串中的 '\0' 拷贝到目标空间
//目标空间必须足够大，以确保能存放源字符串 
//目标空间必须可变
//学会模拟实现

//strcpy函数的模拟实现

char* my_strcpy(char * dst, const char * src)
{
	assert(dst);
	assert(src);
	char *ret = dst;
	do
	{
		*dst = *src;
		++src;
		++dst;
	} while (*src);
	return ret;
}
char* my_strcpy(char * dst, const char * src)
{
	assert(dst);
	assert(src);
	char *ret= dst;
	while (*dst++ = *src++);
	//while (*dst=*src);
	//{
	//	src++;
	//	dst++;
	//}
	return ret;
}
int main()
{
	char*p1 = "hello";
	char p2[10];
	my_strcpy(p2,p1);
	printf("%s\n",p2);
	return 0;
}
#endif

#if 0

//字符串拼接 strcat()
//源字符串必须以 '\0' 结束
//目标空间必须有足够的大，能容纳下源字符串的内容
//目标空间必须可修改

//strcat函数的模拟实现
char * my_strcat(char * dst, const char * src)
{
	assert(dst);
	assert(src);
	char *ret = dst;
	while (*dst)
	{
		++dst;
	}
	while (*dst++ = *src++);
	return ret;
}
int main()
{
	char* p1 = "hello";
	char* p2 = "world";
	my_strcat(p1, p2);
	printf("%s\n", p1);
	return 0;
}
#endif

//#if 0
//字符串比较时strcmp()
int my_strcmp(const char * str1, const char * str2)
{
	assert(str1&&str2);
	while (*str1&&str2)
	{
		if (*str1 > str2)
		{
			return 1;
		}
		else if (*str1 < str2)
		{
			return -1;
		}
		else
		{
			str1++; 
			str2++;
		}
	}
	if (*str1=='\0'&&*str2== '\0')
	{
		return 0;
	}
	else if (*str1 == '\0')
	{
		return -1;
	}
	else if (*str2 == '\0')
	{
		return 1;
	}
	
}
int main()
{
	char* p1 = "hello";
	char* p2 = "world";
	printf("%d\n", my_strcmp(p1, p2));
	return 0;
}
//#endif

#if 0
//strstr函数的模拟实现
char * my_strstr(const char * str1, const char * str2)
{
	assert(str1&&str2);
	char * src = (char*)str1;
	char * sub = (char*)str2;
	char * p = NULL;
	if (*str2 == '\0')
	{
		return NULL;
	}
	while (*src)
	{
		p = src;
		sub = str2;
		while (*p&&*sub && (*src == *sub))
		{
			p++;
			sub++;
		}
		if (*sub == '\0')
		{
			return p;
		}
		else
		{
			src = ++p;
			sub = str2;
		}
	}
}
int main()
{
	char str1[] = "hello world";
	char str2[] = "world";
	printf("%c\n", my_strstr(str1, str2));
	return 0;
}
#endif

#if 0
//memcpy函数的模拟实现
void * my_memcpy(void * dst, const void * src, size_t count)
{
	assert(dst&&src);
	while (count--)
	{
		*(char *)dst = *(char *)src;
		dst = (char *)dst + 1;
		src = (char *)src + 1;
	}
	return dst;
}
struct
{
	char name[20];
	int age;
}person, person_copy;
int main()
{
	char myname[] = "abcdefgh";
	//using memcpy to copy string
	my_memcpy(person.name, myname, strlen(myname) + 1);
	person.age = 46;

	//using memcpy to copy structure
	my_memcpy(&person_copy, &person, sizeof(person));
	printf("person_copy:%s,%d", person_copy.name, person_copy.age);
	return 0;
}
#endif

#if 0
//memmove函数的模拟实现
void * my_memmove(void * dst, const void * src, size_t count)
{
	assert(dst&&src);
	if (dst < src || (char *)dst >= ((char *)src + count))
	{
		while (count--)
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst + 1;
			src = (char *)src + 1;
		}
	}
	else
	{
		dst = (char *)dst + count - 1;
		src = (char *)src + count - 1;
		while (count--)
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst - 1;
			src = (char *)src - 1;
		}
	}
}
int main()
{
	char str[] = "memmove an be very usefull";
	my_memmove(str + 20, str + 15, 11);
	printf("%s\n", str);
	return 0;
}
#endif
