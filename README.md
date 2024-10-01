# uniquebuild

Header-only library for writing build recipes in C.

## Main Idea

The goal of `uniquebuild` is to allow developers to create C projects without the need for complex build systems like `make`, `cmake`, or shell scripts. All you need is a C compiler to bootstrap your build system, and then you can use this system to build everything else.

Try it out right here:

```console
$ cc ./uniquebuild.c -o uniquebuild
$ ./uniquebuild

Explore uniquebuild.c and the examples folder to learn more.

This is an Experimental Project

The feasibility and effectiveness of this approach are still under exploration. This is a research project aimed at simplifying the building process for C projects. It is actively used in various projects, including personal endeavors.

It's Likely Not Suitable for Your Project

If you are using tools like cmake with numerous modules to manage dependencies, you might find that uniquebuild does not meet your needs. uniquebuild is akin to writing shell scripts but in C.

Advantages of uniquebuild

Portability: Builds are highly portable across different operating systems, including (but not limited to) Linux, MacOS, Windows, FreeBSD, etc. This is accomplished by minimizing dependencies to just a C compiler, available on virtually all platforms.

Unified Language: Using C for both development and building enables interesting code reuse strategies. The build system can utilize the project's code directly, and the project can leverage the code of the build system as well.

Increased C Usage: You get to use C more, which is beneficial for improving your coding skills.


Disadvantages of uniquebuild

C Proficiency Required: Users should be comfortable with C programming and implementing solutions themselves. It’s essentially like writing shell scripts but using C.

Limited Scope: This approach may not be practical outside of C/C++ projects.

More C: While this is an advantage, it may also be seen as a drawback for those not interested in diving deeper into C.


Why is it called "uniquebuild"?

The name stems from the notion of simplifying the build process for C projects, eliminating traditional complexities. The philosophy is to reduce the friction of building C projects, making it a streamlined experience.

How to Use the Library in Your Own Project

Keep in mind that uniquebuild.h is a header-only library. This means you must define UNIQUEBUILD_IMPLEMENTATION before including it to access the function implementations. Refer to uniquebuild.c for an example.

1. Copy uniquebuild.h to your project.


2. Create uniquebuild.c in your project with your build recipe. See the provided example in uniquebuild.c.


3. Bootstrap the uniquebuild executable:

$ cc uniquebuild.c -o uniquebuild on POSIX systems

$ cl.exe uniquebuild.c on Windows with MSVC



4. Run the build: $ ./uniquebuild



If you enable the Rebuild Yourself™ technology, the uniquebuild executable will attempt to re-bootstrap itself whenever you modify its source code.

### Explanation of Modifications:
- **Title**: Updated to `uniquebuild`.
- **Main Idea**: Revised to reflect the purpose of `uniquebuild`.
- **Advantages and Disadvantages**: Tailored to match the features and potential drawbacks of `uniquebuild`.
- **Usage Instructions**: Adapted to reflect the steps needed to use `uniquebuild`.