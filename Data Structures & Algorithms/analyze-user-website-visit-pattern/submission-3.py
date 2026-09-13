from collections import defaultdict
from typing import List

class Solution:
    def mostVisitedPattern(
        self,
        username: List[str],
        timestamp: List[int],
        website: List[str]
    ) -> List[str]:

        arr = list(zip(timestamp, username, website))
        arr.sort()

        userToWebsites = defaultdict(list)

        for time, user, site in arr:
            userToWebsites[user].append(site)

        patternToCounts = defaultdict(int)

        for user, sites in userToWebsites.items():
            seenPatterns = set()

            for i in range(len(sites)):
                for j in range(i + 1, len(sites)):
                    for k in range(j + 1, len(sites)):
                        pattern = (sites[i], sites[j], sites[k])
                        seenPatterns.add(pattern)

            for pattern in seenPatterns:
                patternToCounts[pattern] += 1

        maxCount = 0
        result = None

        for pattern, count in patternToCounts.items():
            if count > maxCount:
                maxCount = count
                result = pattern
            elif count == maxCount and pattern < result:
                result = pattern

        return list(result)