#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

// undirected graph
template<typename T>
class graph
{
    public:
        graph(int);

        // build methods
        void add_node(T);
        void add_edge(T,T);
        void add_edge(T,T,int);

        //debug method
        void print_list();

        //Adding functionality for unweighted graph -> code is in -> functionality1 file
        vector<T> get_unweighted_path(T,T);
        bool is_reachable(T,T);
        map<T,int> get_unweighted_distance(T);
        int get_unweighted_distance_btw(T,T);
        map<T,T> get_bfs_tree(T);

        //connected component file
        int no_of_connected_components();
        vector<vector<T>> get_connected_components();

        //bipartite file
        bool is_bipartite();
        vector<vector<T>> get_bipartition();

    protected:

    private:
        int no_of_nodes;
        int no_of_edges;
        vector<vector<pair<int,int>>> adj_list;
        vector<T> node_value;
        unordered_map<T,int> hash_value;
        vector<pair<int,int>> bfs(int);
};
template class graph<int>;
template class graph<char>;
template class graph<string>;
#endif // GRAPH_H_INCLUDED
