/*Q1. Create a class Date with data memebrs day,month and year.
Cretae a class Person with data members name,address and birthdate. The birthdate shoud be of
type Date.
Cretae a class Employee with data members id, sal, dept and joining date. The joining date should
be of type date.
Employee class should be inherited from Person.
Implement following classes. Test all functionalities in main().
(Note
Perform the Associat ion and Inheritance in the above case.)*/

#include<iostream> 
using namespace std;

class date
{
    int day;
    int month;
    int year;

public:
    date()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
    date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void accept()
    {
        cout<< "enter the day month and year";
        cin>> day >> month >> year;
    }
    void display()
    {
        cout<< day << "/" << month << "/" << year;
    }
    void setday(int day)
    {
        this->day = day;
    }
    void setmonth(int month)
    {
        this->month = month;
    }
    void setyear(int year)
    {
        this->year = year;
    }
};

class person
{
    string name;
    string address;
    date dob;

public:
    person()
    {
        this->name = "";
        this->address = "";
    }
    person(string name, string addtress, int day, int month, int year) : dob(day, month, year)
    {
        this->name = name;
        this->address = address;
        this->dob.setday(day);
        this->dob.setmonth(month);
        this->dob.setyear(year);
    }

    void personaceept()
    {
        cin >> name >> address;
        dob.accept();
    }
    void persondisplay()
    {
        cout << "address-:" << address << endl;
        cout << "name-:" << name << endl;
        dob.display();
    }
};

class employee
{
    int empid;
    int sal;
    int dept;
    date doj;

public:
    employee()
    {
        this->empid = 0;
        this->sal = 0;
        this->dept = 0;
    }
    employee(int empid, int sal, int dept, int day, int month, int year) : doj(day, month, year)
    {
        this->empid = empid;
        this->sal = sal;
        this->dept = dept;
        this->doj.setday(day);
        this->doj.setmonth(month);
        this->doj.setyear(year);
    }
    void employeedisplay()
    {
        cout << "empid =" << empid << endl;
        cout << "sal =" << sal << endl;
        cout << "dept" << dept << endl;
        doj.display();
    }
    void employeeaccept()
    {
        cout << "enter empid" << endl;
        cin >> empid;
        cout << "enter sal" << endl;
        cin >> sal;
        cout << "enter deptno" << endl;
        cin >> dept;
        doj.accept();
    }
};
int main()
{
    employee e;
    e.employeeaccept();
    e.employeedisplay();
}