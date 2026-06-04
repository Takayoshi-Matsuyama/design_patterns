class Component:
    def __init__(self):
        raise NotImplementedError("This method should be implemented by subclasses")

    def operation(self):
        raise NotImplementedError("This method should be implemented by subclasses")

    def add(self, component):
        raise NotImplementedError("This method should be implemented by subclasses")

    def remove(self, component):
        raise NotImplementedError("This method should be implemented by subclasses")

    def get_child(self, index):
        raise NotImplementedError("This method should be implemented by subclasses")


class Leaf(Component):
    def __init__(self):
        pass

    def operation(self):
        return "Leaf operation"


class Composite(Component):
    def __init__(self):
        self.children = []

    def operation(self):
        results = []
        for child in self.children:
            results.append(child.operation())
        return f"Composite operation: {', '.join(results)}"

    def add(self, component):
        self.children.append(component)

    def remove(self, component):
        self.children.remove(component)

    def get_child(self, index):
        return self.children[index]


if __name__ == "__main__":
    leaf1 = Leaf()
    leaf2 = Leaf()
    composite = Composite()
    composite.add(leaf1)
    composite.add(leaf2)

    print(composite.operation())
