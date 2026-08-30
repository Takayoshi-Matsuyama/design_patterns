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

using GoF.Prototype;

Console.WriteLine("GoF Prototype Example");

// Create an original.
var prototype = new ConcretePrototype("A Product")
{
    NestedList =
    [
        ["Item01", "Item02"],
        ["Item11", "Item12"]
    ]
};

// Clone the original.
var clone = prototype.Clone() as ConcretePrototype;

// Display the clone's details.
Console.WriteLine($"Clone Name: {clone?.Name}");
Console.WriteLine($"Clone Nested List: {
    string.Join(
        ", ",
        clone?.NestedList?.Select(innerList => string.Join("-", innerList)) ??
        Array.Empty<string>())}");

// Confirm that the clone is a deep copy.
Console.WriteLine($"Is Clone's name reference same as the original? : " +
                  $"{ReferenceEquals(clone?.Name, prototype.Name)}");
Console.WriteLine($"Is Clone's nested root list reference same as the original? : " +
                  $"{ReferenceEquals(clone?.NestedList, prototype.NestedList)}");
Console.WriteLine($"Is Clone's nested child list reference same as the original? : " +
                  $"{ReferenceEquals(clone?.NestedList[0], prototype.NestedList[0])}");
Console.WriteLine($"Is Clone's list item reference same as the original? : " +
                  $"{ReferenceEquals(clone?.NestedList[0][0], prototype.NestedList[0][0])}");
