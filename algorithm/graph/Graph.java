/**
 * Graph
 */

package algorithm.graph;

import java.util.LinkedList;

public class Graph {
    private int size;
    private Node[] nodes;

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

    public int getSize() {
        return this.size;
    }

    public Node getNode(int idx) {
        return this.nodes[idx];
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
