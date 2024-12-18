#include <iostream>
using namespace std;

struct bstnode {
    int data;
    struct bstnode *left, *right;
};

void inorder(struct bstnode *root);
void mirror(struct bstnode *node);
int Maxdepth(struct bstnode *root);

struct bstnode *newNode(int v) {
    bstnode *temp = new bstnode();
    temp->data = v;
    temp->left = temp->right = NULL;
    return temp;
}

struct bstnode *insert(struct bstnode *node, int key) {
    if (node == NULL) 
        return newNode(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

struct bstnode *search(struct bstnode *root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
        return search(root->right, key);
    return search(root->left, key);
}

struct bstnode *minValueNode(struct bstnode *node) {
    struct bstnode *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct bstnode *deleteNode(struct bstnode *root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct bstnode *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            struct bstnode *temp = root->left;
            delete root;
            return temp;
        } else {
            struct bstnode *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void inorder(struct bstnode *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void mirror(struct bstnode *node) {
    if (node == NULL)
        return;
    else {
        struct bstnode *temp;
        mirror(node->left);
        mirror(node->right);
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

int Maxdepth(struct bstnode *root) {
    if (root == NULL) {
        return 0;
    } else {
        int depth1 = Maxdepth(root->left);
        int depth2 = Maxdepth(root->right);
        return (depth1 > depth2) ? (depth1 + 1) : (depth2 + 1);
    }
}

int main() {
    struct bstnode *root = NULL;
    int ch, n, d, depth;

    while (1) {
        cout << endl << "Which operation would you want to perform?";
        cout << endl << "1. INSERT";
        cout << endl << "2. DELETE";
        cout << endl << "3. SEARCH";
        cout << endl << "4. TRAVERSAL";
        cout << endl << "5. DEPTH OF BST";
        cout << endl << "6. MIRROR IMAGE";
        cout << endl << "7. EXIT";
        cout << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nEnter number of values to insert: ";
                cin >> n;
                cout << "\nEnter the values to create BST:\n ";
                for (int i = 0; i < n; i++) {
                    cin >> d;
                    root = insert(root, d);
                }
                break;
            case 2:
                cout << "\nEnter the element to delete: ";
                cin >> d;
                root = deleteNode(root, d);
                break;
            case 3:
                cout << "\nEnter the element to search: ";
                cin >> d;
                if (search(root, d) != NULL)
                    cout << "\nFound in BST!!";
                else
                    cout << "\nNot Found in BST!!";
                break;
            case 4:
                cout << "\nTraversal of BST: ";
                inorder(root);
                cout << endl;
                break;
            case 5:
                depth = Maxdepth(root);
                cout << "The depth of BST is: " << depth;
                break;
            case 6:
                mirror(root);
                cout << "\nInorder traversal of the mirror BST is: ";
                inorder(root);
                cout << endl;
                mirror(root);
                break;
            case 7:
                return 0;
            default:
                cout << "\nWrong Option";
        }
    }
    return 0;
}
