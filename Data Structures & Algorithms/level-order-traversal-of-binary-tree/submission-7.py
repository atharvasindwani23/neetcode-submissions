# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        q = deque()
        result = []
        if not root:
            return [] 
        q.append(root)

        while q:
            n = len(q)
            res = []
            for i in range(n):
                front = q.popleft()
                res.append(front.val)
                if front.left:
                    q.append(front.left)
                if front.right:
                    q.append(front.right)
            
            result.append(res)

        return result