Q2: Create a Circularly Doubly Linked List having the following structure:
Head Node Structure:
PRED No. of Edges SUCC
Structure of Data Node:
PRED Start Vertex End Vertex
Edge Weight
SUCC
Perform the following operations on the CDLL:
1. Insert a new node according to the increasing order of Edge Weight
2. Deleting a node that has the given Start and End Vertex
3. Delete all the nodes that have a given Start Vertex
4. Given the Start Vertex and End Vertex, print its Edge Weight
5. Count number of edges that have weight < x
6. Print all the edges that has edge weight < x
7. Print all the edges that has a given end vertex
8. Print all the edges in the decreasing order of their edge weight




Q1: For a directed graph, get input from the user a
s list of edges and represent the graph as adjacenc
y
matrix. Print the following information for the gra
ph:
1.
Adjacency Matrix
2.
For each vertex print its in-degree and out-degree.
3.
For each vertex print the vertices that are adjacen
t to that vertex.
4.
For each vertex print the vertices to which this ve
rtex is adjacent to.
Note: For a vertex, its in-degree is the number of
edges starting from that vertex and out-degree is t
he
number of edges ending in that vertex. If there is
a directed edge <u, v> v is adjacent to u.
Sample Input:
Enter No. of vertices of graph: 4
Enter No. of edges of graph: 6
Enter start and end vertices of edge-0
0   3
Enter start and end vertices of edge-1
1   3
Enter start and end vertices of edge-2
1   2
Enter start and end vertices of edge-3
0   2
Enter start and end vertices of edge-4
2   3
Enter start and end vertices of edge-5
2   1
Sample Output:
Adjacency Matrix:
0  0  1  1
0  0  1  1
0  1  0  1
0  0  0  0
Vertex       In-Degree     Out-Degree
0                    0                         2
1                    1                         2
2                    2                         2
3                    3                         0
Vertex 0’s adjacent vertices 2, 3
Vertex 1’s adjacent vertices 2, 3
Vertex 2’s adjacent vertices 1, 3
Vertex 3’s adjacent vertices NIL
Vertex 0 is adjacent to  NIL
Vertex 1 is adjacent to  2
Vertex 2 is adjacent to  0, 1
Vertex 3 is adjacent to  0, 1, 2




Q2.
Create a doubly linked list that has the following structure:
HEAD NODE
DATA NODE
FIRST
LAST
COUNT
LLINK
ALPHA
RLINK
Given  a  string  as  input  store  it  as  a DLL  by  storing  each
character  of  the  string  in  a  data  node.
In
head node the FIRST should point to the data node that stores the
first character of the string, LAST
should point to the data node that stores the last character of the
string and COUNT should store the
number of characters in that string. Write a pro
gram to get two strings S1 and S2 as input from the
user, store them in two DLLs. Also get two integers x and y from the
user and concatenate the two
doubly linked lists such that the resultant list should contain first
x characters from S1, followed by
first  y  characters  from  s2,  followed  by  remaining  characters
from  s1  and  followed  by  remai
ning
characters from s2. For example, S1=
”
ABCDE
”
and S2=
”
GHIJKL
”
, then create two DLLs as:
S1

NULL
A


B


C


D


E
NULL
S2

NULL
G


H


I


J


K


L
NULL
If x=3 and y=4 then the r
esult
should be
S1

NULL
A


B


C


G


H


I


J


D


E


K


L
NULL
Note:
Don
’
t create
new DLL nodes again.


