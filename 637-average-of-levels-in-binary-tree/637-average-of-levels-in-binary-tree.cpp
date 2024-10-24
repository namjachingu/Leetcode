#include <vector>
#include <queue>
#include <cassert>
#include <algorithm>
#include <iostream>

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Graph {
public:
    void printAverageOfLevels(std::vector<double> result) {
        std::cout << "[ ";
        for (const auto & res : result) {
            std::cout << res << " ";
        }
        std::cout << "]" << std::endl;
    }

    std::vector<double> averageOfLevels(std::unique_ptr<TreeNode> & root) {
        if (root == nullptr) {
            return {};
        }

        std::vector<double> averages;
        std::queue<TreeNode*> queueOfNodes;
        queueOfNodes.push(root.get());

        while (!queueOfNodes.empty()) {
            double sum = 0;
            size_t queueSize = queueOfNodes.size();

            for (size_t i = 0; i < queueSize; i++) {
                TreeNode* node = queueOfNodes.front();
                queueOfNodes.pop();
                sum += node->val;
                if (node->left) queueOfNodes.push(node->left.get());
                if (node->right) queueOfNodes.push(node->right.get());
            }
            averages.emplace_back(sum / queueSize);
        }
        return averages;
    }
};

int main() {
    Graph graph;

    {
        std::vector<int> input = {3, 9, 20, 0, 0, 15, 7};

        // Create a binary tree for root = [3,9,20,null,null,15,7]
        auto root = std::make_unique<TreeNode>(input[0]);
        root->left = std::make_unique<TreeNode>(input[1]);
        root->right = std::make_unique<TreeNode>(input[2]);
        root->right->left = std::make_unique<TreeNode>(input[5]);
        root->right->right = std::make_unique<TreeNode>(input[6]);

        const std::vector<double> & result = graph.averageOfLevels(root);
        graph.printAverageOfLevels(result);

        const std::vector<double> answer = {3.00000, 14.50000, 11.00000};
        assert(result == answer);
        assert(std::equal(result.begin(), result.end(), answer.begin()));
    }

    // Create a binary tree for root = [3,9,20,15,7]
    {
        std::vector<int> input = {3,9,20,15,7};

        // Create a binary tree for root = [3,9,20,null,null,15,7]
        auto root = std::make_unique<TreeNode>(input[0]);
        root->left = std::make_unique<TreeNode>(input[1]);
        root->right = std::make_unique<TreeNode>(input[2]);
        root->left->left = std::make_unique<TreeNode>(input[3]);
        root->left->right = std::make_unique<TreeNode>(input[4]);

        const std::vector<double> & result = graph.averageOfLevels(root);
        graph.printAverageOfLevels(result);

        const std::vector<double> answer = {3.00000, 14.50000, 11.00000};
        assert(result == answer);
        assert(std::equal(result.begin(), result.end(), answer.begin()));
    }

    return 0;
}
