#include "TestDate.h"

void TestDate1()
{
    Date d1(2023, 2, 4);
    d1.Print();
    cout << "===" << endl;

    Date d2 = d1 + 150;
    d1.Print();
    d2.Print();
    cout << "===" << endl;

    Date d3 = d1;
    d3 += 100;
    // d1+=d3+=100;这样会报错，d1+=d3为 日期类+日期类，
    d1.Print();
    d3.Print();
    cout << "===" << endl;
}

void TestDate2()
{
    Date d1(2023, 2, 4);
    d1.Print();
    ++d1; // d1.operator++();
    d1.Print();
    d1++; // d1.operator++(1);//括号内传整形(不一定是1)只是为了占位，跟前置区分
    d1.Print();
    cout << "===" << endl;
}

void TestDate3()
{
    Date d1(2023, 2, 4);
    d1.Print();
    d1 -= 100;
    d1.Print();
    cout << "=====" << endl;
    Date d2(2023, 2, 4);
    d2.Print();
    d2 += -100;
    d2.Print();
    cout << "=====" << endl;
    Date d3(2023, 2, 4);
    d3.Print();
    d3 -= -100;
    d3.Print();
    cout << "===" << endl;

    Date d4(2023, 2, 4);
    d4.Print();
    d4--;
    d4.Print();
    cout << "===" << endl;
    --d4;
    d4.Print();
}

void TestDate4()
{
    Date d1(2023, 11, 1);
    d1.Print();
    Date d2(2022, 11, 3);
    d2.Print();
    cout << d2 - d1 << endl;
    cout << (d1 - d2) << endl;
}

void TestDate5()
{
    // 流插入
    int i = 1;
    double d=1.11;

    cout << i; // cout.operator(i) //int
    cout << d; // cout.operator(d) //double
    cout<<endl;
    cout<<"===="<<endl;

    //实现流插入
    Date d1(2023, 11, 2);
    // operator<<(cout);
    // d1<<cout;
    operator<<(cout,d1);
    cout<<d1;
    cout<<endl;
    Date d2(2023, 11, 2);
    //此处为连续调用 每次 <<执行完应该return值以便继续调用
    cout<<d1<<d2<<endl;

}

void TestDate6()
{
    //流提取
    Date d1;
    cin>>d1;
    cout<<d1;

}

int main()
{
    TestDate6();

    return 0;
}
