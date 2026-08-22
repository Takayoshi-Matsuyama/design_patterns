// Reference: C# Fundamentals: Learn Modern C# 14 and .NET 10 from the Ground Up
// https://www.unqbd.com/book/csharp-fundamentals-learn-modern-csharp-14-and-net-10-from-the-ground-up

Console.WriteLine("========== Parallel.For ==========");
Parallel.For(0, 5, i =>
{
    Console.WriteLine($"Iteration {i} on thread {Thread.CurrentThread.ManagedThreadId}");
});

Console.WriteLine("========== Parallel.ForEach ==========");
string[] items = { "apple", "banana", "cherry", "date", "elderberry" };
Parallel.ForEach(items, item =>
{
    Console.WriteLine($"Processing {item} on thread {Thread.CurrentThread.ManagedThreadId}");
});

Console.WriteLine("========== Parallel LINQ (PLINQ) ==========");
var numbers = Enumerable.Range(1, 20);
var squares = numbers
    .AsParallel()
    .Select(n => n * n)
    .ToArray();
Console.WriteLine(string.Join(", ", squares));

Console.WriteLine("========== Parallel Options ==========");
ParallelOptions options = new ParallelOptions { MaxDegreeOfParallelism = 2 };
Parallel.For(0, 5, options, i =>
{
    Console.WriteLine($"Running {i} on thread {Thread.CurrentThread.ManagedThreadId}");
});

Console.WriteLine("========== Performance Measurement ==========");
var watch = System.Diagnostics.Stopwatch.StartNew();
// for (int i = 0; i < 1000000; i++)
// {
//     // Simulate some work
//     var result = Math.Sqrt(i);
// }
Parallel.For(0, 1000000, i =>
{
    // Simulate some works
    var result = Math.Sqrt(i);
});
watch.Stop();
Console.WriteLine($"Elapsed time: {watch.ElapsedMilliseconds} ms");
