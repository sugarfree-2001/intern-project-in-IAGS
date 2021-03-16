#include<iostream>
using namespace std;

class Target
{
public:
	virtual void Request(){};
};


class Adaptee
{
public:
	void SpecificRequest()
	{
		cout<<"Called SpecificRequest()"<<endl;
	}
};

class Adapter : public Adaptee, public Target
{
public:
	void Request()
	{
		this->SpecificRequest();
	}
};


int main()
{
	Target *t = new Adapter();
	t->Request();
	return 0;
}
