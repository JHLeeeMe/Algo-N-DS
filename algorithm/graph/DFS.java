/**
 * DFS (Depth-First Search, 깊이 우선 탐색)
 *  1. stack을 활용한 구현
 *  2. 재귀함수를 활용한 구현
 * 
 */

package algorithm.graph;

import java.util.LinkedList;
import java.util.Stack;

class Graph {
    int size;
    Node[] nodes;

    public Graph(int size) {
        this.size = size;
        this.nodes = new Node[size];

        for (int i=0; i<size; i++) {
            nodes[i] = new Node(i);
        }
    }

    /**
     * addEdge
     *  - 두 노드간 간선 추가
     */
    public void addEdge(int a, int b) {
        if (this.size < a || this.size < b) {
            throw new Error();
        }

        Node n1 = nodes[a];
        Node n2 = nodes[b];

        if (!n1.adjacent.contains(n2)) {
            n1.adjacent.add(n2);
        }
        if (!n2.adjacent.contains(n1)) {
            n2.adjacent.add(n1);
        }
    }

    /* 1. stack을 활용한 구현 */
    public void dfs() {
        dfs(0);
    }

    public void dfs(int idx) {
        if ((idx < 0) || (idx >= this.size)) {
            throw new Error();
        }

        Node node = this.nodes[idx];
        dfs(node);
    }

    private void dfs(Node node) {
        assert (node != null);

        // 1. stack 할당 & 시작 노드를 넣으면 준비 끝
        Stack<Node> stack = new Stack<>();
        stack.push(node);
        node.marked = true;  // 넣은 node는 마킹

        while (!stack.isEmpty()) {
            Node tmp = stack.pop();  // 2. stack에서 node를 하나 꺼내서

            /** 
             * 3. 현재 노드와 간선으로 연결된 노드들 중 
             *   마킹이 안돼있는 놈들만 stack에 넣고, 마킹
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
        if ((idx < 0) || (this.size <= idx)) {
            throw new Error();
        }

        Node node = nodes[idx];
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
            if (!n.marked) {  // 4. 방문이 안된 곳이라면
                dfsRecursive(n);
            }
        }
    }

    class Node {
        int data;
        boolean marked;
        LinkedList<Node> adjacent;

        Node(int data) {
            this.data = data;
            this.marked = false;
            this.adjacent = new LinkedList<>();
        }
    }
}

public class DFS {
    public static void main(String[] args) {
        /**
         *     0
         *    /
         *   1 -- 3 -- 5 -- 7
         *   |  / |     \
         *   | /  |      6 -- 8     
         *   2 -- 4
         */
        Graph graph = new Graph(9);
        graph.addEdge(0, 1);
        graph.addEdge(1, 2);
        graph.addEdge(1, 3);
        graph.addEdge(2, 3);
        graph.addEdge(2, 4);
        graph.addEdge(3, 4);
        graph.addEdge(3, 5);
        graph.addEdge(5, 6);
        graph.addEdge(5, 7);
        graph.addEdge(6, 8);

        graph.dfs();
        //graph.dfsRecursive();
    }
}
