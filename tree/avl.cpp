#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

class AVL {
    private:
        Node* root;

        void makeEmpty(Node* tree) {
            if(!tree) {
                return ;
            }
            makeEmpty(tree -> left);
            makeEmpty(tree -> right);
            delete tree;
        }

        int height(Node* tree) {
            if(tree) {
                return tree -> height;
            } else {
                return -1;
            }
        }

        Node* insert(int x, Node* tree) {
            if(!tree) {
                tree = new Node;
                tree -> data   = x;
                tree -> height = 0;
                tree -> left   = NULL;
                tree -> right  = NULL;
            } else if(x < tree -> data) {
                tree -> left = insert(x, tree -> left);

                if(height(tree -> left) - height(tree -> right) == 2) {
                    
                    if(x < tree -> left -> data) { // LL
                        tree = singleRotateWithLeft(tree);
                    } else { // LR
                        tree = doubleRotateWithLeft(tree);
                    }
                
                }

            } else if(x > tree -> data) {
                tree -> right = insert(x, tree -> right);
                
                if(height(tree -> right) - height(tree -> left) == 2) {
                    
                    if(x > tree -> right -> data) { // RR
                        tree = singleRotateWithRight(tree);
                    } else { // RL
                        tree = doubleRotateWithRight(tree);
                    }
                
                }
            }

            tree -> height = max(height(tree -> left), height(tree -> right)) + 1;
            return tree;
        }

        Node* singleRotateWithLeft(Node* tree) { // LL
            Node* temp = tree -> left;
            tree -> left  = temp -> right;
            temp -> right = tree;

            tree -> height = max(height(tree -> left), height(tree -> right)) + 1;
            temp -> height = max(height(temp -> left), tree -> height) + 1;

            return temp;   
        }

        Node* singleRotateWithRight(Node* tree) { // RR
            Node* temp   = tree -> right;

            tree -> right = temp -> left;
            temp -> left  = tree;

            tree -> height = max(height(tree -> left), height(tree -> right)) + 1;
            temp -> height = max(tree -> height, height(temp -> right)) + 1; 

            return temp; 
        }

        Node* doubleRotateWithLeft(Node* tree) {
            tree -> left = singleRotateWithRight(tree -> left);
            return singleRotateWithLeft(tree);
        }

        Node* doubleRotateWithRight(Node* tree) {
            tree -> right = singleRotateWithLeft(tree -> right);
            return singleRotateWithRight(tree);
        }

        Node* findMin(Node* tree) {
            if(!tree) {
                return tree;
            } else if(!tree -> left) {
                return tree;
            } else {
                return findMin(tree -> left);
            }
        }

        Node* findMax(Node* tree) {
            if(!tree) {
                return tree;
            } else if(!tree -> right) {
                return tree;
            } else {
                return findMax(tree);
            }
        }

        Node* remove(int x, Node* tree) {
            Node* temp;

            if(!tree) {
                return tree;
            } else if(x > tree -> data) {
                tree -> right = remove(x, tree -> right);
            } else if(x < tree -> data){
                tree -> left = remove(x, tree -> left);
            } else if(tree -> left && tree -> right) {
                temp = findMin(tree -> right);
                tree -> data = temp -> data;
                tree -> right = remove(tree -> data, tree -> right);  
            } else {
                temp = tree;
                if(!tree -> left) {
                    tree = tree -> right;
                } else if(!tree -> right){
                    tree = tree -> left;
                }
                delete temp;
            }

            // 再次判断, 防止删除的节点是根节点
            if(!tree) {
                return tree;
            }

            tree -> height = max(height(tree -> left), height(tree -> right)) + 1;

            if(height(tree -> left) - height(tree -> right) == 2) {
                if(height(tree -> left -> left) - height(tree -> left -> right) == 1) { // LL型
                    return singleRotateWithRight(tree);
                } else {
                    return doubleRotateWithRight(tree);
                }
            } else if(height(tree -> right) - height(tree -> left) == 2) {
                if(height(tree -> right -> right) - height(tree -> right -> left) == 1) {
                    return singleRotateWithLeft(tree);
                } else {
                    return doubleRotateWithLeft(tree);
                }
            }

            return tree;
        }

        void inOrder(Node* tree) {
            if(!tree) {
                return ;
            } else {
                inOrder(tree -> left);
                cout << tree -> data << " ";
                inOrder(tree -> right);
            }
        }

    public:
        AVL() {
            root = NULL;
        }

        void insert(int x) {
            root = insert(x, root);
        }

        void remove(int x) {
            root = remove(x, root);
        }

        void display() {
            inOrder(root);
            cout << endl;
        }
};

int main() {
    AVL t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.insert(5);
    t.insert(35);
    t.insert(67);
    t.insert(43);
    t.insert(21);
    t.insert(10);
    t.insert(89);
    t.insert(38);
    t.insert(69);
    t.display();
    t.remove(5);
    t.remove(35);
    t.remove(65);
    t.remove(89);
    t.remove(43);
    t.remove(88);
    t.remove(20);
    t.remove(38);
    t.display();
}
