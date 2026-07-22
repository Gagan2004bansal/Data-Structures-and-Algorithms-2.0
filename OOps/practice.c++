// #include <iostream>
// #include <string>
// using namespace std;
// class Electronics
// {
// public:
//     string name;
//     float price;
//     int quantity;
//     void Products(string name, float price, int quantity)
//     {
//         this->name = name;
//         this->price = price;
//         this->quantity = quantity;
//     }
//     int operator+(Electronics &e2)
//     {
//         return this->quantity * this->price + e2.quantity * e2.price;
//     }
// };
// int main()
// {
//     Electronics e1, e2, e3;
//     e1.Products("Laptop", 50000.0, 2);
//     e2.Products("Mobile Phone", 10000.0, 5);
//     cout << "Total Amount : " << (e1 + e2) << endl;
//     return 0;
// }

// // #include <iostream>
// // #include <strixng>
// // using namespace std;
// // class SecretAgent
// // {
// // public:
// //     SecretAgent()
// //     {
// //     }
// //     SecretAgent()
// //     {
// //     }
// //     ~SecretAgent
// //     {
// //         cout << "Destroyed\n";
// //     }
// // };
// // int main()
// // {

// //     return 0;
// // }

// #include <iostream>
// #include <string>
// using namespace std;
// class Account
// {
// public:
//     double amount;
//     string accNo;
//     Account(double amount, string accNo)
//     {
//         this->amount = amount;
//         this->accNo = accNo;
//     }
//     void display()
//     {
//         cout << "Account No : " << accNo << endl;
//         cout << "Total Amount : " << amount << endl;
//     }
//     void widthrawl(double balance)
//     {
//         if (balance > amount)
//         {
//             cout << "Can't Withdrawal" << endl;
//         }
//         else
//         {
//             amount = amount - balance;
//             cout << "successfully withdrawal\n";
//         }
//     }
//     void Deposit(double pp)
//     {
//         amount = amount + pp;
//     }
// };
// int main()
// {
//     Account a1;
//     a1.amount = 1000;
//     a1.accNo = "Gagan";
//     int n;
//     cout << "enter queries size : ";
//     cin >> n;
//     int i = 0;
//     while (i < n)
//     {
//         int No;
//         cin >> No;
//         int bal, ol;
//         double r;
//         if (No == 1)
//         {
//             cin >> bal;
//             if (bal == 0)
//             {
//                 a1.display();
//             }
//             if (bal == 1)
//             {
//                 cin >> r;
//                 widthrawl(r);
//             }
//         }
//         // if (No == 0)
//         // {

//         // }
//         i++;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;
// class Complex
// {
// private:
//     int real, imag;

// public:
//     Complex()
//     {
//         real = 0;
//         imag = 0;
//     }
//     Complex(int r, int i)
//     {
//         real = r;
//         imag = i;
//     }
//     void print()
//     {
//         cout << real << " + " << imag << "i" << endl;
//     }
//     Complex operator+(Complex c)
//     {
//         Complex temp;
//         temp.real = real + c.real;
//         temp.imag = imag + c.imag;
//         return temp;
//     }
// };
// int main()
// {
//     Complex c1(4, 5);
//     Complex c2(2, 3);
//     Complex c3(2, 3);
//     Complex c4;

//     c4 = c1 + c2 + c3;
//     c4.print();
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
// class Electronics
// {
// public:
//     string name;
//     float price;
//     int quantity;
//     void Products(string name, float price, int quantity)
//     {
//         this->name = name;
//         this->price = price;
//         this->quantity = quantity;
//     }
//     int operator+(Electronics &e2)
//     {
//         return this->quantity * this->price + e2.quantity * e2.price;
//     }
// };
// int main()
// {
//     Electronics e1, e2, e3;
//     e1.Products("Laptop", 50000.0, 2);
//     e2.Products("Mobile Phone", 10000.0, 5);
//     cout << "Total Amount : " << (e1 + e2) << endl;
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
// class SecretAgent
// {
// public:
//     SecretAgent()
//     {
//     }
//     SecretAgent()
//     {
//     }
//     ~SecretAgent
//     {
//         cout << "Destroyed\n";
//     }
// };
// int main()
// {

//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
// class Account
// {
// public:
//     double amount;
//     string accNo;
//     Account(double amount, string accNo)
//     {
//         this->amount = amount;
//         this->accNo = accNo;
//     }
//     void display()
//     {
//         cout << "Account No : " << accNo << endl;
//         cout << "Total Amount : " << amount << endl;
//     }
//     void widthrawl(double balance)
//     {
//         if (balance > amount)
//         {
//             cout << "Can't Withdrawal" << endl;
//         }
//         else
//         {
//             amount = amount - balance;
//             cout << "successfully withdrawal\n";
//         }
//     }
//     void Deposit(double pp)
//     {
//         amount = amount + pp;
//     }
// };
// int main()
// {
//     Account a1(1000,"Gagan");
//     int n;
//     cout << "enter queries size : ";
//     cin >> n;
//     int i = 0;
//     while (i < n)
//     {
//         int No;
//         cin >> No;
//         int bal, ol;
//         double r;
//         if (No == 1)
//         {
//             cin >> bal;
//             if (bal == 0)
//             {
//                 a1.display();
//             }
//             if (bal == 1)
//             {
//                 cin >> r;
//                 a1.widthrawl(r);
//             }
//         }
//         if (No == 0)
//         {
//             cin>>ol;
//             a1.display();
//         }
//         i++;
//     }
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
// class OperatorOverloading
// {
// public:
//     string name;
//     float price;
//     int quantity;
//     OperatorOverloading()
//     {
//         price = 0;
//         quantity = 0;
//     }
//     OperatorOverloading(string name, float price, int quantity)
//     {
//         this->name = name;
//         this->price = price;
//         this->quantity = quantity;
//     }
//     OperatorOverloading operator+(OperatorOverloading c)
//     {
//         OperatorOverloading temp;
//         temp.quantity = this->quantity + c.quantity;
//         temp.price = this->price * this->quantity + c.price * c.quantity;
//         return temp;
//     }
//     void Display()
//     {
//         cout << "Total Price : " << price << endl;
//     }
// };
// int main()
// {
//     OperatorOverloading o1("Gagan", 1000.0, 5);
//     OperatorOverloading o2("Jatin", 2000.0, 10);
//     OperatorOverloading o3("Nitin", 3000.0, 5);

//     OperatorOverloading o4;
//     o4 = o1 + o2 + o3;
//     o4.Display();
//     return 0;
// }

// #include <iostream>
// using namespace std;
// class Mammal
// {
// public:
//     void DisplayMammal()
//     {
//         cout << "I am Mammal \n";
//     }
// };
// class MarineAnimals
// {
// public:
//     void DisplayMarineAnimal()
//     {
//         cout << "I am Marine Animal \n";
//     }
// };
// class BlueWhale : public Mammal, public MarineAnimals
// {
// public:
//     void Whale()
//     {
//         cout << "I am Whale\n";
//     }
// };
// int main()
// {
//     // Mammal m1;
//     // m1.DisplayMammal();

//     // MarineAnimals m2;
//     // m2.DisplayMarineAnimal();

//     BlueWhale b1;
//     b1.Whale();
//     b1.DisplayMammal();
//     b1.DisplayMarineAnimal();
//     return 0;
// }

// Make a class named Fruit with a data member to calculate the number of fruits in a basket.Create two other
// class named Apples and Mangoes to calculate the number of apples and mangoes in the basket.Print the
// number of fruits of each type and the total number of fruits in the basket.

// #include <iostream>
// using namespace std;
// class Fruit
// {
// public:
//     int itemCount = 0;

//     void Display()
//     {
//         cout << "Total item in Basket : " << itemCount << endl;
//     }
// };
// class Apple : public Fruit
// {
// private:
//     int appleCount;

// public:
//     Apple(int n)
//     {
//         this->appleCount = n;
//         itemCount += appleCount;
//     }
//     void AppleDisplay()
//     {
//         cout << "Total Apple: " << appleCount << endl;
//     }
// };
// class Mango : public Fruit
// {
// private:
//     int mangoCount;

// public:
//     Mango(int n)
//     {
//         this->mangoCount = n;
//         itemCount += mangoCount;
//     }
//     void MangoDisplay()
//     {
//         cout << "Total Mango : " << mangoCount << endl;
//     }
// };
// int main()
// {
//     Apple a1(10);
//     a1.AppleDisplay();

//     Mango m1(20);
//     m1.MangoDisplay();

//     Fruit f;
//     f.Display();
//     return 0;
// }

// We want to calculate the total marks of each student of a class in Physics,Chemistry and Mathematics
// and the average marks of the class. The number of students in the class are entered by the user.
// Create a class named Marks with data members for roll number, name and marks.
// Create three other classes inheriting the Marks class, namely Physics, Chemistry and Mathematics, which are used
// to define marks in individual subject of each student. Roll number of each student will be generated automatically.
// #include <iostream>
// #include <string>
// using namespace std;
// class Marks
// {
// public:
//     double Cmarks;
//     double Pmarks;
//     double Mmarks;
//     int rollNo;
//     string Name;
//     Marks(string Name, int rollNo, double Cmarks, double Pmarks, double Mmarks)
//     {
//         this->Name = Name;
//         this->rollNo = rollNo;
//         this->Cmarks = Cmarks;
//         this->Pmarks = Pmarks;
//         this->Mmarks = Mmarks;
//     }
//     void TotalMarks()
//     {
//         cout << "Total Marks : " << this->Cmarks + this->Pmarks + this->Mmarks << endl;
//     }
// };
// class Physics : public Marks
// {
// public:
//     void PMarks(int n, int rNo)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             if (rollNo == rNO)
//             {
//                 cout << "Roll No : " << rollNo << endl;
//                 cout << "Name : " << Name << endl;
//                 cout << "Physics Marks : " << Pmarks << endl;
//             }
//         }
//     }
// };
// class Chemistry : public Marks
// {
// public:
//     void CMarks()
//     {
//         cout << "Roll No : " << rollNo << endl;
//         cout << "Name : " << Name << endl;
//         cout << "Physics Marks : " << Cmarks << endl;
//     }
// };
// class Math : public Marks
// {
// public:
//     void MMarks()
//     {
//         cout << "Roll No : " << rollNo << endl;
//         cout << "Name : " << Name << endl;
//         cout << "Physics Marks : " << Mmarks << endl;
//     }
// };
// int main()
// {
//     int n;
//     cout << "Enter no of students in class : ";
//     cin >> n;

//     Marks m[n];
//     for (int i = 1; i <= n; i++)
//     {
//         m[i].set_identity();
//     }

//     Marks m1("Gagan", 1558, 87, 89, 95);
//     m1.TotalMarks();

//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
// class Course
// {
// public:
//     int Marks;
//     string course;

//     Course operator+(Course c)
//     {
//         Course temp;
//         temp.Marks = Marks + c.Marks;
//         return temp;
//     }

//     void PrintAverage(int n)
//     {
//         cout << "Average Marks : " << Marks / n << endl;
//     }
// };
// class Student : public Course
// {
// private:
//     int id;
//     string name;
//     int Batch;

// public:
//     void setValue(int id, string name, int Batch, string course, int Marks)
//     {
//         this->id = id;
//         this->name = name;
//         this->Batch = Batch;
//         this->course = course;
//         this->Marks = Marks;
//     }
//     void Display()
//     {
//         cout << "Roll No : " << id << endl;
//         cout << "Name : " << name << endl;
//         cout << "Batch : " << Batch << endl;
//         cout << "course : " << course << endl;
//         cout << "Marks : " << Marks << endl;
//     }
// };
// int main()
// {
//     int n;
//     cout << "Enter no of studnets in class : ";
//     cin >> n;

//     Student s[n];
//     for (int i = 1; i <= n; i++)
//     {
//         string name, course;
//         int id, Batch, Marks;
//         cout << "Enter Id : ";
//         cin >> id;
//         cout << "Enter Name : ";
//         cin >> name;
//         cout << "Enter Batch : ";
//         cin >> Batch;
//         cout << "Enter Course : ";
//         cin >> course;
//         cout << "Enter Marks : ";
//         cin >> Marks;
//         s[i].setValue(id, name, Batch, course, Marks);
//     }

//     // s[i].Display();
//     Course c1;
//     for (int i = 1; i <= n; i++)
//     {
//         c1 = c1 + s[i];
//     }
//     c1.PrintAverage(n);
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;
// class Person
// {
// public:
//     string name;
//     int rollNo;
//     Person(string name, int rollNo)
//     {
//         this->name = name;
//         this->rollNo = rollNo;
//     }
// };
// int main()
// {
//     vector<Person> People;
//     int n;
//     cout << "Enter N : ";
//     cin >> n;
//     int i = 0;
//     while (i < n)
//     {
//         string name;
//         cout << "Enter Name : ";
//         cin >> name;
//         int rollNumber;
//         cout << "Enter Roll No : ";
//         cin >> rollNumber;

//         Person person(name, rollNumber);
//         People.push_back(person);
//         i++;
//     }
//     for (Person person : People)
//     {
//         cout << person.name << " " << person.rollNo << endl;
//     }

//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
// class Space
// {
// public:
//     int m, *n;
//     Space(int m)
//     {
//         this->m = m;
//         this->n = new int[m];
//     }
//     void Display()
//     {
//         cout << "A spaceship with " << m << " modules, and memory released when the spaceship is decommissioned." << endl;
//     }
//     ~Space()
//     {
//         delete[] n;
//     }
// };
// int main()
// {
//     Space s(10);
//     s.Display();
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
// class Wand
// {
// public:
//     string CoreMaterial;
//     int lenght;
//     static int maxi;
//     static string res;
//     static int check;
//     void setData(string CoreMaterial, int lenght)
//     {
//         this->CoreMaterial = CoreMaterial;
//         this->lenght = lenght;
//         if (lenght > check)
//         {
//             check = lenght;
//             res = CoreMaterial;
//         }
//         if (lenght >= 0)
//         {
//             maxi = maxi + lenght;
//         }
//     }
//     void Display()
//     {
//         cout << res << " " << maxi << endl;
//     }
// };
// int Wand::maxi = 0;
// int Wand::check = 0;
// string Wand::res = "";
// int main()
// {
//     Wand w1, w2;
//     w1.setData("Phonenix", 10);
//     w2.setData("Dragon", 8);
//     w2.Display();
//     return 0;
// }

// #include <iostream>
// using namespace std;
// class Hunt
// {
// public:
//     int x, y;
//     void SetData(int x, int y)
//     {
//         this->x = x;
//         this->y = y;
//     }
//     void Display()
//     {
//         cout << "x = " << x << ", y = " << y << endl;
//     }
//     Hunt operator+(Hunt h)
//     {
//         Hunt h1;
//         h1.x = this->x + h.x;
//         h1.y = this->y + h.y;
//         return h1;
//     }
// };
// int main()
// {
//     Hunt ab, ac, ad;
//     ab.SetData(20, 15);
//     ac.SetData(30, 40);
//     ad = ab + ac;
//     ad.Display();
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
// class Moye_Moye
// {
// public:
//     string ProductCode;
//     int Quantity;
//     void setData(string ProductCode, int Quantity)
//     {
//         this->ProductCode = ProductCode;
//         this->Quantity = Quantity;
//     }
//     void Display()
//     {
//         if (Quantity < 0)
//         {
//             cout << "Error: Cannot add item. Negative Quantity not allowed." << endl;
//             return;
//         }
//         if (ProductCode == "")
//         {
//             cout << "Error: Invalid product code. Please enter a valid product code." << endl;
//             return;
//         }
//         else
//         {
//             cout << ProductCode << " " << Quantity << endl;
//         }
//     }
// };
// int main()
// {
//     Moye_Moye m1;
//     m1.setData("POO1", 5);
//     m1.Display();
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
// class department
// {
// public:
//     string depart;
//     string code;
//     void Display_info()
//     {
//         cout << "Virtual Function Called !" << endl;
//     }
// };
// class MathDepart : public department
// {
// public:
//     void setMath(string depart, string code)
//     {
//         this->depart = depart;
//         this->code = code;
//     }
//     void Display_info()
//     {
//         cout << depart << " " << code << endl;
//     }
// };
// int main()
// {
//     MathDepart m1;
//     m1.setMath("CS Department", "CS101");
//     m1.Display_info();
//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;
class Distance
{
public:
    double feet;
    double inch;
    void readDistance(double feet, double inch)
    {
        this->feet = feet;
        this->inch = inch;
    }
    void display()
    {
        if (inch == 12)
        {
            cout << feet + 1 << "'" << endl;
        }
        else if (inch == 24)
        {
            cout << feet + 2 << "'" << endl;
        }
        else if (inch <= 12)
        {
            cout << feet << "'" << inch << "''" << endl;
        }
        else if (inch > 12 && inch < 24)
        {
            cout << feet + 1 << "'" << inch - 12 << "''" << endl;
        }
    }
    Distance operator+(Distance D)
    {
        Distance d1;
        d1.feet = this->feet + D.feet;
        d1.inch = this->inch + D.inch;
        return d1;
    }
    Distance operator-(Distance H)
    {
        Distance d1;
        d1.feet = this->feet - H.feet;
        d1.inch = this->inch - H.inch;
        if (d1.feet < 0)
        {
            d1.feet = -d1.feet;
        }
        if (d1.inch < 0)
        {
            d1.inch = -d1.inch;
        }
        return d1;
    }
};
int main()
{
    Distance obj1, obj2, obj3;

    obj1.readDistance(2, 12);
    obj2.readDistance(3, 12);

    obj3 = obj1 obj2;
    obj3.display();
    return 0;
}