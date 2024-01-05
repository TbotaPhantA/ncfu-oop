#include <iostream>
#include<stdio.h>
#include<windows.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;

struct Translation {
    string word;
    string translation;
};

class Node {
    Node* left;
    Node* right;

public:
    Translation translation;

    Node(Translation t) {
        this->translation = t;
        this->left = nullptr;
        this->right = nullptr;
    }

    void insert(Translation t) {
        if (t.word == translation.word) return;
        bool isLeft = t.word < translation.word;

        Node* node = isLeft ? left : right;

        if (node == nullptr) {
            node = new Node(t);
        }
        else {
            node->insert(t);
        }

        if (isLeft) {
            left = node;
        }
        else {
            right = node;
        }
    }

    Node* find(string word) {
        if (this->translation.word == word) {
            return this;
        }
        else if (word < this->translation.word && this->left != nullptr) {
            return this->left->find(word);
        }
        else if (word > this->translation.word && this->right != nullptr) {
            return this->right->find(word);
        }
        else {
            return nullptr;
        }
    }

    Node* remove(string word, Node* parent = nullptr) {
        if (word < translation.word && left != nullptr) {
            return left->remove(word, this);
        }
        else if (word > translation.word && right != nullptr) {
            return right->remove(word, this);
        }
        else if (word == translation.word) {
            if (left != nullptr && right != nullptr) {
                // Node has two children
                Node* successor = right->minimum();
                translation = successor->translation;
                return right->remove(successor->translation.word, this);
            }
            else if (parent == nullptr) {
                // Node is root
                if (left != nullptr) {
                    translation = left->translation;
                    right = left->right;
                    left = left->left;
                }
                else if (right != nullptr) {
                    translation = right->translation;
                    left = right->left;
                    right = right->right;
                }
                else {
                    // Node has no children
                    translation = Translation();
                }
                return this;
            }
            else if (this == parent->left) {
                // Node is left child
                parent->left = left != nullptr ? left : right;
                return this;
            }
            else if (this == parent->right) {
                // Node is right child
                parent->right = left != nullptr ? left : right;
                return this;
            }
        }
        return nullptr;
    }

    Node* minimum() {
        if (left == nullptr) {
            return this;
        }
        else {
            return left->minimum();
        }
    }

    void traverse() {
        if (this->left != nullptr) {
            this->left->traverse();
        }
        cout << this->translation.word << " : " << this->translation.translation << std::endl;
        if (this->right != nullptr) {
            this->right->traverse();
        }
    }
};

void printMenu() {
    cout << "Binary Tree Operations:" << endl;
    cout << "1. Insert a node" << endl;
    cout << "2. Find a node" << endl;
    cout << "3. Remove a node" << endl;
    cout << "4. Traverse the tree" << endl;
    cout << "5. Exit" << endl;
}

// ("a" < "b") -> 1
// ("a" > "b") -> 0

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Node* root = nullptr;
    int choice = 0;

    while (choice != 5) {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        string word, translation;

        if (choice == 1) {
            string word, translation;
            cout << "Enter the word to insert: ";
            cin >> word;
            cout << "Enter the translation: ";
            cin >> translation;
            root = root == nullptr ? new Node({ word, translation }) : root;
            root->insert({ word, translation });
            cout << "Node inserted successfully." << endl;
        }
        else if (choice == 2) {
            cout << "Enter the word to find: ";
            cin >> word;
            if (root == nullptr) {
                cout << "Tree is empty." << endl;
            }
            else {
                Node* node = root->find(word);
                if (node == nullptr) {
                    cout << "Node not found." << endl;
                }
                else {
                    cout << "Node found: " << node->translation.word << " : " << node->translation.translation << endl;
                }
            }
        }
        else if (choice == 3) {
            cout << "Enter the word to remove: ";
            cin >> word;
            if (root == nullptr) {
                cout << "Tree is empty." << endl;
            }
            else {
                Node* node = root->remove(word);
                if (node == nullptr) {
                    cout << "Node not found." << endl;
                }
                else {
                    cout << "Node removed successfully." << endl;
                }
            }
        }
        else if (choice == 4) {
            if (root == nullptr) {
                cout << "Tree is empty." << endl;
            }
            else {
                root->traverse();
            }
        }
        else if (choice == 5) {
            cout << "Exiting program..." << endl;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
