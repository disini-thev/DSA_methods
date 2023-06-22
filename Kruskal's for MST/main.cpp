#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int findP(int x, vector<int>& parents){
    if (parents[x] == -1){
        return x;
    }
    return findP(parents[x], parents);
}

void Kruskal (int V, vector<vector<int>>& Graph){

    //update the edges : edges {weight,{u,v}}
    vector<pair<int, pair<int,int>>> edges;
    for (int i=0; i<V; i++){
        for(int j=i+1; j<V; j++){
            if (Graph[i][j]!=0){
                edges.push_back({Graph[i][j],{i,j}});
            }
        }
    }

    //sort the edges
    sort(edges.begin(), edges.end());

    //a vector for storing the parents
    vector<int> parents(V,-1);

    //MST weight
    int weight=0;
    vector<pair<int,int>> MSTedges;

    for (auto edge : edges){
        int w=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;

        //finding the parents of both the nodes
        int pu=findP(u,parents);
        int pv=findP(v, parents);

        if (pu==pv)   continue;
        //else unite them
        parents[pu]=pv;

        weight+=w;
        MSTedges.push_back({u,v});
        cout<<u<<" -> "<<v<<endl;
    }
    cout<<weight<<endl;
}



int main()
{
    vector<vector<int>> adjacencyMatrix = {
        {0, 3, 5, 2, 0, 0, 0, 0},
        {3, 0, 4, 2, 0, 0, 0, 0},
        {5, 4, 0, 3, 0, 0, 0, 0},
        {2, 2, 3, 0, 7, 0, 0, 0},
        {0, 0, 0, 7, 0, 3, 5, 2},
        {0, 0, 0, 0, 3, 0, 4, 2},
        {0, 0, 0, 0, 5, 4, 0, 3},
        {0, 0, 0, 0, 2, 2, 3, 0}
    };

    Kruskal(8,adjacencyMatrix);
    return 0;
}
