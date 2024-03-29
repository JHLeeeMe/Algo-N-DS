/**
 * SinglyLinkedList
 */

package dataStructure;

import java.util.Iterator;

public class SinglyLinkedList<T> {
    private Node<T> head;
    private int size = 0;

    private static class Node<T> {
        private T data;
        private Node<T> next;

        Node(T item) {
            this.data = item;
        }

        public String toString() {
            return "data: " + this.data;
        }
    }

    /**
     * Appends item to the end of this list.
     */
    public void add(T item) {
        addLast(item);
    }

    /**
     * Add into idx
     */
    public void add(int idx, T item) {
        if (idx < 0 || idx > size) {
            throw new IndexOutOfBoundsException("" + idx);
        }

        if (idx == 0) {
            addFirst(item);
        }

        Node<T> before = node(idx-1);
        addAfter(before, item);
    }

    /**
     * Insert into First
     */
    public void addFirst(T item) {
        Node<T> newNode = new Node<>(item);

        newNode.next = head;
        head = newNode;
        size++;
    }

    /**
     * Insert into Last
     */
    public void addLast(T item) {
        Node<T> newNode = new Node<>(item);

        if (head == null) {
            head = newNode;
        } else {
            Node<T> curr = head;
            while (curr.next != null) {
                curr = curr.next;
            }
            curr.next = newNode;
        }
        size++;
    }

    /**
     * Insert into before.next
     */
    private void addAfter(Node<T> before, T item) {
        Node<T> newNode = new Node<>(item);

        newNode.next = before.next;
        before.next = newNode;
        size++;
    }

    /**
     * Remove First Node<T>
     */
    public T remove() {
        return removeFirst();
    }

    public T remove(int idx) {
        if (idx < 0 || idx >= size) {
            throw new IndexOutOfBoundsException("" + idx);
        }

        if (idx == 0) {
            return removeFirst();
        }

        Node<T> before = node(idx-1);
        return removeAfter(before);
    }

    /**
     * Remove By Item
     */
    public boolean removeByItem(T item) {
        int idx = indexOf(item);

        if (idx != -1) {
            remove(idx);
            return true;
        }
        return false;
    }

    /**
     * Remove First 
     */
    public T removeFirst() {
        if (head == null)
            return null;

        T tmp = head.data;
        head = head.next;
        size--;

        System.out.println("first node is removed.");
        return tmp;
    }

    private T removeAfter(Node<T> before) {
        if (before.next == null) {
            return null;
        }
        
        T tmp = before.next.data;
        before.next = before.next.next;
        size--;
        return tmp;
    }

    private Node<T> node(int idx) {
        if (idx < 0 || idx >= size) {
            return null;
        }
        
        Node<T> curr = head;
        for (int i=0; i<idx; i++) {
            curr = curr.next;
        }
        
        return curr;
    }

    public int indexOf(T item) {
        Node<T> curr = head;
        int idx = 0;
        while (curr != null) {
            if (curr.data == item) {
                return idx;
            }
            curr = curr.next;
            idx++;
        }
        System.out.println("data " + item + " is not in linkedlist");
        return -1;
    }

    public int size() {
        return this.size;
    }

    public Iterator<T> iterator() {
        return new MyIterator();
    }

    private class MyIterator implements Iterator<T> {
        private Node<T> nextNode;

        public MyIterator() {
            this.nextNode = head;
        }

        public boolean hasNext() {
            return this.nextNode != null;
        }

        public T next() {
            if (nextNode == null) {
                throw new java.util.NoSuchElementException();
            }

            T tmp = nextNode.data;
            nextNode = nextNode.next;
            return tmp;
        }
    }

    public static void main(String[] args) {
        // SinglyLinkedList<Integer> a = new SinglyLinkedList<>();
        // System.out.println(a.head);                     // prints null
        // System.out.println();

        // a.remove(10);                                   // prints "It's empty.""
        // System.out.println();

        // a.addLast(10);
        // System.out.println(a.head);                     // prints "data: 10"
        // System.out.println(a.head.next);                // prints null
        // System.out.println();

        // a.addLast(20);
        // System.out.println(a.head);                     // prints "data: 10"
        // System.out.println(a.head.next);                // prints "data: 20"
        // System.out.println();

        // a.addLast(30);
        // System.out.println(a.head);                     // prints "data: 10"
        // System.out.println(a.head.next);                // prints "data: 20"
        // System.out.println(a.head.next.next);           // prints "data: 30"
        // System.out.println();

        // a.addFirst(5);
        // System.out.println(a.head);                     // prints "data: 5"
        // System.out.println(a.head.next);                // prints "data: 10"
        // System.out.println(a.head.next.next);           // prints "data: 20"
        // System.out.println(a.head.next.next.next);      // prints "data: 30"
        // System.out.println();

        // a.remove(20);                                   // prints "data 20 삭제 완료.""
        // System.out.println(a.head);                     // prints "data: 5"
        // System.out.println(a.head.next);                // prints "data: 10"
        // System.out.println(a.head.next.next);           // prints "data: 30"
        // System.out.println();

        // a.remove(20);                                   // prints "data 20 is not in linkedlist"

        //SinglyLinkedList<Integer> a = new SinglyLinkedList<>();
        //a.add(9);
        //a.add(8);
        //a.add(7);
        //a.add(6);
        //a.add(5);
        //a.add(4);
        //a.add(3);
        //a.add(2);
        //a.add(1);
        //a.add(0);
        //System.out.println(a.size);

        //a.removeByItem(9);
        //System.out.println(a.size);

        //a.remove(9);
        //System.out.println(a.size);

        //for (int k=0; k<a.size; k++) {
            //System.out.print(a.node(k).data + " ");
        //}
        //System.out.println();

        SinglyLinkedList<String> a = new SinglyLinkedList<>();
        a.add("a");
        a.add("b");
        a.add("c");
        a.add("d");
        System.out.println(a.indexOf("c"));

        Iterator<String> iter = a.iterator();
        while (iter.hasNext())
            System.out.print(iter.next() + " ");
        System.out.println();
    }
}
