class Component:
    def __init__(self):
        raise NotImplementedError("This method should be implemented by subclasses")

    def operation(self):
        raise NotImplementedError("This method should be implemented by subclasses")


class ConcreteComponent(Component):
    def __init__(self):
        pass

    def operation(self):
        return "ConcreteComponent operation"


class Decorator(Component):
    def __init__(self, component):
        raise NotImplementedError("This method should be implemented by subclasses")

    def operation(self):
        raise NotImplementedError("This method should be implemented by subclasses")


class ConcreteDecoratorA(Decorator):
    def __init__(self, component):
        self._component = component
        self.added_state = "Added state in ConcreteDecoratorA"

    def operation(self):
        return f"ConcreteDecoratorA({self._component.operation()})"


class ConcreteDecoratorB(Decorator):
    def __init__(self, component):
        self._component = component

    def operation(self):
        return f"ConcreteDecoratorB({self._component.operation()})"

    def added_behavior(self):
        return "Added behavior in ConcreteDecoratorB"


if __name__ == "__main__":
    component = ConcreteComponent()
    print("Original component operation:")
    print(component.operation())

    decorator_a = ConcreteDecoratorA(component)
    print("\nAfter applying ConcreteDecoratorA:")
    print(decorator_a.operation())

    decorator_b = ConcreteDecoratorB(decorator_a)
    print("\nAfter applying ConcreteDecoratorB on top of ConcreteDecoratorA:")
    print(decorator_b.operation())
    print(decorator_b.added_behavior())
