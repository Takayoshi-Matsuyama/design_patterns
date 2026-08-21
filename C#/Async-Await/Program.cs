// The Original Code is from:
// C# Fundamentals: Learn Modern C# 14 and .NET 10 from the Ground Up
// https://www.unqbd.com/book/csharp-fundamentals-learn-modern-csharp-14-and-net-10-from-the-ground-up

/// <summary>
/// This example demonstrates the use of Tasks in C# to perform asynchronous operations.
/// </summary>
void TryTask()
{
    Console.WriteLine($"Thread {Thread.CurrentThread.ManagedThreadId}: Starting task...");

    Task<int> calculationTask = Task.Run(() =>
    {
        Console.WriteLine($"Thread {Thread.CurrentThread.ManagedThreadId}: Calculating sum of numbers from 1 to 5...");
        int total = 0;
        for (int i = 1; i <= 5; i++)
        {
            total += i;
            Thread.Sleep(500);
        }
        return total;
    });

    Console.WriteLine($"Thread {Thread.CurrentThread.ManagedThreadId}: Working...");

    // Wait for the task thread to complete and get the result.
    int result = calculationTask.Result;

    // This code is executed after the task thread has completed and returned the result.
    Console.WriteLine($"Thread {Thread.CurrentThread.ManagedThreadId}: Result: {result}");
}

async Task TryAsyncAwait()
{
    Console.WriteLine($"Thread {Thread.CurrentThread.ManagedThreadId}: Starting task...");

    Task<int> calculationTask = Task.Run(() =>
    {
        Console.WriteLine($"Thread {Thread.CurrentThread.ManagedThreadId}: Calculating sum of numbers from 1 to 5...");
        int total = 0;
        for (int i = 1; i <= 5; i++)
        {
            total += i;
            Thread.Sleep(500);
        }

        return total;
    });

    Console.WriteLine($"Thread {Thread.CurrentThread.ManagedThreadId}: Working...");

    // Await the task thread to complete and get the result.
    int result = await calculationTask;

    // Note1: Because of "await", the main thread can continue working
    //        while the task is running in the background.

    // Note2: In console applications, there is no SynchronizationContext.
    //        In this case, .NET optimizes performance
    //        by omitting the context switch back to the main thread after the await.

    // Note3: With above optimization, remaining code after "await"
    //        will run on the following either thread:
    //        (A) The thread that completed the task (calculationTask)
    //        (B) A thread that is available in the thread pool

    // Note4: On the other hand, in GUI applications (e.g., WinForms, WPF, MAUI, Blazor),
    //        there is a SynchronizationContext.
    //        In this case, .NET will switch back to the main thread after the await,
    //        so that the remaining code after "await" will run on the main thread.

    Console.WriteLine($"Thread {Thread.CurrentThread.ManagedThreadId}: Result: {result}");
}

// Calls the TryTask method to demonstrate task execution.
// Console output:
// Thread 2: Starting task...
// Thread 2: Working...
// Thread 4: Calculating sum of numbers from 1 to 5...
// Thread 2: Result: 15
Console.WriteLine("=== TryTask ===");
TryTask();

// Calls the TryAsyncAwait method to demonstrate async/await execution.
// Console output:
// Thread 2: Starting task...
// Thread 2: Working...
// Thread 4: Calculating sum of numbers from 1 to 5...
// Thread 4: Result: 15
Console.WriteLine("=== TryAsyncAwait ===");
await TryAsyncAwait();

