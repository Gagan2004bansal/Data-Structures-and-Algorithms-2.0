#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
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

int main(){
    
    int n;
    cout << "Enter No. of Vertices : ";
    cin >> n;
    
    int m;
    cout << "Enter No. of Edges : ";
    cin >> m;
    
    unordered_map<int, vector<int>> adj;
    for(int i = 0; i<m; i++){
        int u , v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Traversal 
    
    // BFS(n, m, adj);
    // DFS(n, m, adj);
    
    // Detect Cycle in an Unidirected Cycle 
    // DetectCycle(n, m, adj);
    
    // Topological Sort
    TopologicalSort(n, m, adj);
    
    return 0;
}