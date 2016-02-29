#include "catch.hpp"
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};


ListNode * addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode sentinel(0);
    auto p = &sentinel;

    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = (l1? l1->val:0) + (l2? l2->val:0) + carry;
        p->next = new ListNode(sum%10);
        p = p->next;
        carry = sum/10;
        l1 = l1? l1->next: NULL;
        l2 = l2? l2->next: NULL;
    }

    return sentinel.next;

}


TEST_CASE("Add two numbers", "[two numbers]") {
    SECTION( "add zeros" ) {
        ListNode* l1 = new ListNode(0);
        ListNode* l2 = new ListNode(0);
        auto p = addTwoNumbers(l1, l2);
        REQUIRE( p->val == 0);
        REQUIRE( p->next == NULL);
    }
    SECTION( "add ones" ) {
        ListNode* l1 = new ListNode(1);
        ListNode* l2 = new ListNode(1);
        auto p = addTwoNumbers(l1, l2);
        REQUIRE( p->val == 2);
        REQUIRE( p->next == NULL);
    }
    SECTION( "5 + 5" ) {
        ListNode* l1 = new ListNode(5);
        ListNode* l2 = new ListNode(5);
        auto p = addTwoNumbers(l1, l2);
        REQUIRE( p->val == 0);
        REQUIRE( p->next->val == 1);
        REQUIRE( p->next->next == NULL);
    }
}