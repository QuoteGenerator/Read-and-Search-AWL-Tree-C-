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

    private:
        TreeNode* m_root;

};

#endif // TREE_H
