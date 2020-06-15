#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct VNode //�ڽӱ�
{
	int m_index;
	VNode* m_nextnode;
};

struct Alist//��������
{
	char m_node;
	VNode* m_next;
};


struct ALGraph//�ܵĽṹ
{
	vector<Alist> vecs;
	int vexnum = 0;//��������
	int arcnum = 0;//�ߵ�����

};

void CreatALGraph(ALGraph& G);
int LocateVex(ALGraph& G, char& v);
void GDFS(ALGraph& G, char& v, vector<int>& visited);
void GBFS(ALGraph& G, char& v);

int main()
{
	ALGraph G;
	CreatALGraph(G);
	char search = 'A';
	vector<int> visited(G.vexnum, 0);
	GDFS(G, search, visited);
	GBFS(G, search);
	return 0;
}

void CreatALGraph(ALGraph& G)
{
	cout <<"�����붥�����ͱ�����"<<endl;
	cin >> G.vexnum>>G.arcnum;
	G.vecs.resize(G.vexnum);//��ʼ����������;
	for (int i = 0; i < G.vexnum; ++i)
		G.vecs[i].m_next = nullptr;

	cout << "���붥�㡣" << endl;
	for (int i = 0; i < G.vexnum; ++i)
		cin >> G.vecs[i].m_node;

	char v1, v2;
	int Lhead, Ltail;
	for (int i = 0; i < G.arcnum; ++i)
	{
		cout << "������ͷ���㡢β���㡣" << endl;
		cin >> v1 >> v2; //���루v1,v2�������
		Lhead = LocateVex(G, v1);
		Ltail = LocateVex(G, v2);

		VNode* p = new VNode();//v1����index�����뵽v2������
		p->m_index = Lhead;
		p->m_nextnode = G.vecs[Ltail].m_next;
		G.vecs[Ltail].m_next = p;

		VNode* q = new VNode();//v2����index�����뵽v1������
		q->m_index = Ltail;
		q->m_nextnode = G.vecs[Lhead].m_next;
		G.vecs[Lhead].m_next = q;
	}
}

int LocateVex(ALGraph& G,char& v)//Ѱ�Ҷ����index
{
	for (int i = 0; i < G.vecs.size();++i)
	{
		if (v == G.vecs[i].m_node) return i;
	}
}

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

void GBFS(ALGraph& G, char& v)
{
	cout << "�������������" << endl;
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