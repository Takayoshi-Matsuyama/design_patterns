# Advanced Topic

## 1. NonTerminalExpression Alternative

// C# 12 features fully leveraged
public class NonTerminalExpression(
    IAbstractExpression expression1,
    IAbstractExpression expression2) : IAbstractExpression
{
    // No need to declare the fields.
    
    public void Interpret(Context context)
    {
        // The arguments can be used directly.
        expression1.Interpret(context);
        expression2.Interpret(context);
    }
}

## 2. Expression Trees

Expression Trees (System.Linq.Expressions) can be used as an interpreter.
