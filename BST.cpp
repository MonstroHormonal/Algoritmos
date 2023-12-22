#include <iostream>

using namespace std;

class BSTNode{
public:
    int key;
    int element;
    BSTNode *left, *right;

    BSTNode(int k, int e)
    {
        key = k;
        element = e;
        left = right = NULL;
    }
};

class BST{
private:
    BSTNode *root;
    int nodecount;

    int FindInternal(BSTNode *rt, int key)
    {
        if(rt == NULL) return NULL;
        if(rt->key > key) return FindInternal(rt->left, key);
        else if(rt->key == key) return rt->element;
        else return FindInternal(rt->right, key);
    }

    BSTNode *getmin(BSTNode *rt){

        if(rt->left == NULL) return rt;
        return getmin(rt->left);
    }

    BSTNode *deletemin(BSTNode *rt){

        if(rt->left == NULL) return rt->right;
        rt->left = deletemin(rt->left);
        return rt;
    }

    BSTNode *inserthelp(BSTNode *rt, int k, int e){
    
        if(rt == NULL) return new BSTNode(k, e)
        if(rt->key > k) rt->left = inserthelp(rt->left, k, e);
        else rt->right = inserthelp(rt->right, k, e);
        return rt;
    }

    BSTNode *removehelp(BSTNode *rt, int k){

        if(rt == NULL) return NULL;
        if(rt->key > k) rt->left = removehelp(rt->left, k);
        else if(rt->key < k) rt->right = removehelp(rt->right, k);
        else{
            if(rt->left == NULL) return rt->right;
            else if(rt->right == NULL) return rt->left;
            else{
                BSTNode *temp = getmin(rt->right);
                rt->element = temp->element;
                rt->key = temp->key;
                rt->right = deletemin(rt->right);
            }
        }
    }

public:
    BST(){
        root = NULL;
        nodecount = 0;
    }

    ~BST(){
        Clear(root);
    }

    int Find(int key){
        return FindInternal(root, key);
    }

    void insert(BSTNode *bst, int k, int e){

        bst->root = inserthelp(bst->root, k, e);
    }

    int remove(BST *bst, int k){
        
        int temp = findhelp(bst->root, k);
        if(temp != NULL){
            bst->root = removehelp(bst->root, k)
            bst->nodecount--;
        }
        return temp;
    }

    Clear(BSTNode *rt){

            if(rt != NULL){
            Clear(rt->left);
            Clear(rt->right);
            delete rt;
        }
    }

};

void preorder(BSTNode *rt){

    if(rt != NULL){
        printf("%d", rt->key);
        preorder(rt->left);
        preorder(rt->right);
    }
}

void inorder(BSTNode *rt){

    if(rt != NULL){
        inorder(rt->left);
        printf("%d", rt->key);
        inorder(rt->right);
    }
}

void postorder(BSTNode *rt){
    
    if(rt != NULL){
        postorder(rt->left);
        postorder(rt->right);
        printf("%d", rt->key);
    }
}

int main(){

    return 0;
}