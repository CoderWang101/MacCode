#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int n)
{
    if (n <= 1 || n % 2 == 0 ) return false;
    if (n == 2) return true; // 2是素数

    // 判断是否有其他因子
    int sqrt_n = sqrt(n);
    for (int i = 3; i <= sqrt_n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        bool tmp=is_prime(a*b);

        if(tmp==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
