#include "Tree.h"

Tree::Tree() : m_root(nullptr), m_sum(0){}

void Tree::readFromFile(const char* filename){
    std::vector<int> keys;
    int key;

    std::ifstream file(filename);

    if(!file.is_open()){
        std::cerr << "Could not open " << filename << '\n';
    }


    while(file >> key){
        keys.emplace_back(key);
    }

    //remove duplicates
    for(size_t i = 0; i < keys.size(); ++i){
        for(size_t j = 0; j < keys.size(); ++j){
            if(keys[i] == keys[j] && i != j){
                keys.erase(keys.begin() + i);
            }
        }
    }

    //add to tree
    for(auto key : keys){
        ++m_length;
        if(m_root == nullptr){
            m_root = new TreeNode(key);
        }
        else{
            m_root = m_root->addNode(m_root, key);
        }

        std::cout << key << '\n';
    }
}

TreeNode* Tree::get_m_root(){
    return m_root;
}


void Tree::changeAVL_TREE_BOOL(bool isItTrue){
    AVL_TREE_CHECK = isItTrue;
}

bool Tree::getAVL_TREE_CHECK(){
    return AVL_TREE_CHECK;
}


//Maximum
int Tree::maxValue(TreeNode* treeNode) {
    if (treeNode->getRightNode() == nullptr)
        return treeNode->getNodeValue();
    return maxValue(treeNode->getRightNode());
}

//Minimum
int Tree::minValue(TreeNode* treeNode) {
    if (treeNode->getLeftNode() == nullptr)
        return treeNode->getNodeValue();
    return minValue(treeNode->getLeftNode());
}

//Average
void Tree::avgValue(TreeNode* treeNode) {
    if (treeNode == nullptr) {
        return;
    }

    avgValue(treeNode->getLeftNode());
    avgValue(treeNode->getRightNode());
    m_sum += treeNode->getNodeValue();
}



void Tree::printStats(){
    avgValue(m_root);
    int treeMax = maxValue(m_root);
    int treeMin = minValue(m_root);
    std::cout << "\nmin:"<< treeMin << ',';
    std::cout << "max:" << treeMax << ',';
    std::cout << "avg:" << m_sum/m_length << '\n';
}
