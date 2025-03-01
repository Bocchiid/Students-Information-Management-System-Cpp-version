#define vc vector
#define pb push_back
#define ll long long
#define ull unsigned long long
using ld = long double;

#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <stdlib.h>
using namespace std;

struct elemType
{
	string id;
	string name;
	string sex;
	double x;
	double y;
	double z;
};

struct node
{
	elemType data;
	node *next;
};

/**************************************
功能: 初始化链表
形参: node *head
返回值：void
日期：2025.03.01
版本：v1
作者: 韩贤煜
***************************************/
void init(node *head)
{
	head = (node *)malloc(sizeof(node) * 1);
	head->next = NULL;
}

/**************************************
功能：输入学生信息
形参: elemType *x
返回值：void
日期：2025.03.01
版本：v1
作者: 韩贤煜
***************************************/
void inputElement(elemType *x)
{
	cin >> x->id >> x->name >> x->sex >> x->x >> x->y >> x->z;
}

/**************************************
功能：插入学生信息
形参: node *tail, elemType x
返回值：void
日期：2025.03.01
版本：v1
作者: 韩贤煜
***************************************/
void insertElement(node *tail, elemType x)
{
	node *p = (node *)malloc(sizeof(node) * 1);
	p->data = x;
	p->next = NULL;
	tail->next = p;
	tail = p;
}

/**************************************
功能：输出学生信息
形参: elemType x
返回值：void
日期：2025.03.01
版本：v1
作者: 韩贤煜
***************************************/
void printElement(elemType x)
{
	cout << x.id << ' ' << x.name << ' ' << x.sex << ' ';
	printf("%.1f %.1f %.1f\n", x.x, x.y, x.z);
}
/**************************************
主函数项目：学生信息管理系统
要求：数据结构必须用链表、尽可能用函数
1. 输入输出学生信息
2. 创建链表
3. 链表的插入结点
4. 链表的遍历、打印
5. 删除结点
6. 查找结点
7. 修改结点
8. 排序
9. 交换二个elemType的值
****************************************/
int main()
{
	elemType x;
	// 1、链表或顺序表初始化
	node *head;
	init(head);
	node *tail = head;

	while (true)
	{
		string op;
		// 2、读入命令字符串
		cin >> op;
		// 3、如果 插入
		if (op == "Insert")
		{
			cout << "Insert:" << endl;
			// 3.1、输入学生信息
			inputElement(&x);
			insertElement(tail, x);
			printElement(x);
			// 3.2如果成功插入信息（函数），则输出学生信息，
			// 否则，输出 "Failed\n"
		}
		// 4、List
		if (op == "List")
		{
			cout << "List:" << endl;
			// 4.1排序（函数）
			// 4.2输出（函数）
		}
		// 5、修改
		if (op == "Change")
		{
			cout << "Change:" << endl;
			// 5.1输入学生信息
			// 5.2如果修改成功（函数），则输出学生信息
			// 否则输出 Failed
		}
		// 6、删除学生信息
		if (op == "Delete")
		{
			cout << "Delete:" << endl;
			// 6.1输入学号
			// 6.2如果成功删除（函数）则deleted
			// 否则 Failed
		}
		// 7、查找，
		if (op == "Find")
		{
			cout << "Find:" << endl;
			// 输入学号
			// 如果查找成功（函数），输出学生信息，否则，输出Failed
		}
		if (op == "Quit")
		{
			cout << "Good bye!" << endl;
			break;
		}
	}

	return 0;
}

/**************************************
功能：
形参:
返回值：
日期：
版本：
作者:
***************************************/