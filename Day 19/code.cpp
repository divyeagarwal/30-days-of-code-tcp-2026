class Solution {
private:
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
public:
    Node* addOne(Node* head) {
        head = reverseList(head);
        int carry = 1;
        Node* curr = head;
        Node* prev = NULL;
        while (curr != NULL && carry > 0) {
            int sum = curr->data + carry;
            curr->data = sum % 10;
            carry = sum / 10;
            prev = curr;
            curr = curr->next;
        }
        if (carry > 0) {
            prev->next = new Node(carry);
        }
        head = reverseList(head);
        return head;
    }
};
