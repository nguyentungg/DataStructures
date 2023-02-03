using System;
using System.Threading;

class Program {
    static int data = 0;
    static readonly object dataLock = new object();

    static void worker1() {
        for (int i = 0; i < 10; ++i) {
            lock (dataLock) {
                data += 1;
                Console.WriteLine("worker1: data = " + data);
            }
        }
    }

    static void worker2() {
        for (int i = 0; i < 10; ++i) {
            lock (dataLock) {
                data += 1;
                Console.WriteLine("worker2: data = " + data);
            }
        }
    }

    static void Main(string[] args) {
        Thread t1 = new Thread(worker1);
        Thread t2 = new Thread(worker2);
        t1.Start();
        t2.Start();
        t1.Join();
        t2.Join();
    }
}
