#include <iostream>
using namespace std;

namespace Nstudent{

    class Student {
        int roll_no;
        string name;
        int marks;

public:
        void accept(){
            cout<<"Enter roll no: "<<endl;
            cin>>roll_no;
            
            cout<<"Enter name: "<<endl;
            cin>>name;
            
            cout<<"Enter Marks: "<<endl;
            cin>>marks;
        }

        void print(){
            cout<<"Roll no is: "<<roll_no<<endl;
            cout<<"Name is: "<<name<<endl;
            cout<<"Marks are: "<<marks<<endl;
        }

        void init(){
           roll_no= 0;
            name= "";
            marks= 0;
        }
    };
}

int main(){
int choice= 0;
Nstudent::Student s;
while(choice != 4){
     cout << "Enter your choice (1-Initialize, 2-Accept, 3-Print, 4-Exit): ";
    cin>>choice;
    switch(choice){

    case 1: 
    s.init();
    cout<<"Initialized" <<endl;
    break;

    case 2:
    s.accept();
    cout<<"values accepted"<<endl;
    break;

    case 3:
    s.print();
    cout<<"values printed"<<endl;
    break;

    case 4:
    cout<<"Exiting . . .";
    break;
}
}
    return 0;
}