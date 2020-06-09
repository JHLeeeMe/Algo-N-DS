package dataStructure;

import java.util.ListIterator;
import java.util.NoSuchElementException;

/**
 * DoublyLinkedList
 */
public class DoublyLinkedList<T> {
    private Node<T> first;
    private Node<T> last;
    private int size = 0;

    private static class Node<T> {
        T item;
        Node<T> prev;
        Node<T> next;

        Node(Node<T> prev, T item, Node<T> next) {
            this.item = item;
            this.prev = prev;
            this.next = next;
        }
    }

    private void linkFirst(T t) {
        final Node<T> f = first;
        final Node<T> newNode = new Node<>(null, t, f);
        first = newNode;
        if (f == null)
            last = first;
        else
            f.prev = newNode;
        size++;
    }

    private void linkLast(T t) {
        final Node<T> l = last;
        final Node<T> newNode = new Node<>(l, t, null);
        last = newNode;
        if (l == null)
            first = newNode;
        else
            l.next = newNode;
        size++;
    }

    private void linkBefore(T t, Node<T> x) {
        // assert x != null;

        final Node<T> prev = x.prev;
        final Node<T> newNode = new Node<>(prev, t, x);
        x.prev = newNode;
        if (prev == null)
            first = newNode;
        else
            prev.next = newNode;
        size++;
    }

    private T unlinkFirst(Node<T> f) {
        final T element = f.item;
        final Node<T> next = f.next;
        f = null;
        first = next;
        if (next == null)
            last = null;
        else 
            next.prev = null;
        size--;
        return element;
    }

    private T unlinkLast(Node<T> l) {
        final T element = l.item;
        final Node<T> prev = l.prev;
        l = null;
        last = prev;
        if (prev == null)
            first = null;
        else
            prev.next = null;
        size--;
        return element;
    }

    private T unlink(Node<T> x) {
        // assert x != null;

        final T element = x.item;
        final Node<T> prev = x.prev;
        final Node<T> next = x.next;

        x = null;
        if (prev == null)
            first = next;
        else
            prev.next = next;

        if (next == null)
            last = prev;
        else
            next.prev = prev;
        size--;
        return element;
    }

    public boolean add(T item) {
        linkLast(item);
        return true;
    }

    public void addFirst(T item) {
        linkFirst(item);
    }

    public void addLast(T item) {
        linkLast(item);
    }

    public boolean add(int idx, T item) {
        if (isPositionIndex(idx)) {
            if (idx == size)
                linkLast(item);
            else
                linkBefore(item, node(idx));
            return true;
        }
        return false;
    }

    public T removeFirst() {
        return unlinkFirst(first);
    }

    public T removelast() {
        return unlinkLast(last);
    }

    public T remove(int idx) {
        if (isElementIndex(idx))
            return unlink(node(idx));
        return null;
    }

    public boolean removeByItem(Object o) {
        if (o == null) {
            for (Node<T> x = first; x != null; x = x.next) {
                if (x.item == null)
                    unlink(x);
                    return true;
            }
        } else {
            int idx = indexOf(o);
            if (isElementIndex(idx)) {
                unlink(node(idx));
                return true;
            }
        }
        return false;
    }

    public boolean set(int idx, T item) {
        if (isElementIndex(idx)) {
            node(idx).item = item;
            return true;
        }
        return false;
    }

    public T get(int idx) {
        if (isElementIndex(idx)) {
            return node(idx).item;
        }
        return null;
    }

    /**
     * Tells if the argument is the index of an existing element.
     */
    private boolean isElementIndex(int idx) {
        return idx >= 0 && idx < size;
    }

    private boolean isPositionIndex(int idx) {
        return idx >= 0 && idx <= size;
    }

    /**
     * get node of index
     * @param idx
     * @return Node<T>
     */
    private Node<T> node(int idx) {
        // assert isElementIndex(idx);

        if (idx < (size >> 1)) {
            Node<T> x = first;
            for (int i = 0; i < idx; i++)
                x = x.next;
            return x;
        } else {
            Node<T> x = last;
            for (int i = size - 1; i > idx; i--)
                x = x.prev;
            return x;
        }
    }

    /**
     * get index of parameter
     * @param o
     * @return idx || -1
     */
    public int indexOf(Object o) {
        int idx = 0;
        if (o == null) {
            for (Node<T> x = first; x != null; x = x.next) {
                if (x.item == null)
                    return idx;
                idx++;
            }
        } else {
            for (Node<T> x = first; x != null; x = x.next) {
                if (o.equals(x.item))
                    return idx;
                idx++;
            }
        }
        return -1;
    }

    public int size() {
        return this.size;
    }

    public ListIterator<T> listIterator() {
       return new MyListIterator();
    }

    public ListIterator<T> listIterator(int idx) {
       return new MyListIterator(idx);
    }

    private class MyListIterator implements ListIterator<T> {
        private Node<T> previous;
        private Node<T> next;
        private Node<T> lastReturned;

        public MyListIterator() {
            this.previous = null;
            this.next = first;
            this.lastReturned = null;
        }

        public MyListIterator(int idx) {
            this.previous = node(idx-1);
            this.next = node(idx);
            this.lastReturned = null;
        }

        public boolean hasPrevious() {
            return this.previous != null;
        }

        public boolean hasNext() {
            return this.next != null;
        }

        public T previous() {
            if (previous == null)
                throw new NoSuchElementException();

            T tmp = previous.item;  // for return item
            this.next = previous;
            this.previous = previous.prev;
            return tmp;
        }

        public T next() {
            if (next == null)
                throw new NoSuchElementException();
            
            T tmp = next.item;
            this.previous = next;
            this.next = next.next;
            return tmp;
        }

        public void add(T t) {
            // TODO Auto-generated method stub

        }

        public void remove() {
        }

        public int previousIndex() {
            // TODO Auto-generated method stub
            return 0;
        }

        public int nextIndex() {
            // TODO Auto-generated method stub
            return 0;
        }

        public void set(T t) {
            // TODO Auto-generated method stub
        }
    }

    public static void main(String[] args) {
        DoublyLinkedList<String> a = new DoublyLinkedList<>();

        a.add("a");
        a.add("b");
        a.add("c");
        a.add("d");
        for (int i = 0; i < a.size; i++)
            System.out.print(a.get(i) + ", ");
        System.out.println();
        System.out.println("size: " + a.size);

        a.add(2, "e");
        for (int i = 0; i < a.size; i++)
            System.out.print(a.get(i) + ", ");
        System.out.println();
        System.out.println("size: " + a.size);

        a.addLast("asdf");
        a.addFirst("zzz");
        for (int i = 0; i < a.size; i++)
            System.out.print(a.get(i) + ", ");
        System.out.println();
        System.out.println("size: " + a.size);

        a.remove(1);
        for (int i = 0; i < a.size; i++)
            System.out.print(a.get(i) + ", ");
        System.out.println();
        System.out.println("size: " + a.size);

        a.removeByItem("e");
        for (int i = 0; i < a.size; i++)
            System.out.print(a.get(i) + ", ");
        System.out.println();
        System.out.println("size: " + a.size);

        a.removeByItem(null);
        for (int i = 0; i < a.size; i++)
            System.out.print(a.get(i) + ", ");
        System.out.println();
        System.out.println("size: " + a.size);
    }
}