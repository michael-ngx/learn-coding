using System;

namespace MyApp // Note: actual namespace depends on the project name.
{
    public class Person
    {
        public string Name;

        public void Introduce (string to)
        {
            Console.WriteLine("hi {0}, I'm {1}", to, Name);
        }

        public static Person Construct(string str)
        {
            return new Person { Name = str };
        }
    }
    
    internal class Program
    {
        static void Main(string[] args)
        {
            var person = Person.Construct("Michael");
            person.Introduce("Linh");
        }
    }
}