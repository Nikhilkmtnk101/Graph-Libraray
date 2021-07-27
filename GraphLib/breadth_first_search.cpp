#include "graph.h"
#include<queue>

template<typename T>
vector<pair<int,int>> graph<T> :: bfs(int source)
{
    vector<pair<int,int>> r_vec(no_of_nodes,{INT_MAX,-1});
    queue<int> Q;
    Q.push(source);
    r_vec[source]={0,source};
    while(!Q.empty())
    {
        int i=Q.front();
        Q.pop();
        for(int j=0;j<(int)adj_list[i].size();j++)
        {
            int index=adj_list[i][j].first;
            if(r_vec[index].second==-1)
            {
                r_vec[index].second=i;
                r_vec[index].first=r_vec[i].first+1;
                Q.push(index);
            }
        }
    }
    return r_vec;
}
