using System;
using System.Threading;
using System.Threading.Tasks;

namespace Lab3
{
    class Program
    {
        static void Main(string[] args)
        {

            Consistent cons = new Consistent();
            cons.method();
            Parallel par = new Parallel();
            par.method();
        }
    }
}
