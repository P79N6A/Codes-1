public class Program {
   public static void main(String args[]) {
	   String a = "1101";
	   String b = "10T";
	   char [] ac = a.toCharArray();
	   char [] bc = b.toCharArray();
	   int la = ac.length, lb = bc.length;
	   int up = 0;
	   for (int i = 0; i < lb; ++i) {
		   char cura = ac[la - i - 1], curb = bc[lb - i - 1];
		   if (cura == 'T') cura = '2';
		   if (curb == 'T') curb = '2';
		   int sum = cura - '0' + curb - '0' + up;
		   up = sum / 3;
		   int lef = sum % 3;
		   ac[la - i - 1] = (char)(lef + '0');
		   if (lef == 2) ac[la - i - 1] = 'T';
	   }
	   System.out.println(ac);
       return;
   }
}