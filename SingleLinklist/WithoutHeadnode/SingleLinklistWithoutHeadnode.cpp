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
void DestoryLinklist(Listnode*& head);//销毁链表和清空链表是一样的
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


int InitLinklist(Listnode*& head) //其实可以不写函数，直接在
{
	head = nullptr;
	return OK;
}

void IsEmpty(Listnode* head)
{
	if (head == nullptr) cout << "Linklist is empty!" << endl;
	else cout << "Linklist is not empty!" << endl;
}

void InsertHead(Listnode*& head, int value)//头插法,传入指针的引用
{
	Listnode* pNew = new Listnode();
	pNew->m_val = value;
	pNew->m_next = nullptr;

	if (head==nullptr) head = pNew;//空表，直接插入
	else
	{
		pNew->m_next = head;
		head = pNew;
	}
	cout << "Insret successful!" << endl;
}

void InsertTail(Listnode*& head, int value)//尾插法，传入指针的引用，因为对空表进行插入，得对头指针进行修改，还得需要一个辅助指针
{
	Listnode* pNew = new Listnode();
	pNew->m_val = value;
	pNew->m_next = nullptr;

	if (head == nullptr) head = pNew;//空表，直接插入
	else
	{
		Listnode* p = head;
		while (p->m_next) p = p->m_next;//找到尾结点
		p->m_next = pNew;
	}
	cout << "Insret successful!" << endl;
}

void DestoryLinklist(Listnode*& head)//销毁单链表
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

int FindElement(Listnode* head, int value)//按值查找，假设值是唯一的，返回位置
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