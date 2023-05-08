#Author: Solai
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        #add prereq list to hashmap DS for each course
        #init each course with empty prereq list
        prereq_hmap = {i: [] for i in range(numCourses)}
        for course, prereq in prerequisites:
            prereq_hmap[course].append(prereq)
        
        #use set to assist in detecting cycle
        cset = set()
        def dfs(course):
            #handle base case
            if [] == prereq_hmap[course]:
                return True
            #detect cyclic dependency
            if course in cset:
                return False
            
            #begin: block of code to check current course completion
            cset.add(course)
            #check whether all prereq can be completed
            for prereq in prereq_hmap[course]:
                if False == dfs(prereq):
                    return False
            cset.remove(course) #since course can be completed, remove it from set
            prereq_hmap[course] = []  #will be useful if we visit completed course again
            return True #since current course and all its prereq can be completed
            #end: block of code to check current course completion

        #iterate through all the courses and check for their completion
        for course in range(numCourses):
            if dfs(course) == False:
                return False
        return True
