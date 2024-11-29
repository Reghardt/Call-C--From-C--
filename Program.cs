namespace ConsoleApp1;
using System.Runtime.InteropServices;


class Program
{
    [UnmanagedCallersOnly(EntryPoint = "AddNumbers")]
    public static int AddNumbers(int a, int b)
    {
        return a + b;
    }
}
