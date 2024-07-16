#include <iostream>
#include <map>

using namespace std;

struct TeamInfo {
    int wins;
    int points;
    int id;

    bool operator<(const TeamInfo& other) const {
        if (wins != other.wins) {
            return wins > other.wins;  // Higher wins come first
        } else if (points != other.points) {
            return points < other.points;  // Among same wins, higher points come first
        } else {
            return id < other.id;  // Among same wins and points, smaller id comes first
        }
    }
};

struct Node {
    TeamInfo key;
    int height;
    int size;
    Node* left;
    Node* right;
    Node(TeamInfo k) : key(k), height(1), size(1), left(nullptr), right(nullptr) {}
};

class OrderStatisticsTree {
public:
    OrderStatisticsTree() : root(nullptr) {}

    void insert(TeamInfo key) {
        root = insert(root, key);
    }

    void erase(TeamInfo key) {
        root = erase(root, key);
    }

    int order_of_key(TeamInfo key) {
        return order_of_key(root, key);
    }

private:
    Node* root;

    int height(Node* N) {
        return N ? N->height : 0;
    }

    int size(Node* N) {
        return N ? N->size : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        y->size = size(y->left) + size(y->right) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        x->size = size(x->left) + size(x->right) + 1;
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        x->size = size(x->left) + size(x->right) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        y->size = size(y->left) + size(y->right) + 1;
        return y;
    }

    int getBalance(Node* N) {
        return N ? height(N->left) - height(N->right) : 0;
    }

    Node* insert(Node* node, TeamInfo key) {
        if (!node) return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (node->key < key)
            node->right = insert(node->right, key);
        else
            return node;
        node->height = 1 + max(height(node->left), height(node->right));
        node->size = 1 + size(node->left) + size(node->right);
        int balance = getBalance(node);
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);
        if (balance < -1 && node->right->key < key)
            return leftRotate(node);
        if (balance > 1 && node->left->key < key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* erase(Node* root, TeamInfo key) {
        if (!root) return root;
        if (key < root->key)
            root->left = erase(root->left, key);
        else if (root->key < key)
            root->right = erase(root->right, key);
        else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                Node* temp = root->left ? root->left : root->right;
                if (!temp) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;
                delete temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = erase(root->right, temp->key);
            }
        }
        if (!root) return root;
        root->height = 1 + max(height(root->left), height(root->right));
        root->size = 1 + size(root->left) + size(root->right);
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

    int order_of_key(Node* node, TeamInfo key) {
        if (!node) return 0;
        if (key < node->key)
            return order_of_key(node->left, key);
        else if (node->key < key)
            return 1 + size(node->left) + order_of_key(node->right, key);
        else
            return size(node->left);
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    std::map<int, pair<int, int>> teams;
    OrderStatisticsTree ranks;

    auto insertOrUpdate = [&](int t, int p) {
        auto it = teams.find(t);
        if (it != teams.end()) {
            ranks.erase({it->second.first, it->second.second, t});
            it->second.first++;
            it->second.second += p;
            ranks.insert({it->second.first, it->second.second, t});
        } else {
            teams[t] = {1, p};
            ranks.insert({1, p, t});
        }
    };

    teams[1] = {0, 0};
    ranks.insert({0, 0, 1});

    for (int i = 0; i < m; i++) {
        int t, p;
        cin >> t >> p;
        insertOrUpdate(t, p);

        int rank = ranks.order_of_key({teams[1].first, teams[1].second, 1}) + 1;

        std::cout << rank << std::endl;
    }

    return 0;
}
