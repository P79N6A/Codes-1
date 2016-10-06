using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpPractice
{
    class Presents
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int []a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int[] b = new int[105];
            for (int i = 0; i < n; ++i)
            {
                b[a[i]] = i + 1;
            }
            for (int i = 1; i <= n; ++i)
            {
                Console.Write("{0} ", b[i]);
            }
        }
    }
}
