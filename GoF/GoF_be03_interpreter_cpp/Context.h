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

class Context {
    public:
        Context(int value) : _inputValue(value), _outputValue(0) {}
        int GetInput() const { return this->_inputValue; }
        void AddToOutput(int value) { this->_outputValue += value; }
        int GetOutput() const { return this->_outputValue; }
    private:
        int _inputValue;
        int _outputValue;
};

#endif // CONTEXT_H
