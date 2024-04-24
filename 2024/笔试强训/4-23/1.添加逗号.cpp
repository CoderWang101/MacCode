#include <iostream>
#include<string>
using namespace std;

int main() 
{
    long long a;
    cin>>a;
    string s=to_string(a);
    int len=s.length();
    if (len<=3)
    {
        cout<<s<<endl;
        return 0;
    }

    for (int i = len-3; i > 0; i-=3)
        s.insert(i,",");
        
    cout<<s<<endl;
    return 0;
}
