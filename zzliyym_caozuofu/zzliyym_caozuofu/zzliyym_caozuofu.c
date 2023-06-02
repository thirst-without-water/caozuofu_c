#include <stdio.h>
A.主要内容：各种操作符的介绍、表达式求值
**各种操作符的介绍：算术操作符、移位操作符、位操作符、赋值操作符、单目操作符、关系操作符、逻辑操作符、条件操作符、逗号表达式、下标引用、函数调用和结构成员访问
一.算术操作符（包括“+ - * / %”）
1.除了%操作符之外，其他的几个操作符可以作用于整数和浮点数。
2.对于 / 操作符如果两个操作数都为整数，执行整数除法。而只要有浮点数执行的就是浮点数除法。
int main()
{
	int a = 6 / 5;
	printf("%d\n", a);                            /*结果为“1”*/

	float a = 6 / 5;
	printf("%f\n", a);                            /*结果为“1.000000”*/

	float a = 6 / 5.0;
	printf("%f\n", a);                            /*结果为“1.200000”*/
	return 0;
}
3.%操作符的两个操作数必须为整数。返回的是整除之后的余数。
int main()
{
	int a = 7 % 3;
	printf("%d\n", a);                              /*结果为“1”*/

  int a = 7 % 3.0;                              /*error,"%"非法*/
	printf("%d\n", a);                              
	return 0;
} 
二.移位操作符（包括“<< >>”）
1.左移操作符移位规则：左边抛弃、右边补O
int main()
{
  int a = 2;
  int b = 2 << 1;                               /*把a的二进制位向左移动一位*/
  printf("b = %d\n", b);                        /*结果为“4”*/
  return 0;
} 
2.右移操作符移位规则︰1.逻辑移位左边用0填充，右边丢弃；2.算术移位左边用原该值的符号位填充，右边丢弃
int main()
{
	int a = -1;
	int b = -1 >> 1;                              /*把a的二进制位向右移动一位*/
	printf("b = %d\n", b);                        /*结果为“-1”（当前的右移操作符使用的是算术右移）*/
	return 0;
} 
警告:对于移位运算符，不要移动负数位，这个是标准未定义的。（num>>-1/error) 
三.位操作符（包括“& | ^”）
1.& - 按位（二进制位）与
int main()
{
	int a = 3;                                    /*00000000000000000000000000000011*/
	int b = 5;                                    /*00000000000000000000000000000101*/
	int c = a & b;                                /*00000000000000000000000000000001*/
	printf("c = %d\n", c);                        /*结果为“1”*/
	return 0;
}
2.| - 按位（二进制位）或 
int main()
{
	int a = 3;                                    /*00000000000000000000000000000011*/
	int b = 5;                                    /*00000000000000000000000000000101*/
	int c = a | b;                                /*00000000000000000000000000000111*/
	printf("c = %d\n", c);                        /*结果为“7”*/
	return 0;
} 
3.^ - 按位（二进制位）异或（规则：相同为0，相异为1）
int main()
{
	int a = 3;                                    /*00000000000000000000000000000011*/
	int b = 5;                                    /*00000000000000000000000000000101*/
	int c = a ^ b;                                /*00000000000000000000000000000110*/
	printf("c = %d\n", c);                        /*结果为“6”*/
	return 0;
} 
题目：交换两个int的值，不能使用第三个变量，即a=3,b=5,交换之后a=5,b=3
int main()
{
	int a = 3;
	int b = 5;
	printf("a=%d b=%d\n", a, b);
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a=%d,b=%d\n", a, b);
	return 0;
} 
四.赋值操作符（包括“= += -= *= /= %= <<= >>= &= |= ^=”）
int main()
{
	int a = 10;

	a = a + 100;
	a += 100;

	a = a >> 3;
	a >>= 3;

	return 0;
}
五.单目操作符（包括“! - + & sizeof ~ -- ++ * (类型)”）
1.“!” - 逻辑反操作
int main()
{
	int flag = 5;
	printf("%d\n", !flag);                        /*结果为“0”*/
	return 0;
} 
2.“sizeof” - 操作数的类型长度（以字节为单位）（是一个操作符，不是函数）（sizeof括号中放的表达式是不参与运算的）
这个操作符计算返回的结果是size_t类型的，是无符号整型的
int main()
{
	int a = 10;
	printf("%d\n", sizeof(a));                    /*计算a所占空间的大小*/
	printf("%d\n", sizeof a);                     /*是一个操作符，不是函数*/
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof int);                   /*error*/

	int arr[10] = { 0 };
	printf("%d\n", sizeof(arr));                  /*计算arr数组所占空间的大小*/
	printf("%d\n", sizeof(int [10]));             /*int [10]是arr数组的类型*/

	short s = 5;
	int a = 10;
	printf("%d\n", sizeof(s = a + 2));            /*结果是“2”*/
	printf("%d\n", s);                            /*结果是“5”sizeof括号中放的表达式是不参与运算的*/
	return 0;
} 
3.“~” - 对一个数的二进制位按位取反
int main()
{
  int a = -1;                                   /*补码 - 11111111111111111111111111111111*/
	int b = ~a;                                   /*补码 - 00000000000000000000000000000000*/
	printf("%d\n", b);                            /*结果是“0”*/
	return 0;
}
4.“--”
int main()
{
int a = 10;
int b = a--;                                    /*后置--：先使用(a)，后--*/
printf("%d\n", a);                              /*结果是“9”*/
printf("%d\n", b);                              /*结果是“10”*/
return 0;

int b = --a;                                    /*前置--：先--(a)，后使用*/
printf("%d\n", a);                              /*结果是“9”*/
printf("%d\n", b);                              /*结果是“9”*/
return 0;
} 
5.“++”
int main()
{
	int a = 10;
	//int b = a++;                                /*后置++：先使用(a)，后++*/
	//printf("%d\n", a);                          /*结果是“11”*/
	//printf("%d\n", b);                          /*结果是“10”*/
	//return 0;

	int b = ++a;                                  /*前置++：先++(a)，后使用*/
	printf("%d\n", a);                            /*结果是“11”*/
	printf("%d\n", b);                            /*结果是“11”*/
	return 0;
} 
6.“&” - 取地址   “*” - 间接访问操作符（解引用操作符）
int main()
{
	int a = 10;
	printf("%p\n", &a);                           /*“&”- 取地址操作符*/
	int* pa = &a;                                 /*pa是用来存放地址的 - pa就是一个指针变量*/
	*pa = 20;                                     /*“*” - 解引用操作符 - 间接访问操作符*/
	printf("%d\n", a);
	return 0;
}
7.“(类型)” - 强制类型转换
int main()
{
	int a = (int)3.14;
	return 0;
} 
六.关系操作符（包括“> < >= <= != =”)
七.逻辑操作符（包括“&& ||”）
1.“&&” - 逻辑与（有一个为假就为假，左边如果为假，右边不计算）
int main()
{
	int a = 3;
	int b = 0;
	if (a && b)
	{
		printf("hehe\n");                         /*不打印*/
	}
	return 0;
}
2.“||” - 逻辑或（有一个为真就为真，左边如果为真，右边不计算）
int main()
{
	int a = 3;
	int b = 0;
	if (a || b)
	{
		printf("hehe\n");                         /*打印*/
	}
	return 0;
} 
题目1：
int main()
{
	int i = 0, a = 0, b = 2, c = 3, d = 4;
	i = a++ && ++b && d++;
	printf("a = %d\n b = %d\n c = %d\n d = %d\n", a, b, c, d);/*1 2 3 4*/
	return 0;
}
题目2：
int main()
{
	int i = 0, a = 0, b = 2, c = 3, d = 4;
	i = a++ || ++b || d++;
	printf("a = %d\n b = %d\n c = %d\n d = %d\n", a, b, c, d);/*1 3 3 4*/
	return 0;
} 
八.条件操作符/三目操作符（包括“ ？ ： ”）
int main()
{
	int a = 3;
	int b = 0;
	if (a > 5)
	{
		b = 1;
	}
	else
	{
		b = -1;
	}


	b = (a > 5 ? 1: -1);
	return 0;
} 
九.逗号表达式 - 要从左向右依次计算，但是整个表达式的结果是最后一个表达式的结果
int main()
{
	int a = 3;
	int b = 5;
	int c = 0;
	int d = (c = 5, a = c + 3, b = a - 4,c += 5);
	        /*c=5   a = 8      b=4       c=10*/
	printf("%d\n",d);                             /*10*/
	return 0;
} 
十.下标引用、函数调用和结构成员
1.[] - 下标引用操作符 - 操作数：一个数组名+一个索引值
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	/*              0 1 2 3 4 5 6 7 8 9                */
	printf("%d\n", arr[4]);                       /*[] - 就是下标引用操作符 - 操作数为“arr、4”*/
	return 0;
} 
2.（） - 函数调用操作符
int Add(int x, int y)
{
	return x + y;
}
int main()
{
	int a = 10;
	int b = 20;
	int ret = Add(a, b);                          /*（）- 函数调用操作符*/
	return 0;
}
3.结构成员访问操作符（包括“. ->”）
i）“.”
struct Book
{
	char name[20];
	char id[20];
	int price;
};                                                /*创建了一个自定义类型*/
int main()
{
	struct Book b = {"C语言","C20020925",55};
	printf("书名：%s\n", b.name);
	printf("书号：%s\n", b.id);
	printf("定价：%d\n", b.price);
	return 0;
} 
ii)“->”
struct Book
{
	char name[20];
	char id[20];
	int price;
};                                                /*创建了一个自定义类型*/
int main()
{
	struct Book b = { "C语言","C2022925",55 };
	struct Book* pb = &b;
	printf("书名：%s\n", pb->name);
	printf("书号：%s\n", pb->id);
	printf("定价：%d\n", pb->price);
	return 0;
} 
**表达式求值:表达式求值的顺序一部分是由操作符的优先级和结合性决定。同样，有些表达式的操作数在求值的过程中可能需要转换为其他类型。
一.隐式类型转换：C的整型算术运算总是至少以缺省整型类型的精度来进行的。为了获得这个精度，表达式中的字符和短整型操作数在使用之前被转换为普通整型，这种转换称为整型提升。
1.整型提升
i)意义：表达式的整型运算要在CPU的相应运算器件内执行，CPU内整型运算器(ALU)的操作数的字节长度一般就是int的字节长度，同时也是CPU的通用寄存器的长度。
因此，即使两个char类型的相加，在CPU执行时实际上也要先转换为CPU内整型操作数的标准长度。
通用CPU(general - purpose CPU)是难以直接实现两个8比特字节直接相加运算（虽然机器指令中可能有这种字节相加指令)。所以，表达式中各种长度可能小于int长度的整型值，都必须先转换为int或unsigned int，然后才能送入CPU去执行运算。
ii)如何进行整体提升呢:整形提升是按照变量的数据类型的符号位来提升的
int main()
{
	char a = 3;                 
	/*00000000000000000000000000000011*/
	/*00000011 - a*/
	char b = 127;                  
	/*00000000000000000000000001111111*/
	/*01111111 - b*/
	char c = a + b;	                      /*发现a和b都是char类型的，都没有达到一个int的大小。这里就会发生整型提升*/
	/*00000000000000000000000000000011+00000000000000000000000001111111=00000000000000000000000010000010*/
  /*10000010 - c*/
	printf("%d\n", c);             
	/*11111111111111111111111110000010 - 补码*/
  /*11111111111111111111111110000001 - 反码*/
  /*10000000000000000000000001111110 - 原码*/
	return 0;
} 
2.算术转换：如果某个操作符的各个操作数属于不同的类型，那么除非其中一个操作数的转换为另一个操作数的类型，否则操作就无法进行。下面的层次体系称为寻常算术转换。
转换规则：如果某个操作数的类型在上面这个列表中排名较低，那么首先要转换为另外一个操作数的类型后执行运算。
警告:但是算术转换要合理，要不然会有一些潜在的问题。 
二.操作符的属性
 复杂表达式的求值有三个影响的因素。
1.操作符的优先级
2.操作符的结合性
3.是否控制求值顺序。
两个相邻的操作符先执行哪个 ? 取决于他们的优先级。如果两者的优先级相同，取决于他们的结合性。操作符优先级
//
//
B.练习
1.统计二进制中1的个数
  写一个函数返回参数二进制中1的个数。
  比如: 15    00001111    4个1
a.
int count_num_of_1(unsigned int n)
{
	int count = 0;
	while (n)
	{
		if ((n % 2) == 1)
		{
			count++;
		}
		n /= 2;
	}
	return count;
}
b.
int count_num_of_1(int n)
{
	int i = 0;
	for(i=0;i<32;i++)
	{
		if((n>>1)&1==1)
		{
			count++
		}
	}
	return count++;
}
c.
int count_num_of_1(int n)
{
	int count = 0;
	while(n)
	{
		n=n&(n-1);
		count++;
	}
	return count;
}
int main()
{
	int num  = 0;
	scanf("%d",&num);
	int n = count_num_of_1(num);
	printf("%d\n" , n);
	return 0;
}
2.求两个数二进制中不同位的个数
  编程实现:两个int(32位)整数m和n的二进制表达中，有多少个位(bit)不同?
  输入例子:1999 2299
  输出例子:.7
a.
int count_diff_bit(int m,int n)
{
	int i = 0;
	int count = 0;
	for(i = 0;i < 32;i++)
	{
		if(((m>>i)&1) != ((n>>i)&1))
		{
			count++
		}
	}
	return count;
}
int main()
{
	  int m = 0;
	  int n = 0;
	  scanf("%d %d",&m,&n);
	  int ret = count_diff_bit(m,n);
	  printf("%d\n",ret);
	  return 0;
}
b.
int count_diff_bit(int m,int n)
{
	int count = 0;
	int ret = m^n;
	while(ret)
	{
		ret = ret&(ret-1);
		count++;
	}
	return count;
}
int main()
{
	  int m = 0;
	  int n = 0;
	  scanf("%d %d",&m,&n);
	  int ret = count_diff_bit(m,n);
	  printf("%d\n",ret);
	  return 0;
}
3.打印整数二进制的合数位和偶数位
  获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
int main()
{
	int i = 0;
	int num = 0;
	scanf("%d",&num);
	for(i=30;i>=0;i-=2)
	{
		printf("%d ",(num>>i)&1);
	}
	printf("\n");
	for(i=31;i>=1;i-=2)
	{
		printf("%d ",(num>>i)&1);
	}
	return 0;
}
4.描述：
  KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“*”组成的X形图案。
  输入描述:
  多组输入，一个整数(2~20)，表示输出的行数，也表示组成×""的反斜线和正斜线的长度。
  输出描述:
  针对每行输入，输出用“*”组成的X形图案。
int main()
{
	  int n = 0;
	  while(scanf("%d",&n)==1)
	  {
		  int i = 0;
		  int j = 0;
		  for(i=0;i<n;i++)
		  {
			  for(j=0;j<n;j++)
			  {
				  if(i=j)
					  printf("*");
				  else if(i+j == n-1)
					  printf("*");
				  else
					  printf(" ");
			  }
			  printf("\n");
		  }
	  }
	  return 0;
}
5.描述:
  KiKi想获得某年某月有多少天，请帮他编程实现。输入年份和月份，计算这一年这个月有多少天。
  输入描述:
  多组输入，一行有两个整数，分别表示年份和月份，用空格分隔。
  输出描述:
  针对每组输入，输出为一行，一个整数，表示这一年这个月有多少天。
int main()
{
	  int y = 0;
	  int m = 0;
	  int d =0;
	  while(scanf(""""""))
	  return 0;
}
