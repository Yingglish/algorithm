package com.stack;

import java.util.Arrays;
import java.util.Iterator;

//TODO:可改用动态数组ArrayList实现

/*
 * 使用数组实现栈
 * 为支持增强for循环需实现Iterable接口
 * */
public class ArrayStack<T> implements Iterable<T> {
    private T[] data;
    private int size; //栈容量
    private int count = 0; //存入栈的元素个数  栈顶元素下标 = count - 1

    ArrayStack(int capacity) {
        data = (T[]) new Object[capacity];
        size = capacity;
    }

    private boolean push(T t) {
        if (count == size) {
            // 当数据不断增加，栈大小达到阈值，此时将栈大小需要扩容到原来的两倍
            resize(size * 2);
        }
        data[count++] = t;
        System.out.println("push :" + t + "  栈内元素:\t" + Arrays.toString(data));
        return true;
    }

    private T pop() {
        if (count == 0) return null;
        T t = data[count - 1]; //栈顶元素下标 = count - 1
        data[count--] = null;
        if (count == size / 4 && size / 2 != 0) {
            resize(size / 2);
        }
        System.out.println("pop :" + t + " 栈内元素:\t" + Arrays.toString(data));
        return t;
    }

    boolean isEmpty() {
        return count == 0;
    }

    int size() {
        return count;
    }

    // 获取栈顶元素
    T peak() {
        if (count == 0) {
            return null;
        }
        T t = data[count - 1];
        System.out.println("peak: " + t + "栈内元素:\t" + Arrays.toString(data));
        return t;
    }

    private void resize(int newSize) {
        T[] newData = (T[]) new Object[newSize];
        for (int i = 0; i < count; i++) {
            newData[i] = data[i];
        }
        size = newData.length;
        System.out.println("调整前: " + data.length);
        data = newData;
        System.out.println("重新调整后: " + data.length);
    }

    public static void main(String[] args) {
        ArrayStack<Integer> data = new ArrayStack<>(4);
        data.push(1);
        data.push(2);
        data.push(3);
        data.push(4);
        data.push(5);
        data.push(6);
        System.out.println("size:\t" + data.size());
        System.out.println("isEmpty:\t" + data.isEmpty());
        for (Integer datum : data) {
            System.out.print(datum + " "); // output 6 5 4 3 2 1
        }
        System.out.println();
        data.pop();
        data.pop();
        data.pop();
        data.pop();
        data.peak();
        data.peak();
        data.peak();
    }

    @Override
    public Iterator<T> iterator() {
        return new ArrayIterator();
    }

    class ArrayIterator implements Iterator<T> {
        int cursor = count;

        @Override
        public boolean hasNext() {
            return cursor > 0;
        }

        @Override
        public T next() {
            return data[--cursor]; //实现栈的先进后出
        }

        @Override
        public void remove() {

        }
    }
}
