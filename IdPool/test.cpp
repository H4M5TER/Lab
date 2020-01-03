#include <iostream>
#include <vector>
#include <algorithm>
#include "IdPool.h"

using namespace std;

void output(const vector<int>& v)
{
    cout << "output:\n" << endl;
    for (auto id : v)
        cout << id << ' ';
    cout << '\n' << endl;
}

int main()
{
    IdPool idp(32767);
    vector<int> ids;
    for (int i = 0; i < 100; ++i)
        ids.push_back(idp.Allocate());
    output(ids);
    random_shuffle(ids.begin(), ids.end());
    output(ids);
    for (auto id : ids)
        idp.Free(id);
    ids.clear();
    for (int i = 0; i < 100; ++i)
        ids.push_back(idp.Allocate());
    output(ids);

    /* 使用双向链表方便增删?
    struct Id
    {
        int id;
        Id* next;
    } ids[32768] = {}, *head = NULL;
    int cnt = 0;
    for (; cnt < 100; ++cnt)
    {
        ids[cnt].id = idp.Allocate();
        ids[cnt].next = head;
        head = &ids[cnt];
    }
    for (int i = 0, random; i < 50; ++i)
    {
        random = rand() % cnt;
        idp.Free(ids[random].id);
        ids[random].
    }
    */
    return 0;
}