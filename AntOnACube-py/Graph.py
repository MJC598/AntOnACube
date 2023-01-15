from collections import defaultdict

class Graph():
    undirected_graph = defaultdict(list)

    def __init__(self):
        pass

    def add_node(self, node: int):
        self.undirect_graph.append(node)

    def add_edge(self, v1: int, v2: int):
        try:
            self.undirected_graph[v1].append(v2)
            self.undirected_graph[v2].append(v1)
        except:
            print("Undirected graph does not contain appropriate nodes")
            return 0

    def build_cube(self):
        for i in range(8):
            self.undirected_graph[i] = []

        self.add_edge(0, 1)
        self.add_edge(0, 3)
        self.add_edge(0, 4)

        self.add_edge(1, 2)
        self.add_edge(1, 5)

        self.add_edge(2, 3)
        self.add_edge(2, 6)

        self.add_edge(3, 7)

        self.add_edge(4, 5)
        self.add_edge(4, 7)

        self.add_edge(5, 6)

        self.add_edge(6, 7)

        return self.undirected_graph
