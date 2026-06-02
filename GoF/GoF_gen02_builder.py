class Product:
    def __init__(self, name):
        self.name = name


class Builder:
    def __init__(self):
        raise NotImplementedError("This method should be implemented by subclasses")

    def build_part(self):
        raise NotImplementedError("This method should be implemented by subclasses")

    def get_result(self):
        raise NotImplementedError("This method should be implemented by subclasses")


class ConcreteBuilder(Builder):
    def __init__(self):
        self.product = None

    def build_part(self):
        self.product = Product("Example Product")

    def get_result(self):
        return self.product


class Director:
    def __init__(self, builder):
        self._builder = builder

    def construct(self):
        self._builder.build_part()


if __name__ == "__main__":
    builder = ConcreteBuilder()
    director = Director(builder)
    director.construct()
    product = builder.get_result()
    print(f"Product created: {product.name}")
