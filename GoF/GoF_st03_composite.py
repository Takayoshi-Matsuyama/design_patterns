class Component:
    def operation(self):
        pass

    def add(self, component):
        pass

    def remove(self, component):
        pass

    def get_child(self, index):
        pass


class Leaf(Component):
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
