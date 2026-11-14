#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
} 

bool search(Node* root, int val) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == val) {
        return true;
    }
    if (val < root->data) {
        return search(root->left, val);
    }
    return search(root->right, val);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node* findMin(Node* root) {
    while (root != nullptr && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int val) {
    if (root == nullptr) return nullptr;

    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* successor = findMin(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }
    return root;
}

int main() {
    Node* root = nullptr;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};

    for (int x : arr) {
        root = insert(root, x);
    }

    cout << "Preorder:  "; preorder(root); cout << endl;
    cout << "Inorder:   "; inorder(root); cout << endl;
    cout << "Postorder: "; postorder(root); cout << endl;

    cout << "\nSearch(40):  " << (search(root, 40) ? "Tim thay" : "Khong tim thay") << endl;
    cout << "Search(100): " << (search(root, 100) ? "Tim thay" : "Khong tim thay") << endl;

    root = deleteNode(root, 20);
    cout << "\nInorder sau khi xoa 20: "; inorder(root); cout << endl;

    root = deleteNode(root, 30);
    cout << "Inorder sau khi xoa 30: "; inorder(root); cout << endl;

    root = deleteNode(root, 50);
    cout << "Inorder sau khi xoa 50: "; inorder(root); cout << endl;

    return 0;
}