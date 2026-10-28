#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Book {
    int ISBN;
    string title;
    string author;
    Book* left;
    Book* right;
    int height;
};

Book* createBook(int ISBN, string title, string author) {
    Book* newBook = new Book();
    newBook->ISBN = ISBN;
    newBook->title = title;
    newBook->author = author;
    newBook->left = nullptr;
    newBook->right = nullptr;
    newBook->height = 1;
    return newBook;
}

int getHeight(Book* node) {
    if (node) {
        return node->height;
    } else {
        return 0;
    }
}

int getBalance(Book* node) {
    if (node) {
        return getHeight(node->left) - getHeight(node->right);
    } else {
        return 0;
    }
}

Book* rotateRight(Book* rootNode) {
    Book* leftChild = rootNode->left;
    Book* tempSubtree = leftChild->right;
    leftChild->right = rootNode;
    rootNode->left = tempSubtree;
    rootNode->height = max(getHeight(rootNode->left), getHeight(rootNode->right)) + 1;
    leftChild->height = max(getHeight(leftChild->left), getHeight(leftChild->right)) + 1;
    return leftChild;
}

Book* rotateLeft(Book* rootNode) {
    Book* rightChild = rootNode->right;
    Book* tempSubtree = rightChild->left;
    rightChild->left = rootNode;
    rootNode->right = tempSubtree;
    rootNode->height = max(getHeight(rootNode->left), getHeight(rootNode->right)) + 1;
    rightChild->height = max(getHeight(rightChild->left), getHeight(rightChild->right)) + 1;
    return rightChild;
}

Book* insertBook(Book* root, int ISBN, string title, string author) {
    if (!root) return createBook(ISBN, title, author);
    if (ISBN < root->ISBN) {
        root->left = insertBook(root->left, ISBN, title, author);
    } else if (ISBN > root->ISBN) {
        root->right = insertBook(root->right, ISBN, title, author);
    } else {
        return root; 
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);
    
    // Balancing tree
    if (balance > 1 && ISBN < root->left->ISBN) {
        return rotateRight(root);
    }
    if (balance < -1 && ISBN > root->right->ISBN) {
        return rotateLeft(root);
    }
    if (balance > 1 && ISBN > root->left->ISBN) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && ISBN < root->right->ISBN) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

Book* minValueBook(Book* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

Book* deleteBook(Book* root, int ISBN) {
    if (!root) return root;
    if (ISBN < root->ISBN) {
        root->left = deleteBook(root->left, ISBN);
    } else if (ISBN > root->ISBN) {
        root->right = deleteBook(root->right, ISBN);
    } else {
        if (!root->left || !root->right) {
            Book* temp;
            if (root->left) {
                temp = root->left;
            } else {
                temp = root->right;
            }
            if (!temp) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            Book* temp = minValueBook(root->right);
            root->ISBN = temp->ISBN;
            root->title = temp->title;
            root->author = temp->author;
            root->right = deleteBook(root->right, temp->ISBN);
        }
    }
    if (!root) return root;
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);
    
    // Balancing tree again after deleting a node
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rotateRight(root);
    }
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) {
        return rotateLeft(root);
    }
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

void searchBook(Book* root, int ISBN) {
    if (!root) {
        cout << "Book not found.\n";
        return;
    }
    if (ISBN == root->ISBN) {
        cout << "Book Found: " << root->title << " by " << root->author << "\n";
    } else if (ISBN < root->ISBN) {
        searchBook(root->left, ISBN);
    } else {
        searchBook(root->right, ISBN);
    }
}

void inorder(Book* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->ISBN << " - " << root->title << " by " << root->author << "\n";
    inorder(root->right);
}

int main() {
    Book* root = nullptr;
    root = insertBook(root, 34567, "Harry Potter and the Philosopher's Stone", "J. K. Rowling");
    root = insertBook(root, 22267, "Harry Potter and the Chamber of Secrets", "J. K. Rowling");
    root = insertBook(root, 12635, "Harry Potter and the Prisoner of Azkaban", "J. K. Rowling");

    cout << "All books in sorted order:\n";
    inorder(root);

    cout << "\nSearching for ISBN 22267:\n";
    searchBook(root, 22267);

    cout << "\nDeleting ISBN 22267\n";
    root = deleteBook(root, 22267);

    cout << "\nAll books after deletion:\n";
    inorder(root);
    return 0;
}


