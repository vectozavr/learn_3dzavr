//
// Created by Иван Ильин on 29.01.2021.
//

#ifndef ENGINE_ASCALE_H
#define ENGINE_ASCALE_H

#include "Animation.h"
#include "../Object.h"

class AScale final : public Animation {
private:
    const std::weak_ptr<Object> _object;
    const Vec3D _scalingValue;

    void update() override {
        auto obj = _object.lock();

        if (obj == nullptr) {
            stop();
            return;
        }

        // TODO: implement (lessons 8)
    }

public:
    AScale(std::weak_ptr<Object> object, const Vec3D &s, double duration = 1, LoopOut looped = LoopOut::None,
           InterpolationType interpolationType = InterpolationType::Bezier) : Animation(duration, looped,
                                                                                        interpolationType),
                                                                              _object(object), _scalingValue(s) {
    }
};

#endif //INC_3DZAVR_ASCALE_H
