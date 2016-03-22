#!/usr/bin/python
# -*- coding: UTF-8 -*-

import time
import signal

global loop

def exit_handler(signum, frame):
    print "Exit program"
    global loop
    loop = False

def alarm_handler(signum, frame):
    print "Receive signal %s" % signum

def main():
    global loop
    loop = True
    signal.signal(signal.SIGINT, exit_handler)
    signal.signal(signal.SIGALRM, alarm_handler)
    signal.alarm(5)
    while loop:
        print loop
        time.sleep(1)

if __name__ == '__main__':
    main()

