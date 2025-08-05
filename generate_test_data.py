#!/bin/python

import os
import random
import sys


MAX_TIME = 100
NAME_SIZE = 8
NAME_START_SYMBOL = ord('A')
NAME_END_SYMBOL = ord('Z')


def generate_random_name():
    name = ""
    for _ in range(NAME_SIZE):
        name += chr(random.randint(NAME_START_SYMBOL, NAME_END_SYMBOL))

    return name


def main():
    args = sys.argv[1:]

    entries_number = int(args[0])
    output_path = args[1]

    with open(output_path, "wt", encoding="utf-8") as output_file:
        output_file.write("Name,Check-in time,Check-out time")
        output_file.write(os.linesep)
        for _ in range(entries_number):
            name = generate_random_name()
            start_time = random.randint(0, MAX_TIME)
            end_time = random.randint(start_time, MAX_TIME)

            name += "_%d-%d" % (start_time, end_time)

            output_file.write("%s,%d,%d" % (name, start_time, end_time))
            output_file.write(os.linesep)


if __name__ == '__main__':
    main()
