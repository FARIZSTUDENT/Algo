#include <iostream>
#include <string>

using namespace std;

struct PtbNode {
    int data;
    PtbNode* left;
    PtbNode* right;

    PtbNode(int val){
            data = val;
            left = left = nullptr;
    }
};

int main(){
      PtbNode* root = new PtbNode(15);
      root->left = new PtbNode(10);
      root->right = new PtbNode(20);
      root->left->left = new PtbNode(9);
}