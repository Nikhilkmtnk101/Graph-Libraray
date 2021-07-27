#include "graph.h"

template<typename T>
graph<T>::graph(int no_of_nodes)
{
    this->no_of_nodes = no_of_nodes;
    adj_list.resize(no_of_nodes);
}

template<typename T>
void graph<T>::add_node(T value)
{
    hash_value[value]=node_value.size();
    node_value.push_back(value);
}

template<typename T>
void graph<T>::add_edge(T node1, T node2)
{
    int index1=hash_value[node1],index2=hash_value[node2];
    adj_list[index1].push_back({index2,1});
    adj_list[index2].push_back({index1,1});
}

template<typename T>
void graph<T>::add_edge(T node1, T node2, int weight)
{
    int index1=hash_value[node1],index2=hash_value[node2];
    adj_list[index1].push_back({index2,weight});
    adj_list[index2].push_back({index1,weight});
}
