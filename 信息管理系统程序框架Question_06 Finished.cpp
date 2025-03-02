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
���ܣ�����ѧ����Ϣ
�β�: elemType &x
����ֵ��void
���ڣ�2025.03.02
�汾��v1
����: ������
***************************************/
void inputElement(elemType &x)
{
    cin >> x.id >> x.name >> x.sex >> x.x >> x.y >> x.z;
}

/**************************************
���ܣ����ѧ����Ϣ
�β�: elemType x
����ֵ��void
���ڣ�2025.03.02
�汾��v1
����: ������
***************************************/
void printElement(elemType x)
{
    cout << x.id << ' ' << x.name << ' ' << x.sex << ' ';
    printf("%.1f %.1f %.1f\n", x.x, x.y, x.z);
}

/**************************************
���ܣ���ʼ������
�β�: node *&head
����ֵ��void
���ڣ�2025.03.02
�汾��v1
����: ������
***************************************/
void init(node *&head)
{
    head = new node;
    head->next = NULL;
}

/**************************************
���ܣ�����ѧ����Ϣ
�β�: node *&tail, elemType x
����ֵ��void
���ڣ�2025.03.02
�汾��v1
����: ������
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
���ܣ��������ѧ����Ϣ
�β�: node *head
����ֵ��void
���ڣ�2025.03.02
�汾��v1
����: ������
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
���ܣ�����ѧ����Ϣ
�β�: node *head, string id
����ֵ��node *
���ڣ�2025.03.02
�汾��v1
����: ������
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
���ܣ��޸�ѧ����Ϣ
�β�: node *&temp, elemType
����ֵ: void
���ڣ�2025.03.02
�汾��v1
����: ������
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
            inputElement(x);
            temp = findElement(head, x.id);
            // 3.2����ɹ�������Ϣ���������������ѧ����Ϣ��

            if (!temp)
            {
                insertElement(tail, x);
                printElement(x);
            }
            else // ������� "Failed\n"
            {
                cout << "Failed" << endl;
            }
        }
        // 4��List
        if (op == "List")
        {
            cout << "List:" << endl;
            // 4.1���򣨺�����
            // 4.2�����������
            printList(head);
        }
        // 5���޸�
        if (op == "Change")
        {
            cout << "Change:" << endl;
            // 5.1����ѧ����Ϣ
            inputElement(x);
            temp = findElement(head, x.id);
            // 5.2����޸ĳɹ����������������ѧ����Ϣ

            if (temp)
            {
                changeElement(temp, x);
                printElement(temp->data);
            }
            else // ������� Failed
            {
                cout << "Failed" << endl;
            }
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
            cin >> id;
            temp = findElement(head, id);
            // ������ҳɹ��������������ѧ����Ϣ���������Failed

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
���ܣ�
�β�:
����ֵ��
���ڣ�
�汾��
����:
***************************************/

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