#include "../../Lab3/Headers/Noise.h"
#include <random>


double noise(double M, double stddev)
{
    std::random_device rd{};
    std::mt19937 gen{rd()};

    std::normal_distribution<double> d{M, stddev};

    return d(gen);
}
