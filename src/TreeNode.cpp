#include "TreeNode.h"

TreeNode::TreeNode(int key){
    m_key = key;
    m_right = nullptr;
    m_left = nullptr;
}

TreeNode* TreeNode::addNode(TreeNode* root, int key){
    TreeNode* newNode = new TreeNode(key);
    if(root == nullptr){
        return newNode;
    }

    TreeNode* currentNode = root;
    TreeNode* parentNode = nullptr;

    while (true){
        parentNode = currentNode;
        if(key < currentNode->m_key){
            currentNode = currentNode->m_left;
            if(currentNode == nullptr){
                parentNode->m_left = newNode;
                return root;
            }
        }
        else {
            currentNode = currentNode->m_right;
            if(currentNode == nullptr){
                parentNode->m_right = newNode;
                return root;
            }
        }
    }
}

int TreeNode::getNodeValue(){
    return m_key;
}

TreeNode* TreeNode::getRightNode(){
    return m_right;
}
TreeNode* TreeNode::getLeftNode(){
    return m_left;
}
