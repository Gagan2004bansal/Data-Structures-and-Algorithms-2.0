#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <limits.h>
#include <algorithm>
using namespace std;
void BFS(int n, int m, unordered_map<int, vector<int>> &adj){
    
    int src = 0;
    vector<int> visited(n, false);
    queue<int> q;
    
    q.push(src);
    visited[src] = true;

    cout << "BFS Traversal of Graph" << endl;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        cout << node << " ";
        
        for(auto nbr : adj[node]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr] = true;
            }
        }
    }
    
    cout << endl;
}
void dfsCall(int node, vector<int>&visited, unordered_map<int, vector<int>> &adj){
    visited[node] = true;
    cout << node << " ";
    
    for(auto nbr : adj[node]){
        if(!visited[nbr]){
            dfsCall(nbr, visited, adj);
        }
    }
}

void DFS(int n, int m, unordered_map<int, vector<int>> &adj){
    vector<int> visited(n, false);
    
    int node = 0;
    cout << "DFS Traversal of Graph" << endl;
    dfsCall(node, visited, adj);
}

bool dfsDetect(int node, int parent, vector<bool>&visited, unordered_map<int, vector<int>>&adj){
    
    visited[node] = true;
    
    for(auto nbr : adj[node]){
        if(!visited[nbr]){
            bool Check = dfsDetect(nbr, node, visited, adj);
            if(Check){
                return true;
            }
        }
        else if(nbr != parent){
            return true;
        }
    }
    
    return false;
}

bool bfsDetect(int src, int n, vector<int>&visited,unordered_map<int, vector<int>> &adj){
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto nbr : adj[node]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr] = true;
                parent[nbr] = node;
            }
            else if(visited[nbr] == true && nbr != parent[node]){
                return true;
            }
        }
    }
    
    return false;
}

void DetectCycle(int n, int m, unordered_map<int, vector<int>> &adj){
    
    // Detecting Cycle Using DFS 
    
    cout << "Cycle Detection in UniDirected Graph" << endl;
    
    // DFS 
    int parent = -1;
    vector<bool> visited(n, false);
    bool ans = false;
    for(int node = 0; node<n; node++){
        if(!visited[node]){
             ans = dfsDetect(node, parent, visited, adj);
            if(ans){
                cout << "Cycle Detected" << endl; 
                break;
            }
        }
    }
    if(!ans){
        cout << "Cycle Not Detected : DFS" << endl;
    }
    
    // BFS
    vector<int> visited2(n, false);
    bool ans2 = false;
    for(int i = 0; i<n; i++){
        if(!visited2[i]){
            ans2 = bfsDetect(i, n, visited2, adj);
            if(ans){
                cout << "Cycle Detected" << endl; 
                break;
            }
        }
    }
    if(!ans2){
        cout << "Cycle Not Detected : BFS" << endl;
    }
}

void DFStopoSort(int node, stack<int>&st, vector<bool>&visited, unordered_map<int, vector<int>> &adj){
    
    visited[node] = true;
    
    for(auto nbr : adj[node]){
        if(!visited[nbr]){
            DFStopoSort(nbr, st, visited, adj);
        }
    }
    
    st.push(node);
}

void TopologicalSort(int n, int m, unordered_map<int, vector<int>> &adj){
    
    cout << "Topological Sort" << endl;
    
    // DFS 
    stack<int> st;
    vector<bool> visited(n, false);
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            DFStopoSort(i, st, visited, adj);
        }
    }
    
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    
    cout << endl;
    
    // BFS : Kahn Algorithm 
    
    vector<int> Indegree(n, 0);
    for(int i = 0; i<n; i++){
        for(auto nbr : adj[i]){
            Indegree[nbr]++;
        }
    }
    
    queue<int> q;
    for(int i = 0; i<n; i++){
        if(Indegree[i] == 0){
            q.push(i);
        }
    }
    
    
    
    while(!q.empty()){
        int node = q.front();
        
        cout << q.front() << endl;
        q.pop();
        
        cout << node << " ";
        
        for(auto nbr : adj[node]){
            Indegree[nbr]--;
            if(Indegree[nbr] == 0){
                q.push(nbr);
            }
        }
    }
    
    cout << endl;
}

bool DFSDetect(int node, vector<bool>&path, vector<bool>&visited, unordered_map<int , vector<int>> &adj){
    
    path[node] = true;
    visited[node] = true;
    
    for(auto nbr : adj[node]){
        if(path[nbr]){
            return true;
        }
        else if(!visited[nbr]){
            if(DFSDetect(nbr, path, visited, adj)){
                return true;
            }
        }
    }
    
    path[node] = false;
    return false;
}

void DetectCycle2(int n, int m, unordered_map<int, vector<int>>&adj){
    
    vector<bool> visited(n, false);
    vector<bool> path(n, false);
    
    // DPS 
    bool ans1 = false;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            ans1 = DFSDetect(i, path, visited, adj);
            if(ans1){
                cout << "Loop Detected" << endl;
                break;
            }
        }
    }
    if(!ans1){
        cout << "Loop Not Detected" << endl;
    }

    // BFS
    vector<int> Indegree(n, 0);
    for(int i = 0; i<n; i++){
        for(auto nbr : adj[i]){
            Indegree[nbr]++;
        }
    }
    
    queue<int> q;
    for(int i = 0; i<n; i++){
        if(Indegree[i] == 0){
            q.push(i);
        }
    }
    
    int count = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;
        
        for(auto nbr : adj[node]){
            Indegree[nbr]--;
            if(Indegree[nbr] == 0){
                q.push(nbr);
            }
        }
    }
    
    if(count == n){
        cout << "No Loop Detect" << endl;
    }
    else{
        cout << "Loop Detect" << endl;
    }
}

int dfsBiparite(int node, vector<int> &color, unordered_map<int, vector<int>> &adj){
    
    for(auto nbr : adj[node]){
        if(color[nbr] == -1){
            color[nbr] = (color[node] + 1) % 2;
            int call = dfsBiparite(nbr, color, adj);
            if(call == 0){
                return 0;
            }
        }
        else{
            if(color[nbr] == color[node]){
                return 0;
            }
        }
    }
    
    return 1;
}

void BipariteGraph(int n, int m, unordered_map<int, vector<int>> &adj){
    
    cout << "Biparite Graph or 2 Coloring Algorithm" << endl;
    // DFS 
    vector<int> color(n, -1);
    int ans1 = 0;
    for(int i = 0; i<n; i++){
        if(color[i] == -1){
            color[i] = 0;
            ans1 = dfsBiparite(i, color, adj);
            if(!ans1){
                cout << "Not Biparite Graph -- DFS" << endl;
                break;
            }
        }
    }
    if(ans1 == 1){
        cout << "Biparite Graph -- DFS" << endl;
    }
    // BFS
    
    queue<int> q;
    vector<int> Color(n, -1);
    for(int i = 0; i<n; i++){
        if(Color[i] == -1){
            q.push(i);
            Color[i] = 0;
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                
                for(auto nbr : adj[node]){
                    if(Color[nbr] == -1){
                        Color[nbr] = (Color[node] + 1)%2;
                        q.push(nbr);
                    }
                    else if(Color[nbr] == Color[node]){
                        cout << "Not Biparite Graph -- BFS" << endl; 
                        return;
                    }
                }
            }
        }
    }
    
    cout << "Biparite Graph -- DFS" << endl;
}

void ShortPathUniGraph(int n, int m, unordered_map<int, vector<int>>& adj){
    
    // Shortest Path using BFS 
    vector<int> visited(n, false);
    vector<int> distance(n, INT_MAX);
    
    int src;
    cout << "Enter Source : ";
    cin >> src;
    
    queue<int> q;
    q.push(src);
    visited[src] = 1;    
    distance[src] = 0;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        
        for(auto nbr : adj[node]){
            if(!visited[nbr] && distance[nbr] > distance[node] + 1 ){
                distance[nbr] = 1 + distance[node];
                visited[nbr] = 1;
                q.push(nbr);
            }
        }
    }
    
    for(int i = 0; i<n; i++){
        if(distance[i] == INT_MAX){
            distance[i] = -1;
        }
    }
    
    cout << "Distance from src " << src << " : ";
    for(int i = 0; i<n; i++){
        cout << distance[i] << " ";
    }
}

void shortPath(int n, int m, unordered_map<int, vector<int>>&adj){
    
    int src, dest;
    cout << "Enter Source : ";
    cin >> src;
    
    cout << "Enter Destination : ";
    cin >> dest;
    
    vector<int> distance(n, INT_MAX);
    vector<int> parent(n, 0);
    vector<int> visited(n, false);
    
    distance[src] = 0;
    visited[src] = 1;
    parent[src] = -1;
    
    queue<int> q;
    q.push(src);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto nbr : adj[node]){
            if(!visited[nbr] && distance[nbr] > distance[node] + 1){
                distance[nbr] = 1 + distance[node];
                q.push(nbr);
                visited[nbr] = 1;
                parent[nbr] = node;
            }
        }
    }
    
    vector<int> path;
    while(dest != -1){
        path.push_back(dest);
        dest = parent[dest];
    }
    
    reverse(path.begin(), path.end());
    
    cout << "Path from " << src << " to " << dest << " : " ;
    for(int i = 0; i<path.size(); i++){
        cout << path[i] << " ";
    }
}

void TopoSortDAG(int node, stack<int>&st, vector<int>&vis, unordered_map<int, vector<pair<int, int>>> &adj){
    
    vis[node] = true;
    
    for(auto nbr : adj[node]){
        if(!vis[nbr.first]){
            TopoSortDAG(nbr.first, st, vis, adj);
        }
    }
    
    st.push(node);
}

void ShortPathinDAG(int n, int m, unordered_map<int, vector<pair<int, int>>> &adj){
    
    // Firstly we find topo sort
    stack<int> st;
    vector<int> vis(n, false);
    for(int i = 0; i<n; i++){
        if(!vis[i]){
            TopoSortDAG(i, st, vis, adj);
        }
    }
    
    int src = 0;
    vector<int> distance(n, INT_MAX);
    distance[src] = 0;
    
    while(!st.empty()){
        int node = st.top();
        st.pop();
        
        if(distance[node] != INT_MAX){
            for(auto nbr : adj[node]){
                if(distance[nbr.first] > distance[node] + nbr.second){
                    distance[nbr.first] = distance[node] + nbr.second;
                }
            }
        }
    }
    
    for(int i = 0; i<n; i++){
        if(distance[i] == INT_MAX){
            distance[i] = -1;
        }
    }
    
    for(int i = 0; i<n; i++){
        cout << distance[i] << " ";   
    }
}

int main(){
    
    int n;
    cout << "Enter No. of Vertices : ";
    cin >> n;
    
    int m;
    cout << "Enter No. of Edges : ";
    cin >> m;
    
    // For Unidirected Unweighted Graph
    unordered_map<int, vector<int> > adj;
    for(int i = 0; i<m; i++){
        int u , v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    
    // For Directed Weighted Graph
    // unordered_map<int, vector<pair<int,int>>> adj;
    // for(int i = 0; i<m; i++){
    //     int u,v,w;
    //     cin >> u >> v >> w;
        
    //     adj[u].push_back(make_pair(v, w));
    // }
    
    // Traversal 
    
    // BFS(n, m, adj);
    // DFS(n, m, adj);
    
    // Detect Cycle in an Unidirected Cycle 
    // DetectCycle(n, m, adj);
    
    // Topological Sort
    // TopologicalSort(n, m, adj);
    
    // Detect Cycle in a Directed Graph
    // DetectCycle2(n, m, adj);
    
    // Biparite Graph or 2 Color Algorithms 
    // BipariteGraph(n, m, adj);

    // Shortest Path in Unidirected Graph
    // ShortPathUniGraph(n, m, adj);
    
    // Find Path of Shortest Path
    // shortPath(n, m, adj);
    
    // Shortest Path in Directed Acyclic Graph
    // ShortPathinDAG(n, m, adj);
    
    return 0;
}