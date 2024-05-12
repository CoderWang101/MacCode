#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> N;
    vector<int> M;
    vector<int> gather;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        N.push_back(tmp);
    }

    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        M.push_back(tmp);
    }
    if (N.empty())
    {
        for (int i = 0; i < M.size(); i++)
        {
            cout << M[i] << " ";
            cout << endl;
        }
    }

    if (M.empty())
    {
        for (int i = 0; i <N.size(); i++)
        {
            cout << N[i] << " ";
            cout << endl;
        }
    }
    if(N.empty()&&M.empty())
        return 0;

    int n_pos = 0, m_pos = 0;
    while (n_pos < N.size() && m_pos < M.size())
    {
        if (N[n_pos] < M[m_pos])
        {
            gather.push_back(N[n_pos]);
            n_pos++;
        }
        else if (N[n_pos] > M[m_pos])
        {
            gather.push_back(M[m_pos]);
            m_pos++;
        }
        else
        {
            if (gather.empty() || gather.back() != N[n_pos])
                gather.push_back(N[n_pos]);
            n_pos++;
            m_pos++;
        }
    }

    while (n_pos < N.size())
    {
        if (gather.empty() || gather.back() != N[n_pos])
            gather.push_back(N[n_pos]);
        n_pos++;
    }

    while (m_pos < M.size())
    {
        if (gather.empty() || gather.back() != M[m_pos])
            gather.push_back(M[m_pos]);
        m_pos++;
    }

    for (int i = 0; i < gather.size(); i++)
        cout << gather[i] << " ";
    cout << endl;

    return 0;
}