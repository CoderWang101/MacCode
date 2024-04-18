// #include <iostream>
// #include <vector>
// using namespace std;

// void generatePascalTriangle(int n)
// {
//     vector<vector<int> > triangle(n, vector<int>(n, 0));
//     for (int i = 0; i < n; i++)
//     {
//         triangle[i][0] = 1;
//         for (int j = 1; j < i; j++)
//             triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
//         triangle[i][i] = 1;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j <= i; j++)
//             cout << "     "<<triangle[i][j] ;
//         cout << endl;
//     }
// }

// int main()
// {
//     int n = 6;

//     generatePascalTriangle(n);

//     return 0;
// }