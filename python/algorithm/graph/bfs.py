from algorithm.graph.graph_base import GraphBase
from queue import Queue


Node = GraphBase.Node


class BFS:
    def __init__(self, graph: GraphBase):
        if not isinstance(graph, GraphBase):
            raise TypeError()

        self.graph = graph
        self.queue = Queue()
