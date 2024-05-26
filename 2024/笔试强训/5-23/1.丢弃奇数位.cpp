#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int ret=1;
        while (ret-1<=n)
            ret*=2;
        cout<<ret/2-1<<endl;        
    }
    return 0;
}
