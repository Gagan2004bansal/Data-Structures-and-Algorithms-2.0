// Next Greater Element
// #include <iostream>
// #include <stack>
// #include <vector>
// using namespace std;
// void solve(int n, vector<int> &arr, vector<int> &vec)
// {
//     stack<int> st;
//     for (int i = n - 2; i >= 0; i--)
//     {
//         st.push(arr[i]);
//     }

//     for (int i = n - 1; i >= 0; i--)
//     {
//         if (st.empty())
//         {
//             vec.push_back(-1);
//         }
//         else if (arr[i] < st.top())
//         {
//             vec.push_back(st.top());
//         }
//         else if (arr[i] >= st.top())
//         {
//             while (!st.empty() && arr[i] >= st.top())
//             {
//                 st.pop();
//             }
//             if (st.empty())
//             {
//                 vec.push_back(-1);
//             }
//             else
//             {
//                 vec.push_back(st.top());
//             }
//         }
//         st.push(arr[i]);
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

//     vector<int> res;
//     solve(n, arr, res);
//     for (int i = 0; i < res.size(); i++)
//     {
//         cout << res[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

// Postfix Evaluation
// #include <iostream>
// #include <stack>
// using namespace std;
// bool isdigit(char ch)
// {
//     return (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9');
// }
// int solve(string str)
// {
//     stack<int> st;
//     for (int i = 0; i < str.length(); i++)
//     {
//         if (isdigit(str[i]))
//         {
//             st.push(str[i] - '0');
//         }
//         else
//         {
//             int val1 = st.top();
//             st.pop();
//             int val2 = st.top();
//             st.pop();

//             switch (str[i])
//             {
//             case '+':
//                 st.push(val1 + val2);
//                 break;
//             case '-':
//                 st.push(val2 - val1);
//                 break;
//             case '*':
//                 st.push(val2 * val1);
//                 break;
//             case '/':
//                 st.push(val2 / val1);
//                 break;
//             }
//         }
//     }

//     return st.top();
// }
// int main()
// {
//     string str;
//     cin >> str;

//     cout << "Postfix Evaluation : " << solve(str) << endl;
//     return 0;
// }

// Prefix Evaluation
// #include <iostream>
// #include <stack>
// using namespace std;
// bool isdigit(char ch)
// {
//     return (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9');
// }
// int solve(string str)
// {
//     stack<int> st;
//     for (int i = str.length() - 1; i >= 0; i--)
//     {
//         if (isdigit(str[i]))
//         {
//             st.push(str[i] - '0');
//         }
//         else
//         {
//             int val1 = st.top();
//             st.pop();
//             int val2 = st.top();
//             st.pop();

//             switch (str[i])
//             {
//             case '+':
//                 st.push(val1 + val2);
//                 break;
//             case '-':
//                 st.push(val2 - val1);
//                 break;
//             case '*':
//                 st.push(val2 * val1);
//                 break;
//             case '/':
//                 st.push(val2 / val1);
//                 break;
//             }
//         }
//     }

//     return st.top();
// }
// int main()
// {
//     string str;
//     cin >> str;

//     cout << "Postfix Evaluation : " << solve(str) << endl;
//     return 0;
// }

// Infix to Postfix Conversion
// #include <iostream>
// #include <stack>
// using namespace std;
// int precedence(char ch)
// {
//     if (ch == '+' || ch == '-')
//     {
//         return 1;
//     }
//     else if (ch == '/' || ch == '*')
//     {
//         return 2;
//     }
//     else if (ch == '^')
//     {
//         return 3;
//     }
//     else
//     {
//         return -1;
//     }
// }
// void infixToPostfix(string str)
// {
//     stack<char> st;
//     string result;

//     for (int i = 0; i < str.length(); i++)
//     {
//         char ch = str[i];
//         if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
//         {
//             result += ch;
//         }
//         else if (ch == '(')
//         {
//             st.push('(');
//         }
//         else if (ch == ')')
//         {
//             while (st.top() != '(')
//             {
//                 result += st.top();
//                 st.pop();
//             }
//             st.pop();
//         }
//         else
//         {
//             while (!st.empty() && precedence(ch) <= precedence(st.top()))
//             {
//                 result += st.top();
//                 st.pop();
//             }
//             st.push(ch);
//         }
//     }

//     while (!st.empty())
//     {
//         result += st.top();
//         st.pop();
//     }

//     cout << result << endl;
// }
// int main()
// {
//     string str;
//     cin >> str;

//     infixToPostfix(str);

//     return 0;
// }

// // "a+b*(c^d-e)^(f+g*h)-i"
// // abcd^e-fgh*+^*+i-

// Infix to Prefix

// #include <iostream>
// #include <stack>
// using namespace std;
// int precedence(char ch)
// {
//     if (ch == '+' || ch == '-')
//     {
//         return 1;
//     }
//     else if (ch == '/' || ch == '*')
//     {
//         return 2;
//     }
//     else if (ch == '^')
//     {
//         return 3;
//     }
//     else
//     {
//         return -1;
//     }
// }
// string infixToPostfix(string str)
// {
//     str = '(' + str + ')';
//     stack<char> st;
//     string result;

//     for (int i = 0; i < str.length(); i++)
//     {
//         char ch = str[i];
//         if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
//         {
//             result += ch;
//         }
//         else if (ch == '(')
//         {
//             st.push('(');
//         }
//         else if (ch == ')')
//         {
//             while (st.top() != '(')
//             {
//                 result += st.top();
//                 st.pop();
//             }
//             st.pop();
//         }
//         else
//         {
//             while (!st.empty() && precedence(ch) < precedence(st.top()))
//             {
//                 result += st.top();
//                 st.pop();
//             }
//             st.push(ch);
//         }
//     }

//     while (!st.empty())
//     {
//         result += st.top();
//         st.pop();
//     }

//     return result;
// }
// int main()
// {
//     string str;
//     cin >> str;

//     reverse(str.begin(), str.end());

//     for (int i = 0; i < str.length(); i++)
//     {
//         if (str[i] == ')')
//         {
//             str[i] = '(';
//             i++;
//         }
//         else if (str[i] == '(')
//         {
//             str[i] = ')';
//             i++;
//         }
//     }

//     string ans = infixToPostfix(str);

//     reverse(ans.begin(), ans.end());

//     cout << ans << endl;

//     return 0;
// }

// // ++x/*yzwu

// Stock Span Problem

// #include <iostream>
// #include <stack>
// #include <vector>
// using namespace std;
// int solve(int data, stack<pair<int, int> > &st)
// {
//     int count = 1;
//     while (!st.empty() && st.top().first <= data)
//     {
//         count += st.top().second;
//         st.pop();
//     }

//     st.push(make_pair(data, count));
//     return count;
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

//     vector<int> res;
//     stack<pair<int, int> > st;
//     for (int i = 0; i < n; i++)
//     {
//         res.push_back(solve(arr[i], st));
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout << res[i] << " ";
//     }

//     return 0;
// }

// Largest Area in Histogram
#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>
using namespace std;
void nextSmallerFind(vector<int> &heights, vector<int> &nextSmaller, int n){
    stack<int> st;
    st.push(-1);
    for(int i = n-1; i>=0; i--){
        int curr = heights[i];
        while(st.top()!=-1 && heights[st.top()] >= curr){
            st.pop();
        }
        nextSmaller[i] = st.top();
        st.push(i);
    }
}
void prevSmallerFind(vector<int> &heights, vector<int> &prevSmaller, int n){
    stack<int> st;
    st.push(-1);
    for(int i = 0; i<n; i++){
        int curr = heights[i];
        while(st.top()!= -1 && heights[st.top()] >= curr){
            st.pop();
        }
        prevSmaller[i] = st.top();
        st.push(i);
    }
}
void solve(vector<int> &heights, int n){
    vector<int> nextSmaller(n);
    vector<int> prevSmaller(n);
    
    nextSmallerFind(heights, nextSmaller, n);
    prevSmallerFind(heights, prevSmaller, n);
    
    int area = INT_MIN;
    for(int i = 0; i<heights.size(); i++){
        int length = heights[i];
        if(nextSmaller[i] == -1){
            nextSmaller[i] = n;
        }
        int breadth = nextSmaller[i] - prevSmaller[i] - 1;
        int currArea = length * breadth;
        area = max(area, currArea);
    }
    
    cout << area << endl;
}
int main() {
    int n;
    cin>>n;
    
    vector<int> heights;
    for(int i = 0; i<n; i++){
        int input;
        cin>>input;
        heights.push_back(input);
    }
    
    solve(heights, n);
    
    return 0;
}