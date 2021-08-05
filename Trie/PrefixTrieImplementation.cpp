#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i, st, n) for (int i = st; i < n; i++)
#define mod 1000000007
#define maxN 1000001
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
class Node
{
public:
    char data;
    unordered_map<char, Node *> m;
    bool isTerminal;
    Node(char d)
    {
        data = d;
        isTerminal = false;
    }
};
class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node('\0');
    }
    void insert(string word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                Node *n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = 1;
    }
    bool search(string word)
    {
        Node *temp = root;
        for (auto ch : word)
        {
            if (temp->m.count(ch) == 0)
                return 0;
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }
};
int main()
{
    string words[] = {"apple", "ape", "no", "news", "not", "never"};
    Trie t;
    for (auto w : words)
        t.insert(w);
    int q;
    cin >> q;
    while (q--)
    {
        string search_word;
        cin >> search_word;
        if (t.search(search_word))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}