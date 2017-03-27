import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;

public class Main {
	
	private final static int BUFFER_SIZE = 10;
	private static LinkedList<Object> buffer = new LinkedList<>(); 
	
	public static void main(String[] args) {
		Thread producerA = new Thread(createProducer("producerA"));
		Thread producerB = new Thread(createProducer("producerB"));
		Thread consumerA = new Thread(createConsumer("consumerA"));
		Thread consumerB = new Thread(createConsumer("consumerB"));
		Thread consumerC = new Thread(createConsumer("consumerC"));
		
		producerA.start();
		producerB.start();
		consumerA.start();
		consumerB.start();
		consumerC.start();
	}
	
	private static Producer createProducer(String name) {
		return new Producer(name);
	}
	
	private static Consumer createConsumer(String name) {
		return new Consumer(name);
	}
	
	static class Producer implements Runnable {
		
		private String name;
		private static AtomicInteger i = new AtomicInteger(0);
		
		public Producer(String name) {
			this.name = name;
		}
		
		@Override
		public void run() {
			while (i.getAndIncrement() < BUFFER_SIZE) {
				synchronized (buffer) {
					produce();
					buffer.notifyAll();
				}
				try {
					Thread.sleep(100);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
		
		public void produce() {
			buffer.add(new Object());
			System.out.println(name + " produce object. buffur.size = " + buffer.size());
		}
	}
	
    static class Consumer implements Runnable {
    	private String name;
        public Consumer(String name){
            this.name = name;
        }
        private static AtomicInteger i = new AtomicInteger(0);
        @Override
        public void run() {
            while (i.getAndIncrement() < BUFFER_SIZE) {
                synchronized (buffer) {
                    while (buffer.size() == 0) {
                        try {
                            buffer.wait(50);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                    consumer();
                }
            }
        }
        public void consumer(){
            buffer.removeFirst();
            System.out.println(name + " consume object. buffer.size = " + buffer.size());
        }

    }
	
}