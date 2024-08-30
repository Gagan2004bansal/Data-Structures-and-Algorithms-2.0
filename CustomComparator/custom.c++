// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// bool compare(int a, int b){
//     if(a > b){
//         return 1;
//     }
//     return 0;
// }
// int main(){
//     int n;
//     cin >> n;

//     vector<int> arr;
//     for(int i = 0; i<n; i++){
//         int input;
//         cin >> input;
//         arr.push_back(input);
//     }

//     sort(arr.begin(), arr.end(), compare); // sort in desecding order

//     for(int i = 0; i<n; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }


// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;

//     vector<int> arr;
//     for(int i = 0; i<n; i++){
//         int input;
//         cin >> input;
//         arr.push_back(input);
//     }

//     // Comparator using lammbda function

//     sort(arr.begin(), arr.end(), [] (int a, int b){
//         if(a > b){
//             return true;   // yhe bhe sort krega decreasing order me
//         }
//         return false;
//     }); 

//     for(int i = 0; i<n; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

// Sort array by frequency 
// link : https://www.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency-1587115621/1

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
    int n;
    cin >> n;

    vector<int> arr;
    for(int i = 0; i<n; i++){
        int input;
        cin >> input;
        arr.push_back(input);
    }

    unordered_map<int,int> freq;

    sort(arr.begin(), arr.end(), [&freq] (int a, int b){
        if(freq[a] > freq[b]){
            return 1;
        }
        if(freq[a] == freq[b]){
            if(a < b){
                return 1;
            }
        }
        return 0;
    }); 

    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}