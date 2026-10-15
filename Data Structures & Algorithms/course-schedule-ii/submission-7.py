class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        neighbours = {}
        indegree = {}
        for i in range(numCourses):
            indegree[i] = 0
            neighbours[i] = set()
        for dest, source in prerequisites:
            neighbours[source].add(dest)
            indegree[dest] += 1
        

        sources = deque()

        for key in indegree:
            value = indegree[key]
            if value == 0:
                sources.append(key)
        
        count = 0
        res = []
        while sources:
            front = sources.popleft()
            res.append(front)
            count += 1
            for neigh in neighbours[front]:
                indegree[neigh] -= 1
                if indegree[neigh] == 0:
                    sources.append(neigh)
        
        if count != numCourses:
            return []
        return res




        
        

