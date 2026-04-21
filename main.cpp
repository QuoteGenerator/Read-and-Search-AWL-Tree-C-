#include "Tree.h"

void printBalanceFactor(TreeNode* treeNode, Tree& tree);
int getDepth(TreeNode* treeNode);

int main(int argc, char* argv[]){
    if(argc != 3){
        std::cerr << "Usage: treecheck [file.txt] [file.txt]\n";
        return 1;
    }
    Tree tree;
    tree.readFromFile(argv[1]);

    printBalanceFactor(tree.get_m_root(), tree);

    if(tree.getAVL_TREE_CHECK()){
        std::cout << "\nAVL: NO";
    } else {
        std::cout << "\nAVL: YES";
    }

}


void printBalanceFactor(TreeNode* treeNode, Tree& tree){
    int leftDepth = 0;
    int rightDepth = 0;
    int balanceFactor = 0;
    bool VIOLATION = false;

    if(treeNode == nullptr){
        return;
    }

    std::cout << std::endl;

    leftDepth = getDepth(treeNode->getLeftNode());
    rightDepth = getDepth(treeNode->getRightNode());
    balanceFactor = rightDepth - leftDepth;

    std::string violationText = "";
    if(balanceFactor >= 2){
        violationText = " (AVL violation!)";
        tree.changeAVL_TREE_BOOL(true);
    }

    std::cout << "bal(" << treeNode->getNodeValue() << ")" << " = " << balanceFactor << violationText;

    printBalanceFactor(treeNode->getLeftNode(), tree);
    printBalanceFactor(treeNode->getRightNode(), tree);

}


int getDepth(TreeNode* treeNode){
    if (treeNode == nullptr) {
        return 0;
    }

    int leftHeight = getDepth(treeNode->getLeftNode());
    int rightHeight = getDepth(treeNode->getRightNode());

    return 1 + std::max(leftHeight, rightHeight);
}

