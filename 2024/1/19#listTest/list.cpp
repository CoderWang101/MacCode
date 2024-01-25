#include <iostream>
#include <list>
using namespace std;

void list_test1()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(5);

    list<int>::iterator it = lt.begin();
    while (it != lt.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;

    list<int>::iterator pos = find(lt.begin(), lt.end(), 3);
    if (pos != lt.end())
    {
        lt.insert(pos, 30);
    }

    it = lt.begin();
    while (it != lt.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;

    lt.remove(3); // find+erase
    it = lt.begin();
    while (it != lt.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

int main()
{
    list_test1();

    return 0;
}