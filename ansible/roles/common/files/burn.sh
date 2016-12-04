#!/usr/bin/env bash
burnCortexA9 &
burnCortexA9 &
burnCortexA9 &
burnCortexA9 &
sleep 3600
killall -9 burnCortexA9
