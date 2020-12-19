# 32ms, 87.09%; 13.1MB, 100.00%
class FizzBuzz:
    def __init__(self, n: int):
        self.n = n + 1
        self.f = threading.Semaphore(0)
        self.b = threading.Semaphore(0)
        self.fb = threading.Semaphore(0)
        self.num = threading.Semaphore(1)
        self.cur = 1

    # printFizz() outputs "fizz"
    def fizz(self, printFizz: callable) -> None:
        for i in range(1, self.n):
            if i % 5 and i % 3 == 0:
                self.f.acquire()
                printFizz()
                self.cur += 1
                if self.cur % 5:
                    self.num.release()
                else:
                    self.b.release()

    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz: callable) -> None:
        for i in range(1, self.n):
            if i % 5 == 0 and i % 3:
                self.b.acquire()
                printBuzz()
                self.cur += 1
                if self.cur % 3:
                    self.num.release()
                else:
                    self.f.release()

    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz: callable) -> None:
        for i in range(1, self.n):
            if i % 5 == 0 and i % 3 == 0:
                self.fb.acquire()
                printFizzBuzz()
                self.cur += 1
                self.num.release()

    # printNumber(x) outputs "x", where x is an integer.
    def number(self, printNumber: callable) -> None:
        for i in range(1, self.n):
            if i % 5 and i % 3:
                self.num.acquire()
                printNumber(i)
                self.cur += 1
                if self.cur % 5 == 0 and self.cur % 3 == 0:
                    self.fb.release()
                elif self.cur % 3 == 0:
                    self.f.release()
                elif self.cur % 5 == 0:
                    self.b.release()
                else:
                    self.num.release()
