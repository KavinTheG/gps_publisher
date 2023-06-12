# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/kavin/esp/esp-idf/components/bootloader/subproject"
  "/home/kavin/esp/projects/gps_publisher/build/bootloader"
  "/home/kavin/esp/projects/gps_publisher/build/bootloader-prefix"
  "/home/kavin/esp/projects/gps_publisher/build/bootloader-prefix/tmp"
  "/home/kavin/esp/projects/gps_publisher/build/bootloader-prefix/src/bootloader-stamp"
  "/home/kavin/esp/projects/gps_publisher/build/bootloader-prefix/src"
  "/home/kavin/esp/projects/gps_publisher/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/kavin/esp/projects/gps_publisher/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/kavin/esp/projects/gps_publisher/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
