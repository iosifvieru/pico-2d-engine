#!/bin/bash
# created by Iosif Vieru.
# 26.09.2024

OPTSTRING=":qhld"
QUIET=false
DEBUG=false
LOGGING=false

PICOTOOL_PATH=$(which picotool)
#PICOTOOL_PATH="/home/$USER/.pico-sdk/picotool/2.0.0/picotool/picotool"

usage()
{
    echo "Invalid options. Use -h for more informations."
    exit 1;
}

help()
{
    printf "
        Usage
            $0 [options]
        Options
            -q \t\t = Quiet mode -> the program won't print details about the build and run execution.
            -h \t\t = Help -> details about usage and options.
            -d \t\t = Debug -> prints stdio usb communcation
            -l \t\t = Enable logging -> compiles with logging enabled (_LOG_)
    "
}

while getopts ${OPTSTRING} opt; do
    case ${opt} in
        q)
            QUIET=true
            echo "Quiet mode on."
            ;;
        h)
            help
            exit 1;
            ;;
        d)
            DEBUG=true
            echo "Debug mode on."
            ;;
        l)
            LOGGING=true
            echo "Logging enabled (LOG)."
            ;;
        ?)
            usage
            exit 1
            ;;
    esac
done

DEFINES=""

if [ "$LOGGING" = true ]; then
    DEFINES="${DEFINES} -DLOG=1"
else
    DEFINES="${DEFINES} -DLOG=0"
fi

if [ "$DEBUG" = true ]; then
    DEFINES="${DEFINES} -DCOLL_DEBUG=1"
else
    DEFINES="${DEFINES} -DCOLL_DEBUG=0"
fi

# cmake
if $QUIET; then
    cmake -B build -S . -G Ninja $DEFINES > /dev/null 2>&1
else
    echo "CMAKE..."
    cmake -B build -S . -G Ninja $DEFINES
fi

if [ $? -eq 0 ]; then
    echo "CMake executed succesfully."
else
    echo "Ooooops..... something went wrong."

    echo "if you don't have build folder try running \"cmake -B build -S . -G Ninja\""
fi

# ninja
if $QUIET; then
    ninja -C build > /dev/null 2>&1
else
    ninja -C build
fi

if [ $? -eq 0 ]; then
    echo "Ninja executed succesfully."
else 
    echo "Ooooops..... something went wrong."
fi

# loading the .elf to pico
if [ -z "$PICOTOOL_PATH" ]; then
    echo "picotool not found. "
else
    current_path=`pwd`
    sudo $PICOTOOL_PATH load $current_path/build/pico-game-engine.elf -fx
fi

# see what s going on
# if $DEBUG; then
#     sleep 1
#     sudo screen /dev/ttyACM0 115200 &

#     if [ $? -eq 0 ]; then
#         echo "It seems to be an error accesing /dev/ttyACM0."
#         echo "Try running \"screen /dev/ttyACM0 115200\" manually insead."
#     fi
# fi