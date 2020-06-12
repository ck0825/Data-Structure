#include <iostream>

#define OK 1
#define ERROR -1

using namespace std;

struct Listnode
{
	int       m_val;
	Listnode* m_next;
};

int InitLinklist(Listnode*& head);
void IsEmpty(Listnode* head);
void InsertHead(Listnode*& head, int value);
void InsertTail(Listnode*& head, int value);
void DestoryLinklist(Listnode*& head);//������������������һ����
int LinklistLength(Listnode* head);
int FindElement(Listnode* head, int value);
int DeleteElement(Listnode*& head, int value);
void PrintLinklist(Listnode* head);

int main()
{
	Listnode* head;
	InitLinklist(head);
	InsertHead(head, 1);
	InsertHead(head, 2);
	InsertTail(head, 3);
	//DestoryLinklist(head);
	cout <<LinklistLength(head)<<endl;
	cout <<FindElement(head, 4)<<endl;
	PrintLinklist(head);
	DeleteElement(head, 2);
	PrintLinklist(head);
	return 0;
}


int InitLinklist(Listnode*& head) //��ʵ���Բ�д������ֱ����
{
	head = nullptr;
	return OK;
}

void IsEmpty(Listnode* head)
{
	if (head == nullptr) cout << "Linklist is empty!" << endl;
	else cout << "Linklist is not empty!" << endl;
}

void InsertHead(Listnode*& head, int value)//ͷ�巨,����ָ�������
{
	Listnode* pNew = new Listnode();
	pNew->m_val = value;
	pNew->m_next = nullptr;

	if (head==nullptr) head = pNew;//�ձ�ֱ�Ӳ���
	else
	{
		pNew->m_next = head;
		head = pNew;
	}
	cout << "Insret successful!" << endl;
}

void InsertTail(Listnode*& head, int value)//β�巨������ָ������ã���Ϊ�Կձ���в��룬�ö�ͷָ������޸ģ�������Ҫһ������ָ��
{
	Listnode* pNew = new Listnode();
	pNew->m_val = value;
	pNew->m_next = nullptr;

	if (head == nullptr) head = pNew;//�ձ�ֱ�Ӳ���
	else
	{
		Listnode* p = head;
		while (p->m_next) p = p->m_next;//�ҵ�β���
		p->m_next = pNew;
	}
	cout << "Insret successful!" << endl;
}

void DestoryLinklist(Listnode*& head)//���ٵ�����
{
	if (!head) cout << "Linnklist is empty!" << endl;
	else
	{
		Listnode* p = nullptr;
		while (head)
		{
			p = head;
			head = head->m_next;
			delete p;
		}
	}
}

int LinklistLength(Listnode* head)
{
	int n = 0;
	if (!head) return n;
	else
	{
		Listnode* p = head;
		while (p)
		{
			++n;
			p = p->m_next;
		}
	}return n;
}

int FindElement(Listnode* head, int value)//��ֵ���ң�����ֵ��Ψһ�ģ�����λ��
{
	int n = 0;
	if (!head)
	{
		cout << "Linklist is empty!" << endl;
		return -1;
	}
	else
	{
		Listnode* p = head;
		while (p && p->m_val != value)
		{
			++n;
			p = p->m_next;
		}
		if (!p)
		{
			cout << "No this value in Linklist!" << endl;
			return -1;
		}
		cout << "This element's location is " << n + 1 << endl;
	}return n + 1;
}

int DeleteElement(Listnode*& head, int value)
{
	if (!head)
	{
		cout << "Linklist is empty!" << endl;
		return ERROR;
	}
	else
	{
		Listnode* p = head;
		Listnode* q = head;
		while (p && p->m_val != value)
		{
			q = p;
			p = p->m_next;
		}
		if (p == nullptr) cout << "The value is not in this Linklist!" << endl;
		else if (p==head)
		{
			head = head->m_next;
			delete p;
		}
		else
		{
			q->m_next = p->m_next;
			delete p;
		}
		return OK;
	}
}

void PrintLinklist(Listnode* head)
{
	if (!head) cout << "Linklist is empty!" << endl;
	else
	{
		Listnode* p = head;
		while (p)
		{
			cout <<p->m_val<<endl;
			p = p->m_next;
		}
	}
}