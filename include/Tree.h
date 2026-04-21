#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <fstream>

class Tree{
    public:
        Tree();
        void readFromFile(const char* filename);
        TreeNode* get_m_root();
        void changeAVL_TREE_BOOL(bool);
        bool getAVL_TREE_CHECK();


    private:
        TreeNode* m_root;
        bool AVL_TREE_CHECK = true;

};

#endif // TREE_H
