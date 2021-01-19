/**
 * BFS (Breadth-First Search, 너비 우선 탐색)
 *  1. queue를 활용한 구현
 */

package algorithm.graph;

import java.util.Queue;

import algorithm.graph.Graph.Node;

public class BFS {
    Graph graph;

    public BFS(Graph graph) {
        this.graph = graph;
    }

    /* queue를 활용한 구현 */
    public void bfs() {
        bfs(0);
    }

    public void bfs(int idx) {
        if ((idx < 0) || (idx >= graph.getSize())) {
            throw new Error();
        }

        Node node = graph.getNode(idx);
        bfs(node);
    }

    private void bfs(Node node) {
        assert (node != null);

        // 1. queue 할당 & 시작 노드를 넣으면 준비 끝
        Queue<Node> queue = new Queue<>();
        queue.add(node);
        node.marked = true;  // 넣은 node는 마킹

        while (!queue.isEmpty()) {
            Node tmp = queue.poll();  // 2. queue에서 node를 하나 꺼내서

            /**
             * 3. 현재 노드와 간선으로 연결된 노드들 중 
             *    마킹이 안돼있는 놈들만 queue에 넣고, 마킹
             */
            for (Node n : tmp.adjacent) {
                if (!n.marked) {
                    queue.add(n);
                    n.marked = true;
                }
            }

            // 4. 꺼낸 node는 print
            System.out.println(tmp.data + " ");
        }
    }

    public static void main(String[] args) {
    }
}
