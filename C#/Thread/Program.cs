// Copyright 2026 Takayoshi Matsuyama
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/// <summary>
/// Simple Threading Example: Demonstrates creating and running a worker thread alongside the main thread.
/// </summary>
/// <remarks>
/// Output example:
///     [05:47:14.093] Main #1 Thread ID: 2
///     [05:47:14.114] Main #2 Thread ID: 2     // Main thread continues executing while the worker thread runs concurrently.
///     [05:47:14.115] Worker #W1 Thread ID: 4  // Worker thread starts executing concurrently with the main thread.
///     [05:47:15.122] Worker #W2 Thread ID: 4
///     [05:47:16.124] Worker #W3 Thread ID: 4  // End of worker thread execution.
///     [05:47:16.124] Main #3 Thread ID: 2     // Main thread resumes after the worker thread has completed.
/// </remarks>

Console.WriteLine($"[{DateTime.Now:HH:mm:ss.fff}] Main #1 Thread ID: {System.Threading.Thread.CurrentThread.ManagedThreadId}");

Thread thread = new(() =>
{
    Console.WriteLine($"[{DateTime.Now:HH:mm:ss.fff}] Worker #W1 Thread ID: {System.Threading.Thread.CurrentThread.ManagedThreadId}");
    Thread.Sleep(1000); // Simulate some work in the worker thread
    Console.WriteLine($"[{DateTime.Now:HH:mm:ss.fff}] Worker #W2 Thread ID: {System.Threading.Thread.CurrentThread.ManagedThreadId}");
    Thread.Sleep(1000); // Simulate some work in the worker thread
    Console.WriteLine($"[{DateTime.Now:HH:mm:ss.fff}] Worker #W3 Thread ID: {System.Threading.Thread.CurrentThread.ManagedThreadId}");
});
thread.Start();

Console.WriteLine($"[{DateTime.Now:HH:mm:ss.fff}] Main #2 Thread ID: {System.Threading.Thread.CurrentThread.ManagedThreadId}");

// Wait for the worker thread to complete before exiting the main thread.
thread.Join();

Console.WriteLine($"[{DateTime.Now:HH:mm:ss.fff}] Main #3 Thread ID: {System.Threading.Thread.CurrentThread.ManagedThreadId}");
