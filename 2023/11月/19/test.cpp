// #include <iostream>
// using namespace std;

// class Solution
// {
//     int countA[26]={0};

//     for(auto ch : s)
//     {
//         countA[ch-'a']++;
//     }

//     for (int i = 0; i < s.size(); i++)
//     {
//         if (countA[s[i]-'a']==1)
//         {
//             return i;
//         }

//     }
//     return -1;
// };

#include <iostream>

class Solution
{
public:
    int firstUniqueCharIndex(const std::string &s)
    {
        int countA[26] = {0};

        for (auto ch : s)
        {
            countA[ch - 'a']++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (countA[s[i] - 'a'] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    Solution solution;
    std::string s = "lleeticode";
    int index = solution.firstUniqueCharIndex(s);
    std::cout << "First unique character index: " << index << std::endl;

    return 0;
}