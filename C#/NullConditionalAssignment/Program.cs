// Check if a string is null and assign a default value using an if statement
string? str1 = null; // Nullable reference type
if (str1 == null)
{
    str1 = "default value";
}

// Check if a string is null and assign a default value using the null-coalescing operator (??=)
string? str2 = null;
str2 ??= "default value";
