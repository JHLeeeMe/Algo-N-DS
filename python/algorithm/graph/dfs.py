from .graph_base import GraphBase


Node = GraphBase.Node


class DFS:
    def __init__(self, graph: GraphBase):
        if not isinstance(graph, GraphBase):
            raise TypeError()

        self._graph = graph

    def dfs(self, idx: int = 0):
        if (idx < 0) or (idx >= self._graph.size):
            raise IndexError("0 <= idx < self.graph.size")

        node = self._graph.node_at(idx)
        self._dfs(node)

    def _dfs(self, node: Node):
        assert (node is not None)

        # 1. stack 생성 & 시작 노드 append
        stack = [node]
        node.marked = True  # 추가된 노드 마킹

        while len(stack) > 0:
            tmp_node = stack.pop()  # 2. stack 에서 노드를 하나 꺼내서

            # 3. 꺼낸 노드와 간선으로 연결된 노드들 중
            #    마킹이 안돼있는 놈들만 stack 에 넣고, 마킹
            for n in tmp_node.adjacent:
                if n.marked is False:
                    stack.append(n)
                    n.marked = True

            # 4. 꺼낸 노드는 print
            print(str(tmp_node.data), end=" ")

    def dfs_recursive(self, idx: int = 0):
        if (idx < 0) or (idx >= self._graph.size):
            raise IndexError("0 <= idx < self.graph.size")

        node = self._graph.node_at(idx)
        self._dfs_recursive(node)

    def _dfs_recursive(self, node: Node):
        assert (node is not None)

        # 1. 방문 마킹
        node.marked = True

        # 2. 현재 노드 출력
        print(node.data, end=" ")

        # 3. 현재 노드와 간선으로 연결된 노드들 중
        #    마킹이 안돼있으면 recursion
        for n in node.adjacent:
            if n.marked is False:
                self._dfs_recursive(n)
