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
        int minValue(TreeNode* treeNode);
        int maxValue(TreeNode* treeNode);
        void avgValue(TreeNode* treeNode);
        void printStats();


    private:
        TreeNode* m_root;
        bool AVL_TREE_CHECK = true;
        float m_sum;
        int m_length;

};

#endif // TREE_H
