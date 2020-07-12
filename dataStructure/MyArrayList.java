package dataStructure;

interface InnerMyArrayList<T> {
    boolean isEmpty();
    void clear();
    void add(T item);
    T remove(int idx);
    void grow();
    void shrink();
}

public class MyArrayList<T> implements InnerMyArrayList<T> {
    private T[] arr;
    private static final int DEFAULT_CAPACITY = 10;
    private int capacity;
    private int size;

    public MyArrayList() {
        this(DEFAULT_CAPACITY);
    }

    @SuppressWarnings("unchecked")
    public MyArrayList(int capacity) {
        this.arr = (T[]) new Object[capacity];
        this.capacity = capacity;
        this.size = 0;
    }

    @Override
    public boolean isEmpty() {
        return this.size == 0;
    }

    @Override
    public void clear() {
        while (size > 0) {
            arr[size - 1] = null;
            size--;
        }
    }

    @Override
    @SuppressWarnings("unchecked")
    public void add(T item) {
        if (size == capacity) {
            capacity = capacity << 1;
            T[] newArr = (T[]) new Object[capacity];
            for (int i=0; i<size; i++) {
                newArr[i] = arr[i];
            }
            this.arr = newArr;
        }
        arr[size++] = item;
    }

    @SuppressWarnings("unchecked")
    public void add(int idx, T item) {
        if (idx < 0 || idx > this.capacity-1) {
            throw new java.lang.IndexOutOfBoundsException();
        }

        if (size == capacity) {
            capacity = capacity << 1;
            T[] newArr = (T[]) new Object[capacity];
            for (int i=0; i<size; i++) {
                newArr[i] = arr[i];
            }
            this.arr = newArr;
        }

        for (int i=size; i>=idx; i--) {
            arr[i] = arr[i-1];
        }
        arr[idx] = item;
        size++;
    }

    @Override
    @SuppressWarnings("unchecked")
    public T remove(int idx) {
        if (idx < 0 || idx >= size) {
            throw new java.lang.IndexOutOfBoundsException();
        }

        if (size == (capacity >> 1)) {
            capacity = capacity >> 1;
            T[] newArr = (T[]) new Object[capacity];
            for (int i=0; i<size; i++) {
                newArr[i] = arr[i];
            }
            this.arr = newArr;
        }

        T tmp = arr[idx];
        for (int i=idx; i<size-1; i++) {
            arr[i] = arr[i+1];
        }
        arr[size-1] = null;
        size--;
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

    @Override
    public void grow() {
    }

    @Override
    public void shrink() {
    }

    public boolean contains(Object o) {
        return indexOf(o) >= 0;
    }

    public int indexOf(Object o) {
        if (o == null) {
            for (int idx=0; idx<size; idx++) {
                if (this.arr[idx] == null)
                    return idx;
            }
        } else {
            for (int idx=0; idx<size; idx++ ) {
                if (this.arr[idx].equals(o))
                    return idx;
            }
        }
        return -1;
    }

    public int size() {
        return this.size;
    }

    public Iterator<T> iterator() {
	    return new Iterator<T>();
    }

    private class Iterator<T> {
    }
}
