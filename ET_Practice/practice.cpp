#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    string name;
    cin >> name;

    long long int phoneNo;
    cin >> phoneNo;

    string address;
    cin >> address;
    // getline(cin, address);

    cout << "--------- Bill Slip ---------";
    cout << endl;
    cout << "Sr No. " << n;
    cout << endl;
    cout << "Name : " << name << endl;
    cout << "Phone No. : " << phoneNo << endl;
    cout << "Address : " << address << endl;
    cout << endl;

    cout << "Total Amount : 650" << endl;

    return 0;
}