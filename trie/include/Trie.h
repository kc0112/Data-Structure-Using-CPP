#ifndef TRIE_H
#define TRIE_H
#include<cstdlib>


struct node
{
    char data{};
    node *child[26]{};
    int c{0};
};

class Trie
{
    private:
   node*root;
   void add_p(char *value,node*root);
   bool searching_p(char*value,node* root);

    public:
        Trie();
        void add(char *value);
        node* create (char * value);
        void create_root();
        bool searching(char *value);
};

#endif // TRIE_H
