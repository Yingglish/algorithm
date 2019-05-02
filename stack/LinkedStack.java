package com.stack;

import java.util.Iterator;

/**
 * 使用链表实现栈
 */

class Node<T> {
    T element;
    Node<T> next;

    public Node(T element) {
        this.element = element;
        this.next = null;
    }

    /**
     * 创建一个新的节点 使新节点的next指向参数中的节点
     */
    public Node(T element, Node n) {
        this.element = element;
        this.next = n;
    }

    public T getElement() {
        return this.element;
    }
    //TODO : 也可使用增强for循环实现遍历
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        Node<T> temp = this;
        while (temp != null){
            T t = temp.getElement();
            sb.append(t).append(" ");
            temp = temp.next;
        }
        sb.append("\n");
        return sb.toString();
    }
}

public class LinkedStack<T> implements Iterable<T> {
    Node<T> head = null; //栈顶元素
    int count = 0;

    void push(T t) {
//
//        Node<T> node = new Node(t);
//        if(head == null){
//            head = node;
//        }else{
//            node.next = head;
//            head = node;
//        }
        head = new Node(t, head);
        count++;
        System.out.println("push:\t" + t + " data:\t" + head.toString());
    }

    T pop() {
        if (head == null) {
            return null;
        }
        T t = head.getElement();
        head = head.next; // 上一个节点
        if (head != null) {
            System.out.println("pop:\t" + t + "  栈内剩余元素:\t" + head.toString());
        } else {
            System.out.println("pop:\t" + t + "  栈内剩余元素:\tnull");
        }
        count--;
        return t;
    }

    boolean isEmpty() {
        return count == 0;
    }

    int size() {
        return count;
    }

    T peak() {
        if (head == null) {
            return null;
        }
        T t = head.element;
        System.out.println("peek:\t" + t + "  data:\t" + head.toString());
        return t;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        while(this.head != null) {
            T t = this.head.getElement();
            head = head.next;
            sb.append(t).append(" ");
        }
        sb.append("\n");
        return sb.toString();
    }

    void clear() {
        head = null;
        count = 0;
    }

    public static void main(String[] args) {
        LinkedStack<Integer> stack = new LinkedStack();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        System.out.println("size:\t" + stack.size());
        System.out.println("isEmpty:\t" + stack.isEmpty());
        for (Integer integer : stack) {
            System.out.print(integer + "\t");
        }
        System.out.println();
        System.out.println(stack.toString());
        stack.peak();
        stack.peak();
        stack.peak();
        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();
    }

    @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            Node<T> first = head; //指向指向栈顶元素
            int cursor = count;

            @Override
            public boolean hasNext() {
                return cursor > 0;
            }

            @Override
            public T next() {
                T t = first.getElement();
                first = first.next;
                cursor--;
                return t;
            }

            @Override
            public void remove() {

            }
        };
    }
}
