// Hashmaps --> type of data structure IMPORTANT
// Time Complexity and space complexity of insertion , deletion and searching is O(1)

// Start with a Question --> Maximum Occuring character in string
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{
    // Creation of map
    unordered_map<string, int> m;

    // insertion in map
    // type 1
    pair<string, int> p = make_pair("Gagan", 3);
    m.insert(p);

    // type 2
    pair<string, int> q("Bansal", 2);
    m.insert(q);

    // type 3
    m["mera"] = 1;

    // what will happen
    m["mera"] = 2;

    // Searching
    cout << m["mera"] << endl;
    cout << m.at("Bansal") << endl;
    // cout << m.at("Tohana") << endl; // gives error as this entry is not present
    // cout << m["Tohana"] << endl; // these give no error as insert entry with 0 then it prints

    // Size
    cout << "Size : " << m.size() << endl;

    // to check presence  gives 1 or 0
    cout << m.count("Gagan") << endl;

    // erase
    m.erase("mera");
    // cout << "Size : " << m.size() << endl;

    /// Iteration in Map
    // for (auto i : m)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }

    // Searching Using Find
    if (m.find("Gagan") != m.end())
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    unordered_map<string, int>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}