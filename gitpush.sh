#!/bin/sh

git status
git add *
git commit -m "automated update"
git push origin master
