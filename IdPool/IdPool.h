#pragma once

#include <vector>

struct Id
{
    int id;
    Id* next_available; // null == inUse
};

class IdPool
{
public:
    IdPool(int pool_size)
        :m_pool_size(pool_size), m_ids(pool_size + 1)
    {
        m_first_available = &m_ids[0];
        m_ids[pool_size].nextAvailable = NULL;
        for (int i = pool_size - 1; i >= 0; --i)
        {
            m_ids[i].nextAvailable = &m_ids[i + 1];
            m_ids[i].id = i;
        }
    }
    int Allocate()
    {
        assert(m_first_available != NULL)
        int new_id = m_first_available->id;
        m_first_available = m_first_available->next_available;
        return new_id;
    }
    void Free(int id)
    {
        assert(m_ids[id]->next_available != NULL)
        m_ids[id]->next_available = m_first_available;
        m_first_available->next_available = &m_ids[id];
    }
    ~IdPool();
private:
    const int m_pool_size;
    std::vector<Id> m_ids;
    Id* m_first_available;
};
