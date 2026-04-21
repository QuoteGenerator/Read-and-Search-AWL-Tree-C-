#include "Tree.h"

Tree::Tree() : m_root(nullptr){}

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
