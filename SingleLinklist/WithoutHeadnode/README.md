# 不带头结点的单链表的操作

- 可能涉及到头指针修改的需要用**二级指针或者一级指针**的引用：
  - **链表初始化、头插、尾插、销毁链表、删除元素**；
- **不涉及头指针的修改只需要一级指针**：
  - 判断空表、统计长度、查找元素、打印链表；
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

   

   2.  用指针的引用传参

      ```C++
      int InitLinklist(Listnode*& head) //其实可以不写函数，直接在
      {
      	head = nullptr;
      	return OK;
      }
      ```
      
      

2. 判断是否为空表

   ```C++
   void IsEmpty(Listnode* head)
   {
   	if (head == nullptr) cout << "Linklist is empty!" << endl;
   	else cout << "Linklist is not empty!" << endl;
   }
   ```

   

3. 头插法插入

   ```C++
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
   ```

   

4. 尾插法插入

   ```C++
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
   ```

   

5. 销毁单链表

   - 销毁链表需要对头指针进行修改，所以需要传入指针的指针或者指针的引用，不带头结点的单链表清空和销毁是一个概念。

   ```C++
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
   ```

   

7. 计算单链表的长度

   ```C++
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
   ```
   

   
8. 按值查找

   ```C++
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
   ```
   

   
9. 打印链表

   ```C++
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
   ```
   
   
   
10. 按值删除

    - 删除值，涉及到释放结点内存，所以需要**两个辅助变量**，可能会涉及到头指针的修改。

    ```C++
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
    ```

