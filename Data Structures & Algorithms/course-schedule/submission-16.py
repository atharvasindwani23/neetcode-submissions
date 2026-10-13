class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        indegree = [0] * numCourses
        neighbours = [[] for i in range(numCourses)]

        for dest, source in prerequisites:
            indegree[dest] += 1
            neighbours[source].append(dest)
        
        sources = deque()

        for i in range(len(indegree)):
            if indegree[i] == 0:
                sources.append(i)
        finish = 0
        while sources:
            front = sources.popleft()
            finish += 1
            for element in neighbours[front]:
                indegree[element] -= 1
                if indegree[element] == 0:
                    sources.append(element)
        
        return finish == numCourses


    #question of cycle detection pretty much 

    #for 225 you need to do 128 and 124
    #for 128 you need to do 124
    #now imagine if suddenly u had to do 225 for 124
    #this creates a cycle which means that you'll never be able to do ur classes

    #so essentially if its a dag we can do it, otherwise it's cooked

    #can do this q in a variety of ways


    #best thing to do in this case is just toposort it
