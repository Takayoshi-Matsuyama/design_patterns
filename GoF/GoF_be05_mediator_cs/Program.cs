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

using GoF.Mediator;

var mediator = new ConcreteMediator();
var colleague1 = new ConcreteColleague1(mediator);
var colleague2 = new ConcreteColleague2(mediator);

// Register colleagues with the mediator.
// Note: This registration might me done inside the constructor of the ConcreteColleague classes,
//       but it is not good practice, because the creation does not complete.
//       Therefore, the registration is done here after ConcreteColleague objects are completely created.
mediator.RegisterColleague(colleague1);
mediator.RegisterColleague(colleague2);

colleague1.Send("Hello from Colleague 1.");
colleague2.Send("Greetings from Colleague 2.");
