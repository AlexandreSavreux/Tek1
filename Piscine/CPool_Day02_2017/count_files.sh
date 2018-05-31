#!/bin/sh

find -type f ! -regex ".*/\..*" | wc -l
