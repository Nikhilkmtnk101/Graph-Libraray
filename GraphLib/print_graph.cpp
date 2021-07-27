#include "graph.h"

template<typename T>
void graph<T> :: print_list()
{
    for(int i=0;i<adj_list.size();i++)
    {
        cout<<i<<"-> ";
        for(int j=0;j<adj_list[i].size();j++)
            cout<<adj_list[i][j].first<<" ";
        cout<<endl;
    }
}
