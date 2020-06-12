#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0


struct Listnode
{
	int       m_val;
	Listnode* m_next;
};


int InitLinklist(Listnode** head);
int InitLinklistRe(Listnode*& head);
void IsEmpty(Listnode* head);
void InsertHead(Listnode* head, int value);
void InsertTail(Listnode* head, int value);
int DestoryLinklist(Listnode*& head);
int ClearList(Listnode* head);
int LinklistLength(Listnode* head);
int FindElement(Listnode* head, int value);
int GetIValue(Listnode* head, int n);
int DeleteElement(Listnode* head, int value);

int main()
{
	Listnode* head;
	InitLinklistRe(head);
	InsertTail(head, 8);
	InsertHead(head,9);
	InsertHead(head, 1);
	FindElement(head, 0);
	IsEmpty(head);
	cout <<LinklistLength(head)<<endl;
	cout << GetIValue(head, 1) << endl;
	DeleteElement(head, 9);
	ClearList(head);
	DestoryLinklist(head);
	return 0;
}

int InitLinklist(Listnode** head)//二级指针进行初始化
{
	*head = new Listnode();
	if (head==nullptr) return ERROR;
	(*head)->m_next = nullptr;
	return OK;
}
int InitLinklistRe(Listnode*& head)//一级指针引用进行初始化
{
	head = new Listnode();
	if (head == nullptr) return ERROR;
	head->m_next = nullptr;
	return OK;
}

void IsEmpty(Listnode* head)
{
	if (head->m_next == nullptr) cout << "Linklist is empty!" << endl;
	else cout << "Linklist is not empty!" << endl;
}

void InsertHead(Listnode* head,int value)//头插法
{
	Listnode* pNew = new Listnode();
	pNew->m_val = value;
	pNew->m_next = nullptr;

	if (head->m_next == nullptr) head->m_next = pNew;
	else
	{
		pNew->m_next = head->m_next;
		head->m_next = pNew;
	}
}

void InsertTail(Listnode* head, int value)//尾插法
{
	Listnode* pNew = new Listnode();
	pNew->m_val = value;
	pNew->m_next = nullptr;

	if (head->m_next == nullptr) head->m_next = pNew;
	else
	{
		Listnode* q = head;
		while (q->m_next != nullptr) q = q->m_next;
		q->m_next = pNew;
	}
}

int DestoryLinklist(Listnode*& head)
{
	Listnode* p = nullptr;

	while (head != nullptr)
	{
		p = head;
		head = head->m_next;
		delete p;
	}
	return OK;
}

int ClearList(Listnode* head)
{
	if (head->m_next == nullptr) cout << "Linklist is empty!" << endl;
	else
	{
		Listnode* p = nullptr;
		while (head->m_next != nullptr)
		{
			p = head->m_next;
			head->m_next = head->m_next->m_next;
			delete p;
		}
	}
	return OK;
}

int LinklistLength(Listnode* head)
{
	int n = 0;
	if (head->m_next == nullptr) cout <<"Linklist is empty!"<<endl;
	else
	{
		Listnode* p = head->m_next;
		while (p)
		{
			++n;
			p = p->m_next;
		}
	}
	return n;
}

int FindElement(Listnode* head,int value)//按值查找，假设值是唯一的，返回位置
{
	int n = 0;
	if (head->m_next == nullptr)
	{
		cout << "Linklist is empty!" << endl;
		return -1;
	}
	else
	{
		Listnode* p = head->m_next;
		while (p && p->m_val!=value )
		{
			++n;
			p = p->m_next;
		}
		if (p == nullptr)
		{
			cout << "No this value in Linklist!" << endl;
			return -1;
		}
		cout << "This element's location is " << n+1 << endl;
	}
	return n+1;
}

int GetIValue(Listnode* head,int n)//取第i个数的值
{
	int m_n = LinklistLength(head);

	if (head->m_next==nullptr|| n<=0 ||m_n<n)
	{
		cout << "Not in the range!" << endl;
		return ERROR;
	}
	else
	{
		Listnode* p = head;
		for (int i = 1; i <= n; ++i)
			p = p->m_next;
		return p->m_val;
	}
}

int DeleteElement(Listnode* head, int value)
{
	if (head == nullptr)
	{
		cout << "Linklist is empty!" << endl;
		return ERROR;
	}
	else
	{
		Listnode* p = head->m_next;
		Listnode* q = head->m_next;
		while (p && p->m_val != value)
		{
			q = p;
			p = p->m_next;
		}
		if (p)
		{
			q->m_next = p->m_next;
			delete p;
		}
		else
		{
			cout << "The value is not in this Linklist!" << endl;
		}
	}return OK;
}