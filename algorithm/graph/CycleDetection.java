/**
 * Cycle Detection
 */

package algorithm.graph;

import java.util.Stack;

import algorithm.graph.AbstGraph.Node;

public class CycleDetection {
    private AbstGraph graph;
    private boolean flag = false;
    Stack<Node> processStack = new Stack<>();

    public boolean hasCycle(AbstGraph graph) {
        if (!(graph instanceof DirectedGraph) && !(graph instanceof UnDirectedGraph)) {
            throw new Error("CycleDetection::hasCycle(AbstGraph)");
        }

        this.graph = graph;
        detectCycle();

        return this.flag;
    }

    /* detect cycle algorithm */
    private void detectCycle() {
        detectCycle(0);
    }

    private void detectCycle(int idx) {
        if ((idx < 0) || (this.graph.getSize() <= idx)) {
            throw new Error("idx is must be between 0 and graph.getSize().");
        }

        Node node = this.graph.getNode(idx);

        if (this.graph instanceof DirectedGraph) {
            detectCycleInDirectedGraphRecursive(node);
        } else {
            detectCycleInUnDirectedGraphRecursive(node, null);
        }
    }

    /* DirectedGraph의 경우 */
    private void detectCycleInDirectedGraphRecursive(Node curr) {
        assert (curr != null);

        // 1. 방문 마킹
        curr.marked = true;

        // 2. 현재 노드를 stack에 push
        this.processStack.push(curr);

        // 3. 현재 노드와 간선으로 연결된 노드들 보기
        for (Node n : curr.adjacent) {
            if (!n.marked) { // 3-1. 방문이 안된 곳이라면
                detectCycleInDirectedGraphRecursive(n);
            } else {
                if (this.processStack.contains(n)) {  // 3-2. 방문이 됐는데 진행중인 process라면 back edge
                    this.flag = true;
                    break;
                }
            }
        }
        this.processStack.pop();
    }

    /* UnDirectedGraph의 경우 */
    private void detectCycleInUnDirectedGraphRecursive(Node curr, Node prev) {
        assert (curr != null);

        // 1. 방문 마킹
        curr.marked = true;

        // 2. 현재 노드와 간선으로 연결된 노드들 보기
        for (Node n : curr.adjacent) {
            if (!n.marked) { // 2-1. 방문이 안된 곳이라면
                detectCycleInUnDirectedGraphRecursive(n, curr);
            } else {
                if (n != prev) {  // 2-2. detect back edge
                    this.flag = true;
                    break;
                }
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

        CycleDetection cycleDetectionInUnDirectedGraph = new CycleDetection();

        if (cycleDetectionInUnDirectedGraph.hasCycle(unDirectedGraph)) {
            System.out.println("싸이클 존재");
        } else {
            System.out.println("안존재");
        }

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
        AbstGraph directedGraph = new DirectedGraph(7);
        directedGraph.addEdge(0, 1);
        directedGraph.addEdge(0, 2);
        directedGraph.addEdge(1, 4);
        directedGraph.addEdge(2, 3);
        directedGraph.addEdge(2, 5);
        directedGraph.addEdge(4, 5);
        directedGraph.addEdge(5, 6);
        directedGraph.addEdge(6, 2);

        CycleDetection cycleDetectionInDirectedGraph = new CycleDetection();

        if (cycleDetectionInDirectedGraph.hasCycle(directedGraph)) {
            System.out.println("싸이클 존재");
        } else {
            System.out.println("안존재");
        }
    }
}
