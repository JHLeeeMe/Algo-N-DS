package java.dataStructure;

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
    private int top = -1;
    private static final int DEFAULT_STACK_SIZE = 10;
    private int size;

    public MyStack() {
        this(DEFAULT_STACK_SIZE);
    }

    @SuppressWarnings("unchecked")
    public MyStack(int stackSize) {
        if (stackSize <= 0) {
            System.err.println("Stack size must be greater than 0.");
        }
        this.arr = (T[]) new Object[stackSize];
        this.size = stackSize;
    }

    @Override
    public boolean isEmpty() {
        return this.top == -1;
    }

    @Override
    public boolean isFull() {
        return this.top == this.arr.length - 1;
    }

    @Override
    public void clear() {
        while (this.top != -1)
            arr[top--] = null;
    }

    @Override
    public void push(T item) {
        if (isFull())
            // prevent stack overflow
            System.out.println("Stack is Full");
        else
            arr[++top] = item;
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

    public int getSize() { 
        return this.size; 
    }

    public static void main(String[] args) {
        MyStack<Integer> myStack = new MyStack<>();
        System.out.println(myStack.isEmpty());
        System.out.println(myStack.isFull());
        System.out.println("====================================");
        myStack.push(0);
        System.out.println(myStack.isEmpty());
        System.out.println(myStack.isFull());
        System.out.println("====================================");
        myStack.push(1);
        myStack.push(2);
        myStack.push(3);
        myStack.push(4);
        myStack.push(5);
        myStack.push(6);
        myStack.push(7);
        myStack.push(8);
        myStack.push(9);
        System.out.println(myStack.isEmpty());
        System.out.println(myStack.isFull());
        System.out.println("====================================");

        System.out.println(myStack.peek());
        System.out.println(myStack.peek());
        System.out.println("====================================");
        System.out.println(myStack.isEmpty());
        System.out.println(myStack.isFull());
        System.out.println(myStack.getSize());
        myStack.push(1111);
        System.out.println(myStack.pop());
        System.out.println(myStack.pop());
        System.out.println(myStack.pop());
        myStack.clear();
        System.out.println("====================================");
        System.out.println(myStack.isEmpty());
        System.out.println(myStack.isFull());
        System.out.println(myStack.getSize());

        new MyStack<>(-1);  // java.lang.NegativeArraySizeException
    }
}