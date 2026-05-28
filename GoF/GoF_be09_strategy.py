class Strategy:
    def algorithm_interface(self, a, b):
        raise NotImplementedError("This method should be implemented by subclasses")


class ConcreteStrategyA(Strategy):
    def algorithm_interface(self, a, b):
        return a + b


class ConcreteStrategyB(Strategy):
    def algorithm_interface(self, a, b):
        return a - b


class Context:
    def __init__(self, strategy):
        self._strategy = strategy

    def set_strategy(self, strategy):
        self._strategy = strategy

    def execute_strategy(self, a, b):
        return self._strategy.algorithm_interface(a, b)


if __name__ == "__main__":
    context = Context(ConcreteStrategyA())
    result = context.execute_strategy(5, 3)
    print(f"Addition Result: {result}")

    context.set_strategy(ConcreteStrategyB())
    result = context.execute_strategy(5, 3)
    print(f"Subtraction Result: {result}")
