// // Smallest Range Covering elements from k lists ::: LEETCODE 632 HARD
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <limits>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     int row;
//     int col;

//     Node(int data, int i, int j)
//     {
//         this->data = data;
//         row = i;
//         col = j;
//     }
// };
// class Compare
// {
// public:
//     bool operator()(Node *a, Node *b)
//     {
//         return a->data > b->data;
//     }
// };
// vector<int> Solution(vector<vector<int> > &nums)
// {
//     int mini = INT_MAX;
//     int maxi = INT_MIN;

//     priority_queue<Node *, vector<Node *>, Compare> minHeap;
//     int k = nums.size();

//     for (int i = 0; i < k; i++)
//     {
//         int element = nums[i][0];
//         mini = min(mini, element);
//         maxi = max(maxi, element);
//         minHeap.push(new Node(element, i, 0));
//     }

//     int start = mini, end = maxi;
//     while (!minHeap.empty())
//     {
//         Node *temp = minHeap.top();
//         minHeap.pop();

//         mini = temp->data;
//         if (maxi - mini < end - start)
//         {
//             start = mini;
//             end = maxi;
//         }

//         if (temp->col + 1 < nums[temp->row].size())
//         {
//             maxi = max(maxi, nums[temp->row][temp->col + 1]);
//             minHeap.push(new Node(nums[temp->row][temp->col + 1], temp->row, temp->col + 1));
//         }
//         else
//         {
//             break;
//         }
//     }

//     vector<int> ans;
//     ans.push_back(start);
//     ans.push_back(end);
//     return ans;
// }
// int main()
// {
//     int n1 = 4;
//     vector<int> arr1;
//     for (int i = 0; i < n1; i++)
//     {
//         int input;
//         cin >> input;
//         arr1.push_back(input);
//     }

//     int n2 = 3;
//     vector<int> arr2;
//     for (int i = 0; i < n2; i++)
//     {
//         int input;
//         cin >> input;
//         arr2.push_back(input);
//     }

//     int n3 = 3;
//     vector<int> arr3;
//     for (int i = 0; i < n3; i++)
//     {
//         int input;
//         cin >> input;
//         arr3.push_back(input);
//     }

//     vector<vector<int> > nums;
//     nums.push_back(arr1);
//     nums.push_back(arr2);
//     nums.push_back(arr3);

//     vector<int> result = Solution(nums);
//     for (int i = 0; i < 2; i++)
//     {
//         cout << result[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    int row;
    int col;

    Node(int data, int i, int j)
    {
        this->data = data;
        row = i;
        col = j;
    }
};
class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
vector<int> Solution(vector<vector<int> > &mainArr)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;
    priority_queue<Node *, vector<Node *>, Compare> pq;
    int k = mainArr.size();

    for (int i = 0; i < k; i++)
    {
        int element = mainArr[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        pq.push(new Node(element, i, 0));
    }

    int start = mini, end = maxi;

    while (!pq.empty())
    {
        Node *temp = pq.top();
        pq.pop();

        mini = temp->data;

        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        if (temp->col + 1 < mainArr[temp->row].size())
        {
            maxi = max(maxi, mainArr[temp->row][temp->col + 1]);
            pq.push(new Node(mainArr[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }
        else
        {
            break;
        }
    }

    vector<int> ans;
    ans.push_back(start);
    ans.push_back(end);

    return ans;
}
int main()
{
    vector<int> arr1;
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr1.push_back(input);
    }

    int m = 4;
    vector<int> arr2;
    for (int i = 0; i < m; i++)
    {
        int input;
        cin >> input;
        arr2.push_back(input);
    }

    int p = 4;
    vector<int> arr3;
    for (int i = 0; i < p; i++)
    {
        int input;
        cin >> input;
        arr3.push_back(input);
    }

    vector<vector<int> > mainArr;
    mainArr.push_back(arr1);
    mainArr.push_back(arr2);
    mainArr.push_back(arr3);

    vector<int> res = Solution(mainArr);
    for (int i = 0; i < 2; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}