class Prototype:
    def __init__(self):
        raise NotImplementedError("You should implement the clone method.")

    def clone(self):
        raise NotImplementedError("You should implement the clone method.")


class ConcretePrototype1(Prototype):
    def __init__(self):
        pass

    def clone(self):
        return ConcretePrototype1()


class ConcretePrototype2(Prototype):
    def __init__(self):
        pass

    def clone(self):
        return ConcretePrototype2()


if __name__ == "__main__":
    prototype1 = ConcretePrototype1()
    clone1 = prototype1.clone()
    print(f"Cloned object of type: {type(clone1).__name__}")

    prototype2 = ConcretePrototype2()
    clone2 = prototype2.clone()
    print(f"Cloned object of type: {type(clone2).__name__}")
