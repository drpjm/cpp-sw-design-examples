#ifndef OBSERVER_HPP
#define OBSERVER_HPP

namespace obsv {

template<typename Message>
class PushObserver {

    public:
        ~PushObserver() = default;
        virtual void update(Message const& msg) = 0;

};

}

#endif  // OBSERVER_HPP