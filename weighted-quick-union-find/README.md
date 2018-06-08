# Weighted Quick Union Find

Union-Find Algorithm can be used to check whether an undirected graph contains cycle or not. 
In this implementation of union find we use two techniques to speed of the operations

# union by rank :
The idea is to always attach smaller depth tree under the root of the deeper tree. This technique is called union by rank. Also, size (in place of height) of trees can also be used as rank. Using size as rank also yields worst case time complexity as O(Logn) 

#Path Compression :
The idea is to flatten the tree when find is called. When find is called for an element x, root of the tree is returned. The find operation traverses up from x to find root. The idea of path compression is to make the found root as parent of x so that we don’t have to traverse all intermediate nodes again. If x is root of a subtree, then path (to root) from all nodes under x also compresses.



