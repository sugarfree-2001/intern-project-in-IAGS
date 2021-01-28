#include <iostream>
#include <string>
#include <list>
#include <stdlib.h>

class Observer;

class Subject
{
public:
    virtual ~Subject() {};
    virtual void registerObsvr(Observer* obsvr) = 0;
    virtual void removeObsvr(Observer* obsvr) = 0;
    virtual void notifyObsvrs(const std::string &msg) = 0;
};

class Observer
{
public:
    virtual ~Observer() {};
    virtual void Update(const std::string &msg)= 0;
    virtual std::string getName() = 0;
protected:
    Observer() {};
};

class announcement : public Subject
{
public:
    announcement()
    {
        _observers = new std::list<Observer*>();
    }
    void registerObsvr(Observer* obsvr);
    void removeObsvr(Observer* obsvr);
    void notifyObsvrs(const std::string &msg);
private:
    std::list<Observer*> *_observers;
};

void announcement::registerObsvr(Observer* obsvr)
{
    _observers->push_back(obsvr);
}

void announcement::removeObsvr(Observer* obsvr)
{
    if (_observers->size() > 0)
        _observers->remove(obsvr);
}
void announcement::notifyObsvrs( const std::string &msg)
{
    std::cout << "state：" << msg << std::endl;
    std::list<Observer*>::iterator iter
    = _observers->begin();
    for ( ; iter != _observers->end(); iter++ )
    {
        (*iter)->Update(msg);
    }
}

class Student : public Observer
{
public:
    Student(std::string name, std::string now ,std::string action)
    {
        _name = name;
        _action = action;
        _now = now;
    };
    void Update( const std::string &msg);
    std::string getName();
private:
    std::string _name;
    std::string _action;
    std::string _now;
};

std::string Student::getName()
{
    return _name;
}

void Student::Update(const std::string &msg)
{
    std::cout<< "This is " << _name << std::endl;
    if ( msg == "class on" )
        std::cout << "Action: " << _action
                  << std::endl << std::endl;
    else
        std::cout << "Continue：" << _now
                  << std::endl << std::endl ;
}


int main()
{
    Student* A = new Student("A",
                               "shopping with girl friend",
                               "go back to school and be worried about girl friend's angry");
    Student* B = new Student("B",
                               "sleeping",
                               "get dressed and run to classroom");
    Student* C = new Student("C",
                               "playing games",
                               "pay the fee and run to classroom");


    announcement* classtime = new announcement();
    classtime->registerObsvr(A);
    classtime->registerObsvr(B);
    classtime->registerObsvr(C);


    classtime->notifyObsvrs("lunchtime");
    classtime->notifyObsvrs("afternoon break");
    classtime->notifyObsvrs("class on");

    system("Pause");
    return 0;
}
