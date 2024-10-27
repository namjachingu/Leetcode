
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LinkedList {
public:
    void removeNthFromEnd(std::unique_ptr<ListNode> & head, int n) {
        if (head->next == nullptr) {
            head = nullptr;
            return;
        }

        ListNode* fast = head.get();
        ListNode* slow = head.get();

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
    }

    void printRemainingList(std::unique_ptr<ListNode> & head) {
        ListNode* current = head.get();

        std::cout << "[";
        if (current == nullptr) {
            std::cout << "]" << std::endl;
            return;
        }

        while (current != nullptr) {
            std::cout  << " " << current->val;
            current = current->next;
        }
        std::cout << " ]" << std::endl;
    }
};

int main() {
    LinkedList linkedList;

    // head = [1,2,3,4,5], n = 2
    {
        std::vector<int> input = {1, 2, 3, 4, 5};
        std::unique_ptr<ListNode> head = std::make_unique<ListNode>(input[0]);
        head->next = new ListNode(input[1]);
        head->next->next = new ListNode(input[2]);
        head->next->next->next = new ListNode(input[3]);
        head->next->next->next->next = new ListNode(input[4]);

        linkedList.removeNthFromEnd(head, 2);
        linkedList.printRemainingList(head);
    }

    // head = [1], n = 1
    {
        std::vector<int> input = {1};
        std::unique_ptr<ListNode> head = std::make_unique<ListNode>(input[0]);
        linkedList.removeNthFromEnd(head, 1);
        linkedList.printRemainingList(head);
    }

    // head = [1,2], n = 1
    {
        std::vector<int> input = {1, 2};
        std::unique_ptr<ListNode> head = std::make_unique<ListNode>(input[0]);
        head->next = new ListNode(input[1]);

        linkedList.removeNthFromEnd(head, 1);
        linkedList.printRemainingList(head);
    }

    return 0;
}
