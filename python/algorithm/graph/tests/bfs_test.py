import unittest

from algorithm.graph.bfs import BFS
from algorithm.graph.directed_graph import DirectedGraph
from algorithm.graph.undirected_graph import UnDirectedGraph


class BFSTests(unittest.TestCase):
    def setUp(self):
        """
        UnDirectedGraph

            0
           /
          1 -- 3 -- 5 -- 7
          |  / |     \
          | /  |      6 -- 8
          2 -- 4
        """
        self.undirected_graph = UnDirectedGraph(9)
        self.undirected_graph.add_edge(0, 1)
        self.undirected_graph.add_edge(1, 2)
        self.undirected_graph.add_edge(1, 3)
        self.undirected_graph.add_edge(2, 3)
        self.undirected_graph.add_edge(2, 4)
        self.undirected_graph.add_edge(3, 4)
        self.undirected_graph.add_edge(3, 5)
        self.undirected_graph.add_edge(5, 6)
        self.undirected_graph.add_edge(5, 7)
        self.undirected_graph.add_edge(6, 8)

        """
        DirectedGraph

            0
           ↙ ↘
          1    2 → 3
          ↓   ↓ ↖
          4 →  5 → 6

          (2 -> 5 -> 6 cycle)
        """
        self.directed_graph = DirectedGraph(7)
        self.directed_graph.add_edge(0, 1)
        self.directed_graph.add_edge(0, 2)
        self.directed_graph.add_edge(1, 4)
        self.directed_graph.add_edge(2, 3)
        self.directed_graph.add_edge(2, 5)
        self.directed_graph.add_edge(4, 5)
        self.directed_graph.add_edge(5, 6)
        self.directed_graph.add_edge(6, 2)

    def test_bfs_in_directed_graph(self):
        print("# Directed Graph BFS")
        bfs = BFS(self.directed_graph)
        bfs.bfs()
        print()

    def test_bfs_in_undirected_graph(self):
        print("# UnDirected Graph BFS")
        bfs = BFS(self.undirected_graph)
        bfs.bfs()
        print()
