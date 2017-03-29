
import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution {
    
    int cnt = 0;
    PriorityQueue<Integer> minHeap = new PriorityQueue<>();
    PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>(11, new Comparator<Integer>() {
        @Override
        public int compare(Integer a, Integer b) {
            return b - a;
        }
    });
    
    public void Insert(Integer num) {
        if ((++cnt & 1) == 1) {
            if (!minHeap.isEmpty() && num > minHeap.peek()) {
                minHeap.offer(num);
                num = minHeap.poll();
            }
            maxHeap.offer(num);
        }
        else {
            if (!maxHeap.isEmpty() && num < maxHeap.peek()) {
                maxHeap.offer(num);
                num = maxHeap.poll();
            }
            minHeap.offer(num);
        }
    }

    public Double GetMedian() {
        if (cnt == 0) throw new RuntimeException("the array is empty");
        if ((cnt & 1) == 1) return (double)maxHeap.peek();
        else return (double)(maxHeap.peek() + minHeap.peek()) / 2.0;
    }
}