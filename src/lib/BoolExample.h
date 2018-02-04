#pragma once

class BoolExample
{
public:
    explicit BoolExample() = default;

    bool AlwaysTrue()
    {
        return true;
    }
    
    bool AlwaysFalse()
    {
        return false;
    }
};
