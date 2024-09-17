#include<iostream>
using namespace std;

class Address{

    string building;
    string street;
    string city;
    int pin;

public:

Address(){

     building = "";
     street = "";
     city = "";
     pin = 0;
      
}

Address(string building, string street, string city, int pin){

     this->building = building;
     this->street = street;
     this->city = city;
     this->pin = pin;

}

void setbuilding(string name1){
building = name1;
} 

string getbuilding(){
    return building;
}

void setstreet(string name2){
street = name2;
} 

string getstreet(){
    return street;
}

void setcity(string name3){
city = name3;
}

string getcity(){
return city;
}

void setpin(int pin1){
pin = pin1;
}

int getpin(){
    return pin;
}

void Accept(){
    cout<<"Enter the name of building: "<<endl;
    cin>>building;

    cout<<"Enter the name of street: "<<endl;
    cin>>street;

    cout<<"Enter the name of city: "<<endl;
    cin>>city;

    cout<<"Enter pin: "<<endl;
    cin>>pin;

}

void Display(){
    cout<<building<<endl;
    cout<<street<<endl;
    cout<<city<<endl;
    cout<<pin<<endl;
}

};

int main(){
Address a;
int choice;
cout<<"1. setter 2. getter 3. Accept 4. Display 5. Exit"<<endl;
cin>>choice;
while(choice != 5 ){}
switch(choice){ 

case 1:

   a.setbuilding("avon");
   a.setstreet("wonder");
   a.setcity("bali");
   a.setpin(1002);

break;

   case 2:

   a.getbuilding();
   a.getstreet();
   a.getcity();
   a.getpin();   
break;
 
   case 3:
   a.Accept();
break;

   case 4:
   a.Display();
break;

   case 5:
cout<<"EXIT"<<endl;
break;
   cout<<""<<endl;
}
    return 0;
}