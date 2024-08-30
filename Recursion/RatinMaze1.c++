// #include <iostream>
// using namespace std;
// int row, col;
// int Solution(int i, int j)
// {
//     // Base Condition
//     if (i > row - 1 && j > col - 1)
//     {
//         return 1;
//     }

//     return Solution(i + 1, j) + Solution(i, j + 1);
// }
// int main()
// {
//     cin >> row >> col;
//     cout << Solution(0, 0) << endl;
//     return 0;
// }

#include <iostream>
using namespace std;

int row, col;
void Solution(int i, int j, string str, int &count)
{
    // Base Condition
    if (i > row - 1 && j > col - 1)
    {
        cout << str << endl;
        count++;
        return;
    }

    if (i < row)
    {
        Solution(i + 1, j, str + 'R', count);
    }
    if (j < col)
    {
        Solution(i, j + 1, str + 'D', count);
    }
}

int main()
{
    cin >> row >> col;
    int count = 0;
    Solution(0, 0, "", count);
    cout << count << endl;
    return 0;
}
