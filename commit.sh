#!/usr/bin/env bash
DATE=$(date)
./format.sh
git add *
git commit -m "$DATE"
git push
