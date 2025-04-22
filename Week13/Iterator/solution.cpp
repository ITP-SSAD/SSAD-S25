#include <iostream>
#include <vector>
#include <stack>
#include <memory>
#include <algorithm>

// Forward declaration
class TreeIterator;

// Tree Node class
class TreeNode {
    int value;
    std::vector<std::shared_ptr<TreeNode>> neighbors; // Outgoing edges

public:
    explicit TreeNode(int val) : value(val) {}

    int getValue() const { return value; }

    void addNeighbor(std::shared_ptr<TreeNode> node) {
        neighbors.push_back(node);
    }

    const std::vector<std::shared_ptr<TreeNode>>& getNeighbors() const {
        return neighbors;
    }

    // Factory method for creating iterator
    std::unique_ptr<TreeIterator> createDFSIterator();
};

// Iterator interface
class TreeIterator {
public:
    virtual ~TreeIterator() = default;
    virtual bool hasNext() const = 0;
    virtual TreeNode& next() = 0;
};

// Concrete DFS Iterator
class DFSIterator : public TreeIterator {
    std::stack<std::shared_ptr<TreeNode>> nodeStack;
    std::vector<bool> visited;

    void pushIfNotVisited(std::shared_ptr<TreeNode> node) {
        if (node && !visited[node->getValue()]) {
            nodeStack.push(node);
            visited[node->getValue()] = true;
        }
    }

public:
    explicit DFSIterator(std::shared_ptr<TreeNode> root) {
        // Assuming node values are non-negative and not too large
        // For a more robust solution, use a hash set
        visited.resize(100, false); // Adjust size as needed
        pushIfNotVisited(root);
    }

    bool hasNext() const override {
        return !nodeStack.empty();
    }

    TreeNode& next() override {
        if (!hasNext()) {
            throw std::out_of_range("No more nodes");
        }

        auto current = nodeStack.top();
        nodeStack.pop();

        // Push neighbors in reverse order to visit them in order
        const auto& neighbors = current->getNeighbors();
        for (auto it = neighbors.rbegin(); it != neighbors.rend(); ++it) {
            pushIfNotVisited(*it);
        }

        return *current;
    }
};

// Implement the factory method
std::unique_ptr<TreeIterator> TreeNode::createDFSIterator() {
    return std::make_unique<DFSIterator>(std::shared_ptr<TreeNode>(this, [](TreeNode*){}));
}

// Helper function to build a sample tree
std::shared_ptr<TreeNode> buildSampleTree() {
    // Build this tree:
    //      1
    //     / \
    //    2   3
    //   / \   \
    //  4   5   6

    auto node1 = std::make_shared<TreeNode>(1);
    auto node2 = std::make_shared<TreeNode>(2);
    auto node3 = std::make_shared<TreeNode>(3);
    auto node4 = std::make_shared<TreeNode>(4);
    auto node5 = std::make_shared<TreeNode>(5);
    auto node6 = std::make_shared<TreeNode>(6);

    node1->addNeighbor(node2);
    node1->addNeighbor(node3);
    node2->addNeighbor(node4);
    node2->addNeighbor(node5);
    node3->addNeighbor(node6);

    return node1;
}

int main() {
    auto root = buildSampleTree();

    // Create iterator
    auto iterator = root->createDFSIterator();

    // Traverse the tree
    std::cout << "DFS traversal: ";
    while (iterator->hasNext()) {
        auto& node = iterator->next();
        std::cout << node.getValue() << " ";
    }
    std::cout << std::endl;

    return 0;
}