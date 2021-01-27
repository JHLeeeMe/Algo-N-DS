import unittest

from algorithm.graph.dfs import DFS
from algorithm.graph.directed_graph import DirectedGraph
from algorithm.graph.undirected_graph import UnDirectedGraph


class DFSTests(unittest.TestCase):
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

        #"""
        #DirectedGraph

        #     0
        #   ↙ ↘
        #  1     2 → 3
        #  ↓   ↓ ↖
        #  4 →  5 → 6

        #  (2 -> 5 -> 6 cycle)
        #"""
        #self.directed_graph = DirectedGraph(7)
        #self.directed_graph.add_edge(0, 1)
        #self.directed_graph.add_edge(0, 2)
        #self.directed_graph.add_edge(1, 4)
        #self.directed_graph.add_edge(2, 3)
        #self.directed_graph.add_edge(2, 5)
        #self.directed_graph.add_edge(4, 5)
        #self.directed_graph.add_edge(5, 6)
        #self.directed_graph.add_edge(6, 2)
        #print("hi1")

    def test_undirected_graph_dfs(self):
        dfs = DFS(self.undirected_graph)
        dfs.dfs()
        print()

    def test_undirected_graph_dfs_recursive(self):
        dfs = DFS(self.undirected_graph)
        dfs.dfs_recursive()
        print()
#
#    def directed_graph_dfs_test(self):
#        dfs = DFS(self.directed_graph)
#        dfs.dfs()
#
#    def directed_graph_dfs_recursive_test(self):
#        dfs = DFS(self.directed_graph)
#        dfs.dfs_recursive()
#