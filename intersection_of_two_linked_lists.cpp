#include "catch.hpp"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    ListNode *p1 = headA;
    ListNode *p2 = headB;
    while (p1 != p2) {
        p1 = p1? p1->next:headB;
        p2 = p2? p2->next:headA;
    }
    return p1;
}

TEST_CASE("intersection of two linked lists") {
    ListNode headA(0);
    ListNode headB(0);
    ListNode tail(1);
    headA.next = &tail;
    headB.next = &tail;

    REQUIRE(getIntersectionNode(&headA, &headB) == &tail);
}