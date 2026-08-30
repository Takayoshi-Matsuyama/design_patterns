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

using GoF.Flyweight;

Console.WriteLine("GoF Flyweight Example");

var factory = new FlyweightFactory();
var flyweight1 = factory.GetFlyweight(1);
var flyweight2a = factory.GetFlyweight(2);
var flyweight2b = factory.GetFlyweight(2); 
var unsharedFlyweight = factory.GetUnsharedFlyweight();

flyweight1.ExecuteOperation(10);
flyweight2a.ExecuteOperation(20);
flyweight2b.ExecuteOperation(30);
unsharedFlyweight.ExecuteOperation(40);

Console.WriteLine($"Flyweight1: {flyweight1}");
Console.WriteLine($"Flyweight2a: {flyweight2a}");
Console.WriteLine($"Flyweight2b: {flyweight2b}");
Console.WriteLine($"UnsharedFlyweight: {unsharedFlyweight}");
