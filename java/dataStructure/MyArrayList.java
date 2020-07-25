package java.dataStructure;

import java.util.Iterator;

interface InnerMyArrayList<T> {
    boolean isEmpty();
    void clear();
    void add(T item);
    T remove(int idx);
}

public class MyArrayList<T> implements InnerMyArrayList<T> {
    private T[] arr;
    private static final int DEFAULT_CAPACITY = 10;
    private final int initialCapacity;
    private int capacity;
    private int size;

    public MyArrayList() {
        this(DEFAULT_CAPACITY);
    }

    @SuppressWarnings("unchecked")
    public MyArrayList(int capacity) {
        this.arr = (T[]) new Object[capacity];
        this.initialCapacity = this.capacity = capacity;
        this.size = 0;
    }

    @Override
    public boolean isEmpty() {
        return this.size == 0;
    }

    @Override
    @SuppressWarnings("unchecked")
    public void clear() {
        // GC helper
        while (size > 0) {
            arr[size - 1] = null;
            size--;
        }
        T[] newArr = (T[]) new Object[initialCapacity];
        this.arr = newArr;
        capacity = initialCapacity;
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
        if (idx < 0 || idx > this.size) {
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

    public boolean contains(Object o) {
        return indexOf(o) >= 0;
    }

    public T elementData(int idx) {
        return this.arr[idx];
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
	    return new MyItr();
    }

    private class MyItr implements Iterator<T> {
        private int cursor;

        public MyItr() {
            this.cursor = 0;
        }

        @Override
        public boolean hasNext() {
            return cursor != size;
        }

        @Override
        public T next() {
            if (cursor >= size) {
                throw new java.util.NoSuchElementException();
            }
            return arr[cursor++];
        }
    }

    public static void main(String[] args) {
        MyArrayList<Integer> arrayList = new MyArrayList<>();
        System.out.println("isEmpty: " + arrayList.isEmpty());      // prints "isEmpty: true"
        System.out.println("arrayList size: " + arrayList.size());  // prints "arrayList size: 0"

        arrayList.add(10);
        arrayList.add(20);
        arrayList.add(30);
        arrayList.add(40);
        arrayList.add(50);
        System.out.println("isEmpty: " + arrayList.isEmpty());      // prints "isEmpty: false"
        System.out.println("arrayList size: " + arrayList.size());  // prints "arrayList size: 5"
        System.out.println(arrayList.elementData(0));   // prints 10
        System.out.println(arrayList.elementData(1));   // prints 20
        System.out.println(arrayList.indexOf(10));      // prints 0
        System.out.println(arrayList.indexOf(100));     // prints -1
        arrayList.add(4, 999);
        Iterator<Integer> iter = arrayList.iterator();
        while (iter.hasNext()) {
            System.out.print(iter.next() + ", ");
        } System.out.println();
        // System.out.println("arrayList size: " + arrayList.size());  // prints "arrayList size: 6"
        // System.out.println(arrayList.elementData(4));  // prints 999
        // System.out.println(arrayList.elementData(5));  // prints 50
        // System.out.println(arrayList.remove(4));
        // System.out.println(arrayList.removeByItem(30));
        // System.out.println("arrayList size: " + arrayList.size());  // prints "arrayList size: 4"
        // arrayList.clear();
        // System.out.println("arrayList size: " + arrayList.size());  // prints "arrayList size: 0"

        // Iterator<Integer> iter = arrayList.iterator();
        // if (iter.hasNext()) {
        //     System.out.println(iter.next());
        // }
        MyArrayList<Integer> arrayList2 = new MyArrayList<>(3);
        System.out.println("isEmpty: " + arrayList2.isEmpty());      // prints "isEmpty: true"
        System.out.println("arrayList size: " + arrayList2.size());  // prints "arrayList size: 0"

        arrayList2.add(0);
        arrayList2.add(1);
        arrayList2.add(2);
        System.out.println("isEmpty: " + arrayList2.isEmpty());      // prints "isEmpty: true"
        System.out.println("arrayList size: " + arrayList2.size());  // prints "arrayList size: 0"
        System.out.println("arrayList capacity: " + arrayList2.capacity);

        Iterator<Integer> iter2 = arrayList2.iterator();
        while (iter2.hasNext()) {
            System.out.print(iter2.next() + ", ");
        } System.out.println();

        arrayList2.add(3);
        System.out.println("arrayList size: " + arrayList2.size());         // prints "arrayList size: 4"
        System.out.println("arrayList capacity: " + arrayList2.capacity);  // prints "arrayList capacity: 6"
        arrayList2.remove(0);
        System.out.println("arrayList size: " + arrayList2.size());         // prints "arrayList size: 3"
        System.out.println("arrayList capacity: " + arrayList2.capacity);  // prints "arrayList capacity: 6"
        arrayList2.remove(1);
        System.out.println("arrayList size: " + arrayList2.size());         // prints "arrayList size: 2"
        System.out.println("arrayList capacity: " + arrayList2.capacity);  // prints "arrayList capacity: 3"
        arrayList2.add(12121);
        System.out.println("arrayList size: " + arrayList2.size());         // prints "arrayList size: 3"
        System.out.println("arrayList capacity: " + arrayList2.capacity);  // prints "arrayList capacity: 3"
        arrayList2.add(1441);
        System.out.println("arrayList size: " + arrayList2.size());         // prints "arrayList size: 4"
        System.out.println("arrayList capacity: " + arrayList2.capacity);  // prints "arrayList capacity: 6"
        arrayList2.clear();
        System.out.println("isEmpty: " + arrayList2.isEmpty());              // prints "isEmpty: true"
        System.out.println("arrayList size: " + arrayList2.size());         // prints "arrayList size: 0"
        System.out.println("arrayList capacity: " + arrayList2.capacity);  // prints "arrayList capacity: 3"
    }
}
