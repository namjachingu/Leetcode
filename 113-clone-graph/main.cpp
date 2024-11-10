#include <iostream>
#include <unordered_map>

// Definition for a Node.
class Node {
public:
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }

    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }

    int val;
    std::vector<Node*> neighbors;
};

class ClonedGraph {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;

        if (map.find(node) != map.end())
            return map[node];

        Node* newNode = new Node(node->val);
        map[node] = newNode;

        // Iterate over the neighbors and clone them
        for (const auto & neighbor : node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(neighbor));
        }
        return newNode;
    }

private:
    std::unordered_map<Node*, Node*> map;
};


int main() {
    std::vector<std::vector<int>> adjacentList = {{2,4},{1,3},{2,4},{1,3}};

    // Input is an empty list, so there is only one node and it does not have any neighbors.
    // std::vector<std::vector<int>> adjacentList = {{}};

    // Empty graph, no nodes
    // std::vector<std::vector<int>> adjacentList = {};

    std::vector<Node*> newGraph = {};

    ClonedGraph clonedGraph;
    for (size_t i = 0; i < adjacentList.size(); i++) {
        Node* currentNode = new Node(i);

        if (!adjacentList[i].empty()) {
            currentNode->neighbors.clear();

            Node* currentNeighbour1 = new Node(adjacentList[i][0]);
            Node* currentNeighbour2 = new Node(adjacentList[i][1]);

            currentNode->val = i + 1;
            currentNode->neighbors.push_back(currentNeighbour1);
            currentNode->neighbors.push_back(currentNeighbour2);
        }

        newGraph.push_back(clonedGraph.cloneGraph(currentNode));
    }

    if (!newGraph.empty()) {
        std::cout << "[";
        for (auto & node : newGraph) {
            if (!node->neighbors.empty())
                std::cout << "[" << node->neighbors[0]->val << ", " << node->neighbors[1]->val << "]";

            if (node != newGraph.back())
                std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
