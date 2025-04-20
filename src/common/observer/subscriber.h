#pragma once

namespace Common {
    class Subscriber {
    public:
        virtual ~Subscriber() = default;

        virtual void Notify() = 0;
    };
}
