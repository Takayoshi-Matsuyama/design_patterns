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

#ifndef DESIGN_PTN_BE07_OBS_CONCRETE_SUBJECT_H_
#define DESIGN_PTN_BE07_OBS_CONCRETE_SUBJECT_H_

#include <algorithm>
#include <string>
#include <vector>

#include "subject.h"

namespace obs_ptn {

class ConcreteSubject : public Subject {
 public:
  // Constructs a ConcreteSubject with an initial empty state.
  ConcreteSubject() : state_("") {};

  // Attaches an observer to the subject.
  // Observers' lifetime is managed outside of this class,
  // so we just refer them through raw pointers without taking ownership.
  void Attach(Observer* observer) override {
    observers_.push_back(observer);
  }

  // Detaches an observer from the subject.
  void Detach(Observer* observer) override {
    observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
  }

  // Notifies all attached observers of a change in the subject's state.
  void Notify() override {
    for (Observer* observer : observers_) {
      if (observer) {
      observer->Update(this);
      }
    }
  }
  
  // Returns the current state of the subject.
  std::string GetState() const override {
    return state_;
  }

  // Sets the state of the subject and notifies observers of the change.
  // Additional methods specific to ConcreteSubject
  void SetState(std::string state) {
    state_ = state;
    Notify();
  };
    
 private:
  // The current state of the subject.
  std::string state_;

  // A list of observers that are attached to the subject.
  std::vector<Observer*> observers_;
};

} // namespace obs_ptn

#endif // DESIGN_PTN_BE07_OBS_CONCRETE_SUBJECT_H_
