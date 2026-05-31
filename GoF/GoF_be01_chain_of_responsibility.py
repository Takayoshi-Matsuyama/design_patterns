class Handler:
    def __init__(self, successor=None):
        raise NotImplementedError("You should implement this method in subclasses")

    def handle_request(self):
        raise NotImplementedError("You should implement this method in subclasses")


class ConcreteHandler1(Handler):
    def __init__(self, successor=None):
        self._successor = successor

    def handle_request(self):
        print("ConcreteHandler1: Handling request.")
        if self._successor:
            self._successor.handle_request()


class ConcreteHandler2(Handler):
    def __init__(self, successor=None):
        self._successor = successor

    def handle_request(self):
        print("ConcreteHandler2: Handling request.")
        if self._successor:
            self._successor.handle_request()


if __name__ == "__main__":
    handler1 = ConcreteHandler1()
    handler2 = ConcreteHandler2(handler1)

    handler2.handle_request()
