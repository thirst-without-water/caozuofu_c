#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//A.��Ҫ���ݣ����ֲ������Ľ��ܡ�����ʽ��ֵ
//**���ֲ������Ľ��ܣ���������������λ��������λ����������ֵ����������Ŀ����������ϵ���������߼������������������������ű���ʽ���±����á��������úͽṹ��Ա����
//һ.������������������+ - * / %����
//1.����%������֮�⣬�����ļ������������������������͸�������
//
// 
//2.���� / ���������������������Ϊ������ִ��������������ֻҪ�и�����ִ�еľ��Ǹ�����������
//int main()
//{
//	int a = 6 / 5;
//	printf("%d\n", a);                            /*���Ϊ��1��*/
//
//	float a = 6 / 5;
//	printf("%f\n", a);                            /*���Ϊ��1.000000��*/
//
//	float a = 6 / 5.0;
//	printf("%f\n", a);                            /*���Ϊ��1.200000��*/
//	return 0;
//}
//
// 
//3.%����������������������Ϊ���������ص�������֮���������
//int main()
//{
//	int a = 7 % 3;
//	printf("%d\n", a);                            /*���Ϊ��1��*/
//
//	int a = 7 % 3.0;                              /*error,"%"�Ƿ�*/
//	printf("%d\n", a);                              
//	return 0;
//}
// 
// 
//��.��λ��������������<< >>����
//1.���Ʋ�������λ��������������ұ߲�O
//int main()
//{
//  int a = 2;
//  int b = 2 << 1;                               /*��a�Ķ�����λ�����ƶ�һλ*/
//  printf("b = %d\n", b);                        /*���Ϊ��4��*/
//  return 0;
//}
//
// 
//2.���Ʋ�������λ����U1.�߼���λ�����0��䣬�ұ߶�����2.������λ�����ԭ��ֵ�ķ���λ��䣬�ұ߶���
//int main()
//{
//	int a = -1;
//	int b = -1 >> 1;                              /*��a�Ķ�����λ�����ƶ�һλ*/
//	printf("b = %d\n", b);                        /*���Ϊ��-1������ǰ�����Ʋ�����ʹ�õ����������ƣ�*/
//	return 0;
//}
// 
// 
//����:������λ���������Ҫ�ƶ�����λ������Ǳ�׼δ����ġ���num>>-1/error)
//
// 
//��.λ��������������& | ^����
//1.& - ��λ��������λ����
//int main()
//{
//	int a = 3;                                    /*00000000000000000000000000000011*/
//	int b = 5;                                    /*00000000000000000000000000000101*/
//	int c = a & b;                                /*00000000000000000000000000000001*/
//	printf("c = %d\n", c);                        /*���Ϊ��1��*/
//	return 0;
//}
// 
// 
//2.| - ��λ��������λ���� 
//int main()
//{
//	int a = 3;                                    /*00000000000000000000000000000011*/
//	int b = 5;                                    /*00000000000000000000000000000101*/
//	int c = a | b;                                /*00000000000000000000000000000111*/
//	printf("c = %d\n", c);                        /*���Ϊ��7��*/
//	return 0;
//}
// 
// 
//3.^ - ��λ��������λ����򣨹�����ͬΪ0������Ϊ1��
//int main()
//{
//	int a = 3;                                    /*00000000000000000000000000000011*/
//	int b = 5;                                    /*00000000000000000000000000000101*/
//	int c = a ^ b;                                /*00000000000000000000000000000110*/
//	printf("c = %d\n", c);                        /*���Ϊ��6��*/
//	return 0;
//}
// 
// 
//��Ŀ����������int��ֵ������ʹ�õ�������������a=3,b=5,����֮��a=5,b=3
//int main()
//{
//	int a = 3;
//	int b = 5;
//	printf("a=%d b=%d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("a=%d,b=%d\n", a, b);
//	return 0;
//}
// 
// 
//��.��ֵ��������������= += -= *= /= %= <<= >>= &= |= ^=����
//int main()
//{
//	int a = 10;
//
//	a = a + 100;
//	a += 100;
//
//	a = a >> 3;
//	a >>= 3;
//
//	return 0;
//}
// 
// 
//��.��Ŀ��������������! - + & sizeof ~ -- ++ * (����)����
//1.��!�� - �߼�������
//int main()
//{
//	int flag = 5;
//	printf("%d\n", !flag);                        /*���Ϊ��0��*/
//	return 0;
//}
//
// 
//2.��sizeof�� - �����������ͳ��ȣ����ֽ�Ϊ��λ������һ�������������Ǻ�������sizeof�����зŵı���ʽ�ǲ���������ģ�
//int main()
//{
//	int a = 10;
//	printf("%d\n", sizeof(a));                    /*����a��ռ�ռ�Ĵ�С*/
//	printf("%d\n", sizeof a);                     /*��һ�������������Ǻ���*/
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof int);                   /*error*/
//
//	int arr[10] = { 0 };
//	printf("%d\n", sizeof(arr));                  /*����arr������ռ�ռ�Ĵ�С*/
//	printf("%d\n", sizeof(int [10]));             /*int [10]��arr���������*/
//
//	short s = 5;
//	int a = 10;
//	printf("%d\n", sizeof(s = a + 2));            /*����ǡ�2��*/
//	printf("%d\n", s);                            /*����ǡ�5��sizeof�����зŵı���ʽ�ǲ����������*/
//	return 0;
//}
// 
// 
//3.��~�� - ��һ�����Ķ�����λ��λȡ��
//int main()
//{
//	int a = -1;                                   /*���� - 11111111111111111111111111111111*/
//	int b = ~a;                                   /*���� - 00000000000000000000000000000000*/
//	printf("%d\n", b);                            /*����ǡ�0��*/
//	return 0;
//}
// 
//
//4.��--��
//int main()
//{
//int a = 10;
//int b = a--;                                    /*����--����ʹ��(a)����--*/
//printf("%d\n", a);                              /*����ǡ�9��*/
//printf("%d\n", b);                              /*����ǡ�10��*/
//return 0;
//
//int b = --a;                                    /*ǰ��--����--(a)����ʹ��*/
//printf("%d\n", a);                              /*����ǡ�9��*/
//printf("%d\n", b);                              /*����ǡ�9��*/
//return 0;
//}
// 
// 
//5.��++��
//int main()
//{
//	int a = 10;
//	//int b = a++;                                /*����++����ʹ��(a)����++*/
//	//printf("%d\n", a);                          /*����ǡ�11��*/
//	//printf("%d\n", b);                          /*����ǡ�10��*/
//	//return 0;
//
//	int b = ++a;                                  /*ǰ��++����++(a)����ʹ��*/
//	printf("%d\n", a);                            /*����ǡ�11��*/
//	printf("%d\n", b);                            /*����ǡ�11��*/
//	return 0;
//}
// 
// 
//6.��&�� - ȡ��ַ   ��*�� - ��ӷ��ʲ������������ò�������
//int main()
//{
//	int a = 10;
//	printf("%p\n", &a);                           /*��&��- ȡ��ַ������*/
//	int* pa = &a;                                 /*pa��������ŵ�ַ�� - pa����һ��ָ�����*/
//	*pa = 20;                                     /*��*�� - �����ò����� - ��ӷ��ʲ�����*/
//	printf("%d\n", a);
//	return 0;
//}
// 
//
//7.��(����)�� - ǿ������ת��
//int main()
//{
//	int a = (int)3.14;
//	return 0;
//}
// 
// 
//��.��ϵ��������������> < >= <= != =��)
// 
// 
//��.�߼���������������&& ||����
//1.��&&�� - �߼��루��һ��Ϊ�پ�Ϊ�٣�������Ϊ�٣��ұ߲����㣩
//int main()
//{
//	int a = 3;
//	int b = 0;
//	if (a && b)
//	{
//		printf("hehe\n");                         /*����ӡ*/
//	}
//	return 0;
//}
// 
// 
//2.��||�� - �߼�����һ��Ϊ���Ϊ�棬������Ϊ�棬�ұ߲����㣩
//int main()
//{
//	int a = 3;
//	int b = 0;
//	if (a || b)
//	{
//		printf("hehe\n");                         /*��ӡ*/
//	}
//	return 0;
//}
// 
// 
//��Ŀ1��
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	i = a++ && ++b && d++;
//	printf("a = %d\n b = %d\n c = %d\n d = %d\n", a, b, c, d);/*1 2 3 4*/
//	return 0;
//}
//
//
//��Ŀ2��
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	i = a++ || ++b || d++;
//	printf("a = %d\n b = %d\n c = %d\n d = %d\n", a, b, c, d);/*1 3 3 4*/
//	return 0;
//}
// 
// 
//��.����������/��Ŀ�������������� �� �� ����
//int main()
//{
//	int a = 3;
//	int b = 0;
//	if (a > 5)
//	{
//		b = 1;
//	}
//	else
//	{
//		b = -1;
//	}
//
//
//	b = (a > 5 ? 1: -1);
//	return 0;
//}
// 
// 
//��.���ű���ʽ - Ҫ�����������μ��㣬������������ʽ�Ľ�������һ������ʽ�Ľ��
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = 0;
//	int d = (c = 5, a = c + 3, b = a - 4,c += 5);
//	        /*c=5   a = 8      b=4       c=10*/
//	printf("%d\n",d);                             /*10*/
//	return 0;
//}
//
// 
//ʮ.�±����á��������úͽṹ��Ա
//1.[] - �±����ò����� - ��������һ��������+һ������ֵ
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	/*              0 1 2 3 4 5 6 7 8 9                */
//	printf("%d\n", arr[4]);                       /*[] - �����±����ò����� - ������Ϊ��arr��4��*/
//	return 0;
//}
// 
// 
//2.���� - �������ò�����
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int ret = Add(a, b);                          /*����- �������ò�����*/
//	return 0;
//}
// 
//3.�ṹ��Ա���ʲ�������������. ->����
//i����.��
//struct Book
//{
//	char name[20];
//	char id[20];
//	int price;
//};                                                /*������һ���Զ�������*/
//int main()
//{
//	struct Book b = {"C����","C20020925",55};
//	printf("������%s\n", b.name);
//	printf("��ţ�%s\n", b.id);
//	printf("���ۣ�%d\n", b.price);
//	return 0;
//}
//
// 
//ii)��->��
//struct Book
//{
//	char name[20];
//	char id[20];
//	int price;
//};                                                /*������һ���Զ�������*/
//int main()
//{
//	struct Book b = { "C����","C2022925",55 };
//	struct Book* pb = &b;
//	printf("������%s\n", pb->name);
//	printf("��ţ�%s\n", pb->id);
//	printf("���ۣ�%d\n", pb->price);
//	return 0;
//}
// 
// 
//**����ʽ��ֵ:����ʽ��ֵ��˳��һ�������ɲ����������ȼ��ͽ���Ծ�����ͬ������Щ����ʽ�Ĳ���������ֵ�Ĺ����п�����Ҫת��Ϊ�������͡�
//һ.��ʽ����ת����C������������������������ȱʡ�������͵ľ��������еġ�Ϊ�˻��������ȣ�����ʽ�е��ַ��Ͷ����Ͳ�������ʹ��֮ǰ��ת��Ϊ��ͨ���ͣ�����ת����Ϊ����������
//1.��������
//i)���壺����ʽ����������Ҫ��CPU����Ӧ����������ִ�У�CPU������������(ALU)�Ĳ��������ֽڳ���һ�����int���ֽڳ��ȣ�ͬʱҲ��CPU��ͨ�üĴ����ĳ��ȡ�
//��ˣ���ʹ����char���͵���ӣ���CPUִ��ʱʵ����ҲҪ��ת��ΪCPU�����Ͳ������ı�׼���ȡ�
//ͨ��CPU(general - purpose CPU)������ֱ��ʵ������8�����ֽ�ֱ��������㣨��Ȼ����ָ���п����������ֽ����ָ��)�����ԣ�����ʽ�и��ֳ��ȿ���С��int���ȵ�����ֵ����������ת��Ϊint��unsigned int��Ȼ���������CPUȥִ�����㡣
//ii)��ν�������������:���������ǰ��ձ������������͵ķ���λ��������
//int main()
//{
//	char a = 3;                 
//	/*00000000000000000000000000000011*/
//	/*00000011 - a*/
//	char b = 127;                  
//	/*00000000000000000000000001111111*/
//	/*01111111 - b*/
//	char c = a + b;	                      /*����a��b����char���͵ģ���û�дﵽһ��int�Ĵ�С������ͻᷢ����������*/
//	/*00000000000000000000000000000011+00000000000000000000000001111111=00000000000000000000000010000010*/
//  /*10000010 - c*/
//	printf("%d\n", c);             
//	/*11111111111111111111111110000010 - ����*/
//  /*11111111111111111111111110000001 - ����*/
//  /*10000000000000000000000001111110 - ԭ��*/
//	return 0;
//}
// 
// 
//2.����ת�������ĳ���������ĸ������������ڲ�ͬ�����ͣ���ô��������һ����������ת��Ϊ��һ�������������ͣ�����������޷����С�����Ĳ����ϵ��ΪѰ������ת����
//ת���������ĳ������������������������б��������ϵͣ���ô����Ҫת��Ϊ����һ�������������ͺ�ִ�����㡣
//����:��������ת��Ҫ������Ҫ��Ȼ����һЩǱ�ڵ����⡣
// 
// 
//��.������������
// ���ӱ���ʽ����ֵ������Ӱ������ء�
//1.�����������ȼ�
//2.�������Ľ����
//3.�Ƿ������ֵ˳��
//�������ڵĲ�������ִ���ĸ� ? ȡ�������ǵ����ȼ���������ߵ����ȼ���ͬ��ȡ�������ǵĽ���ԡ����������ȼ�
// 
// 
//B.��ϰ
//1.��д����ʵ�֣���һ�������������ڴ��еĶ�������1�ĸ���
//int main()
//{
//	int a = 13;                                   /*00000000000000000000000000001101*/
//
//	return 0;
//}
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
//  
//