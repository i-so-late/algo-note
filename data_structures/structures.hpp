#pragma once

#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <unordered_set>
#include <set>
#include <cstdint>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// LeetCode uses the name Node for two shapes: a binary tree node with a next pointer (116, 117) and an N-ary tree node (429, 559). One header cannot define both, so this Node carries the fields and constructors of each.
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    vector<Node*> children;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {}
    Node(int _val, vector<Node*> _children) : val(_val), left(nullptr), right(nullptr), next(nullptr), children(_children) {}
};
 