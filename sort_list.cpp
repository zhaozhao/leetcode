#include "catch.hpp"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

ListNode *merge(ListNode *l1, ListNode *l2) {
    ListNode sentinel(0);
    ListNode *tail = &sentinel;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return sentinel.next;
}

ListNode *sortList(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *h2 = sortList(slow->next);
    slow->next = NULL;
    return merge(sortList(head), h2);
}

TEST_CASE("sort list") {
    ListNode head(2);
    ListNode tail(1);
    head.next = &tail;
    auto sorted = sortList(&head);
    REQUIRE(sorted->val == 1);
    REQUIRE(sorted->next->val == 2);
    REQUIRE(sorted->next->next == NULL);
}