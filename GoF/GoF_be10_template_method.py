class AbstractClass:
    def template_method(self):
        self.primitive_operation1()
        self.primitive_operation2()

    def primitive_operation1(self):
        raise NotImplementedError("This method should be implemented by subclasses")

    def primitive_operation2(self):
        raise NotImplementedError("This method should be implemented by subclasses")


class ConcreteClass(AbstractClass):
    def primitive_operation1(self):
        print("ConcreteClass: Implementing primitive_operation1")

    def primitive_operation2(self):
        print("ConcreteClass: Implementing primitive_operation2")


if __name__ == "__main__":
    concrete = ConcreteClass()
    concrete.template_method()
