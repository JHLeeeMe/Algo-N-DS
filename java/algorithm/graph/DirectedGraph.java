/**
 * DirectedGraph
 */

package algorithm.graph;

public class DirectedGraph extends AbstGraph {
    private int size;
    private Node[] nodes;

    public DirectedGraph(int size) {
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
    public void addEdge(int from, int to) {
        if ((from < 0) || (to < 0) ||
            (this.size < from) || (this.size < to)) {

            throw new Error();
        }

        Node n1 = nodes[from];
        Node n2 = nodes[to];

        if (!n1.adjacent.contains(n2)) {
            n1.adjacent.add(n2);
        }
    }

    @Override
    public int getSize() {
        return this.size;
    }

    @Override
    public Node getNode(int idx) {
        return this.nodes[idx];
    }
}
