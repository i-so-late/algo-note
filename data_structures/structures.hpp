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
#include <numeric>
#include <thread>
#include <mutex>
#include <utility>
#include <condition_variable>
#include <future>
#include <functional>
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
 