#pragma once

#include <array>
#include <numeric>

namespace Engine::Math
{
    template <typename T, std::size_t N>
    class VectorND
    {
    public:
        using iterator = typename std::array<T, N>::iterator;
        using const_iterator = typename std::array<T, N>::const_iterator;
        using value_type = T;
        static constexpr auto dimension = N;

        VectorND() : data(){};

        template <typename... Args>
        VectorND(Args... args)
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

        iterator begin()
        {
            return data.begin();
        }

        iterator end()
        {
            return data.end();
        }

        const_iterator begin() const
        {
            return data.begin();
        }

        const_iterator end() const
        {
            return data.end();
        }

        VectorND<T, N> &operator+=(T const scalar)
        {
            for (std::size_t index{0}; index < this->dimension; index++)
            {
                data[index] += scalar;
            }

            return *this;
        }

        VectorND<T, N> &operator-=(T const scalar)
        {
            for (std::size_t index{0}; index < this->dimension; index++)
            {
                data[index] -= scalar;
            }

            return *this;
        }

        VectorND<T, N> &operator*=(T const scalar)
        {
            for (std::size_t index{0}; index < this->dimension; index++)
            {
                data[index] *= scalar;
            }

            return *this;
        }

        VectorND<T, N> &operator/=(T const scalar)
        {
            for (std::size_t index{0}; index < this->dimension; index++)
            {
                data[index] *= (static_cast<T>(1) / scalar);
            }

            return *this;
        }

    private:
        std::array<T, dimension> data;

        template <typename Arg, typename... Args>
        void initialize(Arg first, Args... rest)
        {
            data[dimension - sizeof...(rest) - 1] = first;
            initialize(rest...);
        }

        void initialize() {}
    };

    template <typename T, std::size_t N>
    VectorND<T, N> operator+(VectorND<T, N> const &lhs, VectorND<T, N> const &rhs)
    {
        VectorND<T, N> result{};

        for (std::size_t index{0}; index < lhs.dimension; index++)
        {
            result[index] = lhs[index] + rhs[index];
        }

        return result;
    }

    template <typename T, std::size_t N>
    VectorND<T, N> operator-(VectorND<T, N> const &lhs, VectorND<T, N> const &rhs)
    {
        VectorND<T, N> result{};

        for (std::size_t index{0}; index < lhs.dimension; index++)
        {
            result[index] = lhs[index] - rhs[index];
        }

        return result;
    }

    template <typename T, std::size_t N>
    VectorND<T, N> operator*(VectorND<T, N> const &lhs, T const rhs)
    {
        VectorND<T, N> result{};

        for (std::size_t index{0}; index < lhs.dimension; index++)
        {
            result[index] = lhs[index] * rhs;
        }

        return result;
    }

    template <typename T, std::size_t N>
    T Magnitude(VectorND<T, N> const &vec)
    {
        return sqrt(std::accumulate(vec.begin(), vec.end(), static_cast<T>(0), [](auto const &accum, auto const& component)
                                    { return accum + (component * component); }));
    }

} // namespace Engine::Math
