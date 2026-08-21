// The Original Code is from:
// C# Fundamentals: Learn Modern C# 14 and .NET 10 from the Ground Up
// https://www.unqbd.com/book/csharp-fundamentals-learn-modern-csharp-14-and-net-10-from-the-ground-up

/// <summary>
/// This example demonstrates the use of Tasks in C# to perform asynchronous operations.
/// </summary>
void TryTask()
{
    Task<int> calculationTask = Task.Run(() =>
    {
        int total = 0;
        for (int i = 1; i <= 5; i++)
        {
            total += i;
            Thread.Sleep(500);
        }
        return total;
    });

    Console.WriteLine("Working...");

    // Wait for the task to complete and get the result
    int result = calculationTask.Result;
    
    Console.WriteLine($"Result: {result}");
}

TryTask();
