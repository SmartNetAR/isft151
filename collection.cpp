#ifndef COLLECTION_H_INCLUDED
#define COLLECTION_H_INCLUDED



#endif // COLLECTION_H_INCLUDED

struct Collection
{
    int count;
    int capacity = 256;
    int rep[256];
    int current;
    int first, last;
    bool init(void)
    {
        count = 0;
        first = -1;
        last = -1;
        for (int i = 0; i < capacity; i++)
        {
            rep[i] = 0;
        }
        current = 0;
    }
    bool IsEmpty(void)
    {
        return count == 0;

    }
    bool IsFull(void)
    {
        return count == capacity;
    }
    bool Add(int items[256])
    {
        for (int i = 0; i < count; i++)
        {
            rep[last] = items[i];
            last++;
        }
        return true;
    }
    bool Delete(int iditem)
    {
        rep[iditem] = 0;
        return true;
    }
    bool Show(void)
    {

        for (int i = 0; i < count; i++)
        {
            cout << rep[i] << ", " ;
        }
        cout << endl;
        return true;
    }
};
