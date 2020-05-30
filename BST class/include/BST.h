#ifndef BST_H
#define BST_H
struct node
    {
        int data;
        node* left;
        node* right;
    };

class BST
{
private:
    node* root;

    void AddLeafPrivate(int value,node* root);
    void PrintInOrderPrivate(node* root);

public:
    BST();                            //constructor
    node* CreateLeaf(int value);      //fn to create leaf;
    void AddLeaf(int value);
    void PrintInOrder();
};

#endif // BST_H
