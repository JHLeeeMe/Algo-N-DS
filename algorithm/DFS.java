/**
 * DFS (Depth-First Search, 깊이 우선 탐색)
 *  1. stack을 활용한 구현
 *  2. 재귀함수를 활용한 구현
 * 
 */

package algorithm;

import java.util.LinkedList;

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
        Node node = this.nodes[idx];
        dfs(node);
    }

    public void dfs(Node node) {
        ;
    }

    /* 2. 재귀함수를 활용한 구현 */
    public void dfsRecursive() {
        dfsRecursive(0);
    }

    public void dfsRecursive(int idx) {
        Node node = nodes[idx];
        dfsRecursive(node);
    }

    public void dfsRecursive(Node node) {
        ;
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
    }
}
