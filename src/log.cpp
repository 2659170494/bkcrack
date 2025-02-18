#include "log.hpp"

#include "Keys.hpp"

#include <ctime>
#include <iomanip>

std::ostream& put_time(std::ostream& os)
{
    std::time_t t = std::time(nullptr);
    return os << std::put_time(std::localtime(&t), "%T");
}

std::ostream& operator<<(std::ostream& os, const Keys& keys)
{
    const auto flagsBefore = os.setf(std::ios::hex, std::ios::basefield);
    const auto fillBefore  = os.fill('0');

    os << std::setw(8) << keys.getX() << " " << std::setw(8) << keys.getY() << " " << std::setw(8) << keys.getZ();

    os.fill(fillBefore);
    os.flags(flagsBefore);

    return os;
}
