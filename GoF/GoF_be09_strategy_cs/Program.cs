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

using GoF.Strategy;

Console.WriteLine("GoF Strategy Pattern Example");

var strategyA = new ConcreteStrategyA();
var strategyB = new ConcreteStrategyB();

Context context = new(strategyA);
Console.WriteLine($"Result of strategy A: {context.ExecuteStrategy(10, 5)}");

context.Strategy = strategyB;
Console.WriteLine($"Result of strategy B: {context.ExecuteStrategy(10, 5)}");
