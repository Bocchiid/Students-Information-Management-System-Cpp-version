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
����: ��ʼ������
�β�: node *head
����ֵ��void
���ڣ�2025.03.01
�汾��v1
����: ������
***************************************/
void init(node *head)
{
	head = (node *)malloc(sizeof(node) * 1);
	head->next = NULL;
}

/**************************************
���ܣ�����ѧ����Ϣ
�β�: elemType *x
����ֵ��void
���ڣ�2025.03.01
�汾��v1
����: ������
***************************************/
void inputElement(elemType *x)
{
	cin >> x->id >> x->name >> x->sex >> x->x >> x->y >> x->z;
}

/**************************************
���ܣ�����ѧ����Ϣ
�β�: node *tail, elemType x
����ֵ��void
���ڣ�2025.03.01
�汾��v1
����: ������
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
���ܣ����ѧ����Ϣ
�β�: elemType x
����ֵ��void
���ڣ�2025.03.01
�汾��v1
����: ������
***************************************/
void printElement(elemType x)
{
	cout << x.id << ' ' << x.name << ' ' << x.sex << ' ';
	printf("%.1f %.1f %.1f\n", x.x, x.y, x.z);
}
/**************************************
��������Ŀ��ѧ����Ϣ����ϵͳ
Ҫ�����ݽṹ�����������������ú���
1. �������ѧ����Ϣ
2. ��������
3. ����Ĳ�����
4. ����ı�������ӡ
5. ɾ�����
6. ���ҽ��
7. �޸Ľ��
8. ����
9. ��������elemType��ֵ
****************************************/
int main()
{
	elemType x;
	// 1�������˳����ʼ��
	node *head;
	init(head);
	node *tail = head;

	while (true)
	{
		string op;
		// 2�����������ַ���
		cin >> op;
		// 3����� ����
		if (op == "Insert")
		{
			cout << "Insert:" << endl;
			// 3.1������ѧ����Ϣ
			inputElement(&x);
			insertElement(tail, x);
			printElement(x);
			// 3.2����ɹ�������Ϣ���������������ѧ����Ϣ��
			// ������� "Failed\n"
		}
		// 4��List
		if (op == "List")
		{
			cout << "List:" << endl;
			// 4.1���򣨺�����
			// 4.2�����������
		}
		// 5���޸�
		if (op == "Change")
		{
			cout << "Change:" << endl;
			// 5.1����ѧ����Ϣ
			// 5.2����޸ĳɹ����������������ѧ����Ϣ
			// ������� Failed
		}
		// 6��ɾ��ѧ����Ϣ
		if (op == "Delete")
		{
			cout << "Delete:" << endl;
			// 6.1����ѧ��
			// 6.2����ɹ�ɾ������������deleted
			// ���� Failed
		}
		// 7�����ң�
		if (op == "Find")
		{
			cout << "Find:" << endl;
			// ����ѧ��
			// ������ҳɹ��������������ѧ����Ϣ���������Failed
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
���ܣ�
�β�:
����ֵ��
���ڣ�
�汾��
����:
***************************************/