package com.advance;

/**
 * @Author: 谷天乐
 * @Date: 2020/3/24 10:58
 * @Description:
 */
public class Node<T> {
    public T data;
    // Cursor,if the value is equal to zero,it means pointless.
    public int cur;

    public Node(T data, int cur) {
        this.data = data;
        this.cur = cur;
    }
}