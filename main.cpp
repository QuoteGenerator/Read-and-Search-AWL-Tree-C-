#include "Tree.h"

void printBalanceFactor(TreeNode* treeNode, Tree& tree);
int getDepth(TreeNode* treeNode);
void keyWordSearch(TreeNode* treeNode, TreeNode* subtreeNode, bool& exists, std::vector<int> quickNodeSave);
void subTreeSearch(TreeNode* treeNode, TreeNode* subtreeNode, bool& exists, std::vector<int> quickNodeSave);
TreeNode* findStartNode(TreeNode* treeNode, int value);
bool matchSubtree(TreeNode* bigNode, TreeNode* smallNode);
void exit();

int main(int argc, char* argv[]){

    int menuInput;
    std::cout << "(1) Start"; std::cout << " | (2) Exit\nCHOOSE: ";
    std::cin >> menuInput;

    if(menuInput == 2){
        exit();
        return 0;
    }

    bool exists = false;
    if(argc != 3){
        std::cerr << "Usage: treecheck [file.txt] [file.txt]\n";
        return 1;
    }
    Tree tree;

    std::cout << "Tree Values: \n";
    tree.readFromFile(argv[1]);


    printBalanceFactor(tree.get_m_root(), tree);

    if(tree.getAVL_TREE_CHECK()){
        std::cout << "\nAVL: YES";
    } else {
        std::cout << "\nAVL: NO";
    }

    tree.printStats();

    Tree subtree;
    subtree.readFromFile(argv[2]);

    std::cout << "\033[1A"; //ANSI SEQUENCE CODE -> Mit Cursor rauf
    std::cout << "\033[2K"; //Zeile Löschen | GRUND: Weil noch die z.B. 100 geprinted wird, bei einlesen des Schlüsselworts 100

    std::cout << "\n\n------ Search! ------\n";
    if(subtree.get_m_root() != nullptr){
        if(subtree.get_m_root()->getLeftNode() == nullptr && subtree.get_m_root()->getRightNode() == nullptr){
            std::cout << "Search for this keyword: " << subtree.get_m_root()->getNodeValue() << std::endl;
            keyWordSearch(tree.get_m_root(), subtree.get_m_root(), exists, {});
            if(!exists){
                std::cout << subtree.get_m_root()->getNodeValue() << " NOT FOUND!\n";
            }
        }else {
            exists = false;

            subTreeSearch(tree.get_m_root(), subtree.get_m_root(), exists, {});

            if(exists){
                std::cout << "Subtree found\n";
            } else {
                std::cout << "Subtree not found!\n";
            }
        }
    }
}


//----------------------------- GET BALANCE FACTOR -----------------------------
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
    if(balanceFactor >= 2 || balanceFactor <= -2){
        violationText = " (AVL violation!)";
        tree.changeAVL_TREE_BOOL(false);
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


//----------------------------- KEYWORD SEARCH -----------------------------
void keyWordSearch(TreeNode* treeNode, TreeNode* subtreeNode, bool& exists, std::vector<int> quickNodeSave){
    if(treeNode == nullptr){
        return;
    }
    if(exists == true){
        return;
    }

    quickNodeSave.push_back(treeNode->getNodeValue());

    if(treeNode->getNodeValue() == subtreeNode->getNodeValue()){
        exists = true;
    }

    if(exists){
        for(auto nodeValue = quickNodeSave.begin(); nodeValue != quickNodeSave.end(); nodeValue++){
            std::cout << "-> " << *nodeValue << " ";
        }
        return;
    }

    /*if(treeNode == nullptr){
        quickNodeSave.empty();
    }debug*/

    keyWordSearch(treeNode->getLeftNode(), subtreeNode, exists, quickNodeSave);
    keyWordSearch(treeNode->getRightNode(), subtreeNode, exists, quickNodeSave);
}


//----------------------------- SUBTREE SEARCH -----------------------------
TreeNode* findStartNode(TreeNode* treeNode, int value){
    if(treeNode == nullptr){
        return nullptr;
    }

    if(treeNode->getNodeValue() == value){
        return treeNode;
    }

    TreeNode* leftResult = findStartNode(treeNode->getLeftNode(), value);
    if(leftResult != nullptr){
        return leftResult;
    }

    return findStartNode(treeNode->getRightNode(), value);
}

bool matchSubtree(TreeNode* bigNode, TreeNode* smallNode){
    if(smallNode == nullptr){
        return true;
    }

    if(bigNode == nullptr){
        return false;
    }

    if(bigNode->getNodeValue() != smallNode->getNodeValue()){
        return false;
    }

    bool leftOK = true;
    bool rightOK = true;

    if(smallNode->getLeftNode() != nullptr){
        leftOK = matchSubtree(bigNode->getLeftNode(), smallNode->getLeftNode());
    }

    if(smallNode->getRightNode() != nullptr){
        rightOK = matchSubtree(bigNode->getRightNode(), smallNode->getRightNode());
    }

    return leftOK && rightOK;
}

void subTreeSearch(TreeNode* treeNode, TreeNode* subtreeNode, bool& exists, std::vector<int> quickNodeSave){



    if(treeNode == nullptr || subtreeNode == nullptr){
        exists = false;
        return;
    }

    TreeNode* startNode = findStartNode(treeNode, subtreeNode->getNodeValue());

    if(startNode == nullptr){
        exists = false;
        return;
    }

    exists = matchSubtree(startNode, subtreeNode);
}


void exit(){
    for(int i = 0; i < 200; i++){
        for(int j = 0; j < 10; j++){
            std::cout << "\033[33m18/\033[35m18 Punkte?";
        }
    }
}
