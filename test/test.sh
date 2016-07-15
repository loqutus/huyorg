#!/usr/bin/env bash
pwd
DATE=$(date)
git add *
git commit -m "DATE"
git push
ssh pi /home/rusik/build.sh || exit
