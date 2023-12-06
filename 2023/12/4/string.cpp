#include "string.h"

int main()
{
    try // char* tmp = new char[s._capacity + 1];是否开辟异常
    {
        //wzf::test_string3();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}