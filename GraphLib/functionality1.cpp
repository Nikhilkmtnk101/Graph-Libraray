#include "graph.h"
#include <algorithm>

// Return path from source to destination
template<typename T>
vector<T> graph<T> :: get_unweighted_path(T source,T destination)
{
    int src=hash_value[source],dst=hash_value[destination];
    // call breadth first search
    vector<pair<int,int>> v_bfs=bfs(src);
    vector<T> r_vec;
    // check if there is a path between source and destination or NOT
    if(v_bfs[dst].second == -1)
        return r_vec;
    int temp=dst;
    while(v_bfs[temp].second!=temp)
    {
        r_vec.push_back(node_value[temp]);
        temp=v_bfs[temp].second;
    }
    r_vec.push_back(source);
    reverse(r_vec.begin(),r_vec.end());
    return r_vec;
}

// return true if there is a path from source to destination
template<typename T>
bool graph<T> :: is_reachable(T source,T destination)
{
    int src=hash_value[source],dst=hash_value[destination];
    // call breadth first search
    vector<pair<int,int>> v_bfs=bfs(src);
    return v_bfs[dst].second == -1 ? false : true;
}

// return vector containing distance of every node from source in unweighted graph
template<typename T>
map<T,int> graph<T> :: get_unweighted_distance(T source)
{
    int src=hash_value[source];
    // call breadth first search
    vector<pair<int,int>> v_bfs=bfs(src);
    map<T,int> r_map;
    for(int i=0;i<no_of_nodes;i++)
        r_map[node_value[i]]=v_bfs[i].first;
    return r_map;
}

// returns unweighted distance between source and destination
template<typename T>
int graph<T> :: get_unweighted_distance_btw(T source, T destination)
{
    int src=hash_value[source],dst=hash_value[destination];
    // call breadth first search
    vector<pair<int,int>> v_bfs=bfs(src);
    return v_bfs[dst].first;
}

// returns a map of nodes and its parent
template<typename T>
map<T,T> graph<T> :: get_bfs_tree(T source)
{
    int src=hash_value[source];
    // call breadth first search
    vector<pair<int,int>> v_bfs=bfs(src);
    map<T,T> r_map;
    for(int i=0;i<no_of_nodes;i++)
    {
        if(v_bfs[i].second != -1)
            r_map[node_value[i]]=node_value[v_bfs[i].second];
    }
    return r_map;
}
