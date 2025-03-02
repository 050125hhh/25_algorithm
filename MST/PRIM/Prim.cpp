// 2025/3/1 16:00-
// ALan

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <climits>
using namespace std;

class PRIM
{
private:
    int vertex;
    int edge;
    int DEBUG=0;                    //调试命令
    vector<vector<int>> path_graph; // 路径矩阵
    vector<int> MST_Node;           // 节点计数
    vector<bool> IsNodeInMST;       // 节点是否已经在树上
    vector<int> min_dis;            // 最小权值（到树的距离）

public:
    // 构造函数
    PRIM(int v, int e) : vertex(v), edge(e)
    {
        path_graph.resize(v + 1, (vector<int>(v + 1, INT_MAX)));
        min_dis.resize(v + 1, INT_MAX);
        IsNodeInMST.resize(v + 1, false);
    }
    // 析构函数
    //~PRIM(){cout<<"PRIM has been destroyed."<<endl;}

    // 初始化路径矩阵
    void initPath()
    {
        int round = edge;
        while (edge--)
        {
            int src;
            int dst;
            int val;
            cin >> src >> dst >> val;
            path_graph[src][dst] = val;
            path_graph[dst][src] = val;
        }
    }

    // 构建MST(找离树最近的节点，将其加入树中，更新最短距离矩阵，再寻找直到MST_Nodes数量等于节点数)
    void buildMST()
    {
        while (MST_Node.size() < vertex)
        {
            // 首节点加入
            if (MST_Node.size() == 0)
            {
               
                min_dis[1] = 0; // 根节点
                addIntoMST(1);
            }
            else
            {
                int index = findClosestNode();
                if(index==-1){
                    cout<<"No more available node"<<endl;
                }
                addIntoMST(index);
            }
        }
    }

    // 向树中补充新节点（传入的是节点的编号）并更新当前最短路径矩阵
    void addIntoMST(int index)
    {
        if(DEBUG){
            cout<<"This time add node "<<index<<",val is "<<min_dis[index]<<endl;
        }
        MST_Node.push_back(index);
        IsNodeInMST[index] = true;
        // 更新最短路径

        for (int i = 1; i <= vertex; i++)
        {
            if (path_graph[index][i] < min_dis[i]&&!IsNodeInMST[i])
            {   

                min_dis[i] = path_graph[index][i]; // 更新路径（可达节点到树的最短距离）
            }
        }
    }

    // 找到当前距离树最近的节点
    int findClosestNode()
    {

        int newIndex = -1;
        int dis = INT_MAX;
        for (int i = 1; i <= vertex; i++)
        {
            if (min_dis[i] < dis && !IsNodeInMST[i])
            { // 当且仅当距离近且未在树中可以作为备选节点
                newIndex = i;
                dis = min_dis[i];
            }
        }
        return newIndex;
    }

    // 展示当前MST的权值和
    void displayMST()
    {

        int sum = 0;
        if(DEBUG){
        for(int i=1;i<=MST_Node.size();i++){
            cout<<min_dis[i]<<" ";
        }
        cout<<endl;
        }
        for (int i = 1; i <= MST_Node.size(); i++)
        {
            sum += min_dis[i];
        }
        cout << sum << endl;
    }

    void debuging()
    {
    }
};

int main()
{

    int v, e;
    cin >> v >> e;
    PRIM myprim(v, e);
    // 初始化路径矩阵
    myprim.initPath();
    // 开始构建MST
    myprim.buildMST();
    // 输出当前最短路径
    myprim.displayMST();
    return 0;
}