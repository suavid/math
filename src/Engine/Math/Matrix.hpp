#pragma once

#include <array>
#include <numeric>
#include "Vector.hpp"

namespace Engine::Math
{
    template <typename T, std::size_t M, std::size_t N>
    class MatrixMND
    {
    public:
        using iterator = typename std::array<T, N>::iterator;
        using const_iterator = typename std::array<T, N>::const_iterator;
        using value_type = T;
        static constexpr auto dimension = M * N;
        static constexpr auto rows = M;
        static constexpr auto columns = N;

        MatrixMND() : data(){};

        template <typename... Args>
        MatrixMND(Args... args)
        {
            static_assert(sizeof...(args) == dimension, "Incorrect number of elements provided!");
            initialize(args...);
        };

        T &operator[](std::size_t index)
        {
            return data[index];
        }

        T const &operator[](std::size_t index) const
        {
            return data[index];
        }

        template <std::size_t K>
        auto dot(MatrixMND<T, N, K> const &other) -> MatrixMND<T, M, K>
        {
            auto result = MatrixMND<T, M, K>{};

            for (auto i = 0; i < M; i++)
            {
                for (auto j = 0; j < K; j++)
                {
                    auto acumm = 0.0f;

                    for (auto l = 0; l < N; l++)
                    {
                        acumm += (data[i + i * l] * other[l + l * j]);
                    }

                    result[i + i * j] = acumm;
                }
            }

            return result;
        }

    private:
        VectorND<T, dimension> data;

        template <typename Arg, typename... Args>
        void initialize(Arg first, Args... rest)
        {
            data[dimension - sizeof...(rest) - 1] = first;
            initialize(rest...);
        }

        void initialize() {}
    };
} // namespace Engine::Math