// 2025/3/3 19:00
//19:46
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge
{
    int l;
    int r;
    int weight;
    edge(int index1, int index2, int w) : l(index1), r(index2), weight(w) {}
};

class Kruskal
{
private:
    int vertex;
    int edgeNum;
    int ass = 0;        // 用于辅助遍历，每次找到可用节点就更新，减少遍历幅度
    vector<edge> graph; // 存放边
    vector<edge> MST;   // 最小生成树记载
    vector<int> father; // 并查集查询逻辑

public:
    // 生成函数
    Kruskal(int v, int e) : vertex(v), edgeNum(e)
    {
        father.resize(v + 1);
    }
    // 析构函数
    ~Kruskal()
    {
        cout << "Kruskal has stopped" << endl;
    }

    // 读入公路情况并完成排序
    void init()
    {
        // 获取边
        int size = edgeNum;
        while (size--)
        {
            int v1, v2, val;
            cin >> v1 >> v2 >> val;
            graph.emplace_back(edge(v1, v2, val));
        }
        sort(graph.begin(), graph.end(), [](const edge &a, const edge &b)
             { return a.weight < b.weight; });
        // 初始化并查集
        for (int i = 1; i <= vertex; i++)
        {
            father[i] = i; // 当前并查集每个元素都是一个集合，祖先即为自己
        }
    }

    //
    void buildMST()
    {
        // n-1即为连通图
        while ((MST.size() < (vertex - 1)) && (ass < edgeNum)) // 构成或者没找到
        {
            edge e = findValidedge();
            insert(e);
        }
    }

    // 找到合法的边（从权值从小到大，边需要满足边连接的两个端点不在一个集合内）
    edge findValidedge()
    {
        for (int i = ass; i < graph.size(); i++)
        {
            if (isdigit(graph[i]))
            {
                ass = i + 1;
                return graph[i];
            }
            else
            {
               
              continue;
            }
        }
        return  graph[0];
    }

    // 判断是否合法即判断两个端点在同一个集合内
    bool isdigit(const edge &e)
    {
        int v = find(e.l);
        int u = find(e.r);
        if (v != u)
            return true;
        else
            return false;
    }

    // 并查集查找工作
    int find(int index)
    {
        while (father[index] != index)
        {
            index = father[index];
        }
        return index;
    }

    // 向最小生成树中插入边，并更新并查集
    void insert(const edge &e)
    {
        // 插边
        MST.push_back(e);
        // 更新并查集
        int u = find(e.l);
        int v = find(e.r);
        father[u] = v;
    }

    // 输出MST的最小边权值之和
    void displayMST()
    {

        int sum = 0;
        for (int i = 0; i < MST.size(); i++)
        {
            sum += MST[i].weight;
        }
        cout << sum << endl;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;
    Kruskal my_kruskal(V, E);
    my_kruskal.init();
    my_kruskal.buildMST();
    my_kruskal.displayMST();
    return 0;
}