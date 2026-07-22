#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

// Check if a substring can be formed starting at a given position with deletions allowed
pair<string, int> canFormSubstring(const string &mainString, const string &subString, size_t start, int remainingDeletions) {
    int tempDeletions = remainingDeletions;
    size_t i = start, j = 0;
    string matchedStr = "";

    while (i < mainString.size() && j < subString.size()) {
        if (mainString[i] == subString[j]) {
            matchedStr += mainString[i];
            j++;
        } else {
            tempDeletions--;
        }
        i++;

        if (tempDeletions < 0) {
            return {"", remainingDeletions}; // Return an empty match if deletions exceed the limit
        }
    }

    if (j == subString.size()) {
        return {matchedStr, tempDeletions}; // Return the matched string and remaining deletions
    }
    return {"", remainingDeletions}; // Return empty if the substring couldn't be fully matched
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

    string result;
    int remainingDeletions = k;
    size_t mainIndex = 0;

    while (mainIndex < mainString.size()) {
        string bestMatch;
        int bestMatchDeletions = remainingDeletions;
        size_t bestMatchLength = 0;

        for (const string &substring : substrings) {
            auto [matchedStr, tempDeletions] = canFormSubstring(mainString, substring, mainIndex, remainingDeletions);
            if (!matchedStr.empty() && matchedStr.size() > bestMatchLength) {
                bestMatch = matchedStr;
                bestMatchLength = matchedStr.size();
                bestMatchDeletions = tempDeletions;
            }
        }

        if (!bestMatch.empty()) {
            result += bestMatch;
            remainingDeletions = bestMatchDeletions;
            mainIndex += bestMatchLength; // Skip the matched substring in mainString
        } else {
            if (remainingDeletions > 0) {
                remainingDeletions--;
                mainIndex++; // Skip a single character due to deletion
            } else {
                break; // Stop processing if no deletions are left
            }
        }
    }

    cout << result << endl;

    return 0;
}
