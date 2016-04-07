#include "catch.hpp"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *anchor = head;
    ListNode *pre = NULL;
    for (int i = 1; i < n; ++i) {
        anchor = anchor->next;
    }
    while (anchor->next != NULL) {
        if (pre) {
            pre = pre->next;
        } else { pre = head; }
        anchor = anchor->next;
    }
    if (pre == NULL) return head->next;
    pre->next = pre->next->next;
    return head;
}

TEST_CASE("remove nth node from end of list") {
    SECTION("three nodes") {
        ListNode head(3);
        ListNode middle(2);
        ListNode tail(1);
        head.next = &middle;
        middle.next = &tail;
        auto removed = removeNthFromEnd(&head, 2);
        REQUIRE(removed->next->next == NULL);
    }
    SECTION("two nodes") {
        ListNode head(2);
        ListNode tail(1);
        head.next = &tail;
        auto removed = removeNthFromEnd(&head, 1);
        REQUIRE(removed->val == 2);
    }
}