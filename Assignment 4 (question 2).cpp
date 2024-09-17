#include<iostream>
using namespace std;

class Stack{

int maxsize;
int top;
int* arr;

 public:

    Stack(){
        int maxsize = 5;
        int top = -1;
        int* arr = new int[maxsize];
    }

    Stack(int size){
   
int maxsize = 5;
int top = -1;
int* arr = new int[maxsize];

    }

    void push(int value){
if (isFull()) {
            cout << "Stack overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value; 
    }

    void pop(){
 if (isEmpty()) {
            cout << "Stack underflow! Cannot pop from empty stack" << endl;
            return;
        }
        cout << "Popped: " << arr[top--] << endl; 
    }

    int peek(){
if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1; 
        }
        return arr[top];
    }

    bool isEmpty(){
 return top == -1;
    }

    bool isFull(){
return top == maxsize - 1;
    }

    void print(){
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;


    }
        ~Stack() {
        delete[] arr;
    }


};

int main(){
int size;
cout<<"Enter stack size: ";
cin>> size;

Stack s(size);

s.push(10);
s.push(20);
s.push(30);
s.push(40);
s.push(50);

cout<<"Top element is: "<< s.peek() << endl;
s.print();

    s.pop();
    s.pop();

    s.print();

    s.push(60);
    s.push(70);

    s.print();
    return 0;
}