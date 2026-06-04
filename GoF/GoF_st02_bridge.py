class Implementor:
    def __init__(self):
        raise NotImplementedError("This method should be implemented by subclasses")

    def operation_impl(self):
        raise NotImplementedError("This method should be implemented by subclasses")


class ConcreteImplementorA(Implementor):
    def __init__(self):
        pass

    def operation_impl(self):
        return "ConcreteImplementorA operation"


class ConcreteImplementorB(Implementor):
    def __init__(self):
        pass

    def operation_impl(self):
        return "ConcreteImplementorB operation"


class Abstraction:
    def __init__(self, implementor):
        raise NotImplementedError("This method should be implemented by subclasses")

    def operation(self):
        return self._implementor.operation_impl()


class RefinedAbstraction(Abstraction):
    def __init__(self, implementor):
        self._implementor = implementor

    def operation(self):
        return f"RefinedAbstraction: {self._implementor.operation_impl()}"


if __name__ == "__main__":
    implementor_a = ConcreteImplementorA()
    abstraction_a = RefinedAbstraction(implementor_a)
    print(abstraction_a.operation())

    implementor_b = ConcreteImplementorB()
    abstraction_b = RefinedAbstraction(implementor_b)
    print(abstraction_b.operation())
