/*
	Graphs
	======
		No root
		Multiple edges
		No hierarchy

	Example - Road map
		Edges between 2 cities means that they are adjacent
		In traversing graph, can only go to adjacent city from a city

	Definition:
		Graph G defined as G = {V, E} ; V = vertices, E = edges
			V = {v1, v2, v3, .. vn}
			E = {e1, e2, e3, .. em}

	Representations:
		1. Adjacency matrix
		2. Adjacency list

	Weighted and unweighted graphs
		Unweighted - all edges have uniform weight of 1
		Weighted   - each edge has a value that is the weight of that edge

	Adjacency Matrix
	----------------
		2d matrix - all vertices listed on horizontal and vertical axes
		Vertical - starting
		Horizontal - ending
		1 => there is an edge (unweighted)
		0 => there is no edge

		If weighted, replace edge with weight
		Use 0 for vk to vk
		Use -1 for no edge

	Adjacency List
	--------------
		Only stores information about the adjacent edges
		Doesn't store edges that don't exist

		For each vertex, store list of adjacent vertices including weight of edge in a weighted graph

	class Graph { // adjacency list
		private:
			vector<vertex> vertices; // include adjacency list; vertex type exists
		public:
			Graph();
			void insertVertex(value);
			void insertEdge(startVal, endVal, weight);
			void deleteVertex(value);
			void deleteEdge(starVal, endVal);
			void printGraph();
			bool search(value);
	};
	
	1. Insert Vertex
	----------------

	// pre condition - value is valid
	// post condition - vertex is added to vertices if it doesn't already exist
	void insertVertex(value) {
		bool found = false;
		for (int i = 0; i < vertices.size(); ++i) {
			if (vertices[i].key == value){
				found = true;
				break;
			}
		}
		// value not in vertices
		if (!found) {
			vertex v; // vertex type exists
			v.key = value;
			vertices.push_back(v);
		}
	}
		
	Traversing Graphs
	=================

	1. Breadth first search (BFS)
		
		Visit all adjacent vertices first before going deeper
		Look at 1 edge away before looking at multiple edges away

		View graph as a tree - BFS
			Root of tree = starting vertex of graph

		Algorithm:
		----------
			find starting vertex
			mark vertex as visited (add a new property to vertex struct)
			add vertex to queue
			while queue ! empty
				dequeue
				for each of vertex adjacent
					if vertex ! visited
						mark as visited
						// do stuff with it like printing, etc.
						add to queue

		Modify the vertex struct to include a distance and a parent

		struct adjVertex {
			vertex* v;
			int weight;
		};

		struct vertex {
			string key;
			vector<adjVertex> adjacent;
			bool visited;
			int distance; // distance from start to current
			vertex* parent;
		};

		// see moodle for detailed implementation


	2. Depth first search (DFS)

		Visit all vertices along a path before trying other paths
		Follow a path to the end before backing up and following a different path

		View graph as a tree - DFS
			Root of tree = starting vertex of graph
		Can be done through recursion and iteration

		Recursive algorithm
		-------------------
		DFS (vertex)
			vertex->visited = true
			for (int x = 0; x < vertex.adjacent.size(); ++x)
				if (!vertex.adjacent[x].visited)
					print vertex.adjacent[x].key
					// do stuff
					DFS(vertex.adjacent[x].v)

		Iterative algorithm
		-------------------
			uses stack data structure instead of call stack => different order

			DFS (value)
				vertex = search(value)
				stack.push(vertex)
				while (!stack.empty)
					v = stack.pop()
					print v.key
					// do stuff
					for each a in v.adjacent
						if !a.visited
							a.visited = true
							stack.push(a)


	Shortest Path
	=============

	Dijkstra's Algorithm
	--------------------
		Edge weight > 0

	Dijkstra (start, end)
		find start
		find end
		solved = {start} // set of solved vertices
		while (!end.solved)
			for each v in solved
				for each a in v.adjacent
					if (!a.solved)
						calculate distance from start to a // distance to v + edge weight v-a
						if dist < minDist
							store a as minVertex
							minDist = dist
			add minVertex to solved
		return end // store dist to endVertex and its parent vertex

		Algorithm doesn't use stack or queue.
		It instead uses a set/array/list
		Note that distance is sum of edge weights and not edge counts
		When vertex added to solved, also store the parent to that vertex (the node from which we got that minDistance)


*/