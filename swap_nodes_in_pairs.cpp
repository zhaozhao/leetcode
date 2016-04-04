#include "catch.hpp"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

ListNode *swapPairs(ListNode *head) {
    ListNode sentinel(0);
    sentinel.next = head;
    ListNode *cur = &sentinel;
    while (cur->next && cur->next->next) {
        ListNode *next = cur->next;
        ListNode *second = next->next;
        next->next = second->next;
        second->next = next;
        cur->next = second;
        cur = next;
    }
    return sentinel.next;
}

TEST_CASE("swap nodes in pairs") {
    ListNode head(1);
    ListNode next(2);
    head.next = &next;
    ListNode second(3);
    next.next = &second;
    ListNode third(4);
    second.next = &third;

    auto swapped = swapPairs(&head);

    REQUIRE(swapped->val == 2);
    REQUIRE(swapped->next->val == 1);
    REQUIRE(swapped->next->next->val == 4);
    REQUIRE(swapped->next->next->next->val == 3);
}