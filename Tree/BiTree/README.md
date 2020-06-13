# 二叉树的基本操作

1. 二叉树的初始化

   ```C++
   int InitialBitree(Treenode*& T)
   {
   	T = nullptr;
   	return OK;
   }
   ```

   

2. 二叉树的创建

   - 比根结点小的放在左子树，其余的放在右子树

   ```C++
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
   ```

   

3. 遍历（递归）

   - 三种遍历代码几乎相同，**只是对根结点的操作的位置不同**

   - 前序

     ```C++
     void Preorder(Treenode* T) //递归前序
     {
     	if (T)
     	{
     		cout << T->m_data << endl;//对根结点的操作
     		Preorder(T->m_lchild);
     		Preorder(T->m_rchild);
     	}else return;
     }
     ```

     

   - 中序

     ```
     void Inorder(Treenode* T) //递归中序
     {
     	if (T) 
     	{
     		Inorder(T->m_lchild);
     		cout << T->m_data << endl;
     		Inorder(T->m_rchild);
     	}else return;
     }
     ```

     

   - 后序

     ```C++
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
     ```

     

4. 遍历（非递归）

   - 三个程序的模板相同，只是将当前结点入栈的顺序不同

   - 前序

     ```C++
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
     ```

     

   - 中序

     ```C++
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
     ```

     

   - 后序

     ```C++
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
     ```

     > https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/mo-fang-di-gui-zhi-bian-yi-xing-by-sonp/

   - 前序和中序

     ```C++
     void PreorderNoRec(Treenode* T)//前序非递归
     {
     	if (!T) return;
     	else
     	{
     		stack<Treenode*> s;//申请一个栈空间
     		s.push(T);
     		Treenode* p=nullptr;
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
     ```

     > https://www.jianshu.com/p/6e739de0d206

5. 层序遍历

   - 利用队列的思想
     - 现将根结点入队，如果根结点有左右结点，分别入队；
     - 打印根结点，将根结点出队，指针转到队列的首元素。

   ```C++
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
   ```



