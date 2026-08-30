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

// Filescope namespace (C# 10.0 or later)
namespace GoF.Proxy;

/// <summary>
/// Represents the real subject in the Proxy design pattern.
/// </summary>
public class RealSubject : ISubject
{
    /// <summary>
    /// Gets a value indicating whether the real subject is ready to handle requests.
    /// </summary>
    public bool IsReady { get; private set; } = false;

    /// <summary>
    /// Initializes a new instance of the <see cref="RealSubject"/> class.
    /// </summary>
    /// <remarks>
    /// (1) The real subject may not be ready immediately after instantiation.
    ///     It simulates some initialization work in a separate thread.
    /// (2) Here, the Thread class is used to perform the initialization work asynchronously for simplicity.
    /// (3) In modern GUI applications, consider using Task or async/await for better practice.
    /// (4) Note: In console applications, Task or async/await does not work as expected.
    ///           Because there is no synchronization context in console applications.
    /// </remarks>
    public RealSubject()
    {
        Thread thread = new (() =>
        {
            Console.WriteLine($"RealSubject #W1: Thread ID: {Thread.CurrentThread.ManagedThreadId}");

            // Simulate some initialization work
            Thread.Sleep(1000);
            IsReady = true;

            Console.WriteLine($"RealSubject #W2: Thread ID: {Thread.CurrentThread.ManagedThreadId}");
        });

        thread.Start();
    }

    /// <summary>
    /// Requests an action to be performed by the real subject.
    /// </summary>
    public void Request()
    {
        Console.WriteLine("RealSubject: Handling Request.");
    }
}
