uint32_t GLOBAL_TIMESTAMP_MS = 0;

void increament_global_timestamp();

/// @brief Get Time Stamp Counter
/// @return tick since the last reset of the CPU
uint32_t get_TSC()
{
    uint32_t tsc;

    asm volatile(
                "RDTSC" : "=a" (tsc)
            );

    return tsc;
}

/// @brief wait for millisecondes
/// @param ms 
void sleep(uint32_t ms)
{
    uint32_t t0 = GLOBAL_TIMESTAMP_MS;

    while ((GLOBAL_TIMESTAMP_MS - t0) <= ms * 1000)
    {
        increament_global_timestamp();
    }
    
}

/// @brief Need to be called each time to refresh timestamp
void increament_global_timestamp()
{
    uint32_t ticks = get_TSC();

    uint32_t sec = reverse_bits(ticks) & 0xff; // éstimation pour CPU i386

    if (sec >= 100)
    {
        GLOBAL_TIMESTAMP_MS++;
    }

}