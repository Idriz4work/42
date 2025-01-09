#!/bin/sh
find -type f,d,p,l,s -iname '*.sh' -execdir basename {} .sh ';'
