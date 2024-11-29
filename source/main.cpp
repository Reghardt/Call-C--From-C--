#include <iostream>
#include <dlfcn.h>

// type defintion for function as in C#
typedef int (*AddNumbersFunc)(int, int);

// load shared library compiled from C# source. Can contain many functions
void *loadSharedLib()
{
    void *handle = dlopen("../bin/Release/net8.0/linux-x64/publish/ConsoleApp1.so", RTLD_LAZY);
    if (!handle)
    {
        throw std::runtime_error("Failed to load library: " + std::string(dlerror()));
    }
    return handle;
}

int main()
{
    void *handle = loadSharedLib();

    // Get the function from the library
    AddNumbersFunc AddNumbers = (AddNumbersFunc)dlsym(handle, "AddNumbers");
    if (!AddNumbers)
    {
        throw std::runtime_error("Failed to load function: " + std::string(dlerror()));
    }

    // Call the function
    std::cout << "Result: " << AddNumbers(1, 20) << std::endl;

    // Close the library
    // seg faults on close, let OS clean up for now, probably something wrong with C# config, test with .so file generated from c++ or another lang to explore error possibilities
    // std::cout << dlclose(handle) << std::endl;
    return 0;
}
