package dataStructure;

interface InnerMyArrayList<T> {
    boolean isEmpty();
    void clear();
    void add(T item);
    T remove(int idx);
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
    @SuppressWarnings("unchecked")
    public void add(T item) {
        if (getSize() == this.capacity) {
            T[] newArr = (T[]) new Object[capacity << 1];
            for (int i=0; i<elementCount; i++) {
                newArr[i] = arr[i];
            }
            this.arr = newArr;
        }
        arr[elementCount++] = item;
    }

    @SuppressWarnings("unchecked")
    public void add(int idx, T item) {
        if (idx < 0 || idx > this.capacity-1) {
            throw new java.lang.IndexOutOfBoundsException();
        }

        if (getSize() == this.capacity) {
            T[] newArr = (T[]) new Object[capacity << 1];
            for (int i=0; i<elementCount; i++) {
                newArr[i] = arr[i];
            }
            this.arr = newArr;
        }

        for (int i=elementCount; i>=idx; i--) {
            arr[i] = arr[i-1];
        }
        arr[idx] = item;
        elementCount++;
    }

    @Override
    public T remove(int idx) {
        if (idx < 0 || idx >= getSize()) {
            throw new java.lang.IndexOutOfBoundsException();
        }

        T tmp = arr[idx];
        arr[idx] = null;
        for (int i=idx; i<getSize(); i++) {
            arr[i] = arr[i+1];
        }
        elementCount--;
        return tmp;
    }
    public T removeByItem(Object o) {
        if (o == null) {
            throw new java.lang.IllegalStateException();
        } else {
            int idx = indexOf(o);
            if (idx == -1) {
                throw new java.util.NoSuchElementException();
            }
            return remove(idx);
        }
    }

    public int indexOf(Object o) {
        if (o == null) {
            for (int idx=0; idx<elementCount; idx++) {
                if (this.arr[idx] == null)
                    return idx;
            }
        } else {
            for (int idx=0; idx<elementCount; idx++ ) {
                if (this.arr[idx].equals(o))
                    return idx;
            }
        }
        return -1;
    }

    public int getSize() {
        return this.elementCount;
    }
}