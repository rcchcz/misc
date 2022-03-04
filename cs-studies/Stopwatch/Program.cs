using System;
using System.Threading;

namespace Stopwatch
{
    class Program
    {
        static void Main(string[] args)
        {
            Menu();
        }

        static void Menu()
        {
            Console.Clear();
            Console.WriteLine("Time in seconds format: 1s");
            Console.WriteLine("Time in minutes format: 1m");
            Console.WriteLine("0 = Exit");
            Console.Write("Enter the amount of time to count and the time unit: ");
            string data = Console.ReadLine().ToLower();
            char type = char.Parse(data.Substring(data.Length - 1, 1));
            int time = int.Parse(data.Substring(0, data.Length - 1));
            Console.WriteLine("");

            int multiplier = 1;

            if (type == 'm')
                multiplier = 60;

            if (time == 0)
                System.Environment.Exit(0);

            PreStart(time * multiplier);

            Console.Clear();

        }

        static void PreStart(int time)
        {
            Console.Clear();
            Console.WriteLine("Ready...");
            Thread.Sleep(1000);
            Console.Clear();
            Console.WriteLine("Set...");
            Thread.Sleep(1000);
            Console.Clear();
            Console.WriteLine("Go!");
            Thread.Sleep(1000);
            Console.Clear();

            Start(time);
        }

        /*
        static void Start(int time)
        {
            int currentTime = 0;

            while (currentTime != time)
            {
                Console.Clear();
                currentTime++;
                Console.WriteLine(currentTime);
                Thread.Sleep(1000);
            }
        }
        */

        static void Start(int time)
        {
            int currentTime = 0; // in seconds
            int min = 0;
            int sec = 0;

            while (currentTime != time)
            {
                Console.Clear();
                currentTime++;

                // formatting
                if (min == 0 && sec < 60)
                {
                    sec++;
                    Console.WriteLine($"{sec}s");
                }
                else if (sec == 60)
                {
                    sec = 0;
                    min++;
                    Console.WriteLine($"{min}m {sec}s");
                }
                else
                {
                    sec++;
                    Console.WriteLine($"{min}m {sec}s");
                }

                Thread.Sleep(1000);
            }
        }
    }
}