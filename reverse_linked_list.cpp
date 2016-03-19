#include "catch.hpp"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

ListNode *reverseList(ListNode *head) {
    ListNode *pre = NULL;
    ListNode *cur = head;
    while (cur) {
        ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

TEST_CASE("reverse linked list") {
    ListNode head(0);
    ListNode middle(1);
    ListNode tail(2);
    head.next = &middle;
    middle.next = &tail;
    ListNode *revesed = reverseList(&head);
    REQUIRE(revesed->val == 2);
    REQUIRE(revesed->next->val == 1);
    REQUIRE(revesed->next->next->val == 0);
}
