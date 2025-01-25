#include <iostream>
using namespace std;

class AVLNode {
public:
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int value) {
        data = value;
        left = right = nullptr;
        height = 1; // New node is initially added at leaf
    }
};

class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int getBalance(AVLNode* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    AVLNode* insert(AVLNode* node, int data) {
        if (node == nullptr) return new AVLNode(data);

        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        else
            return node; // Duplicate data are not allowed

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && data < node->left->data)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && data > node->right->data)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    AVLNode* deleteNode(AVLNode* root, int data) {
        if (root == nullptr) return root;

        if (data < root->data)
            root->left = deleteNode(root->left, data);
        else if (data > root->data)
            root->right = deleteNode(root->right, data);
        else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                AVLNode* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;

                delete temp;
            }
            else {
                AVLNode* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        if (root == nullptr) return root;

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void preOrder(AVLNode* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void inOrder(AVLNode* root) {
        if (root != nullptr) {
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }
    }

public:
    AVLTree() {
        root = nullptr;
    }

    void insert(int data) {
        root = insert(root, data);
    }

    void deleteNode(int data) {
        root = deleteNode(root, data);
    }

    void preOrder() {
        preOrder(root);
    }

    void inOrder() {
        inOrder(root);
    }
};

int main() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "Preorder traversal of the constructed AVL tree is \n";
    tree.preOrder();

    cout << "\nInorder traversal of the constructed AVL tree is \n";
    tree.inOrder();

    tree.deleteNode(40);
    cout << "\nPreorder traversal after deletion of 40 \n";
    tree.preOrder();

    return 0;
}
