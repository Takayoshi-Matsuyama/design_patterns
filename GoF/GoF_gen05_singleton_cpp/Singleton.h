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

#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton {
    public:
        static Singleton& GetInstance() {
            static Singleton instance; // Guaranteed to be destroyed and instantiated on first use.
            return instance;
        }

    private:
        Singleton() {} // Private constructor
        ~Singleton() {} // Private destructor
        Singleton(const Singleton&) = delete; // Prevent copy-construction
        Singleton& operator=(const Singleton&) = delete; // Prevent assignment
};

#endif // SINGLETON_H
