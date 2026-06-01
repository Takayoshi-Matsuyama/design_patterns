class Visitor:
    def __init__(self):
        raise NotImplementedError("You should implement this method in subclasses")

    def visit(self, element):
        raise NotImplementedError("You should implement this method in subclasses")


class Element:
    def __init__(self):
        raise NotImplementedError("You should implement this method in subclasses")

    def accept(self, visitor):
        raise NotImplementedError("You should implement this method in subclasses")


class ConcreteVisitor1(Visitor):
    def __init__(self):
        pass

    def visit(self, element):
        print(f"ConcreteVisitor #1: Visiting {element.__class__.__name__}")


class ConcreteVisitor2(Visitor):
    def __init__(self):
        pass

    def visit(self, element):
        print(f"ConcreteVisitor #2: Visiting {element.__class__.__name__}")


class ConcreteElementA(Element):
    def __init__(self):
        pass

    def accept(self, visitor):
        visitor.visit(self)


class ConcreteElementB(Element):
    def __init__(self):
        pass

    def accept(self, visitor):
        visitor.visit(self)


if __name__ == "__main__":
    elements = [ConcreteElementA(), ConcreteElementB()]
    visitor1 = ConcreteVisitor1()
    visitor2 = ConcreteVisitor2()

    for element in elements:
        element.accept(visitor1)
        element.accept(visitor2)
