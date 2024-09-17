#include<iostream>
using namespace std;

 class tollbooth{

    int payingcars;
    int nonpayingcars;
    double Amt;
public:
tollbooth(){

this->payingcars = 0;
this->nonpayingcars = 0;
this->Amt = 0;

}

void nonpayingcarCount(){
    nonpayingcars = ++nonpayingcars;

}
void payingcarCount(){
    payingcars = ++payingcars;
    Amt = Amt + 0.50;

}
void printOnConsole(){
    cout<<"count of non-paying cars: "<<nonpayingcars<<endl;
    cout<<"count of paying cars: "<<payingcars<<endl;
    cout<<"Total amount: "<<Amt<<endl;
}
 };

int main(){

   tollbooth t1;
   t1.payingcarCount();
   t1.payingcarCount();
   t1.payingcarCount();
   t1.payingcarCount();
   t1.nonpayingcarCount();
   t1.nonpayingcarCount();
   t1.nonpayingcarCount();
   t1.nonpayingcarCount();
   t1.printOnConsole();  


    return 0;

}