# 图的邻接表实现

1. 构造结构体

   - 图的邻接矩阵包含一个一维数组和一些链表结点；
     - 一维数组每个元素是一个结构体，其中包含两个元素：顶点的名称和指向链表结点的指针；
     - 每一个链表结点包含一个数据域，存放每一个结点在数组中的index；包含一个指向自己类型的指针，指向下一个结点。

   ```C++
   struct VNode //邻接表
   {
   	int m_index;
   	VNode* m_nextnode;
   };
   
   struct Alist//顶点数组
   {
   	char m_node;
   	VNode* m_next;
   };
   
   struct ALGraph//总的结构
   {
   	vector<Alist> vecs;
   	int vexnum = 0;//顶点数量
   	int arcnum = 0;//边的数量
   };
   ```

   

2.  创建图的邻接表

   1. 输入顶点数和边数：顶点数用来构造数组的大小；边数用来读入边的信息。
   2. 初始化数组，用resize()函数指定数组的大小；
   3. 输入边的信息，插入结点信息，注意插入结点的位置，如读入(v1,v2)，要将v1的信息插入v2结点后面。

   ```C++
   void CreatALGraph(ALGraph& G)
   {
   	cout <<"请输入顶点数和边数。"<<endl;
   	cin >> G.vexnum>>G.arcnum;
   	G.vecs.resize(G.vexnum);//初始化顶点数组;
   	for (int i = 0; i < G.vexnum; ++i)
   		G.vecs[i].m_next = nullptr;
   
   	cout << "输入顶点。" << endl;
   	for (int i = 0; i < G.vexnum; ++i)
   		cin >> G.vecs[i].m_node;
   
   	char v1, v2;
   	int Lhead, Ltail;
   	for (int i = 0; i < G.arcnum; ++i)
   	{
   		cout << "请输入头顶点、尾顶点。" << endl;
   		cin >> v1 >> v2; //读入（v1,v2）顶点对
   		Lhead = LocateVex(G, v1);
   		Ltail = LocateVex(G, v2);
   
   		VNode* p = new VNode();//v1结点的index，插入到v2结点后面
   		p->m_index = Lhead;
   		p->m_nextnode = G.vecs[Ltail].m_next;
   		G.vecs[Ltail].m_next = p;
   
   		VNode* q = new VNode();//v2结点的index，插入到v1结点后面
   		q->m_index = Ltail;
   		q->m_nextnode = G.vecs[Lhead].m_next;
   		G.vecs[Lhead].m_next = q;
   	}
   }
   
   int LocateVex(ALGraph& G,char& v)//寻找顶点的index
   {
   	for (int i = 0; i < G.vecs.size();++i)
   	{
   		if (v == G.vecs[i].m_node) return i;
   	}
   }
   ```

   

3.  深度优先搜索DFS：使用递归来实现

   - 需要传入一个visited的数组，来记录访问过的顶点。

   ```C++
   void GDFS(ALGraph& G, char& v, vector<int>& visited)
   {
   	cout << v << endl;
   	visited[LocateVex(G, v)] = 1;
   	VNode* p = nullptr;
   	p = G.vecs[LocateVex(G, v)].m_next;
   
   	while (p)
   	{
   		if (visited[p->m_index] == 0)
   			GDFS(G, G.vecs[p->m_index].m_node, visited);
   		p = p->m_nextnode;
   	}
   }
   ```

   

4.  广度优先搜索BFS

   - 需要传入一个visited的数组，来记录访问过的顶点；
   - 用一个队列来存放已经访问过的顶点。

   ```C++
   void GBFS(ALGraph& G, char& v)
   {
   	cout << "宽度优先搜索！" << endl;
   	vector<int> visited(G.vexnum, 0);
   	queue<int> qu;
   	qu.push(LocateVex(G,v));
   	visited[qu.front()] = 1;
   	VNode* p = nullptr;
   	while (!qu.empty())
   	{
   		cout << G.vecs[qu.front()].m_node<<endl;
   		p = G.vecs[qu.front()].m_next;
   		qu.pop();
   		while (p)
   		{
   			if (visited[p->m_index] == 0)
   			{
   				qu.push(p->m_index);
   				visited[p->m_index] = 1;
   			}
   			p = p->m_nextnode;
   		}
   	}
   }
   ```

   