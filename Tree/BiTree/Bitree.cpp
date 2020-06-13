#include <iostream>
#include <stack>
#include <queue>
using namespace std;


#define OK 1
#define ERROR 0


struct Treenode
{
	int m_data;
	Treenode* m_lchild;
	Treenode* m_rchild;
};

int InitialBitree(Treenode*& T);
void CreatBitree(Treenode*& T, int value);

void Preorder(Treenode* T);
void PreorderNoRec2(Treenode* T);
void Inorder(Treenode* T);
void InorderNoRec2(Treenode* T);
void Postorder(Treenode* T);
void PostorderNoRec2(Treenode* T);
void Leveoreder(Treenode* T);
void PreorderNoRec(Treenode* T);
void InorderNoRec(Treenode* T);

int main()
{
	Treenode* T;
 	InitialBitree(T);
	CreatBitree(T, 5);
	CreatBitree(T, 4);
	CreatBitree(T, 6);
	CreatBitree(T, 3);
	CreatBitree(T, 5);
	//PostorderNoRec2(T);
	Leveoreder(T);
	return 0;
}

int InitialBitree(Treenode*& T)
{
	T = nullptr;
	return OK;
}

void CreatBitree(Treenode*& T,int value)
{
	Treenode* pNew = new Treenode();//�����µĽ��
	pNew->m_data = value;
	pNew->m_lchild = nullptr;
	pNew->m_rchild = nullptr;

	int flag = 0; //���óɹ�����ı�־������Ϊ1��ʾ����ɹ�

	if (T == nullptr) T = pNew;
	else
	{
		Treenode* p = T;
		while (!flag)
		{
			if (value < p->m_data) //С�ڸ��ڵ㣬����������
			{
				if (p->m_lchild == nullptr)
				{
					p->m_lchild = pNew;
					flag = 1;
				}
				else
					p = p->m_lchild;
			}
			else//���ڵ��ڸ���㣬����������
			{
				if (p->m_rchild == nullptr)
				{
					p->m_rchild = pNew;
					flag = 1;
				}
				else
					p = p->m_rchild;
			}
		}
	}
}

void Preorder(Treenode* T) //�ݹ�ǰ��
{
	if (T)
	{
		cout << T->m_data << endl;
		Preorder(T->m_lchild);
		Preorder(T->m_rchild);
	}else return;
}

void PreorderNoRec2(Treenode* T)//ǰ��ǵݹ�
{
	stack<Treenode*> s;
	if (T) s.push(T);  //������ջ�����
	Treenode* p = nullptr;
	while (!s.empty())
	{
		p = s.top();
		s.pop();
		if (p != nullptr)
		{
			if (p->m_rchild) s.push(p->m_rchild); //�ҽ������ջ������
			if (p->m_lchild) s.push(p->m_lchild);
			s.push(p);  //��ǰ�ڵ�������ջ�������Ժ�������Ϊ��������������ѹջ
			s.push(nullptr); //�ڵ�ǰ�ڵ�֮ǰ����һ���սڵ��ʾ�Ѿ����ʹ���
		}
		else
		{
			cout << s.top()->m_data << endl;
			s.pop();
		}
	}
}

void Inorder(Treenode* T) //�ݹ�����
{
	if (T) 
	{
		Inorder(T->m_lchild);
		cout << T->m_data << endl;
		Inorder(T->m_rchild);
	}else return;
}

void InorderNoRec2(Treenode* T)//ǰ��ǵݹ�
{
	stack<Treenode*> s;
	if (T) s.push(T);  //������ջ�����
	Treenode* p = nullptr;
	while (!s.empty())
	{
		p = s.top();
		s.pop();
		if (p != nullptr)
		{
			if (p->m_rchild) s.push(p->m_rchild); //�ҽ������ջ������
			s.push(p);  //��ǰ�ڵ�������ջ�������Ժ�������Ϊ��������������ѹջ
			s.push(nullptr); //�ڵ�ǰ�ڵ�֮ǰ����һ���սڵ��ʾ�Ѿ����ʹ���
			if (p->m_lchild) s.push(p->m_lchild);

		}
		else
		{
			cout << s.top()->m_data << endl;
			s.pop();
		}
	}
}

void Postorder(Treenode* T) //�ݹ����
{
	if (T)
	{
		Postorder(T->m_lchild);
		Postorder(T->m_rchild);
		cout << T->m_data << endl;
	}
	else return;
}

void PostorderNoRec2(Treenode* T)//ǰ��ǵݹ�
{
	stack<Treenode*> s;
	if (T) s.push(T);  //������ջ�����
	Treenode* p = nullptr;
	while (!s.empty())
	{
		p = s.top();
		s.pop();
		if (p != nullptr)
		{
			s.push(p);  //��ǰ�ڵ�������ջ�������Ժ�������Ϊ��������������ѹջ
			s.push(nullptr); //�ڵ�ǰ�ڵ�֮ǰ����һ���սڵ��ʾ�Ѿ����ʹ���
			if (p->m_rchild) s.push(p->m_rchild); //�ҽ������ջ������
			if (p->m_lchild) s.push(p->m_lchild);
		}
		else
		{
			cout << s.top()->m_data << endl;
			s.pop();
		}
	}
}


void Leveoreder(Treenode* T)//�������
{
	queue<Treenode*> qu;
	if (T) qu.push(T);
	Treenode* p = nullptr;
	while (!qu.empty())
	{
		p = qu.front();
		qu.pop();
		cout <<p->m_data<<endl;
		if (p->m_lchild) qu.push(p->m_lchild);
		if (p->m_rchild) qu.push(p->m_rchild);
	}
}














void PreorderNoRec(Treenode* T)//ǰ��ǵݹ�
{
	if (!T) return;
	else
	{
		stack<Treenode*> s;//����һ��ջ�ռ�
		s.push(T);
		Treenode* p = nullptr;
		while (!s.empty())
		{
			p = s.top();
			s.pop();
			if (p) //�����ǰ��㲻Ϊ�գ���ӡ��ǰ��㣬�ҽڵ�����ջ����������ջ
			{
				cout << p->m_data << endl;
				s.push(p->m_rchild);
				s.push(p->m_lchild);
			}
		}
	}
}


void InorderNoRec(Treenode* T) //����ǵݹ�
{
	if (!T) return;
	else
	{
		stack<Treenode*> s;
		Treenode* p = T;
		while (p || !s.empty())
		{
			if (p)
			{
				s.push(p);
				p = p->m_lchild;
			}
			else
			{
				p = s.top();
				s.pop();
				cout << p->m_data << endl;
				p = p->m_rchild;
			}
		}
	}
}