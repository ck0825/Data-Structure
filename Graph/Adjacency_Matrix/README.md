# 图的邻接矩阵实现

1. 构造结构体

   - 邻接表是由一个一维数组和一个二维数组组成；一维数组存放结点信息；二维数组存放着边的信息；
   - **注意：在struct中，不能初始化容器，否则会被认为是成员函数，报错。**

   ```C++
   struct AMGraph
   {
   	vector<char> vexs;//结点数组
   	vector<vector<int>> arcs;//边数组
   	int vexnum = 0;//结点的数目
   	int arcnum = 0;//边的数目
   };
   ```

   

2.  创建图的邻接矩阵

   - 步骤：
     1. 先读入结点数和边数；结点数用来构建数组的大小，边数用来输入边的信息；
     2. 初始化数组时，用vector中的resize()函数来指定数组的大小；
     3. 输入边的信息：需要输入头顶点和尾顶点和权值，无权值的图默认为1，网络则为上面的权值。

   ```C++
   void CreatGraph(AMGraph& G)
   {
   	cout << "请输入顶点的个数和边的个数。" << endl;
   	cin >> G.vexnum>>G.arcnum; //输入结点数和边数
   	G.vexs.resize(G.vexnum);//初始化顶点矩阵，大小为结点数，每个元素为最大值
   	cout << "输入顶点。" << endl;
       
   	for (int i = 0; i < G.vexnum; ++i)
   		cin >> G.vexs[i];
   	G.arcs.resize(G.vexnum);//初始化邻接矩阵的行
   	for (int i = 0; i < G.vexnum; ++i)//初始化每一行的内容
   		G.arcs[i].resize(G.vexnum, 0);//默认不相连的结点权值为0
   
   	char v1, v2;
   	int weight,Lhead,Ltail;
   	for (int i = 0; i < G.arcnum; ++i)
   	{
   		cout << "请输入头顶点、尾顶点、权值。" << endl;
   		cin >> v1 >> v2 >> weight;//读入头顶点，尾顶点，权值的值
   		Lhead = LocateVex(G, v1);//查找头顶点的值
   		Ltail = LocateVex(G, v2);//查找尾顶点的值
   		G.arcs[Lhead][Ltail] = G.arcs[Ltail][Lhead] = weight;//对称矩阵
   	}
   }
   
   int LocateVex(AMGraph& G,char& v)
   {
   	for (int i = 0; i < G.vexs.size(); ++i)
   	{
   		if (v == G.vexs[i]) return i;
   	}
   }
   ```

   

3.   深度优先搜索

   - 深度优先搜素这里用的是递归来实现；
   - 需要传入一个visited的数组，来记录访问过的顶点。

   ```C++
   void GDFS(AMGraph& G,char& v,vector<int>& visited)
   {
   	
   	cout <<v<<endl;
   	visited[LocateVex(G, v)] = 1;
   	for (int i = 0; i < G.vexnum; ++i)
   	{
   		if ((G.arcs[LocateVex(G, v)][i] != 0) && (!visited[i]))
   			GDFS(G, G.vexs[i],visited);
   	}
   }
   ```

   