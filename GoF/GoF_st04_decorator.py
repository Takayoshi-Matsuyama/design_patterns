class Component:
    def operation(self):
        pass


class ConcreteComponent(Component):
    def operation(self):
        return "ConcreteComponent operation"


class Decorator(Component):
    def __init__(self, component):
        self._component = component

    def operation(self):
        return self._component.operation()


class ConcreteDecoratorA(Decorator):
    def __init__(self, component):
        super().__init__(component)
        self.added_state = "Added state in ConcreteDecoratorA"

    def operation(self):
        return f"ConcreteDecoratorA({super().operation()})"


class ConcreteDecoratorB(Decorator):
    def operation(self):
        return f"ConcreteDecoratorB({super().operation()})"

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
