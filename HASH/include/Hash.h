#ifndef HASH_H
#define HASH_H
#include<string>
using  namespace std;
class Hash
{
    private:
        static const int tableSize=10;

        struct item
        {
            string name;
            string drink;
            item* next;
        };

        item *HashTable[tableSize];

    public:
        Hash();
        int hash_func(string key);
        void AddItem(string name,string key);
        int NumberOfItemsInIndex(int index);
        void PrintTable();
        void PrintItemInIndex(int index);
        void FindDrink(string name);
        void RemoveItem(string name);
};

#endif // HASH_H
