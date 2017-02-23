import java.util.*;

public class Solution {
	public static void show(List<Integer> list) {
		for (Iterator<Integer> it = list.iterator(); it.hasNext(); ) {
			System.out.print(it.next() + " ");
		}
		System.out.println();
	}
	
	public static void main(String[] args) {
		List<Integer> aryList = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5, 6));
		List<Integer> lnkList = new LinkedList<>(Arrays.asList(7, 8, 9, 10, 11, 12));
		show(aryList);
		show(lnkList);
		int index = 0;
		for (ListIterator<Integer> lit = lnkList.listIterator(); lit.hasNext();) {
			aryList.add(index, lit.next());
			index += 2;
		}
		show(aryList);
		index = 0;
		for (ListIterator<Integer> lit = lnkList.listIterator(lnkList.size()); lit.hasPrevious();) {
			aryList.add(index, lit.previous());
			index += 2;
		}
		show(aryList);
	}
}