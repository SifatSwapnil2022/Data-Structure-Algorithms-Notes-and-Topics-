#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int value;
    int leftIndex;
    int rightIndex;

    TreeNode(int x) {
        value = x;
        leftIndex = -1;
        rightIndex = -1;
    }
};

void build(const vector<int>& nums, int left, int right, vector<TreeNode>& tree, int& index) {
    if (left > right) {
        return;
    }
    int mid = left + (right - left) / 2;
    tree[index] = TreeNode(nums[mid]);

    if (mid > left) {
        tree[index].leftIndex = ++index;  // Increment index first for left child
        build(nums, left, mid - 1, tree, index);
    }

    if (mid < right) {
        tree[index].rightIndex = ++index; // Increment index first for right child
        build(nums, mid + 1, right, tree, index);
    }
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    vector<TreeNode> bst(nums.size());
    int index = 0;
    build(nums, 0, nums.size() - 1, bst, index);
    
    for (int i = 0; i < bst.size(); ++i) {
        cout << "Node " << i << ": Value = " << bst[i].value
             << ", Left Child Index = " << bst[i].leftIndex
             << ", Right Child Index = " << bst[i].rightIndex << endl;
    }

    return 0;
}
