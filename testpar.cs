using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;

namespace EjemploParalelo
{
    class Program
    {
        static void Main(string[] args)
        {
            var limit = 5_000_000;
            var numbers = Enumerable.Range(0,limit).ToList();

            var watchForParallel = Stopwatch.StartNew();
            var numeroPrimosParallel = ListaNumerosPrimosParallel(numbers);
            watchForParallel.Stop();

            Console.WriteLine($"Bucle Parallel.ForEach | Total numeros primos : {numeroPrimosParallel.Count} | Time Taken : {watchForParallel.ElapsedMilliseconds} ms");
        }

        private static IList<int> ListaNumerosPrimosParallel(IList<int> numbers) 
        {
            var primeNumbers = new ConcurrentBag<int>();

            Parallel.ForEach(numbers, number =>
            {
                if (EsPrimo(number))
                    primeNumbers.Add(number);
            });
            return primeNumbers.ToList();
        }

        private static bool EsPrimo(int number)
        {
            if (number < 2)
                return false;

            for (var divisor = 2; divisor <= Math.Sqrt(number); divisor++)
            {
                if (number % divisor == 0)
                    return false;
            }
            return true;
        }
    }
}