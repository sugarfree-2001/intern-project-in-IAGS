#include <iostream>
#include <string>

using namespace std;

class ArrayList
{
private:
    int cnt;
    int arr[100];

public:
    typedef int* Iterator; 

    ArrayList(){cnt = 0;}

    Iterator begin()
    {
        return &arr[0];
    }

    Iterator end()
    {
        return &arr[cnt];
    }

    void insert(int v)
    {
        if(cnt>=100)
        {
            cout << "Full" << endl;
            return;
        }
        arr[cnt++] = v;
    }
};
int main()
{
    ArrayList al;

    for(int i = 0; i< 110; i++)
    {
        al.insert(i);
    }

    ArrayList::Iterator iter = al.begin();
    while( iter != al.end())
    {
        cout << *iter << endl;
        iter++;
    }

    return 0;
}
