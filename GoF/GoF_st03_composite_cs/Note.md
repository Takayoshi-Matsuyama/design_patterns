# Advanced Topic

## Client Code: Using "is" operator (C# 7.0 or later)
if (component is Composite c) { c.Add(...); }  // Check type and cast simultaneously.

## Transparency vs. Safety
* Prioritize transparency:
  Definfinition of collectional operations like (Add / Remove) are in IComponent.
* Prioritize safety:
  Definfinition of collectional operations like (Add / Remove) are only in the concrete composite class.
