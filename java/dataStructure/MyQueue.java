package dataStructure;

interface InnerMyQueue<T> {
    boolean isEmpty();
    void clear();
    void enqueue(T item);
    T dequeue();
    T peek();
}

public class MyQueue<T> implements InnerMyQueue<T> {
    private Node<T> front;
    private Node<T> rear;
    private int size = 0;

    private static class Node<T> {
        private T data;
        private Node<T> next;

        Node(T item) {
            this.data = item;
        }
    }

    @Override
    public boolean isEmpty() {
        return this.front == null;
    }

    @Override
    public void clear() {
        front = rear = null;
        size = 0;
    }

    @Override
    public void enqueue(T item) {
        Node<T> newNode = new Node<>(item);
        if (isEmpty())
            front = newNode;
        else
            rear.next = newNode;
        rear = newNode;
        size++;
    }

    @Override
    public T dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is Empty");
            throw new java.util.NoSuchElementException();
        } else {
            T tmp = front.data;
            front = front.next;
            size--;
            return tmp;
        }
    }

    @Override
    public T peek() {
        if (isEmpty()) {
            System.out.println("Queue is Empty");
            throw new java.util.NoSuchElementException();
        } else {
            return front.data;
        }
    }

    public int getSize() {
        return this.size;
    }

    public void printAll() {
        if (front == null) {
            System.out.println("Queue is Empty");
        } else {
            Node<T> tmp = front;
            System.out.print("[");
            for (int i=0; i<size; i++) {
                System.out.print(tmp.data + ", ");
                tmp = tmp.next;
            }
            System.out.println("]");
        }
    }

    public static void main(String[] args) {
        MyQueue<Integer> queue = new MyQueue<>();
        System.out.println(queue.getSize());
        System.out.println(queue.isEmpty());
        queue.printAll();
        System.out.println("==============================");

        // System.out.println(queue.peek());
        // System.out.println(queue.dequeue());
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        queue.enqueue(40);
        queue.enqueue(50);
        queue.enqueue(60);
        queue.printAll();
        System.out.println(queue.getSize());
        System.out.println("==============================");

        System.out.println(queue.peek());
        System.out.println(queue.getSize());
        System.out.println(queue.dequeue());
        System.out.println(queue.getSize());
        System.out.println("==============================");

        System.out.println(queue.front.data);
        System.out.println(queue.rear.data);
        queue.enqueue(90);
        queue.printAll();
        System.out.println(queue.isEmpty());
        System.out.println("==============================");

        queue.clear();
        queue.printAll();
        System.out.println(queue.getSize());
        System.out.println(queue.isEmpty());
    }
}
