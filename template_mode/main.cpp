#include <iostream>
#include <string>
using namespace std;

 class AbstractClass
{
public:
	void Show() { cout << "I am " << GetName() << endl; }

protected:
	virtual string GetName() = 0;
};

class Tom : public AbstractClass
{
protected:
	virtual string GetName() { return "Tom"; }
};

class Jerry : public AbstractClass
{
protected:
	virtual string GetName() { return "Jerry"; }
};

int main()
{
	Tom* tom = new Tom();
	tom->Show();

	Jerry* jerry = new Jerry();
	jerry->Show();

	return 0;
}
