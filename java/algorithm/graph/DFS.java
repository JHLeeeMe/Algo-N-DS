/**
 * DFS (Depth-First Search, 깊이 우선 탐색)
 *  1. stack을 활용한 구현
 *  2. 재귀함수를 활용한 구현
 */

package algorithm.graph;

import java.util.Stack;

import algorithm.graph.AbstGraph.Node;

public class DFS {
    AbstGraph graph;

    public DFS(AbstGraph graph) {
        this.graph = graph;
    }

    /* 1. stack을 활용한 구현 */
    public void dfs() {
        dfs(0);
    }

    public void dfs(int idx) {
        if ((idx < 0) || (idx >= this.graph.getSize())) {
            throw new Error();
        }

        Node node = this.graph.getNode(idx);
        dfs(node);
    }

    private void dfs(Node node) {
        assert (node != null);

        // 1. stack 할당 & 시작 노드를 넣으면 준비 끝
        Stack<Node> stack = new Stack<>();
        stack.push(node);
        node.marked = true; // 넣은 node는 마킹

        while (!stack.isEmpty()) {
            Node tmp = stack.pop(); // 2. stack에서 node를 하나 꺼내서

            /**
             * 3. 현재 노드와 간선으로 연결된 노드들 중 
             *    마킹이 안돼있는 놈들만 stack에 넣고, 마킹
             */
            for (Node n : tmp.adjacent) {
                if (!n.marked) {
                    stack.push(n);
                    n.marked = true;
                }
            }

            // 4. 꺼낸 node는 print
            System.out.print(tmp.data + " ");
        }
    }

    /* 2. 재귀함수를 활용한 구현 */
    public void dfsRecursive() {
        dfsRecursive(0);
    }

    public void dfsRecursive(int idx) {
        if ((idx < 0) || (this.graph.getSize() <= idx)) {
            throw new Error();
        }

        Node node = this.graph.getNode(idx);
        dfsRecursive(node);
    }

    private void dfsRecursive(Node node) {
        assert (node != null);

        // 1. 방문 마킹
        node.marked = true;

        // 2. 데이터 출력
        System.out.print(node.data + " ");

        // 3. 현재 노드와 간선으로 연결된 노드들 보기
        for (Node n : node.adjacent) {
            if (!n.marked) { // 4. 방문이 안된 곳이라면
                dfsRecursive(n);
            }
        }
    }

    public static void main(String[] args) {
        /**
         * UnDirectedGraph
         * 
         *     0
         *    /
         *   1 -- 3 -- 5 -- 7
         *   |  / |     \
         *   | /  |      6 -- 8     
         *   2 -- 4
         */
        AbstGraph uGraph = new UnDirectedGraph(9);
        uGraph.addEdge(0, 1);
        uGraph.addEdge(1, 2);
        uGraph.addEdge(1, 3);
        uGraph.addEdge(2, 3);
        uGraph.addEdge(2, 4);
        uGraph.addEdge(3, 4);
        uGraph.addEdge(3, 5);
        uGraph.addEdge(5, 6);
        uGraph.addEdge(5, 7);
        uGraph.addEdge(6, 8);

        DFS dfs = new DFS(uGraph);
        //dfs.dfs(7);
        dfs.dfsRecursive(4);

        System.out.println();

        /**
         * DirectedGraph
         * 
         *      0
         *    ↙ ↘
         *   1     2 → 3
         *   ↓   ↓ ↖
         *   4 →  5 → 6
         * 
         *  (2 -> 5 -> 6 cycle)
         */
        AbstGraph dGraph = new DirectedGraph(7);
        dGraph.addEdge(0, 1);
        dGraph.addEdge(0, 2);
        dGraph.addEdge(1, 4);
        dGraph.addEdge(2, 3);
        dGraph.addEdge(2, 5);
        dGraph.addEdge(4, 5);
        dGraph.addEdge(5, 6);
        dGraph.addEdge(6, 2);

        DFS dfs1 = new DFS(dGraph);
        //dfs1.dfs();
        dfs1.dfsRecursive(6);
    }
}
