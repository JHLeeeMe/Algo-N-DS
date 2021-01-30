import unittest

from algorithm.graph.directed_graph import DirectedGraph
from algorithm.graph.undirected_graph import UnDirectedGraph
from algorithm.graph.cycle_detection import CycleDetection


class CycleDetectionTests(unittest.TestCase):
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

    def test_has_cycle_in_directed_graph_recursive(self):
        print("# directed graph has_cycle()...")
        cycle_detection = CycleDetection()
        flag = cycle_detection.has_cycle(self.directed_graph)
        self.assertTrue(flag)
        print()

    def test_has_cycle_in_undirected_graph_recursive(self):
        print("# unDirected graph has_cycle()...")
        cycle_detection = CycleDetection()
        flag = cycle_detection.has_cycle(self.undirected_graph)
        self.assertTrue(flag)
        print()

    def test_detect_cycle_in_directed_graph_recursive(self):
        print("# directed graph detect_cycle()...")
        cycle_detection = CycleDetection()
        cycle_detection.has_cycle(self.directed_graph, 3)
        self.assertFalse(cycle_detection.flag)

        with self.assertRaises(ValueError):
            cycle_detection.has_cycle(self.directed_graph, 7)

        print()

    def test_detect_cycle_in_undirected_graph_recursive(self):
        print("# unDirected graph detect_cycle()...")
        cycle_detection = CycleDetection()
        cycle_detection.has_cycle(self.undirected_graph, 7)
        self.assertTrue(cycle_detection.flag)

        with self.assertRaises(ValueError):
            cycle_detection.has_cycle(self.undirected_graph, 9)

        print()
