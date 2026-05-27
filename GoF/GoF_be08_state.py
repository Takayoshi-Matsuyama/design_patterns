class State:
    def handle(self):
        raise NotImplementedError("This method should be implemented by subclasses")


class ConcreteStateA(State):
    def handle(self):
        print("ConcreteStateA: Handling request in State A.")


class ConcreteStateB(State):
    def handle(self):
        print("ConcreteStateB: Handling request in State B.")


class Context:
    def __init__(self):
        self._state = None

    def set_state(self, state):
        self._state = state

    def request(self):
        if self._state:
            self._state.handle()
        else:
            print("Context: No state set to handle the request.")


if __name__ == "__main__":
    context = Context()

    state_a = ConcreteStateA()
    state_b = ConcreteStateB()

    context.set_state(state_a)
    context.request()

    context.set_state(state_b)
    context.request()
