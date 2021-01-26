from abc import ABC, abstractmethod


class GraphBase(ABC):
    @abstractmethod
    def add_edge(self, a: int, b: int): pass

    @abstractmethod
    def get_node(self, idx: int): pass

    class Node:
        def __init__(self, data: int):
            self.data = data
            self.marked = False
            self.adjacent = list()
