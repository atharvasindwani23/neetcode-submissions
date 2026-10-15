# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:

        if not root:
            return []
        
        res = []

        nodes = deque()
        nodes.append(root)

        while nodes:
            
            n  = len(nodes)

            for i in range(n):

                front = nodes.popleft()

                if i == n - 1:
                    res.append(front.val)
                
                if front.left:
                    nodes.append(front.left)
                if front.right:
                    nodes.append(front.right)
        return res

        