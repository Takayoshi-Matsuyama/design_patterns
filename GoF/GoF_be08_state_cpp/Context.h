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

#ifndef CONTEXT_H
#define CONTEXT_H

#include "State.h"

class Context {
    public:
        void Request();

        // State lifecycle is managed outside of this class.
        // So we just refer it through the raw pointer.
        void SetState(State* state);
    private:
        State* _state;
};

#endif // CONTEXT_H
