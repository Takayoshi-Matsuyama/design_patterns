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
/// Represents the proxy in the Proxy design pattern.
/// </summary>
public class Proxy : ISubject
{
    /// <summary>
    /// The real subject that the proxy delegates requests to.
    /// </summary>
    private Lazy<RealSubject> RealSubject { get; init; }

    /// <summary>
    /// Initializes a new instance of the <see cref="Proxy"/> class.
    /// </summary>
    public Proxy()
    {
        // Initialize the real subject lazily.
        RealSubject = new Lazy<RealSubject>(() => new RealSubject());
    }

    /// <summary>
    /// Requests an action to be performed by the proxy, which delegates to the real subject.
    /// </summary>
    public void Request()
    {
        Console.WriteLine("Proxy: Delegating Request to RealSubject.");

        if (RealSubject.Value.IsReady is false)
        {
            Console.WriteLine("Proxy: RealSubject is not ready yet.");
        }
        else
        {
            RealSubject.Value.Request();
        }   
    }
}
