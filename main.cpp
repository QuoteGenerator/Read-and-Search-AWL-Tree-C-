#include "Tree.h"

int main(int argc, char* argv[]){
    if(argc != 3){
        std::cerr << "Usage: treecheck [file.txt] [file.txt]\n";
        return 1;
    }
    Tree tree;
    tree.readFromFile(argv[1]);



}

