#pragma once

#include <istream>
#include <string>
#include <random>

inline const std::string API_KEY = "33fd47a1c734b29b-40357b345194a388-74392945f67ff65f-ddef98f8bc8d3be0-14395836d484400a";

#define SNAPP__IF_API_KEY_VALID(req) if (req.get_header_value("snapp-ink-api-key") == API_KEY)

inline std::string
generateGUID()
{
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<uint64_t> dis(0, 0xFFFFFFFFFFFFFFFF);

    std::stringstream ss;
    ss << std::hex << std::setfill('0');

    // Generate first part (8 digits)
    ss << std::setw(8) << dis(gen);

    // Generate second part (4 digits)
    ss << '-';
    ss << std::setw(4) << dis(gen);

    // Generate third part (4 digits)
    ss << '-';
    ss << std::setw(4) << dis(gen);

    // Generate fourth part (4 digits)
    ss << '-';
    ss << std::setw(4) << dis(gen);

    // Generate fifth part (12 digits)
    ss << '-';
    ss << std::setw(12) << dis(gen);
    return ss.str();
}
 