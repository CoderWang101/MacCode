#include <iostream>
#include <set>
using namespace std;

class StringAppend
{
public:
    explicit StringAppend(const string &str) : ss(str) {}
    void operator()(const string &str) const
    {
        cout << str << ' ' << ss << endl;
    }

private:
    const string ss;
};

int main()
{
    StringAppend myFunctor2("and world!");
    myFunctor2("Hello");
}