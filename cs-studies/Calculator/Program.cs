using System;

namespace MyApp // Note: actual namespace depends on the project name.
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Menu();
        }

        static void Menu()
        {
            Console.WriteLine("Enter the number related to the operation to be performed:");
            Console.WriteLine("1 - Addition");
            Console.WriteLine("2 - Subtraction");
            Console.WriteLine("3 - Multiplication");
            Console.WriteLine("4 - Division");
            Console.WriteLine("5 - Exit calculator");
            Console.WriteLine("");

            short op = short.Parse(Console.ReadLine());

            switch (op)
            {
                case 1: Add(); break;
                case 2: Sub(); break;
                case 3: Mult(); break;
                case 4: Div(); break;
                case 5: System.Environment.Exit(0); break;
                default: Menu(); break;
            }

        }

        static void Add()
        {
            //Console.Clear();
            Console.Write("Enter first value: ");
            float v1 = float.Parse(Console.ReadLine());
            Console.Write("Enter second value: ");
            float v2 = float.Parse(Console.ReadLine());

            Console.WriteLine($"{v1} + {v2} = {v1 + v2}");

            Console.WriteLine("");
            Menu();
        }

        static void Sub()
        {
            //Console.Clear();
            Console.Write("Enter first value: ");
            float v1 = float.Parse(Console.ReadLine());
            Console.Write("Enter second value: ");
            float v2 = float.Parse(Console.ReadLine());

            Console.WriteLine($"{v1} - {v2} = {v1 - v2}");

            Console.WriteLine("");
            Menu();
        }

        static void Mult()
        {
            //Console.Clear();
            Console.Write("Enter first value: ");
            float v1 = float.Parse(Console.ReadLine());
            Console.Write("Enter second value: ");
            float v2 = float.Parse(Console.ReadLine());

            Console.WriteLine($"{v1} * {v2} = {v1 * v2}");

            Console.WriteLine("");
            Menu();
        }

        static void Div()
        {
            //Console.Clear();
            Console.Write("Enter first value: ");
            float v1 = float.Parse(Console.ReadLine());
            Console.Write("Enter second value: ");
            float v2 = float.Parse(Console.ReadLine());

            Console.WriteLine($"{v1} / {v2} = {v1 / v2}");

            Console.WriteLine("");
            Menu();
        }

    }
}