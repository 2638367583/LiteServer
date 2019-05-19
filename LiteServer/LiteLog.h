/*
 * @Description: Log recard class
 * OFF、FATAL、ERROR、WARN、INFO、DEBUG、ALL
 * @Author: lileiyu
 * @Date: 2019-05-19 23:03:11
 * @LastEditTime: 2019-05-20 00:56:27
 * @LastEditors: lileiyu
 */
class LiteLog
{
public:
    enum LOG_LEVEL
    {
        ALL,
        INFO,
        DEBUG,
        WARN,
        ERR,
        FATAL,
        OFF
    };
    LiteLog(/* args */);
    ~LiteLog();
    static void info(const char *format, ...);
    static void debug(const char *format, ...);
    static void warn(const char *format, ...);
    static void error(const char *format, ...);
    static void fatal(const char *format, ...);
private:
    LOG_LEVEL m_level = ALL;
};