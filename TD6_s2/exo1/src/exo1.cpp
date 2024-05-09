#include <iostream>
#include <vector>

struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    Node(int val) : value(val) {}

    bool is_leaf() const {
        return (left == nullptr && right == nullptr);
    }

    void insert(int val) {
        if (val < value) {
            if (left == nullptr) {
                left = create_node(val);
            } else {
                left->insert(val);
            }
        } else {
            if (right == nullptr) {
                right = create_node(val);
            } else {
                right->insert(val);
            }
        }
    }

    int height() const {
        if (this == nullptr)
            return 0;
        int left_height = (left != nullptr) ? left->height() : 0;
        int right_height = (right != nullptr) ? right->height() : 0;
        return 1 + std::max(left_height, right_height);
    }

    void delete_childs() {
        if (left != nullptr) {
            left->delete_childs();
            delete left;
            left = nullptr;
        }
        if (right != nullptr) {
            right->delete_childs();
            delete right;
            right = nullptr;
        }
    }

    void display_infixe() const {
        if (left != nullptr) {
            left->display_infixe();
        }
        std::cout << value << " ";
        if (right != nullptr) {
            right->display_infixe();
        }
    }

    std::vector<Node const*> prefixe() const {
        std::vector<Node const*> nodes;
        nodes.push_back(this);
        if (left != nullptr) {
            auto left_nodes = left->prefixe();
            nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
        }
        if (right != nullptr) {
            auto right_nodes = right->prefixe();
            nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
        }
        return nodes;
    }

    void postfixe_helper(std::vector<Node const*>& nodes) const {
        if (left != nullptr) {
            left->postfixe_helper(nodes);
        }
        if (right != nullptr) {
            right->postfixe_helper(nodes);
        }
        nodes.push_back(this);
    }

    std::vector<Node const*> postfixe() const {
        std::vector<Node const*> nodes;
        postfixe_helper(nodes);
        return nodes;
    }
};

Node* create_node(int value) {
    return new Node(value);
}

void delete_tree(Node* node) {
    if (node != nullptr) {
        node->delete_childs();
        delete node;
    }
}

Node*& most_left(Node*& node) {
    if (node->left == nullptr) {
        return node;
    }
    return most_left(node->left);
}

bool remove(Node*& node, int value) {
    if (node == nullptr) {
        return false;
    }
    if (value < node->value) {
        return remove(node->left, value);
    } else if (value > node->value) {
        return remove(node->right, value);
    } else {
        if (node->is_leaf()) {
            delete node;
            node = nullptr;
            return true;
        } else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
            return true;
        } else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
            return true;
        } else {
            Node*& leftmost = most_left(node->right);
            node->value = leftmost->value;
            return remove(leftmost, leftmost->value);
        }
    }
}

int main() {
    Node* root = create_node(5);
    root->insert(3);
    root->insert(7);
    root->insert(2);
    root->insert(4);
    root->insert(6);
    root->insert(8);
    root->insert(1);
    root->insert(9);
    root->insert(0);

    std::cout << "infixe parcour: ";
    root->display_infixe();
    std::cout << std::endl;

    std::vector<Node const*> postfix_nodes = root->postfixe();
    int sum = 0;
    for (auto* node : postfix_nodes) {
        sum += node->value;
    }
    std::cout << "Somme av prefixe: " << sum << std::endl;

    std::cout << "Hauteur: " << root->height() << std::endl;

    delete_tree(root);

    return 0;
}