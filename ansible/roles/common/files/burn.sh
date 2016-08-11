#!/usr/bin/env bash
burnCortexA8 &
burnCortexA8 &
burnCortexA8 &
burnCortexA8 &
sleep 3600
killall -9 burnCortexA8
