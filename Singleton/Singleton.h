#pragma once

// Varian 1
class FileSystem
{
public:
    static FileSystem& instance()
    {
        static FileSystem* s_Instance = new FileSystem();
        return *s_Instance;
    }
private:
    FileSystem() = default;
};

// Varian 2
class Input
{
public:
    Input(const Input&) = delete;
    Input& operator=(const Input&) = delete;
    // Virtual functions without realisation
protected:
    Input() = default;
private:
    static Input* s_Instance;
};

// WindowsInput.h
class WindowsInput : public Input
{
protected:
    // Realisation of virtual functions
};

// WindowsInput.cpp
Input* Input::s_Instance = new WindowsInput();
