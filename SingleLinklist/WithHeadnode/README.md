# 带头结点的单链表的操作

- 初始化链表头部指针需要用**二级指针或者一级指针**的引用；
- 销毁链表需要用到**二级指针或者一级指针的引用**；
- 插入、删除、遍历、清空结点用一级指针即可。
- 结论：需要修改头指针的操作才需要**二级指针或者一级指针的引用**。

1. 初始化单链表

   - 因为初始化单链表需要修改头指针的内容，所以需要传递**头指针的指针**或**指针的引用**。

   

   ```C++
   struct Listnode
   {
   	int       m_val;
   	Listnode* m_next;
   };
   ```

   

   1.  用二级指针传参

      ```C++
      int InitLinklist(Listnode** head)//二级指针进行初始化
      {
      	*head = new Listnode();
      	if (head==nullptr) return ERROR;
      	(*head)->m_next = nullptr;
      	return OK;
      }
      ```

   2.  用指针的引用传参

      ```C++
      int InitLinklistRe(Listnode*& head)//一级指针引用进行初始化
      {
      	head = new Listnode();
      	if (head == nullptr) return ERROR;
      	head->m_next = nullptr;
      	return OK;
      }
      ```

      

2. 判断是否为空表

   ```C++
   void IsEmpty(Listnode* head)
   {
   	if (head->m_next == nullptr) cout << "Linklist is empty!" << endl;
   	else cout << "Linklist is not empty!" << endl;
   }
   ```

   

3. 头插法插入

   ```C++
   void InsertHead(Listnode* head,int value)//头插法
   {
   	Listnode* pNew = new Listnode();//将要插入的值保存在一个新节点
   	pNew->m_val = value;
   	pNew->m_next = nullptr;
   
   	if (head->m_next == nullptr) head->m_next = pNew;
   	else
   	{
   		pNew->m_next = head->m_next;
   		head->m_next = pNew;
   	}
   }
   ```

   

4. 尾插法插入

   ```C++
   void InsertTail(Listnode* head, int value)//尾插法，比头插法多一个循环，需要先找到尾结点
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
   ```

   

5. 销毁单链表

   - 销毁链表需要对头指针进行修改，所以需要传入指针的指针或者指针的引用。

   ```C++
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
   ```

   

6. 清空单链表

   - 虽然需要释放结点内存，但是可以把头结点作为一个辅助结点移动，所以只需另外一个p

   ```C++
   int ClearList(Listnode* head)
   {
   	if (head->m_next == nullptr) cout << "Linklist is empty!" << endl;
   	else
   	{
   		Listnode* p = nullptr;
   		while (head->m_next != nullptr)
   		{
   			p = head->m_next;   //从头结点后面一个元素开始清除
   			head->m_next = head->m_next->m_next;
   			delete p;
   		}
   	}
   	return OK;
   }
   ```

   

7. 计算单链表的长度

   ```C++
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
   ```

   

8. 按值查找

   ```C++
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
   		while (p && p->m_val!=value )//如果p不为空&&p的数据域不为value，进行下一个查找
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
   ```

   

9. 按位置返回值

   ```C++
   int GetIValue(Listnode* head,int n)//取第i个数的值
   {
   	int m_n = LinklistLength(head);
   
   	if (head->m_next==nullptr|| n<=0 ||m_n<n)//判断给定的位置是否在范围之内
   	{
   		cout << "Not in the range!" << endl;
   		return ERROR;
   	}
   	else
   	{
   		Listnode* p = head;
   		for (int i = 1; i <= n; ++i)//循环查找
   			p = p->m_next;
   		return p->m_val;
   	}
   }
   ```

   

10. 按值删除

    - 删除值，涉及到释放结点内存，所以需要**两个辅助变量**。

    ```C++
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
    ```

    