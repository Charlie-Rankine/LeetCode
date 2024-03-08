#include <queue>
#include <vector>
using std::queue;
using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

TreeNode *arrayToTree(const vector<int> &arr) {
  if (arr.empty()) {
    return nullptr; // Empty array means empty tree
  }

  TreeNode *root = new TreeNode(arr[0]);
  queue<TreeNode *> q;
  q.push(root);

  int i = 1; // Index into the array
  while (!q.empty() && i < (int)arr.size()) {
    TreeNode *current = q.front();
    q.pop();

    if (arr[i]) {
      current->left = new TreeNode(arr[i]);
      q.push(current->left);
    }

    i++;

    if (arr[i]) {
      current->right = new TreeNode(arr[i]);
      q.push(current->right);
    }

    i++;
  }

  return root;
}
