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
	vector<int> visited(G.vexnum, 0);//���÷��ʱ�־
	GDFS(G, seach,visited);
	return 0;
}

void CreatGraph(AMGraph& G)
{
	cout << "�����붥��ĸ����ͱߵĸ�����" << endl;
	cin >> G.vexnum>>G.arcnum; //���������ͱ���
	G.vexs.resize(G.vexnum);//��ʼ��������󣬴�СΪ�������ÿ��Ԫ��Ϊ���ֵ
	cout << "���붥�㡣" << endl;

	for (int i = 0; i < G.vexnum; ++i)
		cin >> G.vexs[i];
	G.arcs.resize(G.vexnum);//��ʼ���ڽӾ������
	for (int i = 0; i < G.vexnum; ++i)//��ʼ��ÿһ�е�����
		G.arcs[i].resize(G.vexnum, 0);//Ĭ�ϲ������Ľ��ȨֵΪ0

	char v1, v2;
	int weight,Lhead,Ltail;
	for (int i = 0; i < G.arcnum; ++i)
	{
		cout << "������ͷ���㡢β���㡢Ȩֵ��" << endl;
		cin >> v1 >> v2 >> weight;//����ͷ���㣬β���㣬Ȩֵ��ֵ
		Lhead = LocateVex(G, v1);//����ͷ�����ֵ
		Ltail = LocateVex(G, v2);//����β�����ֵ
		G.arcs[Lhead][Ltail] = G.arcs[Ltail][Lhead] = weight;//�Գƾ���
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