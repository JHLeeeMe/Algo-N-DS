/**
 * UnDirectedGraph
 */

package algorithm.graph;

public class UnDirectedGraph extends AbstGraph {
    private int size;
    private Node[] nodes;

    public UnDirectedGraph(int size) {
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
    @Override
    public void addEdge(int a, int b) {
        if ((a < 0) || (b < 0) || 
            (this.size < a) || (this.size < b)) {

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
}
