// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     int a = 0, b = 1, c = 2;
//     int t;
//     cin >> t;

//     vector<vector<int> > word(t, vector<int>(3));

//     for (int i = 0; i < t; i++)
//         for (int j = 0; j < 3; j++)
//             cin >> word[i][j];

//     for (int i = 0; i < t; i++)
//     {
//         int max_you = min(min(word[i][a], word[i][b]), word[i][c]);
//         int max_oo=max(word[i][b]-max_you-1,0);
//         cout << (max_you*2+max_oo) << endl;
//     }

//     return 0;
// }