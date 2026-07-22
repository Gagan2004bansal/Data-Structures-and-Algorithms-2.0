// // Finding minimum spanning Tree
// // Note here solution is done on 0-based indexing
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <limits.h>
// using namespace std;
// int main()
// {
//     int n;
//     cout << "Enter number of nodes : ";
//     cin >> n;

//     int m;
//     cout << "Enter number of edges : ";
//     cin >> m;

//     // Creating adajency Matrix
//     unordered_map<int, vector<pair<int, int> > > adj;

//     for (int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;

//         adj[u].push_back(make_pair(v, w));
//         adj[v].push_back(make_pair(u, w));
//     }

//     // Initializing Vector
//     vector<int> key(n);
//     vector<bool> mst(n);
//     vector<int> parent(n);

//     for (int i = 0; i < n; i++)
//     {
//         key[i] = INT_MAX;
//         parent[i] = -1;
//         mst[i] = false;
//     }

//     parent[0] = -1;
//     key[0] = 0;

//     for (int i = 0; i < n; i++)
//     {
//         // finding minimum value
//         int mini = INT_MAX;
//         int u;

//         for (int v = 0; v < n; v++)
//         {
//             if (mst[v] == false && key[v] < mini)
//             {
//                 u = v;
//                 mini = key[v];
//             }
//         }

//         // Marking mst to true
//         mst[u] = true;

//         // then Finding it adjacent nodes
//         for (auto it : adj[u])
//         {
//             int v = it.first;
//             int w = it.second;

//             if (mst[v] == false && w < key[v])
//             {
//                 parent[v] = u;
//                 key[v] = w;
//             }
//         }
//     }

//     int sum = 0;
//     for (int i = 0; i < key.size(); i++)
//     {
//         sum += key[i];
//     }

//     cout << "Spaning Tree weight is " << sum << endl;

//     // if it said to make spaning Tree
//     vector<pair<int, pair<int, int> > > result;
//     for (int i = 0; i < n; i++)
//     {
//         result.push_back(make_pair(i, make_pair(parent[i], key[i])));
//     }

//     for (auto i : result)
//     {
//         int u = i.first;
//         int v = i.second.first;
//         int w = i.second.second;

//         cout << u << " " << v << " " << w << endl;
//     }

//     return 0;
// }

// Currently T.C is N^2

// Use MinHeap to find miniumn to reduce T.C to nlogn
// Do this when you revise Heap

// below i solution 
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <limits.h>


using namespace std;

void solve(int n,int m, unordered_map<int, vector<pair<int,int> > > &adj){
    
    vector<int> key(n+1, INT_MAX);
    vector<int> mst(n+1, 0);
    vector<int> parent(n+1, -1);
    
    int src = 0; // if not given
    key[src] = 0;
    
    for(int i = 0; i<n; i++){
        int u, mini = INT_MAX;
        
        // step 1 find minimum
        for(int i = 0; i<n; i++){
            if(mst[i] == 0 && key[i] < mini){
                u = i;
                mini = key[i];
            } 
        }
        
        // step 2 mark mst to true
        mst[u] = 1;
        
        // step 3 : Go for adjacent nbr
        for(auto nbr : adj[u]){
            int v = nbr.first;
            int w = nbr.second;
            
            if(mst[v] == 0 && w < key[v]){
                key[v] = w;
                parent[v] = u;
            }
        }
    }
    
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += key[i];
    }
    cout << sum << endl;
    
    // to make minimum spanning tree 
    vector<pair<int, pair<int,int> > > mstlist;
    for(int i = 0; i<n; i++){
        mstlist.push_back(make_pair(i, make_pair(parent[i], key[i])));
    }
    
    
    for(auto it : mstlist){
        cout << it.first << " " << it.second.first <<  " " << it.second.second << endl;
    }
}

void solveusingPQ(int n,int m, unordered_map<int, vector<pair<int,int> > > &adj){
    
    vector<int> key(n+1, INT_MAX);
    vector<int> mst(n+1, 0);
    vector<int> parent(n+1, -1);

    priority_queue<pair<int,int>, vector< pair<int,int> > , greater< pair<int,int> > > pq;
    
    int src = 0;
    pq.push(make_pair(0, src));  // we start from 0 bcoz we need always minimum weight edge node
    key[src] = 0;
    
    while(!pq.empty()){
        
        // find min
        int u = pq.top().second;
        pq.pop();
        
        if(mst[u] == 1){
            continue;
        }
        
        // step 2 mark them true
        mst[u] = true;
        
        // step 3 : Go for adjancent nbr
        for(auto nbr : adj[u]){
            int v = nbr.first;
            int w = nbr.second;
            
            if(mst[v] == 0 && w < key[v]){
                parent[v] = u;
                key[v] = w;
                pq.push(make_pair(key[v], v));
            }
        }
        
    }
    
    
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += key[i];
    }
    cout << sum << endl;
    
    // to make minimum spanning tree 
    vector<pair<int, pair<int,int> > > mstlist;
    for(int i = 0; i<n; i++){
        mstlist.push_back(make_pair(i, make_pair(parent[i], key[i])));
    }
    
    
    for(auto it : mstlist){
        cout << it.first << " " << it.second.first <<  " " << it.second.second << endl;
    }
}

// Testcase 
// 5
// 6
// 0 1 2
// 0 3 6 
// 1 3 8
// 1 2 3
// 1 4 5
// 2 4 7

int main(){

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<pair<int, int> > > adj;
    for(int i = 0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    
    solveusingPQ(n, m, adj);
    cout << endl;
    solve(n, m, adj);   

    return 0;
}