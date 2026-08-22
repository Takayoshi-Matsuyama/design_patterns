// Check if a string is null and assign a default value using an if statement
string? str1 = null; // Nullable reference type
if (str1 == null)
{
    str1 = "default value";
}

// Check if a string is null and assign a default value
// using the null-coalescing operator (??=) (C# 14.0 or later)
string? str2 = null;
str2 ??= "default value";
