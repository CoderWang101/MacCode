#include <iostream>
using namespace std;

int &Count()
{
    static int n = 0;
    n++;
    return n;
}

// int main()
// {
//     int i = 0;
//     const double &rd = i;

//     cout << (double)i << endl;

//     double dd = i;

//     const double &rd = i;

//     return 0;
// }
