/**
 * BFS (Breadth-First Search, 너비 우선 탐색)
 *  1. queue를 활용한 구현
 */

package algorithm.graph;

import java.util.Queue;
import java.util.LinkedList;

import algorithm.graph.AbstGraph.Node;

public class BFS {
    UnDirectedGraph graph;

    public BFS(AbstGraph graph) {
        this.graph = (UnDirectedGraph)graph;
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
        Queue<Node> queue = new LinkedList<>();
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
            System.out.print(tmp.data + " ");
        }
    }

    public static void main(String[] args) {
        /**
         *     0
         *    /
         *   1 -- 3 -- 5 -- 7
         *   |  / |     \
         *   | /  |      6 -- 8     
         *   2 -- 4
         */
        AbstGraph undirectedGraph = new UnDirectedGraph(9);
        undirectedGraph.addEdge(0, 1);
        undirectedGraph.addEdge(1, 2);
        undirectedGraph.addEdge(1, 3);
        undirectedGraph.addEdge(2, 3);
        undirectedGraph.addEdge(2, 4);
        undirectedGraph.addEdge(3, 4);
        undirectedGraph.addEdge(3, 5);
        undirectedGraph.addEdge(5, 6);
        undirectedGraph.addEdge(5, 7);
        undirectedGraph.addEdge(6, 8);

        BFS bfs = new BFS(undirectedGraph);
        //bfs.bfs();
        bfs.bfs(3);
    }
}
