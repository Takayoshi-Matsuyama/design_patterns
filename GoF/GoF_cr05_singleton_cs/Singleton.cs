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
namespace GoF.Singleton;

/// <summary>
/// Represents the Singleton design pattern,
/// ensuring a class has only one instance and providing a global point of access to it.
/// </summary>
/// <remarks>
/// This class is marked as sealed to prevent inheritance,
/// ensuring that only one instance can exist.
/// </remarks>
public sealed class Singleton
{
    /// <summary>
    /// Gets the single instance of the Singleton class.
    /// </summary>
    /// <remarks>
    /// This static readonly field ensures thread safety and lazy initialization.
    /// </remarks>
    private static readonly Singleton _instance = new();

    /// <summary>
    /// Initializes a new instance of the Singleton class.
    /// </summary>
    /// <remarks>
    /// The private constructor ensures that the object is not instantiated from outside.
    /// </remarks>
    private Singleton() { }

    /// <summary>
    /// Gets the single instance of the Singleton class.
    /// </summary>
    public static Singleton Instance => _instance;
}
