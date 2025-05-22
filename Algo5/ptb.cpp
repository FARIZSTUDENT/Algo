#include <iostream>

using namespace std;

struct PtbNode {
    int data;
    PtbNode* left;
    PtbNode* right;

    PtbNode(int val){
            data = val;
            left = right = nullptr;
    }
};

int main(){
      PtbNode* root = new PtbNode(15);
      root->left = new PtbNode(10);
      root->right = new PtbNode(20);
      root->left->left = new PtbNode(9);
      root->left->right = new PtbNode(12);

      cout << "Root: " << root->data << endl;
      cout << "Anak kiri dari root: " << root->left->data << endl;
      cout << "Anak kanan dari root: " << root->right->data << endl;
      cout << "Anak kiri dari PTB Node 2: " << root->left->left->data << endl;
      cout << "Anak kanan dari PTB Node 2: " << root->left->right->data << endl;

}