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
	Treenode* pNew = new Treenode();//生成新的结点
	pNew->m_data = value;
	pNew->m_lchild = nullptr;
	pNew->m_rchild = nullptr;

	int flag = 0; //设置成功插入的标志，设置为1表示插入成功

	if (T == nullptr) T = pNew;
	else
	{
		Treenode* p = T;
		while (!flag)
		{
			if (value < p->m_data) //小于根节点，插入左子树
			{
				if (p->m_lchild == nullptr)
				{
					p->m_lchild = pNew;
					flag = 1;
				}
				else
					p = p->m_lchild;
			}
			else//大于等于根结点，插入右子树
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

void Preorder(Treenode* T) //递归前序
{
	if (T)
	{
		cout << T->m_data << endl;
		Preorder(T->m_lchild);
		Preorder(T->m_rchild);
	}else return;
}

void PreorderNoRec2(Treenode* T)//前序非递归
{
	stack<Treenode*> s;
	if (T) s.push(T);  //首先入栈根结点
	Treenode* p = nullptr;
	while (!s.empty())
	{
		p = s.top();
		s.pop();
		if (p != nullptr)
		{
			if (p->m_rchild) s.push(p->m_rchild); //右结点先入栈，后处理
			if (p->m_lchild) s.push(p->m_lchild);
			s.push(p);  //当前节点重新入栈（留着以后处理），因为先序遍历所以最后压栈
			s.push(nullptr); //在当前节点之前加入一个空节点表示已经访问过了
		}
		else
		{
			cout << s.top()->m_data << endl;
			s.pop();
		}
	}
}

void Inorder(Treenode* T) //递归中序
{
	if (T) 
	{
		Inorder(T->m_lchild);
		cout << T->m_data << endl;
		Inorder(T->m_rchild);
	}else return;
}

void InorderNoRec2(Treenode* T)//前序非递归
{
	stack<Treenode*> s;
	if (T) s.push(T);  //首先入栈根结点
	Treenode* p = nullptr;
	while (!s.empty())
	{
		p = s.top();
		s.pop();
		if (p != nullptr)
		{
			if (p->m_rchild) s.push(p->m_rchild); //右结点先入栈，后处理
			s.push(p);  //当前节点重新入栈（留着以后处理），因为先序遍历所以最后压栈
			s.push(nullptr); //在当前节点之前加入一个空节点表示已经访问过了
			if (p->m_lchild) s.push(p->m_lchild);

		}
		else
		{
			cout << s.top()->m_data << endl;
			s.pop();
		}
	}
}

void Postorder(Treenode* T) //递归后序
{
	if (T)
	{
		Postorder(T->m_lchild);
		Postorder(T->m_rchild);
		cout << T->m_data << endl;
	}
	else return;
}

void PostorderNoRec2(Treenode* T)//前序非递归
{
	stack<Treenode*> s;
	if (T) s.push(T);  //首先入栈根结点
	Treenode* p = nullptr;
	while (!s.empty())
	{
		p = s.top();
		s.pop();
		if (p != nullptr)
		{
			s.push(p);  //当前节点重新入栈（留着以后处理），因为先序遍历所以最后压栈
			s.push(nullptr); //在当前节点之前加入一个空节点表示已经访问过了
			if (p->m_rchild) s.push(p->m_rchild); //右结点先入栈，后处理
			if (p->m_lchild) s.push(p->m_lchild);
		}
		else
		{
			cout << s.top()->m_data << endl;
			s.pop();
		}
	}
}


void Leveoreder(Treenode* T)//层序遍历
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














void PreorderNoRec(Treenode* T)//前序非递归
{
	if (!T) return;
	else
	{
		stack<Treenode*> s;//申请一个栈空间
		s.push(T);
		Treenode* p = nullptr;
		while (!s.empty())
		{
			p = s.top();
			s.pop();
			if (p) //如果当前结点不为空，打印当前结点，右节点先入栈，左结点再入栈
			{
				cout << p->m_data << endl;
				s.push(p->m_rchild);
				s.push(p->m_lchild);
			}
		}
	}
}


void InorderNoRec(Treenode* T) //中序非递归
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