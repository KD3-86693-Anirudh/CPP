#include <iostream>
using namespace std;
class Employee
{
    int id;
    double salary;

public:
    Employee()
    {
    }
    Employee(int id, double salary)
    {
        this->id = id;
        this->salary = salary;
    }

    virtual void accept()
    {
        cout << "Enter empid - ";
        cin >> id;
        cout << "Enter Salary - ";
        cin >> salary;
    }

    virtual void display()
    {
        cout << "Empid -  " << id << endl;
        cout << "Salary -  " << salary << endl;
    }
};

class Manager : virtual public Employee
{
    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter bonus - ";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "Bonus = " << bonus << endl;
    }

public:
    Manager()
    {
    }
    Manager(int id, double salary, double bonus) : Employee(id, salary)
    {
        this->bonus = bonus;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        Employee::display();
        displayManager();
    }
};

class Salesman : virtual public Employee
{
    double commission;

protected:
    void acceptSalesman()
    {
        cout << "Enter commission - ";
        cin >> commission;
    }
    void displaySalesman()
    {
        cout << "commission = " << commission << endl;
    }

public:
    Salesman()
    {
    }
    Salesman(int id, double salary, double commission) : Employee(id, salary)
    {
        this->commission = commission;
    }
    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }

    void display()
    {
        Employee::display();
        displaySalesman();
    }
};

class Salesmanager : public Manager, public Salesman
{
public:
    Salesmanager()
    {
    }
    Salesmanager(int id, double salary, double bonus, double commission) : Employee(id, salary)
    {
        // this->setBonus(bonus);
        // this->setCommission(commission);
        this->acceptManager();
        this->acceptSalesman();
    }

    void accept()
    {
        Employee::accept();
        this->acceptManager();
        this->acceptSalesman();
    }
    void display()
    {
        Employee::display();
        this->displayManager();
        this->displaySalesman();
    }
};
int main()
{
    Employee *e = new Salesmanager;
    // e->accept();
    // e->display();
    Salesman s;
    Employee *arr[5];
    int choice;
    int countManager = 0;
    int countSalesMan = 0;
    int countSalesManager = 0;
    do
    {
        cout << "1. Accept Employee" << endl;
        cout << "__________a. Accept Manager" << endl;
        cout << "__________b. Accept Salesman" << endl;
        cout << "__________c. Accept SalesManager" << endl;
        cout << "2. Display the count of all employees with respect to designation" << endl;
        cout << "3. Display All Managers" << endl;
        cout << "4. Display All Salesman" << endl;
        cout << "5. Display All SalesManagers" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            char c;
            cout << "Choose any one 'A'-> for Accept Manager, 'B'-> for Accept Salesman, 'C'-> for Accept SalesManager " << endl;
            cin >> c;
            for (int i = 0; i < 5; i++)
            {
                if (c == 'a' || 'A')
                {
                    arr[i] = new Manager;
                    arr[i]->accept();
                }
                else if (c == 'b' || 'B')
                {
                    arr[i] = new Salesman;
                    arr[i]->accept();
                }
                else if (c == 'c' || 'C')
                {
                    arr[i] = new Salesmanager;
                    arr[i]->accept();
                }
            }
            break;
        case 2:
            for (int i = 0; i < 5; i++)
            {
                if (typeid(*arr[i]) == typeid(Manager))
                {
                    countManager++;
                }
                if (typeid(*arr[i]) == typeid(Salesman))
                {
                    countSalesMan++;
                }
                if (typeid(*arr[i]) == typeid(Salesmanager))
                {
                    countSalesManager++;
                }
            }
            cout << "count of Managers : " << countManager << endl;
            cout << "count of Salesman : " << countSalesMan << endl;
            cout << "count of SalesManager : " << countSalesManager << endl;

            break;
        case 3:
            for (int i = 0; i < 5; i++)
            {
                if (typeid(*arr[i]) == typeid(Manager))
                {
                    arr[i]->display();
                }
            }
            break;
        case 4:
            for (int i = 0; i < 5; i++)
            {
                if (typeid(*arr[i]) == typeid(Salesman))
                {
                    arr[i]->display();
                }
            }
            break;
        case 5:
            for (int i = 0; i < 5; i++)
            {
                if (typeid(*arr[i]) == typeid(Salesmanager))
                {
                    arr[i]->display();
                }
            }
            break;
        default:
            cout<<"Wrong Input.........."<<endl;
            break;
        }
    } while (choice != 0);

    return 0;
}