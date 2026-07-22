#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool canFormSubstring(const string &mainString, const string &subString, int start, int &remainingDeletions) {
    int tempDeletions = remainingDeletions;
    int i = start, j = 0;

    while (i < mainString.size() && j < subString.size()) {
        if (mainString[i] == subString[j]) {
            j++;
        } else {
            tempDeletions--;
        }
        i++;

        if (tempDeletions < 0) {
            return false;
        }
    }

    if (j == subString.size()) {
        remainingDeletions = tempDeletions;
        return true;
    }
    return false;
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
    int mainIndex = 0;

    while (mainIndex < mainString.size()) {
        bool matched = false;
        string bestMatch;
        int bestMatchLength = 0;
        int bestMatchDeletions = remainingDeletions;

        for (const string &substring : substrings) {
            int tempDeletions = remainingDeletions;
            if (canFormSubstring(mainString, substring, mainIndex, tempDeletions)) {
                if (substring.size() > bestMatchLength) {
                    bestMatch = substring;
                    bestMatchLength = substring.size();
                    bestMatchDeletions = tempDeletions;
                }
            }
        }

        if (!bestMatch.empty()) {
            result += bestMatch;
            remainingDeletions = bestMatchDeletions;
            mainIndex += bestMatchLength;
            matched = true;
        }

        if (!matched) {
            if (remainingDeletions > 0) {
                remainingDeletions--;
                mainIndex++;
            } else {
                break;
            }
        }
    }

    cout << result << endl;

    return 0;
}