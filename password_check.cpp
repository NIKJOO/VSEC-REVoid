#include <windows.h>
#include <iostream>
#include <string>
#include <cstring>
int main()
{
    // Password stored in a character array
    const char password[] = "ThisisMyPassword";
    // Get input from the user
    std::string input;
    std::cout << "Enter password: ";
    std::getline(std::cin, input);
    // Dynamically resolve MessageBoxA
    HMODULE user32 = LoadLibraryA("user32.dll");
    if (!user32)
    {
        std::cerr << "Failed to load user32.dll\n";
        return 1;
    }
    using MessageBoxA_t = int (WINAPI*)(
        HWND,
        LPCSTR,
        LPCSTR,
        UINT
    );
    auto MessageBoxA_Dynamic =
        reinterpret_cast<MessageBoxA_t>(
            GetProcAddress(user32, "MessageBoxA")
        );
    if (!MessageBoxA_Dynamic)
    {
        std::cerr << "Failed to resolve MessageBoxA\n";
        FreeLibrary(user32);
        return 1;
    }
    // Compare the input with the password
    if (input.length() == std::strlen(password) &&
        std::memcmp(input.data(), password, std::strlen(password)) == 0)
    {
        MessageBoxA_Dynamic(
            nullptr,
            "Password is correct!",
            "Result",
            MB_OK | MB_ICONINFORMATION
        );
    }
    else
    {
        MessageBoxA_Dynamic(
            nullptr,
            "Password is incorrect!",
            "Result",
            MB_OK | MB_ICONERROR
        );
    }
    FreeLibrary(user32);
    return 0;
}
