class Context:
    def __init__(self, input):
        self.input = input
        self.output = 0


class AbstractExpression:
    def interpret(self, context):
        raise NotImplementedError("You should implement this method in subclasses")


class TerminalExpression(AbstractExpression):
    def interpret(self, context):
        context.output += int(context.input)


class NonTerminalExpression(AbstractExpression):
    def __init__(self, expression1, expression2):
        self.expression1 = expression1
        self.expression2 = expression2

    def interpret(self, context):
        self.expression1.interpret(context)
        self.expression2.interpret(context)


if __name__ == "__main__":
    context = Context("5")
    terminal_expression = TerminalExpression()
    terminal_expression.interpret(context)
    print(f"Terminal Expression Output: {context.output}")

    context2 = Context("10")
    non_terminal_expression = NonTerminalExpression(
        terminal_expression, terminal_expression
    )
    non_terminal_expression.interpret(context2)
    print(f"Non-Terminal Expression Output: {context2.output}")
