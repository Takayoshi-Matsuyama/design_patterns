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

#ifndef CONCRETE_PROTOTYPE_2_H
#define CONCRETE_PROTOTYPE_2_H

#include "Prototype.h"
#include <memory>

class ConcretePrototype2 : public Prototype {
    public:
        ConcretePrototype2() {}
        ConcretePrototype2(const ConcretePrototype2& other);
        std::unique_ptr<Prototype> Clone() const override;
        double GetValue() const;
        void SetValue(double value);
    private:
        double _value;
};

#endif // CONCRETE_PROTOTYPE_2_H
