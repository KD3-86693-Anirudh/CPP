#include <iostream>
using namespace std;

class Product
{
    int id;
    string title;
public:
    double price;

public:
    Product()
    {
        this->id = 0;
        this->price = 0.0;
        this->title = "no title";
    }
    Product(int id, string title, double price)
    {
        this->id = id;
        this->price = price;
        this->title = title;
    }
    void accept()
    {
        cout << "Enter id :- " << endl;
        cin >> id;
        cout << "Enter title :- " << endl;
        cin >> title;
        cout << "Enter price :- " << endl;
        cin >> price;
    }
    void display()
    {
        cout << "Id - " << id << endl;
        cout << "title - " << title << endl;
        cout << "price - " << price << endl;
    }
};

class Book : public Product
{
    string author;

public:
    Book()
    {
        string author = "unknown author";
    }
    Book(int id, string title, string author, double price) : Product(id, title, price)
    {
        this->author = author;
    }
    void acceptBook()
    {
        Product::accept();
        cout << "Enter author : - " << endl;
        cin >> author;
    }
    void displayBook()
    {
        Product::display();
        cout << "Author - " << author << endl;
    }
};

class Tape : public Product
{

    string artist;

public:
    Tape()
    {
        string title = "no title";
        string artist = "unknown artist";
        double price = 0.0;
    }
    Tape(int id, string title, string artist, double price) : Product(id, title, price)
    {

        this->artist = artist;
    }

    void acceptTape()
    {
        Product::accept();
        cout << "Enter artist - " << endl;
        cin >> artist;
    }

    void displayTape()
    {
        Product::display();
        cout << "Artist - " << artist << endl;
    }
};

int main()
{

    Product *arr[3];
    int choice;

        for (int i = 0; i < 3; i++)
        {
            cout << "0. Buy Books" << endl;
            cout << "1. Buy Tapes" << endl;
            cin >> choice;
            if (choice == 0)
            {
                arr[i] = new Book;
                arr[i]->accept();
            }
            else if (choice == 1)
            {
                arr[i] = new Tape;
                arr[i]->accept();
            }
            else
            {
                cout << "Wrong choice....." << endl;
                break;
            }
        }
    for (int i = 0; i < 3; i++)
    {
        if (typeid(*arr[i]) == typeid(Book))
        {
            arr[i]->display();
        }
        else if (typeid(*arr[i]) == typeid(Tape))
        {
            arr[i]->display();
        }
    }
    int total = 0;
    double totaldiscount = 0;
    int x;
    for (int i = 0; i < 3; i++)
    {
        if (typeid(arr[i]) == typeid(Book))
        {
            x = arr[i]->price;
            total += x;
            totaldiscount += x * .90;
        }
        else
        {
            x = arr[i]->price;
            total += x;
            totaldiscount += x * .95;
        }
    }
    cout << "Total Price :" << total << endl;
    cout << "Discounted Price :" << totaldiscount;
    return 0;
}
