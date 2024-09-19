/*Q2. Write a menu driven program for Student management.
Create a class student with data members name, gender, rollNumber(Auto generated) and array to
keep marks of three subjects.
Accept every thing from user and Print name, rollNumber, gender and percentage.
In main(), create Student* arr[5] and provide facility for accept, print, search
Search function returns index of found Student, otherwise returns 1.*/

#include <iostream>
using namespace std;

class Student
{

    string name;
    string gender;
    static int rollcount;
    int rollNumber;
    int marks[3];

public:
    Student()
    {

        name = "default";
        gender = "m";
        rollNumber = ++rollcount;

        for (int i = 0; i < 3; i++)
        {
            marks[i] = 0;
        }
    }

    Student(string name, string gender, int marks[])
    {

        this->name = name;
        this->gender = gender;
        this->rollNumber = ++rollcount;
        for (int i = 0; i < 3; i++)
        {
            this->marks[i] = marks[i];
        }
    }

    void setName()
    {

        cout << "\nEnter name: ";
        cin >> name;
    }

    void getName()
    {
        cout << " " << name;
    }

    void setGender()
    {
        cout << "\nEnter gender: ";
        cin >> gender;
    }

    void getGender()
    {
        cout << " " << gender;
    }

    void getRollNumber()
    {
        cout << " rollNumber : " << rollNumber;
    }

    void setMarks()
    {
        cout << "\nEnter marks obtained out of 100: ";
        for (int i = 0; i < 3; i++)
        {
            cin >> marks[i];
        }
    }

    void getMarks()
    {
        cout << "\nMarks : ";
        for (int i = 0; i < 3; i++)
        {
            cout << marks[i] << " ";
        }
    }

    int marks_total = 0;
    double percentage;

    void getPercentage()
    {

        for (int i = 0; i < 3; i++)
        {
            marks_total = marks_total + marks[i];
        }
        percentage = (marks_total / 300.0) * 100;

        cout << "\nPercentage : " << percentage;
        int marks_total = 0;
    }

    void acceptStudent()
    {

        setName();
        setGender();
        setMarks();
    }

    void displayData()
    {

        getName();
        getGender();
        getRollNumber();
        getMarks();
        getPercentage();
    }

    static int searchName(Student *arr[], string name)
    {

        for (int i = 0; i < 5; i++)
        {

            if (arr[i]->name == name)
            {
                return i;
            }
        }

        return -1;
    }
};

int Student ::rollcount = 0;

int main()
{

    Student *arr[5];

    for (int i = 0; i < 5; i++)
    {

        arr[i] = new Student();

        arr[i]->acceptStudent();
    }

    for (int i = 0; i < 5; i++)
    {

        arr[i]->displayData();
    }

    string searchN;

    cout << "\nEnter the name to search a student : ";
    cin >> searchN;

    int searrchedIdx;

    searrchedIdx = Student::searchName(arr, searchN);

    if (searrchedIdx != -1)
    {
        cout << "\nStudent " << searchN << " found at index " << searrchedIdx;
        arr[searrchedIdx]->displayData();
    }

    else
    {
        cout << "\nStudent " << searchN << " does not exist";
    }

    for (int i = 0; i < 5; i++)
    {

        delete arr[i];
    }

    return 0;
}
