#!/usr/bin/env python

from __future__ import division

import os, sys

try:
    import sh
except ImportError:
    sys.exit("Can't import sh! Try install it with: \n  pip install sh")


CURRENT_DIR = os.path.dirname(os.path.realpath(__file__))
MAX_SUM_PATH = os.path.join(CURRENT_DIR, 'maxSubSum')

if not os.path.exists(MAX_SUM_PATH):
    sys.exit("No such executable file: %s" % MAX_SUM_PATH)


def execute(program, param):
    outputs = []

    print 'Executing %s algorithm...' % param
    for i in xrange(1, 26):
        print '>> Round %i' % i
        output = program(param)
        outputs.append(output)
        print_summary(output, param)

    return outputs


def average_time(times):
    return sum(times) / float(len(times))


def print_summary(output, param):
    lines = output.split()
    times = [float(x) for x in lines]

    print "Average time: %f" % average_time(times)
    print "Execution times: %s" % ', '.join(lines)


def main():
    max_sum = sh.Command(MAX_SUM_PATH)
    linear_outputs = execute(max_sum, 'linear')
    quadratic_outputs = execute(max_sum, 'quadratic')


if __name__ == '__main__':
    main()
