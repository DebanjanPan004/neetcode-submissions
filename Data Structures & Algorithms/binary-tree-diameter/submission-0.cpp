class Solution
{
public:
    int diameter = 0;

    int depth(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);

        // Update the maximum diameter
        diameter = max(diameter, leftDepth + rightDepth);

        // Return maximum depth
        return 1 + max(leftDepth, rightDepth);
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        depth(root);
        return diameter;
    }
};