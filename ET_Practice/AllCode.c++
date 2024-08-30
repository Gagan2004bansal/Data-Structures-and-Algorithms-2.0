// Q29.Take as input S, a string. Write a function that replaces every even character with the character having just higher ASCII code and every odd character with the character having just lower ASCII code. Print the value returned.
// #include <iostream>
// using namespace std;
// int main() {
//     string s;
//     cin>>s;

//     for(int i = 0; i<s.length(); i++){
//         if(i%2==0){
//             s[i] = s[i]+1;
//         }
//         else{
//             s[i] = s[i]-1;
//         }
//     }
//     cout << s << endl;

//     return 0;
// }

// Firstly we find all possible sub arrays

// #include <iostream>
// #include <vector>
// using namespace std;

// void Show(vector<int> temp)
// {
//     for(int i = 0; i<temp.size(); i++){
//         cout << temp[i] << " ";
//     }
//     cout << endl;
// }

// void Solve(vector<int> &arr, int index, vector<int> &temp,int ans, int sum, int &count )
// {
//     // Base Case
//     if (temp.size() != 0)
//     {
//         if(ans == sum){
//             Show(temp);
//             count++;
//         }
//     }

//     for (int i = index; i < arr.size(); i++)
//     {
//         temp.push_back(arr[i]);
//         ans += arr[i];
//         Solve(arr, i + 1, temp, ans, sum, count);
//         ans -= arr[i];
//         temp.pop_back();
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> arr;
//     for (int i = 0; i < n; i++)
//     {
//         int input;
//         cin >> input;
//         arr.push_back(input);
//     }

//     vector<int> temp;

//     int sum;
//     cin >> sum ;

//     int ans = 0;
//     int count = 0;
//     Solve(arr, 0, temp,ans, sum, count);

//     cout << "Possible Count : " << count << endl;
//     return 0;
// }

// Heapfiy the Code <--- MAX HEAP
// #include <bits/stdc++.h>
// using namespace std;
// void Heapify(vector<int> &arr, int n, int i){
//     int largest = i;
//     int left = 2 * i;
//     int right = 2 * i + 1;
//     if(left <= n && arr[largest] < arr[left]){
//         largest = left;
//     }
//     if(right <= n && arr[largest] < arr[right]){
//         largest = right;
//     }
//     if(largest != i){
//         swap(arr[largest], arr[i]);
//         Heapify(arr, n, largest);
//     }
// }
// int main() {
//     int n;
//     cin>>n;
//     a
//     vector<int> arr;
//     arr.push_back(-1);
//     for(int i = 0; i<n; i++){
//         int input;
//         cin>>input;
//         arr.push_back(input);
//     }

//     for(int i = n/2; i>0; i--){
//         Heapify(arr, n, i);
//     }

//     for(int i = 1; i<=n; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

// 8
// 2 4 1 7 10 9 5 3
// 10 7 9 3 4 1 5 2

// // Online C++ compiler to run C++ program online
// #include <iostream>
// #include <vector>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int data){
//         this -> data = data;
//         this -> left = NULL;
//         this -> right = NULL;
//     }
// };
// int positionFind(vector<int> &in, int ele, int inStart, int inEnd){
//     for(int i = inStart; i<=inEnd ; i++){
//         if(ele == in[i]){
//             return i;
//         }
//     }
//     return -1;
// }
// Node* Solve(vector<int> &in, vector<int> &pre, int n, int &preOrderINDEX, int inStart,int inEnd){
//     if(preOrderINDEX >= n || inStart > inEnd){
//         return NULL;
//     }

//     int ele = pre[preOrderINDEX++];
//     Node* root = new Node(ele);
//     int pos = positionFind(in, ele, inStart, inEnd);

//     root -> left = Solve(in, pre, n, preOrderINDEX, inStart, pos - 1);
//     root -> right = Solve(in, pre, n, preOrderINDEX, pos + 1, inEnd);

//     return root;
// }
// void PostOrder(Node* root){
//     if(root == NULL){
//         return;
//     }

//     PostOrder(root -> left);
//     PostOrder(root -> right);
//     cout << root -> data << " ";
// }
// int main() {
//     int n;
//     cin>>n;

//     vector<int> pre;
//     for(int i = 0; i<n; i++){
//         int input;
//         cin>>input;
//         pre.push_back(input);
//     }

//     vector<int> in;
//     for(int i = 0; i<n; i++){
//         int input;
//         cin>>input;
//         in.push_back(input);
//     }

//     int preOrderINDEX = 0;
//     Node* ans = Solve(in, pre, n, preOrderINDEX, 0, n-1);
//     PostOrder(ans);

//     return 0;
// }

// Q2. Number of Islands
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's
// (water), return the number of islands.

// #include <iostream>
// #include <vector>
// using namespace std;
// void DFS(int row, int col, vector<vector<int>> &arr, vector<vector<int>> &visited){

//     visited[row][col] = 1;
//     int delrow[] = {-1,0,1,0};
//     int delcol[] = {0,1,0,-1};

//     int m = arr.size();
//     int n = arr[0].size();

//     for(int i = 0; i<4 ; i++){
//         int nrow = row + delrow[i];
//         int ncol = col + delcol[i];
//         if(nrow >= 0 && ncol >= 0 && ncol < n && nrow < m && visited[nrow][ncol] == 0 && arr[nrow][ncol] == 1){
//             DFS(nrow, ncol, arr, visited);
//         }
//     }
// }
// int main() {

//     int m,n;
//     cin>>m>>n;

//     vector<vector<int>> arr;
//     for(int i = 0; i<m; i++){
//         vector<int> temp;
//         for(int j = 0; j<n; j++){
//             int input;
//             cin>>input;
//             temp.push_back(input);
//         }
//         arr.push_back(temp);
//     }

//     vector<vector<int>> vis(m, vector<int>(n, 0));
//     int count = 0;
//     for(int i = 0 ; i<m; i++){
//         for(int j = 0; j<n; j++){
//             if(arr[i][j] == 1 && vis[i][j] == 0){
//                 count++;
//                 DFS(i, j, arr, vis);
//             }
//         }
//     }

//     cout << count << endl;

//     return 0;
// }

// Q4. Trapping rain water
// Given N non-negative integers representing an elevation map where the width of each
// bar is 1, compute how much water it can trap after raining.

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> height;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        height.push_back(input);
    }

    int left = 0;
    int right = n - 1;
    int leftH = height[left];
    int rightH = height[right];
    int count = 0;
    while (left < right)
    {
        if (leftH < rightH)
        {
            left++;
            leftH = max(leftH, height[left]);
            count += leftH - height[left];
        }
        else
        {
            right--;
            rightH = max(rightH, height[right]);
            count += rightH - height[right];
        }
    }

    cout << count << endl;
    return 0;
}