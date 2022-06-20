﻿using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3
{
    class Consistent : Global
    {
        public void method()
        {
            DateTime StartDateTime = DateTime.Now;
            Stopwatch stopWatch = new Stopwatch();
            Console.WriteLine("For Loop Execution start");
            stopWatch.Start();
            for (int i = 0; i < 10; i++)
            {
                long total = DoSomeIndependentTask();
                Console.WriteLine("{0} - {1}", i, total);
            }
            DateTime EndDateTime = DateTime.Now;
            Console.WriteLine("For Loop Execution end ");
            stopWatch.Stop();
            Console.WriteLine($"Time Taken to Execute the For Loop in miliseconds {stopWatch.ElapsedMilliseconds}");

            Console.ReadLine();
        }

        static long DoSomeIndependentTask()
        {
            //Do Some Time Consuming Task here
            //Most Probably some calculation or DB related activity
            long total = 0;
            for (int i = 1; i < 100000000; i++)
            {
                total += i;
            }
            return total;
        }
    }
}
