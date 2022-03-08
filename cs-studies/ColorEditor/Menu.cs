using System;

namespace ColorEditor
{
    public static class Menu
    {
        public static void Show()
        {
            Console.Clear();
            Console.BackgroundColor = ConsoleColor.Blue;
            Console.ForegroundColor = ConsoleColor.Black;

            DrawScreen();
            WriteOptions();

            var option = short.Parse(Console.ReadLine());
            HandleMenuOption(option);
        }

        public static void DrawScreen()
        {
            Console.Write("+");
            for (int i = 0; i < 30; i++) { Console.Write("-"); }
            Console.WriteLine("+");

            for (int lines = 0; lines < 10; lines++)
            {
                Console.Write("|");
                for (int i = 0; i < 30; i++) { Console.Write(" "); }
                Console.WriteLine("|");
            }

            Console.Write("+");
            for (int i = 0; i < 30; i++) { Console.Write("-"); }
            Console.WriteLine("+");
        }

        public static void WriteOptions()
        {
            Console.SetCursorPosition(3, 2);
            Console.WriteLine("[ Color Editor ]");
            Console.SetCursorPosition(3, 4);
            Console.WriteLine("Select an option");
            Console.SetCursorPosition(3, 5);
            Console.WriteLine("1 - Write text");
            Console.SetCursorPosition(3, 6);
            Console.WriteLine("0 - Exit");
            Console.SetCursorPosition(3, 7);
            Console.Write("Selected option: ");
        }

        public static void HandleMenuOption(short option)
        {
            switch (option)
            {
                case 1: Editor.Show(); break;
                case 2: Viewer.Show(""); break;
                case 0:
                    {
                        Console.Clear();
                        System.Environment.Exit(0);
                        break;
                    }
                default: Show(); break;
            }
        }

    }
}