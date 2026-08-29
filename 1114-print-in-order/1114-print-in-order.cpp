class Foo {
    binary_semaphore s2{0}, s3{0};

public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        printFirst();
        s2.release();
    }

    void second(function<void()> printSecond) {
        s2.acquire();
        printSecond();
        s3.release();
    }

    void third(function<void()> printThird) {
        s3.acquire();
        printThird();
    }
};