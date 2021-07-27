#include "graph.h"
#include <queue>
// return all set of connected components
template<typename T>
vector<vector<T>> graph<T> :: get_connected_components()
{
    vector<vector<T>> r_vec;
    vector<bool> vis(no_of_nodes,false);
    for(int i=0;i<no_of_nodes;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            vector<T> temp;
            queue<int> Q;
            Q.push(i);
            temp.push_back(node_value[i]);
            while(!Q.empty())
            {
                int j=Q.front(); Q.pop();
                for(int k=0;k<(int)adj_list[j].size();k++)
                {
                    int index=adj_list[j][k].first;
                    if(!vis[index])
                    {
                        vis[index]=true;
                        temp.push_back(node_value[index]);
                        Q.push(index);
                    }
                }
            }
            r_vec.push_back(temp);
        }
    }
    return r_vec;
}

// returns no of connected components
template<typename T>
int graph<T> :: no_of_connected_components()
{
    return get_connected_components().size();
}
