#include <iostream>
using namespace std;

// ---------- BINARY SEARCH TREE ----------

struct Node
{
    int data;
    Node *left, *right;
};

Node* createNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertBST(Node* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insertBST(root->left, value);
    else if (value > root->data)
        root->right = insertBST(root->right, value);

    return root;
}

// ---------- AVL TREE ----------

struct AVLNode
{
    int data, height;
    AVLNode *left, *right;
};

int height(AVLNode* node)
{
    if (node == NULL)
        return 0;

    return node->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

AVLNode* createAVLNode(int value)
{
    AVLNode* node = new AVLNode;
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

AVLNode* rightRotate(AVLNode* y)
{
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* leftRotate(AVLNode* x)
{
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(AVLNode* node)
{
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

AVLNode* insertAVL(AVLNode* node, int value)
{
    if (node == NULL)
        return createAVLNode(value);

    if (value < node->data)
        node->left = insertAVL(node->left, value);
    else if (value > node->data)
        node->right = insertAVL(node->right, value);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    // Right Right
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    // Left Right
    if (balance > 1 && value > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left
    if (balance < -1 && value < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// ---------- TRAVERSAL METHODS ----------

// BST Traversals
void inorderBST(Node* root)
{
    if (root != NULL)
    {
        inorderBST(root->left);
        cout << root->data << " ";
        inorderBST(root->right);
    }
}

void preorderBST(Node* root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorderBST(root->left);
        preorderBST(root->right);
    }
}

void postorderBST(Node* root)
{
    if (root != NULL)
    {
        postorderBST(root->left);
        postorderBST(root->right);
        cout << root->data << " ";
    }
}

// AVL Traversals
void inorderAVL(AVLNode* root)
{
    if (root != NULL)
    {
        inorderAVL(root->left);
        cout << root->data << " ";
        inorderAVL(root->right);
    }
}

void preorderAVL(AVLNode* root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorderAVL(root->left);
        preorderAVL(root->right);
    }
}

void postorderAVL(AVLNode* root)
{
    if (root != NULL)
    {
        postorderAVL(root->left);
        postorderAVL(root->right);
        cout << root->data << " ";
    }
}

// ---------- MAIN FUNCTION ----------

int main()
{
    Node* bstRoot = NULL;
    AVLNode* avlRoot = NULL;

    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        bstRoot = insertBST(bstRoot, value);
        avlRoot = insertAVL(avlRoot, value);
    }

    cout << "\n--- BST Traversals ---\n";

    cout << "Inorder: ";
    inorderBST(bstRoot);

    cout << "\nPreorder: ";
    preorderBST(bstRoot);

    cout << "\nPostorder: ";
    postorderBST(bstRoot);

    cout << "\n\n--- AVL Tree Traversals ---\n";

    cout << "Inorder: ";
    inorderAVL(avlRoot);

    cout << "\nPreorder: ";
    preorderAVL(avlRoot);

    cout << "\nPostorder: ";
    postorderAVL(avlRoot);

    cout << endl;

    return 0;
}