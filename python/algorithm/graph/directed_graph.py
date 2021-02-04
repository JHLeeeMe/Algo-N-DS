from .graph_base import GraphBase


Node = GraphBase.Node


class DirectedGraph(GraphBase):
    def __init__(self, size: int):
        self._size = size
        self._nodes = []

        for i in range(self._size):
            self._nodes.append(Node(i))

    def add_edge(self, from_: int, to_: int):
        if (from_ < 0) or (to_ < 0) or \
                (self._size < from_) or (self._size < to_):
            raise IndexError("")

        n1 = self.node_at(from_)
        n2 = self.node_at(to_)

        if n2 not in n1.adjacent:
            n1.adjacent.append(n2)

    def node_at(self, idx: int) -> Node:
        return self._nodes[idx]

    @property
    def size(self) -> int:
        return self._size
