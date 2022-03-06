#include "arraygraph.h"

void	test(void)
{
	ArrayGraph	*undirected_graph;
	ArrayGraph	*directed_graph;

	// 무방향 / 가중치 없음
	undirected_graph = createArrayGraph(6);
	displayArrayGraph(undirected_graph);

	addVertexAG(undirected_graph, 0);
	addVertexAG(undirected_graph, 1);
	addVertexAG(undirected_graph, 2);
	addVertexAG(undirected_graph, 3);
	addVertexAG(undirected_graph, 4);
	addVertexAG(undirected_graph, 5);
	if (addVertexAG(undirected_graph, 6) == FAIL)
		printf("add vertex failed\n\n");
	displayArrayGraph(undirected_graph);

	addEdgeAG(undirected_graph, 0, 1);
	addEdgeAG(undirected_graph, 0, 2);
	addEdgeAG(undirected_graph, 1, 2);
	addEdgeAG(undirected_graph, 2, 3);
	addEdgeAG(undirected_graph, 3, 4);
	addEdgeAG(undirected_graph, 3, 5);
	addEdgeAG(undirected_graph, 4, 5);
	displayArrayGraph(undirected_graph);

	removeVertexAG(undirected_graph, 0);
	displayArrayGraph(undirected_graph);

	removeEdgeAG(undirected_graph, 3, 4);
	displayArrayGraph(undirected_graph);

	deleteArrayGraph(undirected_graph);
	undirected_graph = NULL;
	displayArrayGraph(undirected_graph);

	// 방향 / 가중치 있음
	directed_graph = createArrayDirectedGraph(6);
	addVertexAG(directed_graph, 0);
	addVertexAG(directed_graph, 1);
	addVertexAG(directed_graph, 2);
	addVertexAG(directed_graph, 3);
	addVertexAG(directed_graph, 4);
	addVertexAG(directed_graph, 5);
	if (addVertexAG(directed_graph, 6) == FAIL)
		printf("add vertex failed\n\n");
	displayArrayGraph(directed_graph);

	addEdgewithWeightAG(directed_graph, 0, 1, 4);
	addEdgewithWeightAG(directed_graph, 1, 2, 1);
	addEdgewithWeightAG(directed_graph, 2, 1, 3);
	addEdgewithWeightAG(directed_graph, 2, 0, 2);
	addEdgewithWeightAG(directed_graph, 2, 3, 2);
	addEdgewithWeightAG(directed_graph, 3, 2, 1);
	addEdgewithWeightAG(directed_graph, 3, 4, 1);
	addEdgewithWeightAG(directed_graph, 4, 5, 1);
	addEdgewithWeightAG(directed_graph, 5, 3, 2);
	displayArrayGraph(directed_graph);

	removeVertexAG(directed_graph, 0);
	displayArrayGraph(directed_graph);

	removeEdgeAG(directed_graph, 3, 4);
	displayArrayGraph(directed_graph);

	deleteArrayGraph(directed_graph);
	directed_graph = NULL;
	displayArrayGraph(directed_graph);
}

int	main(void)
{
	test();
	// system("leaks arraygraph");
	return (0);
}
