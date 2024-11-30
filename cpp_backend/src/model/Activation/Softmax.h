#ifndef SOFTMAX_H
#define SOFTMAX_H

#include <vector>

namespace Activation {

    class Softmax {
    public:
        std::vector<float> activate(const std::vector<float> &input);

        std::vector<float> derivative(const std::vector<float>& output) const;
    };

} // namespace Activation

#endif // SOFTMAX_H
