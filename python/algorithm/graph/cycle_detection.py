from algorithm.graph.graph_base import GraphBase
from algorithm.graph.directed_graph import DirectedGraph
from algorithm.graph.undirected_graph import UnDirectedGraph


Node = GraphBase.Node


class CycleDetection:
    def __init__(self, graph: GraphBase = None):
        self._graph = graph
        self._flag = False
        self._process_list = []

    def has_cycle(self, graph: GraphBase, idx: int = 0) -> bool:
        if not isinstance(graph, (DirectedGraph, UnDirectedGraph)):
            raise TypeError(
                "graph instance must be in (DirectedGraph or UnDirectedGraph)")

        self.__init__(graph)

        self._detect_cycle(idx)

        return self._flag

    def _detect_cycle(self, idx):
        if (idx < 0) or (idx >= self._graph.size):
            raise ValueError(f"idx must be (0 <= idx < {self._graph.size})")

        node = self._graph.node_at(idx)
        if isinstance(self.graph, DirectedGraph):
            self._detect_cycle_in_directed_graph_recursive(node)
        else:
            self._detect_cycle_in_undirected_graph_recursive(node)

    def _detect_cycle_in_directed_graph_recursive(self, curr: Node):
        assert (curr is not None)

        # 1. 현재 노드 마킹
        curr.marked = True

        # 2. 현재 노드를 process_list 에 적재
        self._process_list.append(curr)

        # 3. 현재 노드와 간선으로 연결된 노드 보기
        for n in curr.adjacent:
            if n.marked is False:  # 3-1. 마킹이 안된 노드라면
                self._detect_cycle_in_directed_graph_recursive(n)
            else:
                if n in self._process_list:  # 3-2. 마킹은 돼있는데 프로세스에 있다면 (detect back edge)
                    self._flag = True
                    break

    def _detect_cycle_in_undirected_graph_recursive(self, curr: Node, prev: Node = None):
        assert (curr is not None)

        # 1. 현재 노드 마킹
        curr.marked = True

        # 2. 현재 노드와 간선으로 연결된 노드들 보기
        for n in curr.adjacent:
            if n.marked is False:  # 2-1. 마킹이 안된 노드라면
                self._detect_cycle_in_undirected_graph_recursive(curr=n, prev=curr)
            else:
                if n != prev:  # 2-2. 마킹은 돼있는데 이전노드가 아니라면 (detect back edge)
                    self._flag = True
                    break
