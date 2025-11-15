package offl.leetcodes;

import java.util.concurrent.*;


class Foo {

    Semaphore sm2;
    Semaphore sm3;
    public Foo() {
        sm2 = new Semaphore(0);
        sm3 = new Semaphore(0);
    }

    public void first(Runnable printFirst) throws InterruptedException {

        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        sm2.release();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        sm2.acquire();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        sm3.release();
    }

    public void third(Runnable printThird) throws InterruptedException {
        sm3.acquire();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}

public class leet_PrintInOrder {

    public static void main(String[] args){
        Foo foo = new Foo();
    }
}
