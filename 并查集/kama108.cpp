// 2025/3/4 13:56
//14:13
#include <iostream>
#include <vector>

using namespace std;

struct edge
{
    int l;
    int r;
    edge() : l(-1), r(-1) {}
    edge(int src, int dst) : l(src), r(dst) {}
};

class UnionSet
{
private:
    int vertex;
    int edgeNum;
    vector<int> father;
    edge res;

public:
    UnionSet(int v, int e) : vertex(v), edgeNum(e)
    {
        father.resize(v + 1);
        for (int i = 1; i <= v; i++)
        {
            father[i] = i;
        }
    }

    ~UnionSet() {}

    void init()
    {
        int size = edgeNum;
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
                res = edge(src, dst);
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

    void display()
    {
        if ((res.l == -1) && (res.r == -1))
        {
            cout << "Valid tree.No cut" << endl;
            return;
        }
        cout << res.l << ' ' << res.r << endl;
    }
};

int main()
{
    int N;
    cin >> N;
    UnionSet myUnionset(N, N);
    myUnionset.init();
    myUnionset.display();

    return 0;
}
