/**
 * Cycle Detection
 */

package algorithm.graph;

import algorithm.graph.AbstGraph.Node;

public class CycleDetection {
    private AbstGraph graph;

    boolean hasCycle(AbstGraph graph) {
        if (graph instanceof DirectedGraph) {
            this.graph = graph;
            return hasCycleInDirectedGraph((DirectedGraph)this.graph);
        } else if (graph instanceof UnDirectedGraph) {
            this.graph = graph;
            return hasCycleInUnDirectedGraph((UnDirectedGraph)this.graph);
        }

        throw new Error("CycleDetection::hasCycle(AbstGraph)");
    }

    private boolean hasCycleInDirectedGraph(DirectedGraph directedGraph) {
        assert (directedGraph instanceof DirectedGraph);

        return false;
    }

    private boolean hasCycleInUnDirectedGraph(UnDirectedGraph unDirectedGraph) {
        assert (unDirectedGraph instanceof UnDirectedGraph);

        /* back edge 검출 */

        return false;
    }

    public void dfsRecursive() {
        dfsRecursive(0);
    }

    public void dfsRecursive(int idx) {
        if ((idx < 0) || (graph.getSize() <= idx)) {
            throw new Error();
        }

        Node node = graph.getNode(idx);
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
         *        0
         *       /
         *      1 
         *     /  \
         *    2 -- 3 -- 4
         */
        AbstGraph unDirectedGraph = new UnDirectedGraph(5);
        unDirectedGraph.addEdge(0, 1);
        unDirectedGraph.addEdge(1, 2);
        unDirectedGraph.addEdge(1, 3);
        unDirectedGraph.addEdge(2, 3);
        unDirectedGraph.addEdge(3, 4);

        CycleDetection cycleDetection = new CycleDetection();
        cycleDetection.hasCycle(unDirectedGraph);
        //cycleDetection.hasCycle(null);
    }
}