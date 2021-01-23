/**
 * Cycle Detection
 */

package algorithm.graph;

import algorithm.graph.AbstGraph;
import algorithm.graph.DirectedGraph;
import algorithm.graph.UnDirectedGraph;

public class CycleDetection {
    boolean hasCycle(AbstGraph graph) {
        if (graph instanceof DirectedGraph) {
            return hasCycleInDirectedGraph((DirectedGraph)graph);
        } else if (graph instanceof UnDirectedGraph) {
            return hasCycleInUnDirectedGraph((UnDirectedGraph)graph);
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
        cycleDetection.hasCycle(null);
    }
}