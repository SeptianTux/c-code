#!/bin/bash

echo vector cpp
time ./vector
echo ====================================================
echo

echo native
time ./native
echo ====================================================
echo

echo e_arr
time ./with_e_arr
echo ====================================================
echo
