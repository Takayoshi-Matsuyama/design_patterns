class Aggregate:
    def create_iterator(self):
        raise NotImplementedError("You should implement this method in subclasses")


class ConcreteAggregate(Aggregate):
    def __init__(self):
        self._items = ["A", "B", "C", "D", "E"]

    def create_iterator(self):
        return ConcreteIterator(self)


class Iterator:
    def first(self):
        raise NotImplementedError("You should implement this method in subclasses")

    def next(self):
        raise NotImplementedError("You should implement this method in subclasses")

    def is_done(self):
        raise NotImplementedError("You should implement this method in subclasses")

    def current_item(self):
        raise NotImplementedError("You should implement this method in subclasses")


class ConcreteIterator(Iterator):
    def __init__(self, aggregate):
        self._aggregate = aggregate
        self._current = 0

    def first(self):
        self._current = 0

    def next(self):
        self._current += 1

    def is_done(self):
        return self._current >= len(self._aggregate._items)

    def current_item(self):
        if not self.is_done():
            return self._aggregate._items[self._current]
        else:
            raise StopIteration


if __name__ == "__main__":
    aggregate = ConcreteAggregate()
    iterator = aggregate.create_iterator()

    print("Iterating over the aggregate:")
    while not iterator.is_done():
        print(iterator.current_item())
        iterator.next()
