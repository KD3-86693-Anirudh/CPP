/*Create a class Date with data memebrs day,month and year.
Cretae a class Person with data members name,address and birthdate. The birthdate shoud be of
type Date.
Implement above classes. Test all functionalities in main().*/

#include <iostream>
using namespace std;

class Date{
    int day;
    int month;
    int year;

public:
    Date(){
        cout<<"Inside parameterless Date ctor....."<<endl;
        this->day = 1;
        this->month = 1;
        this->year = 2000;
    }

    Date(int d,int m, int y){
        cout<<"Inside parameterized Date ctor....."<<endl;
        day = d;
        month = m;
        year = y;
    }
    
    void setDay(int day){
        this->day = day;
    }

    void setMonth(int month){
        this->month = month;
    }

    void setYear(int year){
        this->year = year;
    }

    void acceptDate()
    {
        cout << "Enter the day, month and year - ";
        cin >> day >> month >> year;
    }

    void displayDate()
    {
        cout<<"Person's birthdate :- " << day << "/" << month << "/" << year << endl;
    }

};

class Person{
    string name;
    string address;
    Date birthdate;

public:
    Person(){
        cout<<"Inside parameterless Person ctor..."<<endl;
        this->name ="";
        this->address= "";
    }  
     Person(string name,string address,int day,int month,int year):birthdate(day,month,year){
        cout<<"Inside parameterized Person ctor..."<<endl;
        this->name =name;
        this->address= address;
        this->birthdate.setDay(day);
        this->birthdate.setMonth(month);
        this->birthdate.setYear(year);
    }   
    void acceptPerson(){
        cout<<"Enter person's name:- ";
        cin>>name;
        cout<<"Enter person's address:- ";
        cin>>address;
        cout<<"Enter person's Dob:- "<<endl;
        birthdate.acceptDate();

    }
    void displayPerson(){
        cout<<"Person's name: "<<name<<endl;
        cout<<"Person's address: "<<address<<endl;
        birthdate.displayDate();
    }
};

int main(){
    Person p;
    Person p1("Vishal","Ramnagar",1,2,2001);
    p.acceptPerson();
    // p1.acceptPerson();
    p.displayPerson();
    p1.displayPerson();
    return 0;
}
