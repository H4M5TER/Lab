#pragma once

// #include <cassert>
#include <vector>

class IdPool
{
public:
    IdPool(int pool_size)
        :m_pool_size(pool_size), m_ids(pool_size + 1)
    {
        m_first_available = &m_ids[0];
        m_ids[pool_size].next_available = NULL;
        m_ids[pool_size].id = -1;
        for (int i = pool_size - 1; i >= 0; --i)
        {
            m_ids[i].next_available = &m_ids[i + 1];
            m_ids[i].id = i;
        }
    }

    int Allocate()
    {
        // assert(m_first_available != NULL)
        Id* new_id = m_first_available;
        m_first_available = new_id->next_available;
        new_id->next_available = NULL;
        return new_id->id;
    }

    void Free(int id)
    {
        // assert(m_ids[id].next_available != NULL);
        // assert(m_first_available == NULL);
        m_ids[id].next_available = m_first_available;
        m_first_available = &m_ids[id];
    }

    ~IdPool() {}
private:
    struct Id
    {
        int id;
        Id* next_available; // null == inUse
    };
    const int m_pool_size;
    std::vector<Id> m_ids;
    Id* m_first_available;
};
