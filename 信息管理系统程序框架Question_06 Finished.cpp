#include <iostream>
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
功能：输入学生信息
形参: elemType &x
返回值：void
日期：2025.03.02
版本：v1
作者: 韩贤煜
***************************************/
void inputElement(elemType &x)
{
    cin >> x.id >> x.name >> x.sex >> x.x >> x.y >> x.z;
}

/**************************************
功能：输出学生信息
形参: elemType x
返回值：void
日期：2025.03.02
版本：v1
作者: 韩贤煜
***************************************/
void printElement(elemType x)
{
    cout << x.id << ' ' << x.name << ' ' << x.sex << ' ';
    printf("%.1f %.1f %.1f\n", x.x, x.y, x.z);
}

/**************************************
功能：初始化链表
形参: node *&head
返回值：void
日期：2025.03.02
版本：v1
作者: 韩贤煜
***************************************/
void init(node *&head)
{
    head = new node;
    head->next = NULL;
}

/**************************************
功能：插入学生信息
形参: node *&tail, elemType x
返回值：void
日期：2025.03.02
版本：v1
作者: 韩贤煜
***************************************/
void insertElement(node *&tail, elemType x)
{
    node *p = new node;
    p->data = x;
    p->next = NULL;
    tail->next = p;
    tail = p;
}

/**************************************
功能：输出所有学生信息
形参: node *head
返回值：void
日期：2025.03.02
版本：v1
作者: 韩贤煜
***************************************/
void printList(node *head)
{
    node *p = head->next;

    while (p)
    {
        printElement(p->data);
        p = p->next;
    }
}

/**************************************
功能：查找学生信息
形参: node *head, string id
返回值：node *
日期：2025.03.02
版本：v1
作者: 韩贤煜
***************************************/
node *findElement(node *head, string id)
{
    node *p = head->next;

    while (p && p->data.id != id)
    {
        p = p->next;
    }

    return p;
}

/**************************************
功能：修改学生信息
形参: node *&temp, elemType
返回值: void
日期：2025.03.02
版本：v1
作者: 韩贤煜
***************************************/
void changeElement(node *&temp, elemType x)
{
    temp->data = x;
}

int main()
{
    elemType x;
    string id;
    node *temp;
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
            inputElement(x);
            temp = findElement(head, x.id);
            // 3.2如果成功插入信息（函数），则输出学生信息，

            if (!temp)
            {
                insertElement(tail, x);
                printElement(x);
            }
            else // 否则，输出 "Failed\n"
            {
                cout << "Failed" << endl;
            }
        }
        // 4、List
        if (op == "List")
        {
            cout << "List:" << endl;
            // 4.1排序（函数）
            // 4.2输出（函数）
            printList(head);
        }
        // 5、修改
        if (op == "Change")
        {
            cout << "Change:" << endl;
            // 5.1输入学生信息
            inputElement(x);
            temp = findElement(head, x.id);
            // 5.2如果修改成功（函数），则输出学生信息

            if (temp)
            {
                changeElement(temp, x);
                printElement(temp->data);
            }
            else // 否则输出 Failed
            {
                cout << "Failed" << endl;
            }
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
            cin >> id;
            temp = findElement(head, id);
            // 如果查找成功（函数），输出学生信息，否则，输出Failed

            if (temp)
            {
                printElement(temp->data);
            }
            else
            {
                cout << "Failed" << endl;
            }
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