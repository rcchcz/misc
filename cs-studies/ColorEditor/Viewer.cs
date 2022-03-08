using System;
using System.Text.RegularExpressions;

namespace ColorEditor
{
    public class Viewer
    {
        public static void Show(string text)
        {

            Console.Clear();
            Console.BackgroundColor = ConsoleColor.White;
            Console.ForegroundColor = ConsoleColor.Black;
            Console.WriteLine("[ VIEWING ]");
            Console.WriteLine("");
            Replace(text);
            Console.WriteLine("");
            Console.WriteLine(">>> Press any key to return to menu options");
            Console.ReadKey();
            Menu.Show();
        }

        public static void Replace(string text)
        {
            var red = new Regex(@"<\s*red[^>]*>(.*?)<\s*/\s*red>");
            var green = new Regex(@"<\s*green[^>]*>(.*?)<\s*/\s*green>");
            var blue = new Regex(@"<\s*blue[^>]*>(.*?)<\s*/\s*blue>");

            var words = text.Split(' ');

            for (var i = 0; i < words.Length; i++)
            {
                if (red.IsMatch(words[i]))
                {
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.Write(
                        words[i].Substring(
                            words[i].IndexOf('>') + 1,
                            ((words[i].LastIndexOf('<') - 1) - words[i].IndexOf('>'))
                        )
                    );
                    Console.Write(" ");
                }
                else if (green.IsMatch(words[i]))
                {
                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.Write(
                        words[i].Substring(
                            words[i].IndexOf('>') + 1,
                            ((words[i].LastIndexOf('<') - 1) - words[i].IndexOf('>'))
                        )
                    );
                    Console.Write(" ");
                }
                else if (blue.IsMatch(words[i]))
                {
                    Console.ForegroundColor = ConsoleColor.Blue;
                    Console.Write(
                        words[i].Substring(
                            words[i].IndexOf('>') + 1,
                            ((words[i].LastIndexOf('<') - 1) - words[i].IndexOf('>'))
                        )
                    );
                    Console.Write(" ");
                }
                else
                {
                    Console.ForegroundColor = ConsoleColor.Black;
                    Console.Write(words[i]);
                    Console.Write(" ");
                }
            }
        }
    }
}