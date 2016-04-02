#include "catch.hpp"


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};


ListNode *deleteDuplicates(ListNode *head) {
    ListNode *cur = head;
    while (cur) {
        if (cur->next && cur->val == cur->next->val) {
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
    return head;
}

TEST_CASE("remove duplicates from sorted list") {
    ListNode head(0);
    ListNode duplicate(0);
    ListNode tail(1);
    head.next = &duplicate;
    duplicate.next = &tail;
    ListNode *remove = deleteDuplicates(&head);
    REQUIRE(remove->next->val == 1);
}