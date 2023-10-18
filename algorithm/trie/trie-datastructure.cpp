#include <bits/stdc++.h>
using namespace std;

void io()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// insert and search in matrin form**
const long long inf = 1LL << 62;
const int md = 1000000007;

int trie[1000005][26];
bool stop[1000005];
int dp[5005];
int ct = 0;
void iinsert(string s)
{
    int node = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (!trie[node][s[i] - 'a'])
            trie[node][s[i] - 'a'] = ++ct;
        node = trie[node][s[i] - 'a'];
    }
    stop[node] = 1;
}
string s;
int ssearch(int x)
{
    int node = 0, ans = 0;
    for (int i = x; i < s.size(); i++)
    {
        if (!trie[node][s[i] - 'a'])
            return ans;
        node = trie[node][s[i] - 'a'];
        if (stop[node])
        {
            (ans += dp[i + 1]) %= md;
        }
    }
    return ans;
}

//*********end;

class Trie
{
public:
    class node
    {
    public:
        bool end;
        node *next[26];
        node()
        {
            end = false;
            for (int i = 0; i < 26; i++)
            {
                next[i] = NULL;
            }
        }
    };
    node *trie;
    Trie()
    {
        trie = new node();
    }

    void insert(string word)
    {
        int i = 0;
        node *it = trie;
        while (i < word.size())
        {
            if (it->next[word[i] - 'a'] == NULL)
                it->next[word[i] - 'a'] = new node();
            it = it->next[word[i] - 'a'];
            it++;
        }
        it->end = true;
    }
    bool search(string word)
    {
        int i = 0;
        node *it = trie;
        while (i < word.size())
        {
            if (it->next[word[i] - 'a'] == NULL)
                return false;
            it = it->next[word[i] - 'a'];
            i++;
        }
        return it->end;
    }
};
int main()
{
    io();
    Trie *myTrie = new Trie();
    int i = 0;
    for(;i<5;i++)
    {
        string k;
        cin >> k;
        myTrie->insert(k);
    }
    i=4;
    while(i--)
    {
        string k;
        cin>>k;
        if(myTrie->search(k))
        cout<<"found"<<endl;
        else
        cout<<"not found"<<endl;
    }
}