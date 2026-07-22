#include<iostream>
#include<unordered_map>
#include<queue>
#include <vector>
#include<set>
using namespace std;
void bfs(unordered_map<int,vector<int> > &adjlist,vector<int>&ans,int node, int n){
    queue<int>q;
    q.push(node);
    vector<bool> visited(n, false);
    visited[node] = true;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        // store  frontnode into ans
        ans.push_back(frontNode);

        // trvase all neighbour of frontnode

        for(auto i : adjlist[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    
    unordered_map<int, vector<int> > adjlist;

    int n, m, u , v;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> u;
        cin >> v;
        adjlist[u].push_back(v);
    }

    vector<int>ans;
    bfs(adjlist ,ans, 0, n);
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}