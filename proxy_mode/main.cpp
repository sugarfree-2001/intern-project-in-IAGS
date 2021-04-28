#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    virtual void rentHouse() = 0;
};


class Customer :public Person
{
public:
    void rentHouse()
    {
        cout << "renting a house" << endl;
    }
};

class Intermediary :public Person
{
public:
    Intermediary(Person *person) :m_Person(person){}
    void rentHouse()
    {
        m_Person->rentHouse();
        cout << "the agent takes a commission of 10%" << endl;
    }
private:
    Person *m_Person;
};

int main()
{
    Person *customer = new Customer;
    Person *intermediary = new Intermediary(customer);
    intermediary->rentHouse();
    return 0;
}
