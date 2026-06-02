class Product:
    def __init__(self, name):
        raise NotImplementedError("This method should be implemented by subclasses")

    def operation(self):
        raise NotImplementedError("This method should be implemented by subclasses")


class ConcreteProduct(Product):
    def __init__(self):
        pass

    def operation(self):
        return "Operation of ConcreteProduct"


class Creator:
    def __init__(self):
        raise NotImplementedError("This method should be implemented by subclasses")

    def factory_method(self):
        raise NotImplementedError("This method should be implemented by subclasses")


class ConcreteCreator(Creator):
    def __init__(self):
        pass

    def factory_method(self):
        return ConcreteProduct()


if __name__ == "__main__":
    creator = ConcreteCreator()
    product = creator.factory_method()
    print(product.operation())
