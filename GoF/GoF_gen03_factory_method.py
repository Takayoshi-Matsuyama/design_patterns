class Product:
    def operation(self):
        pass


class ConcreteProduct(Product):
    def operation(self):
        return "Operation of ConcreteProduct"


class Creator:
    def factory_method(self):
        pass


class ConcreteCreator(Creator):
    def factory_method(self):
        return ConcreteProduct()


if __name__ == "__main__":
    creator = ConcreteCreator()
    product = creator.factory_method()
    print(product.operation())
