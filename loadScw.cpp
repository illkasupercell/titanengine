#include <array>
#include <iostream>
#include <string_view>
#include <type_traits>

std::string_view getMaxMargin();

template<int bit_num>
struct flag {
    friend constexpr int adl_flag(flag<bit_num>);
};

template<int bit_num>
struct writer {
    friend constexpr int adl_flag(flag<bit_num>)
    {
        return bit_num;
    }

    static constexpr int value = bit_num;
};

template<int bit_num, int = adl_flag(flag<bit_num>{})>
constexpr bool is_flag_set(int, flag<bit_num>)
{
    return bit_num >= 0;
}

template<int bit_num>
constexpr bool is_flag_set(float, flag<bit_num>)
{
    return false;
}

template<size_t number, size_t bit_num>
constexpr bool get_bit()
{
    return (number & (1 << bit_num)) != 0;
}

#define flags_to_size()                     \
     ((is_flag_set<0>(0, flag<0>{}) << 0)   \
    | (is_flag_set<1>(0, flag<1>{}) << 1)   \
    | (is_flag_set<2>(0, flag<2>{}) << 2)   \
    | (is_flag_set<3>(0, flag<3>{}) << 3))

template<bool test, typename T_true, typename T_false>
struct meta_if {
    using type = T_true;
};

template<typename T_true, typename T_false>
struct meta_if<false, T_true, T_false> {
    using type = T_false;
};

template<bool test, typename T_true, typename T_false>
using meta_if_t = typename meta_if<test, T_true, T_false>::type;

template<
    size_t desired_size,
    int = (0 +
           sizeof(meta_if_t<get_bit<desired_size, 0>(), writer<0>, int>) +
           sizeof(meta_if_t<get_bit<desired_size, 1>(), writer<1>, int>) +
           sizeof(meta_if_t<get_bit<desired_size, 2>(), writer<2>, int>) +
           sizeof(meta_if_t<get_bit<desired_size, 3>(), writer<3>, int>)
    )
>
constexpr size_t f()
{
    return desired_size;
}

int main()
{
    constexpr size_t a = f<1>();
    constexpr size_t b = f<6>();
    std::cout << "Max margin size: " << getMaxMargin().size() << std::endl;
}

constexpr size_t MARGIN_SIZE = flags_to_size();
constexpr char MARGIN_CHAR = 'x';

template<typename T, T... Args>
constexpr auto getMarginStorageImpl(std::integer_sequence<T, Args...>)
{
    return std::array<char, sizeof...(Args)>{(static_cast<void>(Args), MARGIN_CHAR)...};
}
constexpr auto getMarginStorage()
{
    return getMarginStorageImpl(std::make_integer_sequence<int, MARGIN_SIZE>());
}
constexpr static auto marginStorage = getMarginStorage();;

std::string_view getMaxMargin()
{
    return std::string_view(marginStorage.data(), MARGIN_SIZE);
}
"Интересно, можно ли насфиначить так
