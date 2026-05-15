class Target:
    def request(self):
        return "Target: The default target's behavior."


class Adaptee:
    def specific_request(self):
        return "Adaptee: The specific behavior of the adaptee."


class Adapter(Target):
    def __init__(self, adaptee):
        self.adaptee = adaptee

    def request(self):
        return f"Adapter: (TRANSLATED) {self.adaptee.specific_request()}"


if __name__ == "__main__":
    adaptee = Adaptee()
    print("Adaptee:", adaptee.specific_request())

    adapter = Adapter(adaptee)
    print(adapter.request())
