// Reference: C# Fundamentals: Learn Modern C# 14 and .NET 10 from the Ground Up
// https://www.unqbd.com/book/csharp-fundamentals-learn-modern-csharp-14-and-net-10-from-the-ground-up

Console.WriteLine("========== Extension Method ==========");

string word = "Hello";
Console.WriteLine($"Is '{word}' longer than 3 characters? {word.IsLongerThan3()}");

Console.WriteLine("========== Extension Property ==========");

DateTime today = DateTime.Today;
Console.WriteLine($"Is {today} Sunday? {today.IsSunday()}");

Console.WriteLine("========== Static Extension Method ==========");
double result = 5.0.MultiplyBy3();
Console.WriteLine($"5.0 multiplied by 3 is {result}.");

public static class StringExtensions
{
    /// <summary>
    /// Extension method to check if a string is longer than 3 characters.
    /// </summary>
    /// <param name="value">The string to check.</param>
    /// <returns>True if the string is longer than 3 characters; otherwise, false.</returns>
    public static bool IsLongerThan3(this string value)
    {
        return !string.IsNullOrEmpty(value) && value.Length > 3;
    }
}

public static class DateTimeExtensions
{
    /// <summary>
    /// Extension property indicating whether the date is Sunday or not.
    /// </summary>
    /// <param name="date">The date to check.</param>
    /// <returns>True if the date is Sunday; otherwise, false.</returns>
    public static bool IsSunday(this DateTime date)
        => date.DayOfWeek == DayOfWeek.Sunday;
}


public static class MathExtensions
{
    /// <summary>
    /// Static extension method to multiply a double value by 3.
    /// </summary>
    /// <param name="value">The double value to multiply.</param>
    /// <returns>The result of multiplying the value by 3.</returns>
    public static double MultiplyBy3(this double value)
        => value * 3;
}
