#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// menyimpan deklarasi dalam struct TNode
struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // constructor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// melihat node dari root, subtree kiri, dan terakhir ke subtree kanan
void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

// melihat node dari subtree kiri, root, dan terakhir ke subtree kanan
void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

// melihat node dari subtree kiri, subtree kanan, dan terakhir ke root
void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

// melakukan pencarian pada suatu node berdasarkan nilai
TNode* search_Ardelia_2311110051(TNode* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    TNode* leftSearch = search_Ardelia_2311110051(root->left, value);
    if (leftSearch != NULL) return leftSearch;
    return search_Ardelia_2311110051(root->right, value);
}

// menambahkan node
void addNode(TNode* &root, int parentValue, int value, char child) {
    TNode* parent = search_Ardelia_2311110051(root, parentValue);
    if (parent == NULL) {
        cout << "Parent node not found!" << endl;
        return;
    }
    if (child == 'L') {
        if (parent->left == NULL) {
            parent->left = new TNode(value);
        } else {
            cout << "Left child already exists!" << endl;
        }
    } else if (child == 'R') {
        if (parent->right == NULL) {
            parent->right = new TNode(value);
        } else {
            cout << "Right child already exists!" << endl;
        }
    } else {
        cout << "Invalid child type!" << endl;
    }
}

// tampilkan child dari node
void tampilkanChildren(TNode* node) {
    if (node == NULL) {
        cout << "Node not found!" << endl;
        return;
    }
    cout << "Children of node " << node->data << ": ";
    if (node->left != NULL) {
        cout << node->left->data << " (Left) ";
    }
    if (node->right != NULL) {
        cout << node->right->data << " (Right) ";
    }
    if (node->left == NULL && node->right == NULL) {
        cout << "None";
    }
    cout << endl;
}

// tampilkan descendants dari node
void tampilkanDescendants(TNode* node) {
    if (node == NULL) {
        cout << "Node not found!" << endl;
        return;
    }
    cout << "Descendants of node " << node->data << ": ";
    queue<TNode*> qvalue;
    qvalue.push(node);
    bool first = true;
    while (!qvalue.empty()) {
        TNode* current = qvalue.front();
        qvalue.pop();
        if (!first) {
            cout << current->data << " ";
        }
        if (current->left != NULL) {
            qvalue.push(current->left);
        }
        if (current->right != NULL) {
            qvalue.push(current->right);
        }
        first = false;
    }
    cout << endl;
}

// main program (program utama)
int main() {
    TNode* root = NULL;
    int pilihan, value, parentValue;
    char child;

    // tampilkan opsi yang dapat dipilih pada program menu
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Tambah node root" << endl;
        cout << "2. Tambah node anak" << endl;
        cout << "3. Pre-order traversal" << endl;
        cout << "4. In-order traversal" << endl;
        cout << "5. Post-order traversal" << endl;
        cout << "6. Tampilkan child dari node" << endl;
        cout << "7. Tampilkan descendant dari node" << endl;
        cout << "8. Keluar" << endl;
        cout << "Opsi mana yang ingin Anda pilih? : ";
        cin >> pilihan;

        // jalankan case sesuai opsi yang dipilih (1-8)
        switch (pilihan) {
            // case 1 menambahkan nilai root
            case 1:
                if (root != NULL) {
                    cout << "Root already exists!" << endl;
                } else {
                    cout << "Masukkan nilai untuk root: ";
                    cin >> value;
                    root = new TNode(value);
                }
                break;
            // case 2 memasukkan nilai anak sesuai dengan node parent
            case 2:
                cout << "Masukkan nilai parent: ";
                cin >> parentValue;
                cout << "Masukkan nilai anak: ";
                cin >> value;
                cout << "L (left) atau R (right): ";
                cin >> child;
                addNode(root, parentValue, value, child);
                break;
            // case 3 menampilkan pre-order traversal
            case 3:
                cout << "Pre-order traversal: ";
                preOrder(root);
                cout << endl;
                break;
            // case 4 menampilkan in-order traversal
            case 4:
                cout << "In-order traversal: ";
                inOrder(root);
                cout << endl;
                break;
            // case 5 menampilkan post-order traversal
            case 5:
                cout << "Post-order traversal: ";
                postOrder(root);
                cout << endl;
                break;
            // case 6 menampilkan node children berdasarkan nilai node yang dimasukkan
            case 6:
                cout << "Masukkan nilai node: ";
                cin >> value;
                tampilkanChildren(search_Ardelia_2311110051(root, value));
                break;
            // case 7 menampilkan node descendants berdasarkan nilai node yang dimasukkan
            case 7:
                cout << "Masukkan nilai node: ";
                cin >> value;
                tampilkanDescendants(search_Ardelia_2311110051(root, value));
                break;
            // case 8 keluar dari prorgam
            case 8:
                return 0;
            // tampilan apabila user memasukkan opsi selain 1 hingga 8
            default:
                cout << "Opsi yang Anda pilih tidak valid! Silakan masukkan opsi lain." << endl;
        }
    }
    cout << endl;
    return 0;
}
