class AbstractProductA:
    def __init__(self):
        raise NotImplementedError("This method should be implemented by subclasses")

    def operation_a(self):
        raise NotImplementedError("This method should be implemented by subclasses")


class ProductA1(AbstractProductA):
    def __init__(self):
        pass

    def operation_a(self):
        return "ProductA1 operation"


class ProductA2(AbstractProductA):
    def __init__(self):
        pass

    def operation_a(self):
        return "ProductA2 operation"


class AbstractProductB:
    def __init__(self):
        raise NotImplementedError("This method should be implemented by subclasses")

    def operation_b(self):
        raise NotImplementedError("This method should be implemented by subclasses")


class ProductB1(AbstractProductB):
    def __init__(self):
        pass

    def operation_b(self):
        return "ProductB1 operation"


class ProductB2(AbstractProductB):
    def __init__(self):
        pass

    def operation_b(self):
        return "ProductB2 operation"


class AbstractFactory:
    def __init__(self):
        raise NotImplementedError("This method should be implemented by subclasses")

    def create_product_a(self):
        raise NotImplementedError("This method should be implemented by subclasses")

    def create_product_b(self):
        raise NotImplementedError("This method should be implemented by subclasses")


class ConcreteFactory1(AbstractFactory):
    def __init__(self):
        pass

    def create_product_a(self):
        return ProductA1()

    def create_product_b(self):
        return ProductB1()


class ConcreteFactory2(AbstractFactory):
    def __init__(self):
        pass

    def create_product_a(self):
        return ProductA2()

    def create_product_b(self):
        return ProductB2()


if __name__ == "__main__":
    factory1 = ConcreteFactory1()
    product_a1 = factory1.create_product_a()
    product_b1 = factory1.create_product_b()
    print(product_a1.operation_a())
    print(product_b1.operation_b())

    factory2 = ConcreteFactory2()
    product_a2 = factory2.create_product_a()
    product_b2 = factory2.create_product_b()
    print(product_a2.operation_a())
    print(product_b2.operation_b())
