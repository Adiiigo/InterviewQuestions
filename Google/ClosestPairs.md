You are given a tree of N nodes. The tree is rooted at node 1. Each tree node has a value associated with it ans is represented as value(i). For each node, you are required to determine the closest ancestor that contains values that are coprime to the current node value. If no such nodes exist, then print -1. Two integers a and b are relatively prime, mutually prime or coprime if the only positive integer(factor) that can divide both the integers is 1.

A tree is a connected graph without cycles. A rooted has a special vertex called the root. A parent of a node v is the last difference from v vertex on the path from the root to vertex v. Children of vertex v are all nodes for which v is the parent. A vertec is a leaf if it has no children.

Input Format:
- The first line contains an integer T denoting the number of test cases.
- The first line of each test contains an integer N denoting the number of nodees in the tree.
- The next line of each test case continas N space-separated inetgers where the ith integr denotes the value at node(i) represented as value(i).
- Next N-1 lines of each test case contain two space-separated integers u and v denoting the dege between node u and node v. 

Output Format:
- For each test case, print N space-separated integers where the ith integer denotes the closest ancestor that contains coprime values. If no such ancestors exist, then print -1.


