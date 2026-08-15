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
/// Represents an error event that can be handled by the chain of responsibility.
/// </summary>
/// <param name="Level">The severity level of the error.</param>
/// <param name="Message">The error message.</param>
/// <remarks>
/// Using a record struct for immutability and value semantics (C# 10.0 and later).
/// </remarks>
public readonly record struct ErrorEvent(int Level, string Message);
