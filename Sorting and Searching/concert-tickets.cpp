#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, m;
    multiset<int> ticket;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        ticket.insert(val);
    }
    int bid[m];
    for (int i = 0; i < m; i++)
    {
        cin >> bid[i];
    }
    for (int i = 0; i < m; i++)
    {
        if (ticket.upper_bound(bid[i]) == ticket.begin())
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << *(--ticket.upper_bound(bid[i])) << "\n";
            ticket.erase(--ticket.upper_bound(bid[i]));
        }
    }
    return 0;
}