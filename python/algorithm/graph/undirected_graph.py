from .graph_base import GraphBase


Node = GraphBase.Node


class UnDirectedGraph(GraphBase):
    def __init__(self, size: int):
        self.__size = size
        self.__nodes = list()

    def add_edge(self, _from: int, _to: int):
        if (_from < 0) or (_to < 0) or \
                (self.__size < _from) or (self.__size < _to):
            raise IndexError("")

        n1 = self.nodes[_from]
        n2 = self.nodes[_to]

        if n2 not in n1.adjacent:
            n1.adjacent.append(n2)
        if n1 not in n2.adjacent:
            n2.adjacent.append(n1)

    @property
    def node(self, idx: int) -> Node:
        return self.nodes[idx]

    @property
    def size(self) -> int:
        return self.__size
