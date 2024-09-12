#include<iostream>
using namespace std;

class Volume{
    int length;
    int width;
    int height;

public:
Volume(){
    length = 0;
    width = 0;
    height = 0;
}

Volume(int a){
    length = a;
    width = a;
    height = a;
}

Volume(int a, int b, int c){
    length = a;
    width = b;
    height = c;
}

void display(){
    int Area = length*width*height;
    cout<<Area<<endl;
}

}; 

int main(){
int choice;
Volume v ;
Volume v1(5);
Volume v2(7,8,9);
while(choice != 4){
cout<<"Enter 1. default value volume 2. single value volume 3. different values volume 4. Exit"<<endl;
cin>>choice;
switch(choice){
    case 1:
    cout<<"Accepted from Default value "<<endl;
      v.display();
break;

       case 2:
    cout<<"Single value Accepted "<<endl;
    v1.display();
break;

       case 3:
    cout<<"user defined values length, width and height "<<endl;
    v2.display();
break;

   

      case 4:
      cout<<"Exiting..."<<endl;
      return 0;
}
}
    return 0;
}