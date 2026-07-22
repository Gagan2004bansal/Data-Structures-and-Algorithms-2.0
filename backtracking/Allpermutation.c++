#include <iostream>
#include <set>
#include <vector>

using namespace std;

void solve(int index, vector<int>&temp, vector< vector<int> > &st, vector<int>&arr, vector<int>&vis){

    if(index >= arr.size()){
        st.push_back(temp);
        return;
    }

    for(int i = 0; i<arr.size(); i++){
        if(vis[i] == 1 || (i > 0 && arr[i] == arr[i-1] && !vis[i-1])){
            continue;
        }

        vis[i] = 1;
        temp.push_back(arr[i]);
        solve(index + 1, temp, st, arr, vis);
        vis[i] = 0;
        temp.pop_back();
    }
}

int main(){

    int n;
    cin >> n;

    vector<int> arr(n, 0);

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector < vector<int> > st;
    vector<int> vis(n, 0);
    vector<int> temp;

    solve(0, temp, st, arr, vis);

    for(auto it : st){
        for(auto j : it){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}