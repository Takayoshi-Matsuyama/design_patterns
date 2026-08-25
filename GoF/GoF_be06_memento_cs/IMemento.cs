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
namespace GoF.Memento;

/// <summary>
/// Represents the IMemento interface for Memento design pattern.
/// </summary>
/// <remarks>
/// This interface is for hiding the Memento implementation inside the Originator class,
/// allowing the Caretaker class to manage mementos without knowing their internal structure.
/// Therefore, this interface is intentionally left empty.
/// </remarks>
public interface IMemento {}
