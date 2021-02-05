#include <iostream>

using namespace std;

class Singleton {
private:
    static Singleton *p;

    Singleton() = default;
    ~Singleton() = default;

public:
    static Singleton* get_instance() {
        if(p == NULL) {
            p = new Singleton();
        }
        cout << Singleton::p << endl;
        return p;
    }

    static void release_instance() {
        if(p != NULL) {
            cout << Singleton::p << " release" << endl;
            delete p;
            p = NULL;
        }
    }
};

Singleton* Singleton::p = NULL;

int main(int argc, char const *argv[])
{
    Singleton *s = Singleton::get_instance();
    Singleton *s2 = Singleton::get_instance();

    Singleton::release_instance();

    return 0;
}
