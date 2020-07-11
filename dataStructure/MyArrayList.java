package dataStructure;

interface InnerMyArrayList<T> {
    boolean isEmpty();
    void clear();
    void add(T item);
    T remove();
}

public class MyArrayList<T> implements InnerMyArrayList<T> {
    private T[] arr;
    private static final int DEFAULT_CAPACITY = 10;
    private int capacity;
    private int elementCount;

    public MyArrayList() {
        this(DEFAULT_CAPACITY);
    }

    @SuppressWarnings("unchecked")
    public MyArrayList(int capacity) {
        this.arr = (T[]) new Object[capacity];
        this.capacity = capacity;
        this.elementCount = 0;
    }

    @Override
    public boolean isEmpty() {
        return this.elementCount == 0;
    }

    @Override
    public void clear() {
        while (elementCount > 0) {
            arr[elementCount - 1] = null;
            elementCount--;
        }
    }

    @Override
    public void add(T item) {
        if (getSize() == this.capacity)
            capacity = capacity * 2;
        arr[elementCount++] = item;
    }

    @Override
    public T remove() {
        return null;
    }

    public int getSize() {
        return this.elementCount;
    }
}