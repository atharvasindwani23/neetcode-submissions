# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:

        if root.val > p.val and root.val > q.val:
            return self.lowestCommonAncestor(root.left, p, q)
        elif root.val < p.val and root.val < q.val:
            return self.lowestCommonAncestor(root.right, p, q)
        else:
            return root
    
        

#start from the root, the point where you realize you have to diverge is the node which is the smallest common ancestor


#basically, if both aren't at the same side of the tree, the first occurence of that is when you know its cooked

#the advantage is that it's a binary search tree, so we know where both the items would be placed


#the first instance where the root is in the middle of the values, u are cooked
