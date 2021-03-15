
#ifdef _WIN32
#include <filesystem>
#else
#include <experimental/filesystem>
#endif    // _WIN32

namespace robertobernabe::countit
{
#ifdef _WIN32
    namespace stdfs = std::filesystem;
#else
    namespace stdfs = std::experimental::filesystem;
#endif

    class System
    {
    public:
        static std::string get_user_home_directory()
        {
#ifdef _WIN32
            // TODO: use getenv_s instead of getenv
            // But using this here is okay, because getenv is not called in a threaded
            // env here.
            auto path = std::string(std::getenv("HOMEDRIVE")) + std::string(std::getenv("HOMEPATH"));
#elif __linux
            auto path = std::string(std::getenv("HOME"));
#endif
            return path;
        }
    };

}    // namespace robertobernabe::whour
