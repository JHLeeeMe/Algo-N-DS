package dataStructure;

/**
 * BinarySearchTree
 * 
 * search, delete, insert => O(logN)
 */
public class BinarySearchTree {
    public static void main(String[] args) {
        /**
         * bst is ....
         *   10                           50
         *    \                           /\
         *     50                       25  60
         *     /\                       /\
         *   20  60        ===>       17  30      
         *   /\                           
         * 17  30                       
         *     /
         *   25  
         */
        BinarySearchTree bst = new BinarySearchTree();
        bst.insert(10);
        bst.insert(10);  // prints "중복 데이터 10 (이)가 있으므로 insert하지 않음."
        bst.insert(50);
        bst.insert(20);
        bst.insert(30);
        bst.insert(25);
        bst.insert(17);
        bst.insert(60);

        System.out.println(bst.root.right.right);       // prints "data: 60"
        bst.delete(60);
        System.out.println(bst.root.right.right);       // prints "null"
        bst.insert(60);
        System.out.println(bst.root.right.right);       // prints "data: 60"

        System.out.println(bst.root.right.left);        // prints "data: 20"
        bst.delete(20);
        System.out.println(bst.root.right.left);        // prints "data: 25"
        System.out.println(bst.root.right.left.right);  // prints "data: 30"

        bst.delete(10);
        System.out.println(bst.root);                   // prints "data: 50"
        System.out.println(bst.search(50).left);        // prints "data: 25"
    }

    private Node root;

    // Node Class
    private class Node {
        int data;
        Node left;
        Node right;

        public Node(int item) {
            this.data = item;
        }

        public String toString() {
            return "data: " + this.data;
        }
    }

    /**
     * Insert
     */
    public boolean insert(int item) {
        if (search(item) != null) {
            System.out.println("중복 데이터 " + item + " (이)가 있으므로 insert하지 않음.");
            return false;
        }

        if (root == null) {
            root = new Node(item);
            return true;
        } else {
            return insertNode(root, item);
        }
    }

    private boolean insertNode(Node root, int item) {
        if (root.data > item) {
            if (root.left != null) {
                return insertNode(root.left, item);
            } else {
                root.left = new Node(item);
            }
        } else {
            if (root.right != null) {
                return insertNode(root.right, item);
            } else {
                root.right = new Node(item);
            }
        }
        return true;
    }

    /**
     * Search
     */
    public Node search(int item) {
        if (root == null)
            return null;
        else 
            return searchNode(root, item);
    }

    private Node searchNode(Node root, int item) {
        if (root.data == item) {
            return root;
        } else {
            if (root.data > item) {
                if (root.left != null)
                    return searchNode(root.left, item);
            } else {
                if (root.right != null)
                    return searchNode(root.right, item);
            }

            return null;
        }
    }

    /**
     * Delete
     */
    public boolean delete(int item) {
        if (root == null) {
            System.out.println("트리가 존재하지 않습니다.");
            return false;
        } 
        if (root.data == item) {  // 삭제하려는 데이터가 root 노드
            switch (childNum(root)) {
                case 0:
                    root = null;
                    break;
                case 1:
                    if (root.left == null)   // 오른쪽 자식만 있는 경우
                        root = root.right;
                    else                    // 왼쪽 자식만 있는 경우
                        root = root.left;
                    break;
                case 2:
                    Node parentOfSuccessor = getSuccessor(root)[0];  // successor 부모 노드
                    Node successor = getSuccessor(root)[1];         // successor

                    root.data = successor.data;             // successor의 '데이터'를 옮기고
                    // 석세서의 right child를 석세서의 부모노드의 left에 붙힌다.
                    parentOfSuccessor.left = successor.right; 
                    break;
            }
            return true;
        } else {
            if (root.data > item)
                return deleteNode(root, root.left, item);
            else
                return deleteNode(root, root.right, item);
        }
    }

    private boolean deleteNode(Node parent, Node curr, int item) {
        if (curr == null) {
            System.out.println("데이터가 존재하지 않습니다.");
            return false;
        }

        if (curr.data == item) {
            switch (childNum(curr)) {
                case 0:
                    if (parent.left == curr)
                        parent.left = null;
                    else
                        parent.right = null;
                    break;
                case 1:
                    if (parent.left == curr)
                        parent.left = curr.right;
                    else
                        parent.right = curr.right;
                    break;
                case 2:
                    // 자식이 둘이면 그 노드의 석세서와 석세서의 부모노드를 구하고 작업
                    Node[] successorInfo = getSuccessor(curr);
                    Node parentOfSuccessor = successorInfo[0];
                    Node successor = successorInfo[1];

                    curr.data = successor.data;
                    parentOfSuccessor.left = successor.right;

                    break;
            }
            return true;
        } else {
            if (curr.data > item)
                return deleteNode(curr, curr.left, item);
            else
                return deleteNode(curr, curr.right, item);
        }
    }

    /**
     * 파라미터 노드의 child node 수
     */
    private int childNum(Node root) {
        if (root.left == null && root.right == null) {
            return 0;
        } else if (root.left != null && root.right != null) {
            return 2;
        } else {
            return 1;
        }
    }

    /**
     * 파라미터 노드의 successor & successor의 부모노드를 Node[] 타입으로 return
     */
    private Node[] getSuccessor(Node root) {
        Node parent = root;
        root = root.right;

        while(root.left != null) {
            parent = root;
            root = root.left;
        }

        Node[] result = {parent, root};
        return result;
    }
}