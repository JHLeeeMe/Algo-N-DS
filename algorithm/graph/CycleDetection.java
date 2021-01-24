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

    public CycleDetection(AbstGraph graph) {
        this.graph = graph;
    }

    boolean hasCycle(AbstGraph graph) {
        if (!(graph instanceof DirectedGraph) && !(graph instanceof UnDirectedGraph)) {
            throw new Error("CycleDetection::hasCycle(AbstGraph)");
        }

        this.graph = graph;
        detectCycle();

        return this.flag;
    }

    /* detect cycle algorithm */
    public void detectCycle() {
        detectCycle(0);
    }

    private void detectCycle(int idx) {
        if ((idx < 0) || (graph.getSize() <= idx)) {
            throw new Error("idx is must be between 0 and graph.getSize().");
        }

        Node node = graph.getNode(idx);

        if (graph instanceof DirectedGraph) {
            detectCycleInDirectedGraphRecursive(node);
        } else {
            detectCycleInUnDirectedGraphRecursive(node, null);
        }
    }

    private void detectCycleInDirectedGraphRecursive(Node curr) {
        assert (curr != null);

        // 1. 방문 마킹
        curr.marked = true;

        // 2. 현재 노드를 stack에 push
        processStack.push(curr);

        // 2. 현재 노드와 간선으로 연결된 노드들 보기
        for (Node n : curr.adjacent) {
            if (!n.marked) { // 3. 방문이 안된 곳이라면
                detectCycleInDirectedGraphRecursive(n);
            } else {
                if (processStack.contains(n)) {  // 방문이 됐는데 진행중인 process라면 back edge
                    this.flag = true;
                    break;
                }
            }
        }
        processStack.pop();
    }

    private void detectCycleInUnDirectedGraphRecursive(Node curr, Node parent) {
        assert (curr != null);

        // 1. 방문 마킹
        curr.marked = true;

        // 2. 현재 노드와 간선으로 연결된 노드들 보기
        for (Node n : curr.adjacent) {
            if (!n.marked) { // 3. 방문이 안된 곳이라면
                detectCycleInUnDirectedGraphRecursive(n, curr);
            } else {
                if (n != parent) {  // detect back edge
                    this.flag = true;
                    break;
                }
            }
        }
    }

    /* dfs recursion altorithm */
    public void dfsRecursive() {
        dfsRecursive(0);
    }

    public void dfsRecursive(int idx) {
        if ((idx < 0) || (graph.getSize() <= idx)) {
            throw new Error("idx is must be between 0 and graph.getSize().");
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
        //AbstGraph unDirectedGraph = new UnDirectedGraph(5);
        //unDirectedGraph.addEdge(0, 1);
        //unDirectedGraph.addEdge(1, 2);
        //unDirectedGraph.addEdge(1, 3);
        //unDirectedGraph.addEdge(2, 3);
        //unDirectedGraph.addEdge(3, 4);

        //CycleDetection cycleDetection = new CycleDetection(unDirectedGraph);

        //if (cycleDetection.hasCycle(unDirectedGraph)) {
        //    System.out.println("싸이클 존재");
        //} else {
        //    System.out.println("안존재");
        //}

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

        CycleDetection cycleDetection = new CycleDetection(directedGraph);

        if (cycleDetection.hasCycle(directedGraph)) {
            System.out.println("싸이클 존재");
        } else {
            System.out.println("안존재");
        }
    }
}