#include "string.h"
void test_string9()
{
    wzf::string s1("0123456789");
    cout << s1.c_str() << endl;
    cout << s1 << endl;

    cin >> s1;
    cout << s1 << endl;
}
int main()
{
    try // char* tmp = new char[s._capacity + 1];是否开辟异常
    {
        test_string9();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}