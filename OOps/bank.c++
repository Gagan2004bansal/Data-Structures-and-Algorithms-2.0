#include <iostream>
#include <string>
using namespace std;
class Customer
{
public:
    string name;
    int Account_no;
    void setCustomer(string name, int Account_no)
    {
        this->name = name;
        this->Account_no = Account_no;
    }
};
class Account : public Customer
{
public:
    string Account_type;
    double balance;
    void setAccountType(string Account_type, double balance)
    {
        this->Account_type = Account_type;
        this->balance = balance;
    }
};
class RBI : public Account
{
public:
    double interset_rate;
    RBI()
    {
        interset_rate = 0.04;
    }
    void InterestRate(double Rate)
    {
        this->interset_rate = Rate / 100;
    }
};
class SBI : public RBI
{
public:
    void sbiCustomer(string name, string Account_type, int Account_no, double balance)
    {
        setCustomer(name, Account_no);
        setAccountType(Account_type, balance);
        double n;
        cout << "Enter interest Rate : ";
        cin >> n;
        if (n == 4)
        {
            RBI();
        }
        else
        {
            InterestRate(n);
        }
    }
    void Display()
    {
        cout << "Balance after " << interset_rate << " Interest : " << balance + (balance * interset_rate) << endl;
    }

    void FullDisplay()
    {
        cout << "Welcome to SBI BANk" << endl;
        cout << "Customer Name : " << name << endl;
        cout << "Account No : " << Account_no << endl;
        cout << "Account Type : " << Account_type << endl;
        cout << "Balance : " << balance << endl;
        cout << "RBI Interest Rate : " << interset_rate << endl;
        cout << "Balance after Interst : " << balance + (balance * interset_rate) << endl;
    }
};
class ICICI : public RBI
{
public:
    void ICICICustomer(string name, string account_type, int Account_no, double balance)
    {
        setCustomer(name, Account_no);
        setAccountType(Account_type, balance);
        double n;
        cout << "Enter interest Rate : ";
        cin >> n;
        if (n == 4)
        {
            RBI();
        }
        else
        {
            InterestRate(n);
        }
    }
    void Display()
    {
        cout << "Balance after " << interset_rate << " Interest : " << balance + (balance * interset_rate) << endl;
    }

    void FullDisplay()
    {
        cout << "Welcome to ICICI BANK" << endl;
        cout << "Customer Name : " << name << endl;
        cout << "Account No : " << Account_no << endl;
        cout << "Account Type : " << Account_type << endl;
        cout << "Balance : " << balance << endl;
        cout << "RBI Interest Rate : " << interset_rate << endl;
        cout << "Balance after Interst : " << balance + (balance * interset_rate) << endl;
    }
};
int main()
{
    string bank_name;
    cout << "Enter Bank Name : ";
    cin >> bank_name;
    if (bank_name == "SBI")
    {
        SBI s1;
        s1.sbiCustomer("Gagan", "Saving", 1558, 1000);
        s1.FullDisplay();
    }
    else if (bank_name == "ICICI")
    {
        ICICI i1;
        i1.ICICICustomer("Gagan", "Saving", 1558, 2000);
        i1.FullDisplay();
    }
    return 0;
}
