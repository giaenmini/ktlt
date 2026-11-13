#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int x)
{
    Node* p = new Node;
    p->data = x;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

Node* search(Node* root, int x)
{
    if (root == nullptr)
        return nullptr;

    if (root->data == x)
        return root;

    if (x < root->data)
        return search(root->left, x);

    return search(root->right, x);
}

Node* insert(Node* root, int x)
{
    if (root == nullptr)
        return createNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

void nhapDaySo(Node*& root)
{
    int n, x;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> x;
        root = insert(root, x);
    }
}

int main()
{
    Node* root = nullptr;
    
    nhapDaySo(root);
    
    cout << "\nDuyet inorder: ";
    inorder(root);
    cout << endl;

    return 0;
}