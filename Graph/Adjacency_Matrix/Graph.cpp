#include <iostream>
#include <vector>
using namespace std;

const int MVnum = 100;
struct AMGraph
{
	vector<char> vexs;
	vector<vector<int>> arcs;
	int vexnum = 0;
	int arcnum = 0;
};
void CreatGraph(AMGraph& G);
int LocateVex(AMGraph& G, char& v);
void GDFS(AMGraph& G, char& v, vector<int>& visited);

int main()
{
	char seach = 'A';
	AMGraph G;
	CreatGraph(G);
	vector<int> visited(G.vexnum, 0);//设置访问标志
	GDFS(G, seach,visited);
	return 0;
}

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