#include "catch.hpp"
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> pstack;
    for (char ch: s) {
        switch (ch) {
            case '(':
            case '[':
            case '{':
                pstack.push(ch);
                break;
            case ')':
                if (pstack.empty() || pstack.top() != '(')
                    return false;
                pstack.pop();
                break;
            case ']':
                if (pstack.empty() || pstack.top() != '[')
                    return false;
                pstack.pop();
                break;
            case '}':
                if (pstack.empty() || pstack.top() != '{')
                    return false;
                pstack.pop();
                break;
            default:
                break;
        }
    }
    return pstack.empty();
}

TEST_CASE("valid parentheses") {
    SECTION("empty input") {
        REQUIRE(isValid(""));
    }
    SECTION("valid") {
        REQUIRE(isValid("()"));
        REQUIRE(isValid("[]"));
        REQUIRE(isValid("{}"));
        REQUIRE(isValid("([])"));
        REQUIRE(isValid("([{}])"));
        REQUIRE(isValid("[a]"));
    }
    SECTION("invalid") {
        REQUIRE(!isValid("("));
        REQUIRE(!isValid("]"));
        REQUIRE(!isValid("{[}"));
        REQUIRE(!isValid("([{)}])"));
    }
}

