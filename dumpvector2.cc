
#include <cstdio>

template <typename T>
struct TreeNode {
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode(T val) : val(val), left(nullptr), right(nullptr) {}
};

template <typename T>
void Print(TreeNode<T>*& node) {
    if (node != nullptr) {
        Print(node->left);
        Print(node->right);
        printf("%d\n", node->val);
    }
}

int main(int argc, char* argv[]) {
    TreeNode<int> node(1);
    TreeNode<int> left(2);
    TreeNode<int> right(3);
    node.left = &left;
    node.right = &right;
    TreeNode<int>* param = &node;

    Print(param);
    return 0;
}
