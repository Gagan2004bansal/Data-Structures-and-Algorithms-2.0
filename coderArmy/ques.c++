#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

pair<string, int> tryMatch(string &mainString,string &subString, int start, int remainingDeletions) {
    int deletionsUsed = 0;
    string matched = "";
    int i = start, j = 0;
  
    while (i < mainString.size() && j < subString.size()) {
        if (mainString[i] == subString[j]) {
            matched += mainString[i];
            i++;
        } else {
            deletionsUsed++;
        }
        j++;

        if (deletionsUsed > remainingDeletions) {
            pair<string, int> p = make_pair("", INT_MAX); 
            return p;
        }
    }
    pair<string, int> p =  make_pair(matched, deletionsUsed);
    return p;
}

int main() {
    int n, k;
    cin >> n;

    vector<string> substrings(n);
    for (int i = 0; i < n; ++i) {
        cin >> substrings[i];
    }

    string mainString;
    cin >> mainString;
    cin >> k;

    string result = "";
    int remainingDeletions = k;
    int mainIndex = 0;

    while (mainIndex < mainString.size()) {
        
        string bestMatch = "";
        int bestDeletions = INT_MAX;
        int bestMatchLength = 0;

        for (string &substring : substrings) {
            pair<string, int> match = tryMatch(mainString, substring, mainIndex, remainingDeletions);
            if (match.second < bestDeletions || match.first.length() > bestMatchLength) {
                bestMatch = match.first;
                bestDeletions = match.second;
                bestMatchLength = match.first.size();
            }
        }

        if (!bestMatch.empty()) {
            result += bestMatch;
            remainingDeletions -= bestDeletions;
            mainIndex += bestMatchLength;
        } else {
            if (remainingDeletions >= 0) {
                mainIndex++;  
            } else {
                break; 
            }
        }
    }

    if(result != mainString && result.length() > 0){
        cout << "Impossible";
    }
    else if(result == mainString){
        cout << "Possible";
    }
    else{
        cout << "Nothing";
    }

    return 0;
}