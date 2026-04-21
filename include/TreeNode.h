#ifndef TREENODE_H
#define TREENODE_H


class TreeNode{
    public:
        TreeNode(int key);
        TreeNode* addNode(TreeNode* root, int key);

        int getNodeValue();
        TreeNode* getRightNode();
        TreeNode* getLeftNode();

    private:
        int m_key;
        TreeNode* m_right;
        TreeNode* m_left;

};

#endif // TREENODE_H
