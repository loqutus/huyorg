#!/usr/bin/env bash
pwd
DATE=$(date)
cd ..
git add *
git commit -m "$DATE"
git push
ssh pi '/home/rusik/build.sh'
