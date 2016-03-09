#include "catch.hpp"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode sentinel(0);
    auto current = &sentinel;
    ListNode *next;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    current->next = l1 ? l1 : l2;
    return sentinel.next;
}

TEST_CASE("merge two sorted lists") {
    ListNode l1(1);
    ListNode l2(2);
    auto p = mergeTwoLists(&l1, &l2);
    REQUIRE(p->val == 1);
    REQUIRE(p->next->val == 2);
}