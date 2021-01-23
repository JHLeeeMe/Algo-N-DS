package algorithm.graph;

import java.util.List;
import java.util.LinkedList;

public abstract class AbstGraph {
    private int size = 0;

    public int getSize() {
        return this.size;
    }

    public abstract void addEdge(int a, int b);
    public abstract Node getNode(int idx);

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
