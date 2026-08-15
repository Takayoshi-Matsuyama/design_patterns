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

// Filescope namespace (C# 10.0 and later)
namespace GoF.ChainOfResponsibility;

/// <summary>
/// Represents a concrete handler in the Chain of Responsibility pattern.
/// </summary>
public class ConcreteHandler1 : IHandler
{
    /// <summary>
    /// The next handler in the chain.
    /// </summary>
    private IHandler? _successor;

    /// <summary>
    /// Initializes a new instance of the <see cref="ConcreteHandler1"/> class with an optional successor.
    /// </summary>
    /// <param name="successor">The next handler in the chain.</param>
    public ConcreteHandler1(IHandler? successor = null)
    {
        _successor = successor;
    }

    /// <summary>
    /// Handles the request represented by the given error event.
    /// </summary>
    /// <param name="errorEvent">The error event to handle.</param>
    public void HandleRequest(ErrorEvent errorEvent)
    {
        Console.WriteLine("ConcreteHandler1: Handling request.");
        if (errorEvent.Level == 1)
        {
            Console.WriteLine($"ConcreteHandler1: Handled " +
                $"Error Level: {errorEvent.Level}, Message: {errorEvent.Message}");
        }
        else if (_successor != null)
        {
            Console.WriteLine("ConcreteHandler1: Passing request to successor.");
            _successor.HandleRequest(errorEvent);
        }
        else
        {
            Console.WriteLine("ConcreteHandler1: No handler available for error: " +
                $"Error Level: {errorEvent.Level}, Message: {errorEvent.Message}");
        }
    }
}
