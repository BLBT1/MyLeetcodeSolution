class BSTIterator
{
    stack<pair<TreeNode *, bool>> nexts;
    stack<TreeNode *> visited;

public:
    BSTIterator(TreeNode *root)
    {
        TreeNode *p = root;
        while (p)
        {
            nexts.push({p, true});
            p = p->left;
        }
    }

    bool hasNext()
    {
        return !nexts.empty();
    }

    int next()
    {
        auto [node, flag] = nexts.top();
        nexts.pop();

        if (flag == 1)
        {
            TreeNode *p = node->right;
            while (p)
            {
                nexts.push({p, true});
                p = p->left;
            }
        }

        visited.push(node);
        return node->val;
    }

    bool hasPrev()
    {
        return visited.size() > 1;
    }

    int prev()
    {
        nexts.push({visited.top(), false});
        visited.pop();

        return visited.top()->val;
    }
};