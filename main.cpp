#include <cassert>
#include <iostream>
#include "binary-tree-playground/binary_tree.h"

using namespace std;

class Solution {
 public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return sortedArrayToBST(nums, 0, nums.size());
  }

 private:
  TreeNode *sortedArrayToBST(vector<int> &nums, size_t start, size_t end) {
    TreeNode *head = nullptr;
    if (not nums.empty() and start < end) {
      if (1 == end - start) {
        head = new TreeNode{nums[start]};
      } else {
        size_t mid = start + (end - start) / 2;
        head = new TreeNode{nums[mid]};
        head->left = sortedArrayToBST(nums, start, mid);
        head->right = sortedArrayToBST(nums, mid + 1, end);
      }
    }

    return head;
  }
};

bool sameTree(TreeNode *p, TreeNode *q) {
  if (not p and not q) return true;
  if (p and q) {
    return p->val == q->val
        and sameTree(p->left, q->left)
        and sameTree(p->right, q->right);
  }

  return false;
}

void TestSortedArrayToBST() {
  Solution s;
  {
    vector<int> numbers{-10, -3, 0, 5, 9};
    TreeNode *root = s.sortedArrayToBST(numbers);
    TreeNode *expected = stringToTreeNode("[0,-3,9,-10,null,5]"s);
    assert(sameTree(root, expected));
  }
  {
    vector<int> numbers{1, 3};
    TreeNode *root = s.sortedArrayToBST(numbers);
    TreeNode *expected = stringToTreeNode("[3,1]"s);
    assert(sameTree(root, expected));
  }
}

int main() {
  TestSortedArrayToBST();
  std::cout << "Ok!" << std::endl;
  return 0;
}
