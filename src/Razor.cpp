#include "Razor.h"

#include <iostream>
#include <vector>
#include <math.h>
#include <random>
#include <functional>

#include "Engine/Math/Vector.hpp"
#include "Engine/Math/Matrix.hpp"

int main(int argc, char **arc)
{
    Engine::Math::MatrixMND<float, 2, 3> matrix23d_a{1.0f, 2.0f, 3.0f, 3.0f, 2.0f, 1.0f};
    Engine::Math::MatrixMND<float, 3, 2> matrix32d_a{0.0f, 2.0f, 1.0f, -1.0f, 0.0f, 1.0f};

    auto result = matrix23d_a.dot(matrix32d_a);

    for (auto i = 0; i < result.rows; i++)
    {
        for (auto j = 0; j < result.columns; j++)
        {
            std::cout << result[i + i*j] << "\t";
        }

        std::cout << "\n";
    }

    return 0;
}