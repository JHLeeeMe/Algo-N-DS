from queue import Queue

from algorithm.graph.graph_base import GraphBase


Node = GraphBase.Node


class BFS:
    def __init__(self, graph: GraphBase):
        if not isinstance(graph, GraphBase):
            raise TypeError()

        self._graph = graph

    def bfs(self, idx: int = 0):
        if (idx < 0) or (idx >= self._graph.size):
            raise IndexError("0 <= idx < self._graph.size")

        node = self._graph.node_at(idx)
        self._bfs(node)

    def _bfs(self, node: Node):
        assert (node is not None)

        # 1. queue 생성 & 시작 노드 put
        queue = Queue()
        queue.put(node)
        node.marked = True  # 추가된 노드 마킹

        while not queue.empty():
            tmp_node = queue.get()  # 2. queue 에서 노드를 하나 꺼내서

            # 3. 꺼낸 노드와 간선으로 견결된 노드들 중
            #    마킹이 안돼있는 놈들만 queue 넣고, 마킹
            for n in tmp_node.adjacent:
                if n.marked is False:
                    queue.put(n)
                    n.marked = True

            # 4. 꺼낸 노드는 print
            print(str(tmp_node.data), end=" ")
