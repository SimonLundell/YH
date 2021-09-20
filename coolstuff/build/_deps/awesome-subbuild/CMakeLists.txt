# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.21.2)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(awesome-populate NONE)



include(ExternalProject)
ExternalProject_Add(awesome-populate
                     "UPDATE_DISCONNECTED" "False" "URL" "/home/simon/YH/awesome"
                    SOURCE_DIR          "/home/simon/YH/coolstuff/build/_deps/awesome-src"
                    BINARY_DIR          "/home/simon/YH/coolstuff/build/_deps/awesome-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)


