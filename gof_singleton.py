class Singleton:
    _instance = None

    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(Singleton, cls).__new__(cls)
        return cls._instance


# Example usage
if __name__ == "__main__":
    s1 = Singleton()
    s2 = Singleton()

    print(s1 is s2)  # Output: True
    print(id(s1), id(s2))  # Output: same id for both instances
    print(s1, s2)  # Output: same instance for both variables
    s1.value = 42
    print(s2.value)  # Output: 42, since s1 and s2 are the same instance
    s2.value = 99
    print(s1.value)  # Output: 99, since s1 and s2 are the same instance
