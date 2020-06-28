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

    private class Node<T> {
        private T data;
        private Node<T> next;

        Node(T item) {
            this.data = item;
        }
    }

    @Override
    public boolean isEmpty() {
        // TODO Auto-generated method stub
        return false;
    }

    @Override
    public void clear() {
        // TODO Auto-generated method stub

    }

    @Override
    public void enqueue(T item) {
        // TODO Auto-generated method stub

    }

    @Override
    public T dequeue() {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    public T peek() {
        // TODO Auto-generated method stub
        return null;
    }
    
}