#include "graph.h"
#include <queue>

// returns two set of bipartition
// its unique only when the graph is connected
template<typename T>
vector<vector<T>> graph<T> :: get_bipartition()
{
    vector<int> color(no_of_nodes,0);
    vector<T> red,blue;
    for(int i=0;i<no_of_nodes;i++)
    {
        if(color[i]==0)
        {
            color[i]=1;
            queue<int> Q;
            Q.push(i);
            red.push_back(node_value[i]);
            while(!Q.empty())
            {
                int j=Q.front(); Q.pop();
                for(int k=0;k<(int)adj_list[j].size();k++)
                {
                    int index=adj_list[j][k].first;
                    if(color[index]==0 && color[j]==1)
                    {
                        color[index]=2;
                        blue.push_back(node_value[index]);
                        Q.push(index);
                    }
                    else if(color[index]==0 && color[j]==2)
                    {
                        color[index]=1;
                        red.push_back(node_value[index]);
                        Q.push(index);
                    }
                    else if(color[index]==color[j])
                    return {};
                }
            }
        }
    }
    return {red,blue};
}

// return true if graph is bipartite
template<typename T>
bool graph<T> :: is_bipartite()
{
    return get_bipartition().size() != 0 ? true : false;
}
