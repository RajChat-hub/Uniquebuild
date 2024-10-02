#ifndef UNIQUEBUILD_H
#define UNIQUEBUILD_H

// Platform-specific code
#ifdef _WIN32
    #define OS_WINDOWS
    #include <windows.h>
#elif __linux__
    #define OS_LINUX
    #include <unistd.h>
#elif __APPLE__
    #define OS_MAC
    #include <TargetConditionals.h>
    #if TARGET_OS_MAC
        #include <sys/types.h>
        #include <sys/stat.h>
    #endif
#endif

// Debug and Release mode configurations
#ifdef DEBUG_MODE
    #define DEBUG_PRINT(x) std::cout << "DEBUG: " << x << std::endl;
#else
    #define DEBUG_PRINT(x)
#endif

// Define architecture-specific macros
#ifdef __x86_64__
    #define ARCH_X64
#elif __i386__
    #define ARCH_X86
#elif __arm__
    #define ARCH_ARM
#elif __aarch64__
    #define ARCH_ARM64
#endif

// Fix for architecture preprocessor directive
#if defined(ARCH_X64)
    #define ARCHITECTURE "x64"
#elif defined(ARCH_X86)
    #define ARCHITECTURE "x86"
#elif defined(ARCH_ARM)
    #define ARCHITECTURE "ARM"
#elif defined(ARCH_ARM64)
    #define ARCHITECTURE "ARM64"
#endif

// Maximum values used in the build system
#define MAX_PATH_LENGTH 4096
#define MAX_FILENAME_LENGTH 256
#define MAX_THREADS 16

// Version information
#define UNIQUEBUILD_VERSION_MAJOR 1
#define UNIQUEBUILD_VERSION_MINOR 0
#define UNIQUEBUILD_VERSION_PATCH 3

// Functionality switches
#define ENABLE_LOGGING 1
#define ENABLE_MULTITHREADING 1
#define ENABLE_CACHE 0

// Preprocessor checks for optional features
#if ENABLE_LOGGING
    #include <iostream> // Required for std::cout
    #define LOG(x) std::cout << "LOG: " << x << std::endl;
#else
    #define LOG(x)
#endif

#if ENABLE_MULTITHREADING
    #include <thread>
    #define THREAD_POOL_SIZE 4
#else
    #define THREAD_POOL_SIZE 1
#endif

#if ENABLE_CACHE
    #include <unordered_map>
#endif

// Add additional preprocessor directives
#ifdef OS_LINUX
    #include <sys/time.h>
    #include <sys/resource.h>
#endif

// Include necessary headers
#include <fstream>     // Required for std::fstream
#include <numeric>     // Required for std::accumulate
#include <iomanip>     // Required for std::put_time
#include <iostream>    // Required for std::cout, std::endl
#include <string>      // Required for std::string, std::getline
#include <vector>      // Required for std::vector 
#include <algorithm>   // Required for std::sort, std::find
#include <sstream>     // Required for std::stringstream
#include <chrono>      // Required for std::chrono, std::system_clock
#include <cstdlib>     // Required for rand, srand
#include <ctime>       // Required for std::time
#include <cmath>       // Required for std::pow, std::sqrt
#include <map>         // Required for std::map
#include <set>         // Required for std::set
#include <list>        // Required for std::list
#include <deque>       // Required for std::deque
#include <stdexcept>   // Required for std::invalid_argument, std::out_of_range
#include <iterator>    // Required for std::iterator, std::back_inserter
#include <functional>  // Required for std::function
#include <memory>      // Required for std::shared_ptr, std::unique_ptr

// End of include guard
#endif // UNIQUEBUILD_H

// Constants for buffer sizes
#define BUFFER_SIZE_256 256
#define BUFFER_SIZE_512 512
#define BUFFER_SIZE_1024 1024
#define BUFFER_SIZE_2048 2048

// Time-related constants
#define SECOND_MS 1000
#define MINUTE_MS (60 * SECOND_MS)
#define HOUR_MS (60 * MINUTE_MS)
#define DAY_MS (24 * HOUR_MS)

// Math-related constants
#define PI 3.14159265358979323846
#define E 2.71828182845904523536
#define GOLDEN_RATIO 1.618033988749895
#define DEG_TO_RAD(deg) ((deg) * (PI / 180.0))
#define RAD_TO_DEG(rad) ((rad) * (180.0 / PI))

// Return codes
#define SUCCESS 0
#define ERROR_INVALID_ARG 1
#define ERROR_OUT_OF_MEMORY 2
#define ERROR_FILE_NOT_FOUND 3
#define ERROR_PERMISSION_DENIED 4

// Boolean values
#define TRUE 1
#define FALSE 0

// Macros for min and max values
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Safe delete macro
#define SAFE_DELETE(ptr) if (ptr) { delete ptr; ptr = nullptr; }

// File handling constants
#define MAX_FILE_SIZE 104857600  // 100 MB
#define MAX_OPEN_FILES 100

// File permissions
#define FILE_READ_ONLY 0x01
#define FILE_WRITE_ONLY 0x02
#define FILE_READ_WRITE 0x03

// File opening modes
#define FILE_MODE_READ "r"
#define FILE_MODE_WRITE "w"
#define FILE_MODE_APPEND "a"
#define FILE_MODE_READ_BINARY "rb"
#define FILE_MODE_WRITE_BINARY "wb"
#define FILE_MODE_APPEND_BINARY "ab"

// HTTP status codes
#define HTTP_OK 200
#define HTTP_BAD_REQUEST 400
#define HTTP_UNAUTHORIZED 401
#define HTTP_FORBIDDEN 403
#define HTTP_NOT_FOUND 404
#define HTTP_INTERNAL_SERVER_ERROR 500

// Color codes (hex values)
#define COLOR_RED 0xFF0000
#define COLOR_GREEN 0x00FF00
#define COLOR_BLUE 0x0000FF
#define COLOR_WHITE 0xFFFFFF
#define COLOR_BLACK 0x000000
#define COLOR_YELLOW 0xFFFF00
#define COLOR_CYAN 0x00FFFF
#define COLOR_MAGENTA 0xFF00FF

// Utility macros for arrays
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof((arr)[0]))
#define SWAP(a, b) { typeof(a) tmp = (a); (a) = (b); (b) = tmp; }

// Error handling macros
#define CHECK_ERROR(cond, err_code) if (!(cond)) { return err_code; }
#define ASSERT(cond, msg) if (!(cond)) { fprintf(stderr, "%s\n", msg); exit(EXIT_FAILURE); }

// String manipulation macros
#define STRINGIFY(x) #x
#define CONCAT(a, b) a ## b
#define TO_UPPER(c) (((c) >= 'a' && (c) <= 'z') ? (c) - 32 : (c))
#define TO_LOWER(c) (((c) >= 'A' && (c) <= 'Z') ? (c) + 32 : (c))

// Logging macros
#define LOG_INFO(msg) printf("[INFO] %s\n", msg)
#define LOG_WARN(msg) printf("[WARN] %s\n", msg)
#define LOG_ERROR(msg) printf("[ERROR] %s\n", msg)
#define LOG_DEBUG(msg) printf("[DEBUG] %s\n", msg)

// Threading constants
#define THREAD_STACK_SIZE 8192
#define MAX_THREAD_COUNT 16
#define DEFAULT_THREAD_PRIORITY 5

// Network-related constants
#define MAX_CONNECTIONS 100
#define DEFAULT_PORT 8080
#define MAX_PACKET_SIZE 4096
#define TIMEOUT_MS 5000

// Memory alignment macros
#define ALIGN_UP(x, a) (((x) + ((a) - 1)) & ~((a) - 1))
#define ALIGN_DOWN(x, a) ((x) & ~((a) - 1))

// Endian conversion macros
#define TO_LITTLE_ENDIAN_16(x) ((x) & 0xFF) | (((x) & 0xFF00) >> 8)
#define TO_LITTLE_ENDIAN_32(x) ((x) & 0xFF) | (((x) & 0xFF00) >> 8) | (((x) & 0xFF0000) >> 16) | (((x) & 0xFF000000) >> 24)

#define TO_BIG_ENDIAN_16(x) (((x) & 0xFF) << 8) | (((x) & 0xFF00) >> 8)
#define TO_BIG_ENDIAN_32(x) (((x) & 0xFF) << 24) | (((x) & 0xFF00) << 8) | (((x) & 0xFF0000) >> 8) | (((x) & 0xFF000000) >> 24)

// Limits
#define MAX_BUFFER_SIZE 8192
#define MAX_LOG_LENGTH 1024
#define MAX_INPUT_SIZE 512
#define MAX_OUTPUT_SIZE 512

// Common file paths
#define CONFIG_FILE_PATH "/etc/myapp/config.cfg"
#define LOG_FILE_PATH "/var/log/myapp.log"
#define TEMP_FILE_PATH "/tmp/myapp.tmp"

// Default values
#define DEFAULT_TIMEOUT 3000  // 3 seconds
#define DEFAULT_BUFFER_SIZE 1024
#define DEFAULT_PORT_NUMBER 80

// Signal handling macros
#define CATCH_SIGNAL(sig, handler) signal(sig, handler)
#define IGNORE_SIGNAL(sig) signal(sig, SIG_IGN)
#define DEFAULT_SIGNAL_HANDLER SIG_DFL

// Debugging utility macros
#ifdef DEBUG
    #define DEBUG_PRINT_VAR(var) printf(#var " = %d\n", var)
    #define DEBUG_PRINT_STR(var) printf(#var " = %s\n", var)
#else
    #define DEBUG_PRINT_VAR(var)
    #define DEBUG_PRINT_STR(var)
#endif

// Exit codes
#define EXIT_CODE_SUCCESS 0
#define EXIT_CODE_FAILURE 1
#define EXIT_CODE_INVALID_ARGUMENTS 2
#define EXIT_CODE_OUT_OF_MEMORY 3
#define EXIT_CODE_FILE_ERROR 4

// Common mathematical constants
#define MAX_INT 2147483647
#define MIN_INT (-2147483647 - 1)
#define MAX_FLOAT 3.402823466e+38F
#define MIN_FLOAT 1.175494351e-38F

// File access permissions
#define PERM_READ 0x01
#define PERM_WRITE 0x02
#define PERM_EXECUTE 0x04

// Process control macros
#define FORK_PROCESS fork()
#define KILL_PROCESS(pid, sig) kill(pid, sig)

// Example use of a build-related macro
#define BUILD_WITH_DEBUG 1
#define BUILD_VERSION_MAJOR 1
#define BUILD_VERSION_MINOR 0
#define BUILD_VERSION_PATCH 0

// Time macros
#define MS_TO_S(ms) ((ms) / 1000)
#define S_TO_MS(s) ((s) * 1000)
#define MS_TO_MIN(ms) ((ms) / (1000 * 60))
#define MIN_TO_MS(min) ((min) * (1000 * 60))


/***************************************
 * Project: Uniquebuild.h 
 * Description: A robust header file containing common macros, constants, and utilities.
 * 
 * Author: Rajdeep Chatterjee
 * Date: October 2024
 ***************************************/

/***************************************
 * SECTION: Buffer Sizes
 * These macros define the standard buffer sizes used for memory allocation,
 * file operations, or network communication.
 ***************************************/

/**
 * BUFFER_SIZE_256: Represents a 256-byte buffer.
 * Commonly used for small I/O operations.
 */
#define BUFFER_SIZE_256 256

/**
 * BUFFER_SIZE_512: Represents a 512-byte buffer.
 * Frequently used for intermediate size file operations.
 */
#define BUFFER_SIZE_512 512

/**
 * BUFFER_SIZE_1024: 1024-byte buffer, used in situations where moderate
 * data transfer (like reading lines from files) is needed.
 */
#define BUFFER_SIZE_1024 1024

/**
 * BUFFER_SIZE_2048: 2048-byte buffer, commonly used for larger data
 * handling like copying data from large files or packets in network communication.
 */
#define BUFFER_SIZE_2048 2048

/***************************************
 * SECTION: Time Units
 * These constants help convert time units, from milliseconds to hours.
 * Useful when dealing with timeouts, delays, or any time-based calculation.
 ***************************************/

/**
 * SECOND_MS: Number of milliseconds in one second.
 * Useful for converting time durations into milliseconds.
 */
#define SECOND_MS 1000

/**
 * MINUTE_MS: Number of milliseconds in one minute.
 * Can be used to set long-term timeouts or delays.
 */
#define MINUTE_MS (60 * SECOND_MS)

/**
 * HOUR_MS: Number of milliseconds in one hour.
 * Useful in long-running processes or periodic jobs.
 */
#define HOUR_MS (60 * MINUTE_MS)

/**
 * DAY_MS: Number of milliseconds in one day.
 * Typically used in applications that deal with scheduling.
 */
#define DAY_MS (24 * HOUR_MS)

/***************************************
 * SECTION: Mathematical Constants
 * These are standard constants like PI and the Euler number (E) used in various
 * mathematical operations.
 ***************************************/

/**
 * PI: Defines the mathematical constant PI (3.14159).
 * Essential for trigonometric operations in geometry.
 */
#define PI 3.14159265358979323846

/**
 * E: Defines Euler's number (e ~ 2.71828).
 * Commonly used in exponential and logarithmic calculations.
 */
#define E 2.71828182845904523536

/**
 * GOLDEN_RATIO: Approximate value of the golden ratio (1.618...).
 * Useful in various design and aesthetic calculations.
 */
#define GOLDEN_RATIO 1.618033988749895

/**
 * DEG_TO_RAD(deg): Converts degrees to radians.
 * Useful when dealing with angular values in trigonometry.
 * @param deg: Angle in degrees.
 * @return: Angle in radians.
 */
#define DEG_TO_RAD(deg) ((deg) * (PI / 180.0))

/**
 * RAD_TO_DEG(rad): Converts radians to degrees.
 * Used when you need to convert angles from radian-based calculations
 * to degrees.
 * @param rad: Angle in radians.
 * @return: Angle in degrees.
 */
#define RAD_TO_DEG(rad) ((rad) * (180.0 / PI))

/***************************************
 * SECTION: Return Codes
 * Standard return codes for functions indicating success or different
 * kinds of failures.
 ***************************************/

/**
 * SUCCESS: Indicates that the function has completed successfully.
 * It is generally used as a return value from functions.
 */
#define SUCCESS 0

/**
 * ERROR_INVALID_ARG: Returned when an invalid argument is passed to a function.
 * Helps in argument validation logic.
 */
#define ERROR_INVALID_ARG 1

/**
 * ERROR_OUT_OF_MEMORY: Indicates that the system has run out of memory.
 * Useful in memory allocation functions.
 */
#define ERROR_OUT_OF_MEMORY 2

/**
 * ERROR_FILE_NOT_FOUND: Returned when a file is not found in file system operations.
 */
#define ERROR_FILE_NOT_FOUND 3

/**
 * ERROR_PERMISSION_DENIED: Indicates that the user does not have permission
 * to access the file or resource.
 */
#define ERROR_PERMISSION_DENIED 4

/***************************************
 * SECTION: Boolean Constants
 * Defines TRUE and FALSE constants for logical operations.
 ***************************************/

/**
 * TRUE: Boolean value for 'true'.
 */
#define TRUE 1

/**
 * FALSE: Boolean value for 'false'.
 */
#define FALSE 0

/***************************************
 * SECTION: Safe Memory Management
 * A macro that safely deletes a pointer and sets it to nullptr.
 * Prevents dangling pointers.
 ***************************************/

/**
 * SAFE_DELETE(ptr): Deletes a pointer if it is not null and sets it to null.
 * This helps to prevent memory leaks and dangling pointers.
 * @param ptr: The pointer to delete.
 */
#define SAFE_DELETE(ptr) if (ptr) { delete ptr; ptr = nullptr; }

/***************************************
 * SECTION: File Handling Constants
 * These constants help define file handling modes and limits for file sizes.
 ***************************************/

/**
 * MAX_FILE_SIZE: Defines the maximum file size that can be handled (100 MB).
 * Adjust this if the program needs to handle larger files.
 */
#define MAX_FILE_SIZE 104857600  // 100 MB

/**
 * FILE_READ_ONLY: File is opened in read-only mode.
 */
#define FILE_READ_ONLY 0x01

/**
 * FILE_WRITE_ONLY: File is opened in write-only mode.
 */
#define FILE_WRITE_ONLY 0x02

/**
 * FILE_READ_WRITE: File is opened for both reading and writing.
 */
#define FILE_READ_WRITE 0x03

/**
 * FILE_MODE_READ: Mode string for opening a file for reading.
 * Used in fopen() or similar functions.
 */
#define FILE_MODE_READ "r"

/**
 * FILE_MODE_WRITE: Mode string for opening a file for writing.
 */
#define FILE_MODE_WRITE "w"

/**
 * FILE_MODE_APPEND: Mode string for opening a file for appending data.
 */
#define FILE_MODE_APPEND "a"

/***************************************
 * SECTION: Logging Macros
 * These macros provide a simple way to log messages to the console.
 * Each log type has a different format for clarity.
 ***************************************/

/**
 * LOG_INFO(msg): Logs an informational message to the console.
 * @param msg: The message to log.
 */
#define LOG_INFO(msg) printf("[INFO] %s\n", msg)

/**
 * LOG_WARN(msg): Logs a warning message to the console.
 * Warnings indicate potential issues but do not stop program execution.
 * @param msg: The warning message.
 */
#define LOG_WARN(msg) printf("[WARN] %s\n", msg)

/**
 * LOG_ERROR(msg): Logs an error message to the console.
 * Error messages should indicate critical failures that need attention.
 * @param msg: The error message.
 */
#define LOG_ERROR(msg) printf("[ERROR] %s\n", msg)

/**
 * LOG_DEBUG(msg): Logs a debug message to the console.
 * These are typically used during development for troubleshooting.
 * @param msg: The debug message.
 */
#define LOG_DEBUG(msg) printf("[DEBUG] %s\n", msg)

/***************************************
 * SECTION: Mathematical Macros
 * These macros simplify certain mathematical operations like finding
 * minimum and maximum values, swapping variables, and aligning memory.
 ***************************************/

/**
 * MIN(a, b): Returns the minimum of two values.
 * @param a: First value.
 * @param b: Second value.
 * @return: The smaller value.
 */
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/**
 * MAX(a, b): Returns the maximum of two values.
 * @param a: First value.
 * @param b: Second value.
 * @return: The larger value.
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * SWAP(a, b): Swaps two values of any type.
 * @param a: First value.
 * @param b: Second value.
 */
#define SWAP(a, b) { typeof(a) tmp = (a); (a) = (b); (b) = tmp; }

/**
 * ALIGN_UP(x, a): Aligns a value x to the next multiple of a.
 * Useful when allocating memory blocks.
 * @param x: The value to align.
 * @param a: The alignment boundary.
 */
#define ALIGN_UP(x, a) (((x) + ((a) - 1)) & ~((a) - 1))

/**
 * ALIGN_DOWN(x, a): Aligns a value x down to the nearest multiple of a.
 * @param x: The value to align.
 * @param a: The alignment boundary.
 */
#define ALIGN_DOWN(x, a) ((x) & ~((a) - 1))

/***************************************
 * SECTION: Namespaces
 * The following namespaces are designed to group related functionalities.
 * They help avoid naming collisions in larger projects and provide better
 * code organization.
 ***************************************/

namespace UniqueBuild {

/**
 * @namespace FileUtils
 * Provides a collection of utility functions for handling files.
 * Contains methods for file reading, writing, and deletion.
 */
namespace FileUtils {

/**
 * Reads the contents of a file.
 * @param filename: The name of the file to read.
 * @return: The content of the file as a string.
 */
std::string readFile(const std::string& filename);

/**
 * Writes content to a file.
 * @param filename: The name of the file to write.
 * @param content: The content to write to the file.
 * @return: True if the operation is successful, false otherwise.
 */
bool writeFile(const std::string& filename, const std::string& content);

/**
 * Deletes a file.
 * @param filename: The name of the file to delete.
 * @return: True if the file was successfully deleted, false otherwise.
 */
bool deleteFile(const std::string& filename);

}  // namespace FileUtils

/**
 * @namespace MathUtils
 * Contains various utility functions for mathematical calculations.
 */
namespace MathUtils {

/**
 * Computes the factorial of a number.
 * @param n: The number to compute the factorial of.
 * @return: The factorial of the number.
 */
int factorialInt(int n);           // Returns factorial as an int (for smaller n)
unsigned long long factorial_ull(int n); // Returns factorial as unsigned long long (for larger n)

/**
 * Computes the greatest common divisor (GCD) of two numbers.
 * @param a: First number.
 * @param b: Second number.
 * @return: The GCD of the two numbers.
 */
int gcd(int a, int b);

}  // namespace MathUtils

}  // namespace NoBuild

/***************************************
 * SECTION: Classes
 * The following classes are designed to encapsulate related data and functions.
 * Classes provide a blueprint for creating objects in the program.
 ***************************************/

/**
 * @class FileHandler
 * Handles file operations such as opening, closing, reading, and writing files.
 */
class FileHandler {
public:
        FileHandler() = default;  // Constructor
    ~FileHandler() { close(); }  // Destructor to close file if open
    /**
     * Opens a file with the given filename.
     * @param filename: The name of the file to open.
     * @return: True if the file was successfully opened, false otherwise.
     */
    bool open(const std::string& filename);

    /**
     * Reads data from the file.
     * @return: A string containing the data read from the file.
     */
    std::string read() const;  // Marked const

    /**
     * Writes data to the file.
     * @param data: The data to write to the file.
     */
    void write(const std::string& data);

    /**
     * Closes the file.
     */
    void close();

private:
    std::string filename_;  // The name of the file
    std::fstream fileStream_;  // File stream for reading and writing
};

/**
 * @class MathOperations
 * Provides various mathematical operations.
 */
class MathOperations {
public:
    /**
     * Computes the square of a number.
     * @param x: The number to square.
     * @return: The square of the number.
     */
    int square(int x);

    /**
     * Computes the cube of a number.
     * @param x: The number to cube.
     * @return: The cube of the number.
     */
    int cube(int x);

    /**
     * Checks if a number is prime.
     * @param x: The number to check.
     * @return: True if the number is prime, false otherwise.
     */
    bool isPrime(int x);
};

/***************************************
 * SECTION: Structs
 * Structs are used to group related variables together under one name.
 * The following structs represent common data structures.
 ***************************************/

/**
 * @struct Point
 * Represents a 2D point on a Cartesian plane.
 */
struct Point {
    int x;  // X-coordinate
    int y;  // Y-coordinate
};

/**
 * @struct Rectangle
 * Represents a rectangle defined by its top-left corner and its width and height.
 */
struct Rectangle {
    Point topLeft;  // Top-left corner of the rectangle
    int width;  // Width of the rectangle
    int height;  // Height of the rectangle
};

/**
 * @struct FileInfo
 * Holds information about a file, including its name, size, and permissions.
 */
struct FileInfo {
    std::string name;  // File name
    size_t size;  // File size in bytes
    bool isReadOnly;  // Indicates if the file is read-only
};

/***************************************
 * SECTION: Enums
 * Enums are used to represent a set of named integer constants.
 * The following enums define common status codes and error types.
 ***************************************/

/**
 * @enum StatusCode
 * Represents the status of an operation.
 */
enum class StatusCode {
    STATUS_SUCCESS,  // The operation was successful
    STATUS_ERROR,  // A generic error occurred
    FILE_NOT_FOUND,  // The file was not found
    PERMISSION_DENIED  // The operation was denied due to lack of permissions
};

/**
 * @enum FileMode
 * Represents the mode in which a file can be opened.
 */
enum class FileMode {
    READ,  // Open the file for reading
    WRITE,  // Open the file for writing
    APPEND  // Open the file for appending data
};

/**
 * @enum LogLevel
 * Represents the different levels of logging that can be used in the application.
 */
enum LogLevel {
    LOG_LEVEL_DEBUG,  // Debug-level log messages
    LOG_LEVEL_INFO,  // Informational log messages
    LOG_LEVEL_WARNING,  // Warning-level log messages
    LOG_LEVEL_ERROR  // Error-level log messages
};

/**
 * @enum MathError
 * Represents various mathematical errors that can occur during calculations.
 */
enum MathError {
    MATH_ERROR_NONE,  // No error
    MATH_ERROR_DIVIDE_BY_ZERO,  // Division by zero
    MATH_ERROR_OVERFLOW,  // Overflow during calculation
    MATH_ERROR_UNDERFLOW  // Underflow during calculation
};

/***************************************
 * SECTION: Additional Structs and Enums
 ***************************************/

/**
 * @struct Circle
 * Represents a circle defined by its center and radius.
 */
struct Circle {
    Point center;  // Center of the circle
    double radius;  // Radius of the circle
};

/**
 * @struct User
 * Represents a user with an ID, name, and age.
 */
struct User {
    int id;  // User ID
    std::string name;  // User name
    int age;  // User age
};

/**
 * @enum UserRole
 * Represents the role of a user in the system.
 */
enum UserRole {
    ROLE_ADMIN,  // Administrator role
    ROLE_EDITOR,  // Editor role
    ROLE_VIEWER  // Viewer role
};

/***************************************
 * SECTION: Function Declarations
 * This section contains declarations for various functions
 * used throughout the project.
 ***************************************/

/**
 * Initializes the application.
 * @return: True if initialization was successful, false otherwise.
 */
bool initApp();

/**
 * Cleans up resources before the application exits.
 */
void cleanupApp();

/**
 * Prints a welcome message to the user.
 */
void printWelcomeMessage();

/**
 * Displays the help menu for the application.
 */
void displayHelp();

/**
 * Reads user input from the console.
 * @return: The input string entered by the user.
 */
std::string readUserInput();

/**
 * Converts a string to uppercase.
 * @param str: The input string.
 * @return: The converted uppercase string.
 */
std::string toUpperCase(const std::string& str);

/**
 * Computes the sum of two integers.
 * @param a: The first integer.
 * @param b: The second integer.
 * @return: The sum of the two integers.
 */
int add(int a, int b);

/**
 * Computes the sum of two floating-point numbers.
 * @param a: The first float.
 * @param b: The second float.
 * @return: The sum of the two floats.
 */
float add(float a, float b);

/**
 * Finds the minimum of two integers.
 * @param a: The first integer.
 * @param b: The second integer.
 * @return: The smaller of the two integers.
 */
int min(int a, int b);

/**
 * Finds the minimum of two floating-point numbers.
 * @param a: The first float.
 * @param b: The second float.
 * @return: The smaller of the two floats.
 */
float min(float a, float b);

/***************************************
 * SECTION: Overloaded Functions
 * These functions have the same name but different parameter types
 * or numbers of parameters, demonstrating function overloading.
 ***************************************/

/**
 * Overloaded function to compute the absolute value of an integer.
 * @param value: The integer value.
 * @return: The absolute value of the integer.
 */
int absolute(int value);

/**
 * Overloaded function to compute the absolute value of a float.
 * @param value: The floating-point value.
 * @return: The absolute value of the float.
 */
float absolute(float value);

/**
 * Overloaded function to compute the absolute value of a double.
 * @param value: The double value.
 * @return: The absolute value of the double.
 */
double absolute(double value);

/**
 * Overloaded function to print a message.
 * @param message: The message string.
 */
void print(const std::string& message);

/**
 * Overloaded function to print an integer.
 * @param number: The integer to print.
 */
void print(int number);

/**
 * Overloaded function to print a floating-point number.
 * @param number: The float to print.
 */
void print(float number);

/**
 * Overloaded function to print a double-precision number.
 * @param number: The double to print.
 */
void print(double number);

/***************************************
 * SECTION: Function Templates
 * Templates allow functions to work with any data type.
 ***************************************/

/**
 * A generic template function to swap two values.
 * @tparam T: The type of the values to swap.
 * @param a: The first value.
 * @param b: The second value.
 */
template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

/**
 * A generic template function to find the maximum of two values.
 * @tparam T: The type of the values.
 * @param a: The first value.
 * @param b: The second value.
 * @return: The larger of the two values.
 */
template<typename T>
T max(const T& a, const T& b) {
    return (a > b) ? a : b;
}

/**
 * A generic template function to find the minimum of two values.
 * @tparam T: The type of the values.
 * @param a: The first value.
 * @param b: The second value.
 * @return: The smaller of the two values.
 */
template<typename T>
T min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

/**
 * A generic template function to sort an array.
 * @tparam T: The type of the array elements.
 * @param arr: The array to sort.
 * @param size: The size of the array.
 */
template<typename T>
void sortArray(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/**
 * A generic template function to print the elements of an array.
 * @tparam T: The type of the array elements.
 * @param arr: The array to print.
 * @param size: The size of the array.
 */
template<typename T>
void printArray(const T arr[], int size) {
    for (int i = 0; i < size; i++) {
        print(arr[i]);
    }
}

/**
 * A generic template function to reverse an array.
 * @tparam T: The type of the array elements.
 * @param arr: The array to reverse.
 * @param size: The size of the array.
 */
template<typename T>
void reverseArray(T arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(arr[i], arr[size - i - 1]);
    }
}

/**
 * A generic template function to find the sum of array elements.
 * @tparam T: The type of the array elements.
 * @param arr: The array whose elements will be summed.
 * @param size: The size of the array.
 * @return: The sum of the array elements.
 */
template<typename T>
T arraySum(const T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

/***************************************
 * SECTION: Specialized Template Functions
 * Specialized templates provide custom implementations for specific types.
 ***************************************/

/**
 * A specialized template function to find the sum of a char array.
 * Treats each char as its ASCII value.
 * @param arr: The char array.
 * @param size: The size of the array.
 * @return: The sum of the ASCII values of the chars in the array.
 */
template<>
char arraySum<char>(const char arr[], int size) {
    char sum = 0;
    for (int i = 0; i < size; i++) {
        sum += static_cast<int>(arr[i]);
    }
    return sum;
}

/**
 * A specialized template function to print a bool array.
 * Prints "true" for true and "false" for false.
 * @param arr: The bool array.
 * @param size: The size of the array.
 */
template<>
void printArray<bool>(const bool arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] ? print("true") : print("false");
    }
}

/***************************************
 * SECTION: Helper Functions
 * These functions assist in performing smaller, modular tasks
 * that are often reused across the application.
 ***************************************/

/**
 * Helper function to check if a number is even.
 * @param number: The number to check.
 * @return: True if the number is even, false otherwise.
 */
bool isEven(int number) {
    return number % 2 == 0;
}

/**
 * Helper function to check if a number is odd.
 * @param number: The number to check.
 * @return: True if the number is odd, false otherwise.
 */
bool isOdd(int number) {
    return number % 2 != 0;
}

/**
 * Helper function to check if a string is a palindrome.
 * @param str: The input string.
 * @return: True if the string is a palindrome, false otherwise.
 */
bool isPalindrome(const std::string& str) {
    int length = str.length();
    for (int i = 0; i < length / 2; ++i) {
        if (str[i] != str[length - i - 1]) {
            return false;
        }
    }
    return true;
}

/**
 * Helper function to find the factorial of a number.
 * @param n: The input number.
 * @return: The factorial of the number.
 */
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

/**
 * Helper function to calculate the power of a number.
 * @param base: The base number.
 * @param exponent: The exponent.
 * @return: The result of base raised to the power of exponent.
 */
double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

/**
 * Helper function to convert a string to an integer.
 * @param str: The input string.
 * @return: The integer representation of the string.
 */
int stringToInt(const std::string& str) {
    return std::stoi(str);
}

/**
 * Helper function to generate a random number between min and max.
 * @param min: The minimum value.
 * @param max: The maximum value.
 * @return: A random number between min and max.
 */
int randomInRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

/***************************************
 * SECTION: Inline Functions
 * These functions are marked as inline to suggest that the compiler
 * should attempt to expand them inline rather than calling them.
 ***************************************/

/**
 * Inline function to find the maximum of two integers.
 * @param a: The first integer.
 * @param b: The second integer.
 * @return: The larger of the two integers.
 */
inline int max(int a, int b) {
    return (a > b) ? a : b;
}

/**
 * Inline function to find the minimum of two integers.
 * @param a: The first integer.
 * @param b: The second integer.
 * @return: The smaller of the two integers.
 */
inline int min(int a, int b) {
    return (a < b) ? a : b;
}

/**
 * Inline function to compute the square of a number.
 * @param x: The input number.
 * @return: The square of the number.
 */
inline int square(int x) {
    return x * x;
}

/**
 * Inline function to check if a number is positive.
 * @param x: The number to check.
 * @return: True if the number is positive, false otherwise.
 */
inline bool isPositive(int x) {
    return x > 0;
}

/**
 * Inline function to compute the absolute value of a number.
 * @param x: The input number.
 * @return: The absolute value of the number.
 */
inline int absolute(int x) {
    return (x < 0) ? -x : x;
}

/***************************************
 * SECTION: Utility Functions
 * These functions are general-purpose utilities that are commonly
 * used across various parts of the program.
 ***************************************/

/**
 * Utility function to print a line of dashes for formatting output.
 */
void printLine() {
    std::cout << "----------------------------------------" << std::endl;
}

/**
 * Utility function to trim whitespace from both ends of a string.
 * @param str: The input string.
 * @return: The trimmed string.
 */
std::string trim(const std::string& str) {
    const auto strBegin = str.find_first_not_of(' ');
    const auto strEnd = str.find_last_not_of(' ');
    return (strBegin == std::string::npos) ? "" : str.substr(strBegin, strEnd - strBegin + 1);
}

/**
 * Utility function to convert a string to lowercase.
 * @param str: The input string.
 * @return: The lowercase string.
 */
std::string toLowerCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

/**
 * Utility function to print a vector of integers.
 * @param vec: The input vector of integers.
 */
void printVector(const std::vector<int>& vec) {
    std::cout << "[ ";
    for (const int& val : vec) {
        std::cout << val << " ";
    }
    std::cout << "]" << std::endl;
}

/**
 * Utility function to find the index of an element in a vector.
 * @param vec: The input vector.
 * @param element: The element to find.
 * @return: The index of the element if found, -1 otherwise.
 */
int findIndex(const std::vector<int>& vec, int element) {
    auto it = std::find(vec.begin(), vec.end(), element);
    return (it != vec.end()) ? std::distance(vec.begin(), it) : -1;
}

/**
 * Utility function to reverse a string.
 * @param str: The input string.
 * @return: The reversed string.
 */
std::string reverseString(const std::string& str) {
    std::string result = str;
    std::reverse(result.begin(), result.end());
    return result;
}

/**
 * Utility function to check if a vector contains a value.
 * @param vec: The input vector.
 * @param value: The value to check.
 * @return: True if the value is found, false otherwise.
 */
bool contains(const std::vector<int>& vec, int value) {
    return std::find(vec.begin(), vec.end(), value) != vec.end();
}

/**
 * Utility function to sort a vector of integers.
 * @param vec: The input vector.
 */
void sortVector(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
}

/**
 * Utility function to calculate the average of a vector of integers.
 * @param vec: The input vector.
 * @return: The average value of the elements.
 */
double calculateAverage(const std::vector<int>& vec) {
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    return static_cast<double>(sum) / vec.size();
}

/**
 * Utility function to find the median of a vector of integers.
 * @param vec: The input vector.
 * @return: The median value.
 */
double calculateMedian(std::vector<int>& vec) {
    sortVector(vec);
    int size = vec.size();
    if (size % 2 == 0) {
        return (vec[size / 2 - 1] + vec[size / 2]) / 2.0;
    } else {
        return vec[size / 2];
    }
}

/**
 * Utility function to split a string by a delimiter.
 * @param str: The input string.
 * @param delimiter: The delimiter character.
 * @return: A vector of split strings.
 */
std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}

/**
 * Utility function to get the current timestamp as a string.
 * @return: The current timestamp.
 */
std::string getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

/************************************************
 * SECTION: Additional Comments and Explanations
 * This section contains detailed comments to provide 
 * clarity and context to the functions and structures
 * defined in this header file. Use this section as a
 * guide for understanding the rationale behind
 * the code implementations.
 ************************************************/

/**
 * Explanation of Helper Functions:
 * 
 * Helper functions are designed to perform smaller, repetitive
 * tasks that may be required across different parts of the application.
 * Functions like `isEven`, `isPalindrome`, and `factorial` are useful
 * for handling basic operations with minimal dependencies.
 *
 * Rationale for Inline Functions:
 * 
 * Inline functions provide an optimization by eliminating the overhead
 * of a function call. Functions like `max`, `min`, and `square` are
 * perfect candidates for inlining, as they are small and frequently used.
 *
 * Explanation of Utility Functions:
 * 
 * Utility functions such as `printLine`, `trim`, and `sortVector` are
 * general-purpose functions that improve code readability and reusability.
 * They are designed to handle common tasks like string manipulation,
 * printing, and vector sorting, which are common in many applications.
 *
 ************************************************/

/************************************************
 * SECTION: External Dependencies
 * 
 * This section outlines the external libraries and headers
 * required by the functionality defined in this header file.
 * These dependencies ensure that the functions in nobuild.h
 * have access to necessary data types, utilities, and 
 * functions provided by the C++ Standard Library and
 * additional external libraries.
 ************************************************/

#include <iostream>     // Required for basic input/output operations (std::cout, std::endl)
#include <string>       // Required for string manipulation (std::string, std::getline)
#include <vector>       // Required for working with dynamic arrays (std::vector)
#include <algorithm>    // Required for sorting and searching (std::sort, std::find)
#include <numeric>      // Required for numerical operations (std::accumulate)
#include <sstream>      // Required for string stream manipulation (std::stringstream)
#include <chrono>       // Required for working with time and date (std::chrono, std::system_clock)
#include <iomanip>      // Required for formatting output (std::put_time)
#include <cstdlib>      // Required for general-purpose functions (rand, srand)
#include <ctime>        // Required for seeding random numbers (std::time)
#include <fstream>      // Required for file handling operations (std::ifstream, std::ofstream)
#include <cmath>        // Required for mathematical operations (std::pow, std::sqrt)
#include <map>          // Required for associative containers (std::map)
#include <set>          // Required for unique container management (std::set)
#include <list>         // Required for doubly linked list operations (std::list)
#include <deque>        // Required for double-ended queue operations (std::deque)
#include <stdexcept>    // Required for exception handling (std::invalid_argument, std::out_of_range)
#include <iterator>     // Required for iterating over containers (std::iterator, std::back_inserter)
#include <functional>   // Required for function objects and callbacks (std::function)
#include <memory>       // Required for dynamic memory management (std::shared_ptr, std::unique_ptr)

/************************************************
 * SECTION: Third-Party Dependencies
 * 
 * If the project depends on any external third-party libraries, 
 * they should be listed here. These dependencies could include:
 * 
 * 1. Boost: Provides additional utility libraries not present in the standard library.
 *    Example: `#include <boost/algorithm/string.hpp>` for string utilities.
 * 
 * 2. Eigen: Used for matrix and vector algebra in computational applications.
 *    Example: `#include <Eigen/Dense>` for matrix operations.
 * 
 * 3. OpenSSL: Required for encryption and decryption operations in networked applications.
 *    Example: `#include <openssl/sha.h>` for hashing functions.
 * 
 * 4. SQLite: A lightweight database engine used for data storage.
 *    Example: `#include <sqlite3.h>` for database management.
 ************************************************/

/**
 * Notes on Performance:
 * 
 * - The use of inline functions has been minimized to avoid bloating
 *   the executable size. Only small, frequently used functions like
 *   `max`, `min`, and `square` have been inlined.
 * 
 * - For larger, more complex functions (e.g., `factorial`, `isPalindrome`),
 *   a standard function call is preferred for better maintainability.
 * 
 * - Vector operations like sorting and searching rely on the Standard
 *   Library functions (`std::sort`, `std::find`) to ensure optimal
 *   performance and reduce code duplication.
 * 
 * - The use of the C++ Standard Library ensures that the code is portable
 *   and performs well across different platforms, compilers, and environments.
 *
 ************************************************/

/************************************************
 * SECTION: Memory Management Guidelines
 * 
 * This header file adheres to the RAII (Resource Acquisition Is Initialization)
 * principle, where resources like memory and file handles are automatically
 * managed by objects. Dynamic memory allocation is minimized by using
 * `std::vector` and other standard containers, which automatically manage
 * their memory.
 * 
 * Any function that allocates dynamic memory should either:
 * 1. Return a `std::unique_ptr` or `std::shared_ptr` to manage ownership.
 * 2. Ensure that any manually allocated memory is freed before returning.
 * 
 * Example:
 * std::unique_ptr<int[]> createArray(int size) {
 *     return std::make_unique<int[]>(size);
 * }
 * 
 ************************************************/

/************************************************
 * SECTION: Thread Safety and Concurrency
 * 
 * This header file assumes a single-threaded environment for the majority
 * of the functions. If used in a multithreaded context, external synchronization
 * mechanisms (e.g., mutexes) should be employed where necessary to avoid
 * data races and undefined behavior.
 * 
 * C++11 provides built-in threading support, and if concurrency is required,
 * consider using:
 * 
 * - `std::mutex` for mutual exclusion.
 * - `std::lock_guard` for scoped locking.
 * - `std::thread` for creating and managing threads.
 * 
 * Example of thread safety with a mutex:
 * 
 * std::mutex mtx;
 * void threadSafeFunction() {
 *     std::lock_guard<std::mutex> lock(mtx);
 *     // Critical section of code
 * }
 * 
 ************************************************/

/************************************************
 * END OF FILE
 * 
 * The nobuild.h file is intended to provide a comprehensive
 * set of utilities, macros, functions, and structures that can be
 * reused across the project without requiring additional libraries,
 * except for those provided by the C++ Standard Library.
 * 
 * Future improvements to this file may include:
 * - Additional utility functions.
 * - Performance optimization for certain functions.
 * - Better integration with external libraries and frameworks.
 ************************************************/





