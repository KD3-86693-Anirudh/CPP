/*Q2. Implement following classes. Test all functionalities in main() of each created class. Note that
employee is inherited into manager and salesman.*/

#include<iostream>
using namespace std;

class employee {
    int empid;
    double salary;

public:
    employee() {
        empid = 0;
        salary = 0;
    }
    employee(int empid, double salary) {
        this->empid = empid;
        this->salary = salary;
    }
    void setid(int empid) {
        this->empid = empid;
    }
    int getid() {
        return empid;
    }
    void setsalary(double salary) {
        this->salary = salary;
    }
    double getsalary() {
        return salary;
    }
    void accept() {
        cout << "enter id";
        cin >> empid;
        cout << "enter salary";
        cin >> salary;
    }
    void display() {
        cout << "empid is -:" << empid;
        cout << "salary is -: " << salary;
    }
};

class manager : virtual public employee {
    double bonus;

public:
    manager() {
        bonus = 0;
    }
    manager(int empid, double salary, double bonus) : employee(empid, salary) {
        this->bonus = bonus;
    }
    void setBonus(double bonus) {
        this->bonus = bonus;
    }
    double getBonus() {
        return bonus;
    }
    void acceptmanager() {
        cout << "enter the bonus";
        cin >> bonus;
        employee::accept();
    }
    void managerdisply() {
        cout << "bonus is -:" << bonus;
        employee::display();
    }
};

class salesman : virtual public employee {
    double comm;

public:
    salesman() {
        this->comm = 0;
    }
    salesman(int empid, double salary, double comm) : employee(empid, salary) {
        this->comm = comm;
    }
    void setcomm(double comm) {
        this->comm = comm;
    }
    double getcomm() {
        return comm;
    }
    void acceptsalesman() {
        cout << "enter comm" << endl;
        cin >> comm;
        employee::accept();
    }
    void displaysalesman() {
        cout << "commission is " << comm;
        employee::display();
    }
};

class salesmanager : public manager, public salesman {
public:
    salesmanager() {}
    salesmanager(int empid, double salary, double comm, double bonus) : manager(empid, salary, bonus), salesman(empid, salary, comm) {}
    void salesmanageraccept() {
        employee::accept();
        manager::acceptmanager();
        salesman::acceptsalesman();
    }
    void salesmanagedisplay() {
        employee::display();
        manager::managerdisply();
        salesman::displaysalesman();
    }
};

int main() {
    employee e;
    e.accept(); 
    e.display(); 

    manager m;
    m.acceptmanager(); 
    m.managerdisply(); 

    salesman s;
    s.acceptsalesman(); 
    s.displaysalesman(); 

    salesmanager s1;
    s1.salesmanageraccept(); 
    s1.salesmanagedisplay(); 

    return 0;
}