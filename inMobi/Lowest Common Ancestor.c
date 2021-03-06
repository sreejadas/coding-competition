/*2. Lowest Common Ancestor [100 points] [http://www.hackerearth.com/inmobi-hiring-challenge/algorithm/lowest-common-ancestor/]
Shinchan and Kazama are very fond of trees. Kazama is a smart boy and always learn topics which are supposed to appear in higher standard. This time he has learnt about the trees that were used in graph theory. He gives shinchan the description of a tree and a set of nodes, and asked him to find the lowest common ancestor for the given set of nodes.

A tree can be defined recursively as a collection of nodes (starting at a root node), where each node consists a list of references to nodes (ie "children"), with the constraints that no reference is duplicated, and none points to the root. [A simple definition: A tree is a connected acyclic simple graph rooted at a specific node.]

[A sample tree]

Here tree consists of N nodes with each node having a unique index between 0 and N-1, inclusively. Root node is indexed 0. We are given a list of N-1 nodes, p1, p2...pN-1, where pi is the parent of ith node. Along with this, we are also provided a list of M nodes {u0, u1...uM-1} for whom Shinchan have to find the lowest common ancestor.

Lowest Common Ancestor: Let T be a rooted tree with N nodes. Then the lowest common ancestor for a set of nodes U {u0, u1...uM-1} is the lowest node, v, for which subtree rooted at v contains all the nodes in set U.

Constraints:
1 <= N <= 105
1 <= M <= N
0 <= Number of children of each node <= 10
0 <= pi < N, 1 <= i <= N-1
0 <= ui < N, 0 <= i <= M-1

Input:
First line of input contains a integer N, number of nodes in the tree. Then in the following line there are N-1 space separated integers, p1, p2...pN-1, where pi is the parent of ith node. Then in next line there is an integer M. In next line we have M space separated integers, u0, u1...uM-1, representing the nodes of set U.

Output
Print the id of lowest common ancestor of U.*/



#include<stdio.h>
#define MAX 10000
int parent[MAX];
int query[MAX];
int n,q;
int main()
{
	int i,j,ret;
	scanf("%d",&n);

	for(i=0;i<n-1;i++)
		scanf("%d",&parent[i]);
	scanf("%d",&q);

	for(i=0;i<q;i++)
		scanf("%d",&query[i]);

	while(q>1)
	{
		up:
		for(i=0;i<q-1;i++)
		{
			for(j=i+1;j<q;j++)
			{
				ret=checkparent(query[i],query[j]);
				if(ret==-1)
					continue;
				query[i]=ret;
				q--;
				query[j]=query[q];
				goto up;	
			}
		}	

		for(i=0;i<q;i++)
		{
			query[i]=parent[i];
		}
	}
	printf("%d",query[0]);
}

int checkparent(int i,int j)
{
	
	if(parent[i]==parent[j])
		return parent[i];
	else if(i==parent[j])
		return i;
	else if(j==parent[i])
		return j;
	else
		return -1;
}



