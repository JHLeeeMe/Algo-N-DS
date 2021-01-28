from algorithm.graph.graph_base import GraphBase
from algorithm.graph.directed_graph import DirectedGraph
from algorithm.graph.undirected_graph import UnDirectedGraph


Node = GraphBase.Node


class CycleDetection:
    def __init__(self):
        self.graph = None
        self.flag = False
        self.process_list = []

    def has_cycle(self, graph: GraphBase) -> bool:
        if not isinstance(graph, (DirectedGraph, UnDirectedGraph)):
            raise TypeError("graph instance must be in (DirectedGraph or UnDirectedGraph)")

        if self.graph is not None:
            self.graph = None

        self.graph = graph
        self.detect_cycle()

        return self.flag

    def detect_cycle(self, idx: int = 0):
        if (idx < 0) or (idx >= self.graph.size):
            raise ValueError(f"idx must be (0 <= idx < {self.graph.size})")

        node = self.graph.node_at(idx)
        if isinstance(self.graph, DirectedGraph):
            self.__detect_cycle_in_directed_graph_recursive(node)
        else:
            self.__detect_cycle_in_undirected_graph_recursive(node)

    def __detect_cycle_in_directed_graph_recursive(self, curr: Node):
        pass

    def __detect_cycle_in_undirected_graph_recursive(self, curr: Node, prev: Node = None):
        assert (curr is not None)

        # 1. 현재 노드 마킹
        curr.marked = True

        # 2. 현재 노드와 간선으로 연결된 노드들 보기
        for n in curr.adjacent:
            if n.marked is False:  # 3. 마킹이 안된 노드라면
                self.__detect_cycle_in_undirected_graph_recursive(curr=n, prev=curr)
            else:
                if n != prev:  # detect back edge
                    self.flag = True
                    break
