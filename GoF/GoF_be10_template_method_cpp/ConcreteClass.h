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

#ifndef CONCRETE_CLASS_H
#define CONCRETE_CLASS_H

#include "AbstractClass.h"

class ConcreteClass : public AbstractClass {
    public:
        void Primitive_Operation1() override;
        void Primitive_Operation2() override;
};

#endif // CONCRETE_CLASS_H
