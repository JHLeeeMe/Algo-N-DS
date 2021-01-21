package algorithm.graph;

import java.util.List;
import java.util.LinkedList;

public abstract class AbstGraph {
    public abstract void addEdge(int a, int b);

    class Node {
        int data;
        boolean marked;
        List<Node> adjacent;

        Node(int data) {
            this.data = data;
            this.marked = false;
            this.adjacent = new LinkedList<>();
        }
    }
}
