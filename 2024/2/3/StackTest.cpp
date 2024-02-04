#include <iostream>
#include <stack>
using namespace std;

void test_stack1()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);


    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    test_stack1();

    return 0; 
}