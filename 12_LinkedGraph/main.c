#include "linkedgraph.h"

void	test(void)
{
	LinkedGraph	*undirected_graph;
	LinkedGraph	*directed_graph;

	// 무방향 / 가중치 없음
	undirected_graph = createLinkedGraph(6);
	displayLinkedGraph(undirected_graph);

	addVertexLG(undirected_graph, 0);
	addVertexLG(undirected_graph, 1);
	addVertexLG(undirected_graph, 2);
	addVertexLG(undirected_graph, 3);
	addVertexLG(undirected_graph, 4);
	addVertexLG(undirected_graph, 5);
	if (addVertexLG(undirected_graph, 6) == FAIL)
		printf("add vertex failed\n\n");
	displayLinkedGraph(undirected_graph);

	addEdgeLG(undirected_graph, 0, 1);
	addEdgeLG(undirected_graph, 0, 2);
	addEdgeLG(undirected_graph, 1, 2);
	addEdgeLG(undirected_graph, 2, 3);
	addEdgeLG(undirected_graph, 3, 4);
	addEdgeLG(undirected_graph, 3, 5);
	addEdgeLG(undirected_graph, 4, 5);
	displayLinkedGraph(undirected_graph);

	removeVertexLG(undirected_graph, 0);
	displayLinkedGraph(undirected_graph);

	removeEdgeLG(undirected_graph, 3, 4);
	displayLinkedGraph(undirected_graph);

	deleteLinkedGraph(undirected_graph);
	undirected_graph = NULL;
	displayLinkedGraph(undirected_graph);

	// 방향 / 가중치 있음
	directed_graph = createLinkedDirectedGraph(6);
	addVertexLG(directed_graph, 0);
	addVertexLG(directed_graph, 1);
	addVertexLG(directed_graph, 2);
	addVertexLG(directed_graph, 3);
	addVertexLG(directed_graph, 4);
	addVertexLG(directed_graph, 5);
	if (addVertexLG(directed_graph, 6) == FAIL)
		printf("add vertex failed\n\n");
	displayLinkedGraph(directed_graph);

	addEdgewithWeightLG(directed_graph, 0, 1, 4);
	addEdgewithWeightLG(directed_graph, 1, 2, 1);
	addEdgewithWeightLG(directed_graph, 2, 1, 3);
	addEdgewithWeightLG(directed_graph, 2, 0, 2);
	addEdgewithWeightLG(directed_graph, 2, 3, 2);
	addEdgewithWeightLG(directed_graph, 3, 2, 1);
	addEdgewithWeightLG(directed_graph, 3, 4, 1);
	addEdgewithWeightLG(directed_graph, 4, 5, 1);
	addEdgewithWeightLG(directed_graph, 5, 3, 2);
	displayLinkedGraph(directed_graph);

	removeVertexLG(directed_graph, 0);
	displayLinkedGraph(directed_graph);

	removeEdgeLG(directed_graph, 3, 4);
	displayLinkedGraph(directed_graph);

	deleteLinkedGraph(directed_graph);
	directed_graph = NULL;
	displayLinkedGraph(directed_graph);
}

void	search_test(void)
{
	LinkedGraph	*dfs_graph;
	LinkedGraph	*bfs_graph;

	dfs_graph = createLinkedGraph(8);
	addVertexLG(dfs_graph, 0);
	addVertexLG(dfs_graph, 1);
	addVertexLG(dfs_graph, 2);
	addVertexLG(dfs_graph, 3);
	addVertexLG(dfs_graph, 4);
	addVertexLG(dfs_graph, 5);
	addVertexLG(dfs_graph, 6);
	addVertexLG(dfs_graph, 7);

	addEdgeLG(dfs_graph, 0, 1);
	addEdgeLG(dfs_graph, 0, 2);
	addEdgeLG(dfs_graph, 1, 3);
	addEdgeLG(dfs_graph, 1, 4);
	addEdgeLG(dfs_graph, 2, 5);
	addEdgeLG(dfs_graph, 2, 6);
	addEdgeLG(dfs_graph, 3, 7);
	addEdgeLG(dfs_graph, 4, 5);

	bfs_graph = createLinkedGraph(8);
	addVertexLG(bfs_graph, 0);
	addVertexLG(bfs_graph, 1);
	addVertexLG(bfs_graph, 2);
	addVertexLG(bfs_graph, 3);
	addVertexLG(bfs_graph, 4);
	addVertexLG(bfs_graph, 5);
	addVertexLG(bfs_graph, 6);
	addVertexLG(bfs_graph, 7);

	addEdgeLG(bfs_graph, 0, 1);
	addEdgeLG(bfs_graph, 0, 2);
	addEdgeLG(bfs_graph, 1, 3);
	addEdgeLG(bfs_graph, 1, 4);
	addEdgeLG(bfs_graph, 2, 5);
	addEdgeLG(bfs_graph, 2, 6);
	addEdgeLG(bfs_graph, 3, 7);
	addEdgeLG(bfs_graph, 4, 5);

	searchDFS(dfs_graph);
	searchBFS(bfs_graph);

	deleteLinkedGraph(dfs_graph);
	deleteLinkedGraph(bfs_graph);
}

int	main(void)
{
	// test();
	search_test();
	// system("leaks linkedgraph");
	return (0);
}
