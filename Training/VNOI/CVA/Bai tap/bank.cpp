#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int type,k,p;

struct Person
{
    int id,priority;
    Person(int _id, int _priority)
    {
        id = _id;
        priority = _priority;
    }
};

struct cmp
{
    bool operator() (Person x, Person y) const
    {
        return x.priority < y.priority;
    }
};

set<Person, cmp> s;

int main()
{
    init();
    while(cin >> type)
    {
        if(type == 0) break;
        if(type == 1)
        {
            cin >> k >> p;
            s.insert({k,p});
        }
        else
        {
            if(s.empty())
            {
                cout << 0 << '\n';
                continue;
            }
            auto it = s.begin();
            if(type == 2)
            {
                it = s.end();
                it--;
            }
            else
            {
                it = s.begin();
            }
            cout << it->id << '\n';
            s.erase(it);
        }
    }
}

