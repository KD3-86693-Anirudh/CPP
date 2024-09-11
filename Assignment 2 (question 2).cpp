#include<iostream>
#include<string>
using namespace std;

class student {

    int roll_no;
    string name;
    int marks;

public:
    void initStudent(){
       roll_no = 0;
       name= "";
       marks= 0;
    }

    void printStudentOnConsole(){
     cout<<"("<<"Roll no: "<< roll_no<<", "<<"Name: "<<name<<", "<<"Marks :"<<marks<<")"<<endl;
    }

    void acceptStudentFromConsole(){
     cout<<"Enter roll no: ";
     cin>>roll_no;
     cout<<"Enter name: ";
     cin>>name;
     cout<<"Enter Marks: ";
     cin>>marks;
    }

};

int main(){
int choice = 0;
student s;
while(choice != 4){
    cout << "Enter your choice (1-Initialize, 2-Print, 3-Accept, 4-Exit): ";
cin>>choice;

switch(choice){

case 1: 
s.initStudent();
cout<<"Student initialized"<<endl;
break;

case 2: 
s.printStudentOnConsole();
cout<<"Student printed"<<endl;
break;

case 3: 

s.acceptStudentFromConsole();
cout<<" Student Accepted "<<endl;
break;

case 4: 

cout<<"Exited"<<endl;
return 0;
}

}

return 0;
}