using System;

namespace TextEditor
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Menu();
        }

        static void Menu()
        {
            Console.Clear();
            Console.WriteLine("[ Enter the number related to the operation to be performed ]");
            Console.WriteLine("1 - Open file");
            Console.WriteLine("2 - New file");
            Console.WriteLine("0 - Exit");
            Console.WriteLine("");

            short option = short.Parse(Console.ReadLine());

            switch (option)
            {
                case 0: System.Environment.Exit(0); break;
                case 1: Open(); break;
                case 2: Edit(); break;
                default: Menu(); break;
            }
        }

        static void Open()
        {
            Console.Clear();
            Console.WriteLine("[ Enter file path ]");
            string path = Console.ReadLine();

            using (var file = new StreamReader(path))
            {
                string text = file.ReadToEnd();
                Console.WriteLine(text);
            }

            Console.WriteLine("");
            Console.WriteLine("[ Press Enter to return to options menu ]");
            Console.ReadLine();
            Menu();
        }

        static void Edit()
        {
            Console.WriteLine("");
            Console.WriteLine("[ Enter your text below / ESC to exit]");
            Console.WriteLine("");

            string text = "";

            do
            {
                text += Console.ReadLine();
                text += Environment.NewLine;
            }
            while (Console.ReadKey().Key != ConsoleKey.Escape);

            Console.WriteLine("");
            Save(text);
        }

        static void Save(string text)
        {
            Console.Clear();
            Console.WriteLine("[ Enter the path to save the file ]");

            var path = Console.ReadLine();

            using (var file = new StreamWriter(path))
            {
                file.Write(text);
            }

            Console.WriteLine($"[ File saved successfully in {path} ]");

            Console.WriteLine("");
            Console.WriteLine("[ Press Enter to return to options menu ]");
            Console.ReadLine();
            Menu();
        }
    }
}