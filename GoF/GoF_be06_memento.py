class Memento:
    def __init__(self, state):
        self._state = state

    def get_state(self):
        return self._state

    def set_state(self, state):
        self._state = state


class Originator:
    def __init__(self):
        self._state = None

    def set_state(self, state):
        self._state = state

    def get_state(self):
        return self._state

    def create_memento(self):
        return Memento(self._state)

    def set_memento(self, memento):
        self._state = memento.get_state()


class Caretaker:
    def __init__(self):
        self._mementos = []

    def add_memento(self, memento):
        self._mementos.append(memento)

    def get_memento(self, index):
        return self._mementos[index]


if __name__ == "__main__":
    originator = Originator()
    caretaker = Caretaker()

    originator.set_state("State 1")
    caretaker.add_memento(originator.create_memento())

    originator.set_state("State 2")
    caretaker.add_memento(originator.create_memento())

    originator.set_state("State 3")
    caretaker.add_memento(originator.create_memento())

    print(f"Current State: {originator.get_state()}")

    originator.set_memento(caretaker.get_memento(0))
    print(f"Restored State: {originator.get_state()}")

    originator.set_memento(caretaker.get_memento(1))
    print(f"Restored State: {originator.get_state()}")

    originator.set_memento(caretaker.get_memento(2))
    print(f"Restored State: {originator.get_state()}")
