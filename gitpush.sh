#!/bin/sh

git status
git add .
git status
git commit -m "automated update"
git push origin master
