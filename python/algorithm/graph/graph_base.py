from abc import ABC, abstractmethod


class GraphBase(ABC):
    def __init__(self):
        self.size = 0

    @abstractmethod
    def add_edge(a: int, b: int): pass

    @abstractmethod
    def get_node(idx: int): pass

    class Node():
        def __init__(self, data: int):
            self.data = data
            self.marked = False
            self.adjacent = list()
