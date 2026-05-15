class Singleton:
    """Singleton design pattern implementation in Python."""

    # class variable to hold the single instance of the class
    _instance = None

    def __new__(cls):
        """Override __new__ to control the creation of the instance."""
        if cls._instance is None:
            # Create the instance by using the superclass's __new__ method
            # The super class is 'object' in this case, so we call super().__new__(cls)
            cls._instance = super().__new__(cls)
        return cls._instance

    @classmethod
    def get_instance(cls):
        """Get the singleton instance."""
        if cls._instance is None:
            cls._instance = cls()
        return cls._instance


# Example usage
if __name__ == "__main__":
    s1 = Singleton()
    s2 = Singleton()
    s3 = Singleton.get_instance()

    print(f"{id(s1)=}\n{id(s2)=}\n{id(s3)=}")  # Output: same id for all instances
    print(f"{s1=}\n{s2=}\n{s3=}")  # Output: same instance for all variables

    print(f"{s1 is s2=}")  # Output: True
    print(f"{s1 is s3=}")  # Output: True

    s1.value = 42
    print(f"{s2.value=}")  # Output: 42, since s1 and s2 are the same instance
    print(f"{s3.value=}")  # Output: 42, since s1 and s3 are the same instance

    s2.value = 99
    print(f"{s1.value=}")  # Output: 99, since s1 and s2 are the same instance
    print(f"{s3.value=}")  # Output: 99, since s1 and s3 are the same instance
