//并查集就是用来处理判断元素是否位于集合中的数据结构，不考虑路径的具体过程，只考虑是否在集合中

#include <iostream>
#include <vector>

using namespace std;

class unionSet
{
private:
    int DEBUG=0;
    int vertex;
    int edge;
    
    vector<int> father;

public:
    unionSet(int v, int e) : edge(e), vertex(v)
    {
        father.resize(v + 1);
        // 初始化并查集(father数组是记录节点的连接情况的)
        
        for (int i = 1; i <= v; i++)
        {
            father[i] = i;
        }
    }

    /*~unionSet()
    {
        cout << "unionSet has been destroyed." << endl;
    }*/

    void init()
    {
        // 根据情况修改并查集

        int size = edge;
        while (size--)
        {
            int src, dst;
            cin >> src >> dst;
            int u = find(src);
            int v = find(dst);
            if (u != v)
            {
                father[u] = v;
            }
            else
            {
                // 读入下一条边
            }
        }
    }

    int find(int index)
    {
        while (index != father[index])
        {
            index = father[index];
        }
        return index;
        
    }

    bool isInSet()
    {
        int src,dst;
        cin>>src>>dst;

        int u = find(src);
        int v = find(dst);
        if (u == v){
        cout<<"1"<<endl;
            return true;
        }
        else{
            cout<<"0"<<endl;
            return false;
        }
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    unionSet myunionset(N,M);
    myunionset.init();
    myunionset.isInSet();
    return 0;
}
