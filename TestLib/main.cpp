#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    graph<char> g(7);
    for(char i='a';i<'h';i++)
        g.add_node(i);
    g.add_edge('a','b');
    g.add_edge('a','c');
    g.add_edge('a','e');
    g.add_edge('c','b');
    g.add_edge('c','e');
    g.add_edge('c','d');
    //g.add_edge('e','d');
    g.add_edge('g','f');

    cout<<g.is_bipartite()<<endl;
    vector<vector<char>> ans=g.get_bipartition();
    for(auto v:ans)
    {
        for(auto ch:v)
            cout<<ch<<" ";
        cout<<endl;
    }
}
