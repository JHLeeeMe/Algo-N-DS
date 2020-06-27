package dataStructure;

interface InnerMyStack<T> {
    boolean isEmpty();
    boolean isFull();
    void clear();
    void push(T item);
    T pop();
    T peek();
}

public class MyStack<T> implements InnerMyStack<T> {
    private T[] arr;
    private int top = 0;
    private static final int defaultStackSize = 10;

    public MyStack() {
        this(defaultStackSize);
    }

    public MyStack(int stackSize) {
        this.arr = (T[]) new Object[stackSize];
    }

    @Override
    public boolean isEmpty() {
        return this.top == 0;
    }

    @Override
    public boolean isFull() {
        return this.top == this.arr.length;
    }

    @Override
    public void clear() {
        while (this.top >= 0)
            arr[top--] = null;
        this.top = 0;
    }

    @Override
    public void push(T item) {
        if (isFull())
            // prevent stack overflow
            System.out.println("Stack is Full");
        else
            arr[top++] = item;
    }

    @Override
    public T pop() {
        if (isEmpty()) {
            // prevent stack underflow
            System.out.println("Stack is Empty");
            throw new java.util.NoSuchElementException();
        } else {
            T tmp = arr[top];
            arr[top] = null;
            top--;
            return tmp;
        }
    }

    @Override
    public T peek() {
        if (isEmpty()) {
            System.out.println("Stack is Empty");
            throw new java.util.NoSuchElementException();
        } else {
            return arr[top];
        }
    }
}