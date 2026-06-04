class Subject:
    def __init__(self):
        raise NotImplementedError("This method should be implemented by subclasses")

    def request(self):
        raise NotImplementedError("This method should be implemented by subclasses")


class RealSubject(Subject):
    def __init__(self):
        pass

    def request(self):
        print("RealSubject: Handling request.")


class Proxy(Subject):
    def __init__(self, real_subject):
        self._real_subject = real_subject

    def request(self):
        print("Proxy: Logging request before forwarding to RealSubject.")
        self._real_subject.request()


if __name__ == "__main__":
    real_subject = RealSubject()
    proxy = Proxy(real_subject)

    proxy.request()
