#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
vector<vector<string> > solve(vector<string> &wordList, string startWord, string LastWord)
{
    unordered_set<string> st(wordList.begin(), wordList.end());
    vector<vector<string> > ans;
    queue<vector<string> > q;

    vector<string> temp;
    temp.push_back(startWord);
    q.push(temp);
    vector<string> usedOnLevel;
    usedOnLevel.push_back(startWord);
    int level = 0;

    while (!q.empty())
    {
        vector<string> vec = q.front();
        q.pop();

        if (vec.size() > level)
        {
            level++;
            for (auto it : usedOnLevel)
            {
                st.erase(it);
            }
            usedOnLevel.clear();
        }

        string word = vec.back();

        if (word == LastWord)
        {
            if (ans.size() == 0)
            {
                ans.push_back(vec);
            }
            else if (ans[0].size() == vec.size())
            {
                ans.push_back(vec);
            }
        }

        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.count(word) > 0)
                {
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }

    return ans;
}
int main()
{
    int n;
    cin >> n;

    vector<string> wordList;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        wordList.push_back(str);
    }

    string startWord;
    cout << "Enter StartWord : ";
    cin >> startWord;

    string endWord;
    cout << "Enter endWord : ";
    cin >> endWord;

    vector<vector<string> > ans = solve(wordList, startWord, endWord);

    cout << "All shortest Path \n";
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}