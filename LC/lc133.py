"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        #hashmap
        origToCopy = {}
        
        orig = node
        def clone(orig):
            #already in hashmap ?, return the copy
            if orig in origToCopy:
                return origToCopy[orig]
            
            #Not in hashmap, create orig's copy and add list of neighbours
            copy = Node(orig.val)
            #add the copy to hashmap
            origToCopy[orig] = copy
            #add list of neighbours to the copy
            for n in orig.neighbors:
                copy.neighbors.append(clone(n))
            return copy
        
        #return Null if graph input is empty
        return clone(node) if node else None
