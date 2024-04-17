// #include <iostream>
// using namespace std;

// void become_large_insert(string &s, int i, string &de)
// {
//     if (s[i] >= 97 && s[i] <= 122)
//         s[i] -= 32;
//     de.push_back(s[i]);
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     string s, de;
//     getline(cin, s);

//     become_large_insert(s, 0, de);

//     for (int i = 1; i < s.size(); i++)
//     {
//         if (s[i] == ' ')
//             become_large_insert(s, i + 1, de);
//     }
//     cout << de << endl;

//     return 0;
// }
